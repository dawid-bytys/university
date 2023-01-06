package src.edu.uj.pl;

public class Hive {
    private static final int NUM_HOLES = 2;
    private final boolean[] holesInUse = new boolean[NUM_HOLES];

    public synchronized int getFreeHole() {
        // Check if the first hole is free
        if (!holesInUse[0]) {
            return 0;
        }

        // Check if the second hole is free
        if (!holesInUse[1]) {
            return 1;
        }

        // If both holes are in use, return -1
        return -1;
    }

    public synchronized void enter(final int hole) {
        if (holesInUse[hole]) {
            try {
                wait(1000);
            } catch (InterruptedException e) {
                System.out.println("Bee has accidentally died");
            }
        }

        holesInUse[hole] = true;
        notify();
    }

    public synchronized void leave(final int hole) {
        if (holesInUse[hole]) {
            try {
                wait(1000);
            } catch (InterruptedException e) {
                System.out.println("Bee has accidentally died");
            }
        }

        holesInUse[hole] = false;
        notify();
    }
}
