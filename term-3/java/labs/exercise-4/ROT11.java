public class ROT11 implements Algorithm {
    private static final String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    private static final int alphabetSize = alphabet.length();
    private static final int shift = 11;

    public String crypt(String inputWord) {
        String outputWord = "";
        for (int i = 0; i < inputWord.length(); i++) {
            final char currentChar = inputWord.charAt(i);
            if (!isCharValid(currentChar)) {
                outputWord += currentChar;
                continue;
            }

            final int index = alphabet.indexOf(inputWord.charAt(i));
            final int newIndex = (index + shift) % alphabetSize;
            outputWord += alphabet.charAt(newIndex);
        }
        return outputWord;
    }

    public String decrypt(String inputWord) {
        String outputWord = "";
        for (int i = 0; i < inputWord.length(); i++) {
            final char currentChar = inputWord.charAt(i);
            if (!isCharValid(currentChar)) {
                outputWord += currentChar;
                continue;
            }

            final int index = alphabet.indexOf(currentChar);
            final int newIndex = (index - shift + alphabetSize) % alphabetSize;
            outputWord += alphabet.charAt(newIndex);
        }
        return outputWord;
    }
}
