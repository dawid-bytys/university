package pl.edu.uj;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Utils {
    public static void writeLog(String text)  {
        System.out.println(text);

        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("logs.txt", true));
            writer.write(text);
            writer.newLine();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
