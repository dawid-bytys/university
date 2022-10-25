public class Main {
    public static void main(String[] args) {
        Value a = new ImaginaryInt().create("12i4").add(new MyInteger().create("10"));
        Value b = new ImaginaryDouble().create("12.5i4.5").add(new MyDouble().create("10.5"));
        Value c = new MyInteger().create("12").add(new ImaginaryInt().create("10i4"));
        Value d = new MyDouble().create("12.5").add(new ImaginaryDouble().create("10.5i4.5"));
        Value e = new MyInteger().create("12").add(new MyDouble().create("10.5"));
        Value f = new MyDouble().create("12.5").add(new MyInteger().create("10"));
        Value g = new ImaginaryInt().create("12i4").add(new ImaginaryDouble().create("10.5i4.5"));
        Value h = new ImaginaryDouble().create("12.5i4.5").add(new ImaginaryInt().create("10i4"));
        Value i = new ImaginaryInt().create("12i4").add(new ImaginaryInt().create("10i4"));
        Value j = new ImaginaryDouble().create("12.5i4.5").add(new ImaginaryDouble().create("10.5i4.5"));

        for (Value v : new Value[] { a, b, c, d, e, f, g, h, i, j }) {
            v.print();
        }
    }
}