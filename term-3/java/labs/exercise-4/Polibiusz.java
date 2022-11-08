import java.util.HashMap;
import java.util.Map;

public class Polibiusz implements Algorithm {
    private static final Map<Character, String> polybiusSquare = new HashMap<Character, String>() {
        {
            put('A', "11");
            put('B', "12");
            put('C', "13");
            put('D', "14");
            put('E', "15");
            put('F', "21");
            put('G', "22");
            put('H', "23");
            put('I', "24");
            put('J', "24");
            put('K', "25");
            put('L', "31");
            put('M', "32");
            put('N', "33");
            put('O', "34");
            put('P', "35");
            put('Q', "41");
            put('R', "42");
            put('S', "43");
            put('T', "44");
            put('U', "45");
            put('V', "51");
            put('W', "52");
            put('X', "53");
            put('Y', "54");
            put('Z', "55");
        }
    };

    public String crypt(String inputWord) {
        String outputWord = "";
        for (int i = 0; i < inputWord.length(); ++i) {
            final char currentChar = inputWord.charAt(i);
            if (isDigit(currentChar)) {
                continue;
            }
            if (!isCharDigitOrLetter(currentChar)) {
                outputWord += currentChar;
                continue;
            }

            outputWord += polybiusSquare.get(Character.toUpperCase(currentChar));
        }
        return outputWord;
    }

    public String decrypt(String inputWord) {
        String outputWord = "";
        for (int i = 0; i < inputWord.length(); ++i) {
            final char currentChar = inputWord.charAt(i);
            if (!isDigit(currentChar)) {
                outputWord += currentChar;
                continue;
            }

            for (Map.Entry<Character, String> entry : polybiusSquare.entrySet()) {
                if (entry.getValue().equals(inputWord.substring(i, i + 2))) {
                    outputWord += entry.getKey();
                    ++i;
                    break;
                }
            }
        }
        return outputWord;
    }

    private boolean isDigit(char c) {
        return Character.isDigit(c);
    }
}