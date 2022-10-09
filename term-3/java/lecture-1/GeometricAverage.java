public class GeometricAverage {
    public static double[] strArrToDoubleArr(String[] args) {
        double[] result = new double[args.length];
        for (int i = 0; i < args.length; i++) {
            result[i] = Double.parseDouble(args[i]);
        }
        return result;
    }

    public static double getGeometricAverage(double[] args) {
        double result = 1;
        for (int i = 0; i < args.length; i++) {
            result *= args[i];
        }
        return Math.pow(result, 1.0 / args.length);
    }

    public static void main(String[] args) {
        double[] doubleArgs = strArrToDoubleArr(args);
        double result = getGeometricAverage(doubleArgs);

        System.out.println(result);
    }
}