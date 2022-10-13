public class Pesel {
    private static final int[] weights = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };
    private final String pesel;

    public Pesel(String pesel) {
        this.pesel = pesel;
    }

    public final boolean isValid() {
        if (!this.pesel.matches("[0-9]{11}") || !isControlDigitCorrect()) {
            return false;
        }
        return true;
    }

    private final boolean isControlDigitCorrect() {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += weights[i] * (this.pesel.charAt(i) - '0');
        }
        return (10 - (sum % 10)) == (this.pesel.charAt(10) - '0');
    }
}
