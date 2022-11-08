public interface Algorithm {
    public String crypt(String inputWord);

    public String decrypt(String inputWord);

    default boolean isCharDigitOrLetter(char c) {
        return Character.isLetter(c) || Character.isDigit(c);
    }
}