import java.io.FileNotFoundException;
import java.io.IOException;

public class Main {
    public static void validateArguments(String[] args) throws IllegalArgumentException {
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

    public static Algorithm getAlgorithm(String algorithmName) throws IllegalArgumentException {
        if (algorithmName.equals("Polibiusz")) {
            return new Polibiusz();
        }
        if (algorithmName.equals("rot")) {
            return new ROT11();
        }
        throw new IllegalArgumentException("Invalid algorithm");
    }

    public static void performOperation(String operation, String path_to_file_in, String path_to_file_out,
            Algorithm algorithm) throws IOException, IllegalArgumentException, FileNotFoundException {
        if (operation.equals("crypt")) {
            Cryptographer.cryptfile(path_to_file_in, path_to_file_out, algorithm);
        } else if (operation.equals("decrypt")) {
            Cryptographer.decryptfile(path_to_file_in, path_to_file_out, algorithm);
        } else {
            throw new IllegalArgumentException("Invalid operation");
        }
    }

    public static void main(String[] args) {
        try {
            validateArguments(args);
            Algorithm algorithm = getAlgorithm(args[3]);
            performOperation(args[2], args[0], args[1], algorithm);

            System.out.println("Done!");
            System.exit(0);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            System.exit(1);
        }
    }
}