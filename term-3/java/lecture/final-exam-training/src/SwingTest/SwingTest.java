
import javax.swing.*;

public class SwingTest {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Swing Test");
        JScrollBar scrollBar = new JScrollBar();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);
        frame.add(scrollBar);
        frame.setVisible(true);
    }
}
