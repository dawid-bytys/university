class Order {
    boolean isSameString(final String s1, final String s2) {
        if (s1 == null) {
            return s2 == null;
        }
        return s1.equals(s2);
    }
}

class Mail {
    static boolean isSameString(final String s1, final String s2) {
        if (s1 == null) {
            return s2 == null;
        }
        return s1.equals(s2);
    }
}