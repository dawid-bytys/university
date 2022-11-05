public class Polibiusz implements Algorithm {
    // Nie jestem pewny czy chodzi o rozróżnianie I i J, czy o L i J, ponieważ
    // wszędzie widzę, że to I i J są nierozróżnialne. Ponadto wynik mojego szyfru
    // rózni sie od tego na stronie, bo nie do konca wiem, jak wyglada ta tabliczka
    // u Doktora, wiec dobrałem taką, która mi się wydaje sensowna.
    private static final char[][] polybiusSquare = {
            { 'A', 'B', 'C', 'D', 'E', 'F' },
            { 'G', 'H', 'I', 'J', 'K', 'L' },
            { 'M', 'N', 'O', 'P', 'Q', 'R' },
            { 'S', 'T', 'U', 'V', 'W', 'X' },
            { 'Y', 'Z', '0', '1', '2', '3' },
            { '4', '5', '6', '7', '8', '9' }
    };

    public String crypt(String inputWord) {
        String capitalizedInputWord = inputWord.toUpperCase();
        String outputWord = "";
        for (int i = 0; i < inputWord.length(); i++) {
            final char currentChar = capitalizedInputWord.charAt(i);
            if (!isCharValid(currentChar)) {
                outputWord += currentChar;
                continue;
            }

            final int[] coordinates = getCoordinates(currentChar);
            outputWord += coordinates[0] + "" + coordinates[1];
        }
        return outputWord;
    }

    public String decrypt(String inputWord) {
        String capitalizedInputWord = inputWord.toUpperCase();
        String outputWord = "";
        for (int i = 0; i < inputWord.length(); i += 2) {
            final char currentChar = capitalizedInputWord.charAt(i);
            if (!isCharValid(currentChar)) {
                outputWord += currentChar;
                i -= 1;
                continue;
            }

            final int row = Character.getNumericValue(currentChar);
            final int column = Character.getNumericValue(capitalizedInputWord.charAt(i + 1));
            outputWord += polybiusSquare[row][column];
        }
        return outputWord;
    }

    private static final int[] getCoordinates(char c) {
        for (int i = 0; i < polybiusSquare.length; i++) {
            for (int j = 0; j < polybiusSquare[i].length; j++) {
                if (polybiusSquare[i][j] == c) {
                    return new int[] { i, j };
                }
            }
        }
        return null;
    }
}