public class Main {
    public static void main(final String[] args) {
        @SuppressWarnings("unchecked")
        DataFrame df = new DataFrame(new Class[] { MyDouble.class, MyDouble.class, MyDouble.class },
                new String[] { "col1", "col2", "col3" });

        df.addRow(new String[] { "1.0", "2.0", "3.0" });
        df.addRow(new String[] { "4.0", "5.0", "6.0" });
        df.addRow(new String[] { "7.0", "8.0", "9.0" });

        df.head();

        df.apply(new Appliable() {
            @Override
            public void apply(Series series) {
                for (int i = 0; i < series.getSize(); ++i) {
                    MyDouble val = (MyDouble) series.getValue(i);
                    val.create(val.toString());
                    series.setValue(i, val.add(new MyDouble().create("1.0")));
                }
            }
        }, "col2", 3);

        df.head();
    }
}