public class AppliableThread extends Thread {
    private Series series;
    private Appliable appliable;

    public AppliableThread(final Series series, final Appliable appliable) {
        this.series = series;
        this.appliable = appliable;
    }

    @Override
    public void run() {
        appliable.apply(series);
        System.out.println("Thread " + Thread.currentThread().threadId() + " finished");
    }

    public Series getSeries() {
        return series;
    }
}
