import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MicroDVD {
    public void delay(final String in, final String out, final int delay, final int fps)
            throws InvalidFrameRate, IOException, InvalidInputLine {
        if (fps <= 0) {
            throw new InvalidFrameRate("Invalid FPS value");
        }

        BufferedReader reader = null;
        BufferedWriter writer = null;

        try {
            reader = new BufferedReader(new FileReader(in));
            writer = new BufferedWriter(new FileWriter(out));

            String line = reader.readLine();
            while (line != null) {
                if (!line.matches("\\{\\d+\\}\\{\\d+\\}.*")) {
                    throw new InvalidInputLine("Invalid line: " + line);
                }

                final int startFrame = Integer.parseInt(line.substring(1, line.indexOf("}")));
                final int endFrame = Integer.parseInt(line.substring(line.indexOf("}") + 2, line.lastIndexOf("}")));

                final int newStartFrame = startFrame + delay * fps / 1000;
                final int newEndFrame = endFrame + delay * fps / 1000;

                writer.write(
                        "{" + newStartFrame + "}{" + newEndFrame + "}" + line.substring(line.lastIndexOf("}") + 1));
                line = reader.readLine();
                if (line != null) {
                    writer.newLine();
                }
            }
        } catch (final IOException e) {
            throw e;
        } catch (final InvalidInputLine e) {
            throw e;
        } finally {
            try {
                if (reader != null) {
                    reader.close();
                }
            } catch (final IOException e) {
                throw e;
            }

            try {
                if (writer != null) {
                    writer.close();
                }
            } catch (final IOException e) {
                throw e;
            }
        }
    }
}
