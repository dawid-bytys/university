package pl.edu.uj;

public class Main {
    public static void usage() {
        System.out.println("Usage: java Main <beesCount>");
        System.exit(1);
    }

    public static void validateArguments(String[] args) throws IllegalArgumentException, NumberFormatException {
        if (args.length != 1) {
            throw new IllegalArgumentException("Invalid number of arguments");
        }
        try {
            Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            throw new NumberFormatException("Argument is not a number");
        }
    }

    public static void main(String[] args) {
        try {
            validateArguments(args);
            new Hive(Integer.parseInt(args[0]));
        } catch (Exception e) {
            System.out.println(e.getMessage());
            usage();
        }
    }
}