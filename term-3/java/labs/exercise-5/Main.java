public class Main {
    private static void validateArgs(final String[] args) throws InvalidFrameRate, IllegalArgumentException {
        if (args.length != 4) {
            throw new IllegalArgumentException("Invalid number of arguments");
        }
        if (args[0] == null || args[0].isEmpty()) {
            throw new IllegalArgumentException("Invalid input file");
        }
        if (args[1] == null || args[1].isEmpty()) {
            throw new IllegalArgumentException("Invalid output file");
        }
        if (args[2].matches("\\d+") == false) {
            throw new IllegalArgumentException("Delay must be an integer");
        }
        if (args[3].matches("\\d+") == false) {
            throw new IllegalArgumentException("FPS must be an integer");
        }
        if (Integer.parseInt(args[3]) <= 0) {
            throw new InvalidFrameRate("FPS value must be greater than 0");
        }
    }

    public static void main(String[] args) {
        try {
            validateArgs(args);
            new MicroDVD().delay(args[0], args[1], Integer.parseInt(args[2]), Integer.parseInt(args[3]));
            System.out.println("Done!");

            System.exit(0);
        } catch (final Exception e) {
            System.out.println(e.getMessage());
            System.exit(1);
        }
    }
}