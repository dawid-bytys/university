public class MyInteger extends Value {
    @Override
    public Value create(String val) {
        MyInteger newInteger = new MyInteger();
        newInteger.value = Integer.parseInt(val);
        return newInteger;
    }

    @Override
    public Value add(Value val) {
        MyInteger result = new MyInteger();

        if (val.value instanceof Integer) {
            result.value = (Integer) this.value + (Integer) val.value;
        } else {
            result.value = (Integer) this.value + Double.valueOf(val.value.toString()).intValue();
        }

        return result;
    }

    @Override
    public Value sub(Value val) {
        MyInteger result = new MyInteger();

        if (val.value instanceof Integer) {
            result.value = (Integer) this.value - (Integer) val.value;
        } else {
            result.value = (Integer) this.value - Double.valueOf(val.value.toString()).intValue();
        }

        return result;
    }

    @Override
    public Value mul(Value val) {
        MyInteger result = new MyInteger();

        if (val.value instanceof Integer) {
            result.value = (Integer) this.value * (Integer) val.value;
        } else {
            result.value = (Integer) this.value * Double.valueOf(val.value.toString()).intValue();
        }

        return result;
    }

    @Override
    public Value div(Value val) {
        MyInteger result = new MyInteger();

        try {
            if (val.value instanceof Integer) {
                result.value = (Integer) this.value / (Integer) val.value;
            } else {
                result.value = (Integer) this.value / Double.valueOf(val.value.toString()).intValue();
            }
        } catch (ArithmeticException e) {
            System.out.println("Cannot divide by zero");
        }

        return result;
    }

    @Override
    public Value pow(Value val) {
        MyInteger result = new MyInteger();

        if (val.value instanceof Integer) {
            result.value = Math.pow((Integer) this.value, (Integer) val.value);
        } else {
            result.value = Math.pow((Integer) this.value, Double.valueOf(val.value.toString()).intValue());
        }

        return result;
    }

    @Override
    public boolean eq(Value val) {
        if (val.value instanceof Integer) {
            return (Integer) this.value == (Integer) val.value;
        }
        return (Integer) this.value == Double.valueOf(val.value.toString()).intValue();
    }

    @Override
    public boolean lte(Value val) {
        if (val.value instanceof Integer) {
            return (Integer) this.value <= (Integer) val.value;
        }
        return (Integer) this.value <= Double.valueOf(val.value.toString()).intValue();
    }

    @Override
    public boolean gte(Value val) {
        if (val.value instanceof Integer) {
            return (Integer) this.value >= (Integer) val.value;
        }
        return (Integer) this.value >= Double.valueOf(val.value.toString()).intValue();
    }

    @Override
    public boolean neq(Value val) {
        if (val.value instanceof Integer) {
            return (Integer) this.value != (Integer) val.value;
        }
        return (Integer) this.value != Double.valueOf(val.value.toString()).intValue();
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        if (other == null || getClass() != other.getClass()) {
            return false;
        }
        MyInteger otherInteger = (MyInteger) other;
        return this.value == otherInteger.value;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 17;
        result = prime * result + ((this.value == null) ? 0 : this.value.hashCode());
        return result;
    }
}
