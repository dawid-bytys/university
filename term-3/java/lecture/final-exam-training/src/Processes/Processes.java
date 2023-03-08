import java.io.IOException;
import java.util.Scanner;

public class Processes {
    public static void main(String[] args) throws IOException {
        ProcessBuilder pb = new ProcessBuilder("ls", "-l");
        Process p = pb.start();

        Scanner s = new Scanner(p.getInputStream());

        while (s.hasNextLine()) {
            System.out.println(s.nextLine());
        }

        s.close();
    }
}
