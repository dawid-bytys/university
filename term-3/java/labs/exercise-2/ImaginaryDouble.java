public class ImaginaryDouble extends MyDouble {
    protected Object imaginary;

    @Override
    public Value create(String val) {
        String[] parts = val.split("i");
        ImaginaryDouble v = new ImaginaryDouble();
        v.value = new MyDouble().create(parts[0]);
        v.imaginary = new MyDouble().create(parts[1]);
        return v;
    }

    @Override
    public Value add(Value val) {
        ImaginaryDouble result = new ImaginaryDouble();

        result.value = ((MyDouble) this.value).add(val);
        if (val instanceof ImaginaryInt) {
            result.imaginary = ((MyDouble) this.imaginary).add((MyInteger) ((ImaginaryInt) val).imaginary);
        } else if (val instanceof ImaginaryDouble) {
            result.imaginary = ((MyDouble) this.imaginary).add((MyDouble) ((ImaginaryDouble) val).imaginary);
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
