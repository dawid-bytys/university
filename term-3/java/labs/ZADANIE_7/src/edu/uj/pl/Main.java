package src.edu.uj.pl;

public class Main {
    public static void usage() {
        System.out.println("Usage: java Main <number of bees>");
        System.exit(1);
    }

    public static void validateArgs(String[] args) {
        if (args.length != 1) {
            usage();
        }

        try {
            Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            throw new NumberFormatException("Number of bees must be an integer");
        }
    }

    public static void main(String[] args) {
        try {
            validateArgs(args);
            final int beesCount = Integer.parseInt(args[0]);
            Hive hive = new Hive();
            for (int i = 0; i < beesCount; ++i) {
                new Bee(hive, i + 1).start();
            }
        } catch (NumberFormatException e) {
            System.out.println(e.getMessage());
            usage();
        }
    }
}