public class Static {
    static int x = 5;

    public static void main(String[] args) {
        Static s = new Static();
        s.nonStaticMethod();
    }

    void nonStaticMethod() {
        System.out.println("The value of static variable x is: " + x);
    }
}
