public class Main {
    private static void validateArguments(String[] args) throws IllegalArgumentException {
        if (args.length != 4) {
            throw new IllegalArgumentException("Invalid number of arguments");
        }
        if (args[0] == null || args[0].isEmpty()) {
            throw new IllegalArgumentException("Invalid input file");
        }
        if (args[1] == null || args[1].isEmpty()) {
            throw new IllegalArgumentException("Invalid output file");
        }
        if (!args[2].equals("crypt") && !args[2].equals("decrypt")) {
            throw new IllegalArgumentException("Invalid operation");
        }
        if (!args[3].equals("Polibiusz") && !args[3].equals("rot")) {
            throw new IllegalArgumentException("Invalid algorithm");
        }
    }

    public static void main(String[] args) {
        try {
            validateArguments(args);

            Algorithm algorithm = null;
            if (args[3].equals("Polibiusz")) {
                // algorithm = new Polibiusz();
            } else {
                algorithm = new ROT11();
            }

            if (args[2].equals("crypt")) {
                Cryptographer.cryptfile(args[0], args[1], algorithm);
            } else {
                Cryptographer.decryptfile(args[0], args[1], algorithm);
            }

            System.out.println("Done!");
            System.exit(0);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            System.exit(1);
        }
    }
}