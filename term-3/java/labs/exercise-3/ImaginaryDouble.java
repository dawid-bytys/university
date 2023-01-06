public class ImaginaryDouble extends MyDouble {
    protected MyDouble imaginary;

    @Override
    public Value create(String val) {
        ImaginaryDouble newImaginaryDouble = new ImaginaryDouble();
        newImaginaryDouble.value = new MyDouble().create(parseReal(val));
        newImaginaryDouble.imaginary = (MyDouble) new MyDouble().create(parseImaginary(val));
        return newImaginaryDouble;
    }

    @Override
    public Value add(Value val) {
        ImaginaryDouble result = new ImaginaryDouble();

        result.value = ((MyDouble) this.value).add(val);
        if (val instanceof ImaginaryInt) {
            result.imaginary = (MyDouble) this.imaginary.add((MyInteger) ((ImaginaryInt) val).imaginary);
        } else if (val instanceof ImaginaryDouble) {
            result.imaginary = (MyDouble) this.imaginary.add((MyDouble) ((ImaginaryDouble) val).imaginary);
        } else {
            result.imaginary = this.imaginary;
        }

        return result;
    }

    @Override
    public Value sub(Value val) {
        ImaginaryDouble result = new ImaginaryDouble();

        result.value = ((MyDouble) this.value).sub(val);
        if (val instanceof ImaginaryInt) {
            result.imaginary = (MyDouble) this.imaginary.sub((MyInteger) ((ImaginaryInt) val).imaginary);
        } else if (val instanceof ImaginaryDouble) {
            result.imaginary = (MyDouble) this.imaginary.sub((MyDouble) ((ImaginaryDouble) val).imaginary);
        } else {
            result.imaginary = this.imaginary;
        }

        return result;
    }

    @Override
    public Value mul(Value val) {
        ImaginaryDouble result = new ImaginaryDouble();

        if (val instanceof ImaginaryInt) {
            MyDouble a = (MyDouble) ((MyDouble) this.value).mul((MyInteger) ((ImaginaryInt) val).value);
            MyDouble b = (MyDouble) ((MyDouble) this.imaginary).mul((MyInteger) ((ImaginaryInt) val).imaginary);
            MyDouble c = (MyDouble) ((MyDouble) this.value).mul((MyInteger) ((ImaginaryInt) val).imaginary);
            MyDouble d = (MyDouble) ((MyDouble) this.imaginary).mul((MyInteger) ((ImaginaryInt) val).value);
            result.value = (MyDouble) a.sub(b);
            result.imaginary = (MyDouble) c.add(d);
        } else if (val instanceof ImaginaryDouble) {
            MyDouble a = (MyDouble) ((MyDouble) this.value).mul((MyDouble) ((ImaginaryDouble) val).value);
            MyDouble b = (MyDouble) ((MyDouble) this.imaginary).mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyDouble c = (MyDouble) ((MyDouble) this.value).mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyDouble d = (MyDouble) ((MyDouble) this.imaginary)
                    .mul((MyDouble) ((ImaginaryDouble) val).value);
            result.value = (MyDouble) a.sub(b);
            result.imaginary = (MyDouble) c.add(d);
        } else {
            result.value = ((MyDouble) this.value).mul(val);
            result.imaginary = (MyDouble) ((MyDouble) this.imaginary).mul(val);
        }

        return result;
    }

    @Override
    public Value div(Value val) {
        ImaginaryDouble result = new ImaginaryDouble();

        if (val instanceof ImaginaryInt) {
            MyDouble a = (MyDouble) ((MyDouble) this.value).mul((MyInteger) ((ImaginaryInt) val).value);
            MyDouble b = (MyDouble) ((MyDouble) this.imaginary).mul((MyInteger) ((ImaginaryInt) val).imaginary);
            MyDouble c = (MyDouble) ((MyDouble) this.value).mul((MyInteger) ((ImaginaryInt) val).imaginary);
            MyDouble d = (MyDouble) ((MyDouble) this.imaginary).mul((MyInteger) ((ImaginaryInt) val).value);
            MyDouble e = (MyDouble) ((MyInteger) ((ImaginaryInt) val).value)
                    .mul((MyInteger) ((ImaginaryInt) val).value);
            MyDouble f = (MyDouble) ((MyInteger) ((ImaginaryInt) val).imaginary)
                    .mul((MyInteger) ((ImaginaryInt) val).imaginary);
            result.value = (MyDouble) a.add(b).div(e.add(f));
            result.imaginary = (MyDouble) c.sub(d).div(e.add(f));
        } else if (val instanceof ImaginaryDouble) {
            MyDouble a = (MyDouble) ((MyDouble) this.value).mul((MyDouble) ((ImaginaryDouble) val).value);
            MyDouble b = (MyDouble) ((MyDouble) this.imaginary).mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyDouble c = (MyDouble) ((MyDouble) this.value).mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyDouble d = (MyDouble) ((MyDouble) this.imaginary).mul((MyDouble) ((ImaginaryDouble) val).value);
            MyDouble e = (MyDouble) ((MyDouble) ((ImaginaryDouble) val).value)
                    .mul((MyDouble) ((ImaginaryDouble) val).value);
            MyDouble f = (MyDouble) ((MyDouble) ((ImaginaryDouble) val).imaginary)
                    .mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            result.value = (MyDouble) a.add(b).div(e.add(f));
            result.imaginary = (MyDouble) c.sub(d).div(e.add(f));
        } else {
            result.value = ((MyDouble) this.value).div(val);
            result.imaginary = (MyDouble) ((MyDouble) this.imaginary).div(val);
        }

        return result;
    }

    @Override
    public Value pow(Value val) {
        ImaginaryDouble result = new ImaginaryDouble();

        if (val instanceof ImaginaryInt) {
            MyDouble a = (MyDouble) ((MyDouble) this.value).pow((MyInteger) ((ImaginaryInt) val).value);
            MyDouble b = (MyDouble) ((MyDouble) this.imaginary).pow((MyInteger) ((ImaginaryInt) val).imaginary);
            MyDouble c = (MyDouble) ((MyDouble) this.value).pow((MyInteger) ((ImaginaryInt) val).imaginary);
            MyDouble d = (MyDouble) ((MyDouble) this.imaginary).pow((MyInteger) ((ImaginaryInt) val).value);
            result.value = (MyDouble) a.sub(b);
            result.imaginary = (MyDouble) c.add(d);
        } else if (val instanceof ImaginaryDouble) {
            MyDouble a = (MyDouble) ((MyDouble) this.value).pow((MyDouble) ((ImaginaryDouble) val).value);
            MyDouble b = (MyDouble) ((MyDouble) this.imaginary).pow((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyDouble c = (MyDouble) ((MyDouble) this.value).pow((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyDouble d = (MyDouble) ((MyDouble) this.imaginary).pow((MyDouble) ((ImaginaryDouble) val).value);
            result.value = (MyDouble) a.sub(b);
            result.imaginary = (MyDouble) c.add(d);
        } else {
            result.value = ((MyDouble) this.value).pow(val);
            result.imaginary = (MyDouble) ((MyDouble) this.imaginary).pow(val);
        }

        return result;
    }

    @Override
    public boolean eq(Value val) {
        if (val instanceof ImaginaryInt) {
            return ((MyDouble) this.value).eq((MyInteger) ((ImaginaryInt) val).value)
                    && ((MyDouble) this.imaginary).eq((MyInteger) ((ImaginaryInt) val).imaginary);
        }
        if (val instanceof ImaginaryDouble) {
            return ((MyDouble) this.value).eq((MyDouble) ((ImaginaryDouble) val).value)
                    && ((MyDouble) this.imaginary).eq((MyDouble) ((ImaginaryDouble) val).imaginary);
        }
        return ((MyDouble) this.value).eq(val) && ((MyDouble) this.imaginary).eq(new MyDouble().create("0"));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 20;
        result = prime * result + ((this.value == null) ? 0 : this.value.hashCode());
        return result;
    }

    @Override
    public String toString() {
        return this.value.toString() + "i" + this.imaginary.toString();
    }

    private String parseReal(String val) {
        if (val.contains("i")) {
            final String real = val.substring(0, val.indexOf("i"));
            return real == "" ? "0" : real;
        }
        return val;
    }

    private String parseImaginary(String val) {
        if (val.contains("i")) {
            final String imaginary = val.substring(val.indexOf("i") + 1);
            return imaginary == "" ? "0" : imaginary;
        }
        return "0";
    }
}
