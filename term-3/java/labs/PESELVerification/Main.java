class Main {
    private static final int[] weights = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };

    public static final boolean isPeselValid(String pesel) {
        if (!pesel.matches("[0-9]{11}") || !hasCorrectControlDigit(pesel)) {
            return false;
        }
        return true;
    }

    private static final boolean hasCorrectControlDigit(String pesel) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += weights[i] * (pesel.charAt(i) - '0');
        }
        return (10 - (sum % 10)) == (pesel.charAt(10) - '0');
    }

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No argument provided!");
            return;
        }

        String output = String.format("Is PESEL %s valid?: %b", args[0], isPeselValid(args[0]));
        System.out.println(output);
    }
}