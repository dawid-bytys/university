public class ImaginaryInt extends MyInteger {
    protected Object imaginary;

    @Override
    public Value create(String val) {
        String[] parts = val.split("i");
        ImaginaryInt v = new ImaginaryInt();
        v.value = new MyInteger().create(parts[0]);
        v.imaginary = new MyInteger().create(parts[1]);
        return v;
    }

    @Override
    public Value add(Value val) {
        ImaginaryInt result = new ImaginaryInt();

        result.value = ((MyInteger) this.value).add(val);
        if (val instanceof ImaginaryInt) {
            result.imaginary = ((MyInteger) this.imaginary).add((MyInteger) ((ImaginaryInt) val).imaginary);
        } else if (val instanceof ImaginaryDouble) {
            result.imaginary = ((MyInteger) this.imaginary).add((MyDouble) ((ImaginaryDouble) val).imaginary);
        } else {
            result.imaginary = this.imaginary;
        }

        return result;
    }

    @Override
    public String toString() {
        return this.value.toString() + "i" + this.imaginary.toString();
    }
}
