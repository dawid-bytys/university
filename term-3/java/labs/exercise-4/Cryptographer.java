import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class Cryptographer {
    static public void cryptfile(String path_to_file_in, String path_to_file_out, Algorithm algorithm)
            throws FileNotFoundException, IOException, IllegalArgumentException {
        if (path_to_file_in == null || path_to_file_out == null || algorithm == null) {
            throw new IllegalArgumentException("Arguments cannot be null");
        }

        BufferedReader readBuffer = null;
        BufferedWriter writeBuffer = null;

        try {
            readBuffer = new BufferedReader(new FileReader(path_to_file_in));
            writeBuffer = new BufferedWriter(new FileWriter(path_to_file_out));

            String line = readBuffer.readLine();
            while (line != null) {
                String cryptedLine = algorithm.crypt(line);
                writeBuffer.write(cryptedLine);

                line = readBuffer.readLine();
                if (line != null) {
                    writeBuffer.newLine();
                }
            }
        } catch (FileNotFoundException e) {
            throw new FileNotFoundException(e.getMessage());
        } catch (IOException e) {
            throw new IOException(e.getMessage());
        } finally {
            try {
                if (readBuffer != null) {
                    readBuffer.close();
                }
                if (writeBuffer != null) {
                    writeBuffer.close();
                }
            } catch (IOException e) {
                throw new IOException(e.getMessage());
            }
        }
    }

    static public void decryptfile(String path_to_file_in, String path_to_file_out, Algorithm algorithm)
            throws IOException, IllegalArgumentException, FileNotFoundException {
        if (path_to_file_in == null || path_to_file_out == null || algorithm == null) {
            throw new IllegalArgumentException("Arguments cannot be null");
        }

        BufferedReader readBuffer = null;
        BufferedWriter writeBuffer = null;

        try {
            readBuffer = new BufferedReader(new FileReader(path_to_file_in));
            writeBuffer = new BufferedWriter(new FileWriter(path_to_file_out));

            String line = readBuffer.readLine();
            while (line != null) {
                String decryptedLine = algorithm.decrypt(line);
                writeBuffer.write(decryptedLine);

                line = readBuffer.readLine();
                if (line != null) {
                    writeBuffer.newLine();
                }
            }
        } catch (FileNotFoundException e) {
            throw new FileNotFoundException(e.getMessage());
        } catch (IOException e) {
            throw new IOException(e.getMessage());
        } finally {
            try {
                if (readBuffer != null) {
                    readBuffer.close();
                }
                if (writeBuffer != null) {
                    writeBuffer.close();
                }
            } catch (IOException e) {
                throw new IOException(e.getMessage());
            }
        }
    }
}