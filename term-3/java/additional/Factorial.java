public class Factorial {
    public static int iterative(int n) {
        if (n == 1) {
            return 1;
        }

        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public static int recursive(int n) {
        if (n == 1) {
            return 1;
        }
        return n * recursive(n - 1);
    }

    public static void main(String[] args) {
        String method = args[0];
        if (method == "r") {
            System.out.println(recursive(Integer.parseInt(args[1])));
        } else if (method == "i") {
            System.out.println(iterative(Integer.parseInt(args[1])));
        }
    }
}