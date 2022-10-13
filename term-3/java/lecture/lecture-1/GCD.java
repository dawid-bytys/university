public class GCD {
    public static int getGCD(int a, int b) {
        int result = 1;
        for (int i = 1; i <= a && i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                result = i;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int result = getGCD(a, b);

        System.out.println(result);
    }
}
