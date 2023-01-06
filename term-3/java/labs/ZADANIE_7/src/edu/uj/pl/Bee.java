package src.edu.uj.pl;

public class Bee extends Thread {
    private final Hive hive;
    private final int id;
    private int countOfInlets;
    private int countOfOutlets;
    private int averageTimeOfOutlet;
    private int averageTimeOfInlet;

    public Bee(Hive hive, final int id) {
        this.hive = hive;
        this.id = id;
    }

    @Override
    public void run() {
        while (true) {
            // Check which hole is free
            System.out.println("Bee " + id + " checks which hole is free...");
            int hole = hive.getFreeHole();

            // If no hole is free, wait for one to become free
            if (hole == -1) {
                System.out.println("Bee " + id + " is waiting for any hole to become free...");
            }

            while (hole == -1) {
                hole = hive.getFreeHole();
            }

            // Enter the hive through the hole
            hive.enter(hole);

            // Simulate the bee entering the hive
            try {
                System.out.println("Bee " + id + " is entering the hole " + hole + "...");
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Bee has accidentally died");
            }

            System.out.println("Bee " + id + " has entered the hole " + hole);

            // Spend some time inside the hive
            try {
                Thread.sleep(1000 + (long) (Math.random() * 4000));
            } catch (InterruptedException e) {
                System.out.println("Bee " + id + " has accidentally died");
            }

            // Check which hole is free
            System.out.println("Bee " + id + " checks which hole is free...");
            hole = hive.getFreeHole();

            // If no hole is free, wait for one to become free
            if (hole == -1) {
                System.out.println("Bee " + id + " is waiting for any hole to become free...");
            }

            while (hole == -1) {
                hole = hive.getFreeHole();
            }

            // Leave the hive through the same hole
            hive.leave(hole);

            // Simulate the bee exiting the hive
            try {
                System.out.println("Bee " + id + " is leaving the hole " + hole + "...");
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Bee has accidentally died");
            }

            System.out.println("Bee " + id + " has left the hive through hole " + hole);

            // Sleep for 5000ms to 10000ms to simulate the time outside the hive
            try {
                Thread.sleep(5000 + (long) (Math.random() * 5000));
            } catch (InterruptedException e) {
                System.out.println("Bee " + id + " has accidentally died");
            }
        }
    }
}