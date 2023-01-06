public class ImaginaryInt extends MyInteger {
    protected MyInteger imaginary;

    @Override
    public Value create(String val) {
        ImaginaryInt newImaginaryInt = new ImaginaryInt();
        newImaginaryInt.value = new MyInteger().create(parseReal(val));
        newImaginaryInt.imaginary = (MyInteger) new MyInteger().create(parseImaginary(val));
        return newImaginaryInt;
    }

    @Override
    public Value add(Value val) {
        ImaginaryInt result = new ImaginaryInt();

        result.value = ((MyInteger) this.value).add(val);
        if (val instanceof ImaginaryInt) {
            result.imaginary = (MyInteger) this.imaginary.add((MyInteger) ((ImaginaryInt) val).imaginary);
        } else if (val instanceof ImaginaryDouble) {
            result.imaginary = (MyInteger) this.imaginary.add((MyDouble) ((ImaginaryDouble) val).imaginary);
        } else {
            result.imaginary = this.imaginary;
        }

        return result;
    }

    @Override
    public Value sub(Value val) {
        ImaginaryInt result = new ImaginaryInt();

        result.value = ((MyInteger) this.value).sub(val);
        if (val instanceof ImaginaryInt) {
            result.imaginary = (MyInteger) this.imaginary.sub((MyInteger) ((ImaginaryInt) val).imaginary);
        } else if (val instanceof ImaginaryDouble) {
            result.imaginary = (MyInteger) this.imaginary.sub((MyDouble) ((ImaginaryDouble) val).imaginary);
        } else {
            result.imaginary = this.imaginary;
        }

        return result;
    }

    @Override
    public Value mul(Value val) {
        ImaginaryInt result = new ImaginaryInt();

        if (val instanceof ImaginaryInt) {
            MyInteger a = (MyInteger) ((MyInteger) this.value).mul((MyInteger) ((ImaginaryInt) val).value);
            MyInteger b = (MyInteger) ((MyInteger) this.imaginary).mul((MyInteger) ((ImaginaryInt) val).imaginary);
            MyInteger c = (MyInteger) ((MyInteger) this.value).mul((MyInteger) ((ImaginaryInt) val).imaginary);
            MyInteger d = (MyInteger) ((MyInteger) this.imaginary).mul((MyInteger) ((ImaginaryInt) val).value);
            result.value = (MyInteger) a.sub(b);
            result.imaginary = (MyInteger) c.add(d);
        } else if (val instanceof ImaginaryDouble) {
            MyInteger a = (MyInteger) ((MyInteger) this.value).mul((MyDouble) ((ImaginaryDouble) val).value);
            MyInteger b = (MyInteger) ((MyInteger) this.imaginary).mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyInteger c = (MyInteger) ((MyInteger) this.value).mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyInteger d = (MyInteger) ((MyInteger) this.imaginary).mul((MyDouble) ((ImaginaryDouble) val).value);
            result.value = (MyInteger) a.sub(b);
            result.imaginary = (MyInteger) c.add(d);
        } else {
            result.value = ((MyInteger) this.value).mul(val);
            result.imaginary = (MyInteger) ((MyInteger) this.imaginary).mul(val);
        }

        return result;
    }

    @Override
    public Value div(Value val) {
        ImaginaryInt result = new ImaginaryInt();

        if (val instanceof ImaginaryInt) {
            MyInteger a = (MyInteger) ((MyInteger) this.value).mul((MyInteger) ((ImaginaryInt) val).value);
            MyInteger b = (MyInteger) ((MyInteger) this.imaginary).mul((MyInteger) ((ImaginaryInt) val).imaginary);
            MyInteger c = (MyInteger) ((MyInteger) this.value).mul((MyInteger) ((ImaginaryInt) val).imaginary);
            MyInteger d = (MyInteger) ((MyInteger) this.imaginary).mul((MyInteger) ((ImaginaryInt) val).value);
            MyInteger e = (MyInteger) ((MyInteger) ((ImaginaryInt) val).value)
                    .mul((MyInteger) ((ImaginaryInt) val).value);
            MyInteger f = (MyInteger) ((MyInteger) ((ImaginaryInt) val).imaginary)
                    .mul((MyInteger) ((ImaginaryInt) val).imaginary);
            MyInteger g = (MyInteger) e.add(f);
            result.value = (MyInteger) a.add(b).div(g);
            result.imaginary = (MyInteger) c.sub(d).div(g);
        } else if (val instanceof ImaginaryDouble) {
            MyInteger a = (MyInteger) ((MyInteger) this.value).mul((MyDouble) ((ImaginaryDouble) val).value);
            MyInteger b = (MyInteger) ((MyInteger) this.imaginary).mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyInteger c = (MyInteger) ((MyInteger) this.value).mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyInteger d = (MyInteger) ((MyInteger) this.imaginary).mul((MyDouble) ((ImaginaryDouble) val).value);
            MyInteger e = (MyInteger) ((MyInteger) ((ImaginaryDouble) val).value)
                    .mul((MyDouble) ((ImaginaryDouble) val).value);
            MyInteger f = (MyInteger) ((MyDouble) ((ImaginaryDouble) val).imaginary)
                    .mul((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyInteger g = (MyInteger) e.add(f);
            result.value = (MyInteger) a.add(b).div(g);
            result.imaginary = (MyInteger) c.sub(d).div(g);
        } else {
            result.value = ((MyInteger) this.value).div(val);
            result.imaginary = (MyInteger) ((MyInteger) this.imaginary).div(val);
        }

        return result;
    }

    @Override
    public Value pow(Value val) {
        ImaginaryInt result = new ImaginaryInt();

        if (val instanceof ImaginaryInt) {
            MyInteger a = (MyInteger) ((MyInteger) this.value).pow((MyInteger) ((ImaginaryInt) val).value);
            MyInteger b = (MyInteger) ((MyInteger) this.imaginary).pow((MyInteger) ((ImaginaryInt) val).imaginary);
            MyInteger c = (MyInteger) ((MyInteger) this.value).pow((MyInteger) ((ImaginaryInt) val).imaginary);
            MyInteger d = (MyInteger) ((MyInteger) this.imaginary).pow((MyInteger) ((ImaginaryInt) val).value);
            MyInteger e = (MyInteger) ((MyInteger) ((ImaginaryInt) val).value)
                    .pow((MyInteger) ((ImaginaryInt) val).value);
            MyInteger f = (MyInteger) ((MyInteger) ((ImaginaryInt) val).imaginary)
                    .pow((MyInteger) ((ImaginaryInt) val).imaginary);
            MyInteger g = (MyInteger) e.add(f);
            result.value = (MyInteger) a.sub(b).div(g);
            result.imaginary = (MyInteger) c.add(d).div(g);
        } else if (val instanceof ImaginaryDouble) {
            MyInteger a = (MyInteger) ((MyInteger) this.value).pow((MyDouble) ((ImaginaryDouble) val).value);
            MyInteger b = (MyInteger) ((MyInteger) this.imaginary).pow((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyInteger c = (MyInteger) ((MyInteger) this.value).pow((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyInteger d = (MyInteger) ((MyInteger) this.imaginary).pow((MyDouble) ((ImaginaryDouble) val).value);
            MyInteger e = (MyInteger) ((MyInteger) ((ImaginaryDouble) val).value)
                    .pow((MyDouble) ((ImaginaryDouble) val).value);
            MyInteger f = (MyInteger) ((MyDouble) ((ImaginaryDouble) val).imaginary)
                    .pow((MyDouble) ((ImaginaryDouble) val).imaginary);
            MyInteger g = (MyInteger) e.add(f);
            result.value = (MyInteger) a.sub(b).div(g);
            result.imaginary = (MyInteger) c.add(d).div(g);
        } else {
            result.value = ((MyInteger) this.value).pow(val);
            result.imaginary = (MyInteger) ((MyInteger) this.imaginary).pow(val);
        }

        return result;
    }

    @Override
    public boolean eq(Value val) {
        if (val instanceof ImaginaryInt || val instanceof ImaginaryDouble) {
            return ((MyInteger) this.value).eq((MyInteger) ((ImaginaryInt) val).value)
                    && ((MyInteger) this.imaginary).eq((MyInteger) ((ImaginaryInt) val).imaginary);
        }
        return ((MyInteger) this.value).eq(val) && ((MyInteger) this.imaginary).eq(new MyInteger().create("0"));
    }

    @Override
    public boolean lte(Value val) {
        if (val instanceof ImaginaryInt || val instanceof ImaginaryDouble) {
            return ((MyInteger) this.value).lte((MyInteger) ((ImaginaryInt) val).value)
                    && ((MyInteger) this.imaginary).lte((MyInteger) ((ImaginaryInt) val).imaginary);
        }
        return ((MyInteger) this.value).lte(val) && ((MyInteger) this.imaginary).lte(new MyInteger().create("0"));
    }

    @Override
    public boolean gte(Value val) {
        if (val instanceof ImaginaryInt || val instanceof ImaginaryDouble) {
            return ((MyInteger) this.value).gte((MyInteger) ((ImaginaryInt) val).value)
                    && ((MyInteger) this.imaginary).gte((MyInteger) ((ImaginaryInt) val).imaginary);
        }
        return ((MyInteger) this.value).gte(val) && ((MyInteger) this.imaginary).gte(new MyInteger().create("0"));
    }

    @Override
    public boolean neq(Value val) {
        return !eq(val);
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        if (other == null || getClass() != other.getClass()) {
            return false;
        }
        ImaginaryInt imaginaryInt = (ImaginaryInt) other;
        return this.value.equals(imaginaryInt.value) && this.imaginary.equals(imaginaryInt.imaginary);
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 19;
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
