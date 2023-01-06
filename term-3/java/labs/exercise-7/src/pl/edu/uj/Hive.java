package pl.edu.uj;

import java.util.Random;

import static pl.edu.uj.Utils.writeLog;

public class Hive {
    private static final Hole HOLE_1 = new Hole(1);
    private static final Hole HOLE_2 = new Hole(2);

    public Hive(int beesCount) {
        for (int i = 0; i < beesCount; ++i) {
            new Bee(i + 1).start();
        }
    }

    private static class Bee extends Thread {
        private final Random random = new Random();
        private final int id;

        private Bee(int id) {
            this.id = id;
        }

        @Override
        public void run() {
            writeLog("Bee " + id + " has started working.");
            while (true) {
                waitOutside();

                writeLog("Bee " + id + " is trying to enter the hive...");
                Hole hole = tryEnterHive();
                if (hole == null) {
                    writeLog("Bee " + id + " is waiting for a free hole...");
                    while (hole == null) {
                        hole = tryEnterHive();
                    }
                }

                enterHive(hole);
                writeLog("Bee " + this.id + " has entered the hive through hole " + hole.id);

                waitInside();

                exitHive(hole);
                writeLog("Bee " + this.id + " has exited the hive through hole " + hole.id);
            }
        }

        private void waitOutside() {
            try {
                Thread.sleep(random.nextInt(5000) + 5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private void waitInside() {
            try {
                Thread.sleep(random.nextInt(4000) + 1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private Hole tryEnterHive() {
            Hole hole = null;
            synchronized (HOLE_1) {
                if (HOLE_1.isFree()) {
                    hole = HOLE_1;
                    HOLE_1.setOccupied(true);
                }
            }
            if (hole == null) {
                synchronized (HOLE_2) {
                    if (HOLE_2.isFree()) {
                        hole = HOLE_2;
                        HOLE_2.setOccupied(true);
                    }
                }
            }
            return hole;
        }

        private void enterHive(Hole hole) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            hole.setOccupied(false);
        }

        private void exitHive(Hole hole) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            hole.setOccupied(false);
        }
    }

    private static class Hole {
        private boolean occupied;
        private final int id;

        private Hole(int id) {
            this.id = id;
        }

        public boolean isFree() {
            return !occupied;
        }

        public void setOccupied(boolean occupied) {
            this.occupied = occupied;
        }
    }
}