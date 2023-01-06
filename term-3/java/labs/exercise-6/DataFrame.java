import java.util.ArrayList;

public class DataFrame {
    ArrayList<Series> series = new ArrayList<>();

    public DataFrame(Class<? extends Value>[] types, String[] names) {
        for (int i = 0; i < types.length; ++i) {
            series.add(new Series(types[i], names[i]));
        }
    }

    public void addRow(String[] values) {
        for (int i = 0; i < series.size(); ++i) {
            series.get(i).addValue(values[i]);
        }
    }

    public void head() {
        for (int i = 0; i < series.size(); ++i) {
            System.out.print(series.get(i).getName() + " ");
        }
        System.out.println();
        for (int i = 0; i < series.get(0).getSize(); ++i) {
            for (int j = 0; j < series.size(); ++j) {
                System.out.print(series.get(j).getValue(i) + " ");
            }
            System.out.println();
        }
    }

    public DataFrame iloc(final int startIndex, final int endIndex) {
        @SuppressWarnings("unchecked")
        Class<? extends Value>[] types = new Class[series.size()];
        String[] names = new String[series.size()];
        for (int i = 0; i < series.size(); ++i) {
            types[i] = series.get(i).getType();
            names[i] = series.get(i).getName();
        }

        DataFrame result = new DataFrame(types, new String[series.size()]);
        for (int i = 0; i < series.size(); ++i) {
            result.series.add(series.get(i).iloc(startIndex, endIndex));
        }

        return result;
    }

    public void apply(final Appliable appliable, final String name) {
        Series seriesToApply = null;
        for (int i = 0; i < series.size(); ++i) {
            if (series.get(i).getName().equals(name)) {
                seriesToApply = series.get(i);
                break;
            }
        }

        for (int i = 0; i < seriesToApply.getSize(); ++i) {
            appliable.apply(seriesToApply);
        }
    }

    public void apply(final Appliable appliable, final String name, final int jobs) {
        Series seriesToApply = null;
        for (int i = 0; i < series.size(); ++i) {
            if (series.get(i).getName().equals(name)) {
                seriesToApply = series.get(i);
                break;
            }
        }

        final int seriesSize = series.get(0).getSize();
        final int step = Math.ceilDiv(jobs, seriesSize);
        AppliableThread[] threads = new AppliableThread[jobs];

        for (int i = 0, threadId = 0; i < seriesSize; i += step, ++threadId) {
            Series partSeries = seriesToApply.iloc(i, i + step);
            threads[threadId] = new AppliableThread(partSeries, appliable);
        }

        try {
            for (AppliableThread thread : threads) {
                thread.start();
            }
            for (AppliableThread thread : threads) {
                thread.join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        for (int i = 0; i < jobs - 1; ++i) {
            for (int j = 0; j < step; ++j) {
                seriesToApply.setValue(i * step + j, threads[i].getSeries().getValue(j));
            }
        }

        for (int i = 0; i < series.size(); ++i) {
            if (series.get(i).getName().equals(name)) {
                series.set(i, seriesToApply);
                break;
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < series.size(); ++i) {
            result.append(series.get(i).getName()).append(" ");
        }
        result.append("\n");
        for (int i = 0; i < series.get(0).getSize(); ++i) {
            for (int j = 0; j < series.size(); ++j) {
                result.append(series.get(j).getValue(i)).append(" ");
            }
            result.append("\n");
        }
        return result.toString();
    }
}
