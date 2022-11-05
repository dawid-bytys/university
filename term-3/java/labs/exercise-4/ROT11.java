public class ROT11 implements Algorithm {
    private static final String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    private static final int alphabetSize = alphabet.length();
    private static final int shift = 11;

    public String crypt(String inputWord) {
        String outputWord = "";
        for (int i = 0; i < inputWord.length(); i++) {
            if (alphabet.indexOf(inputWord.charAt(i)) == -1) {
                outputWord += inputWord.charAt(i);
            } else {
                final int index = alphabet.indexOf(inputWord.charAt(i));
                final int newIndex = (index + shift) % alphabetSize;
                outputWord += alphabet.charAt(newIndex);
            }
        }
        return outputWord;
    }

    public String decrypt(String inputWord) {
        String outputWord = "";
        for (int i = 0; i < inputWord.length(); i++) {
            if (alphabet.indexOf(inputWord.charAt(i)) == -1) {
                outputWord += inputWord.charAt(i);
            } else {
                final int index = alphabet.indexOf(inputWord.charAt(i));
                final int newIndex = (index - shift + alphabetSize) % alphabetSize;
                outputWord += alphabet.charAt(newIndex);
            }
        }
        return outputWord;
    }
}
