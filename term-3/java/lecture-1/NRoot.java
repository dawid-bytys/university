public class NRoot {
    public static void main(String[] args) {
        double n = Double.parseDouble(args[0]);
        double x = Double.parseDouble(args[1]);
        double result = Math.pow(x, 1 / n);

        System.out.println(result);
    }
}