public class MyDouble extends Value {
    @Override
    public Value create(String val) {
        MyDouble newDouble = new MyDouble();
        newDouble.value = Double.parseDouble(val);
        return newDouble;
    }

    @Override
    public Value add(Value val) {
        MyDouble result = new MyDouble();
        result.value = (Double) this.value + Double.valueOf(val.value.toString());
        return result;
    }

    @Override
    public Value sub(Value val) {
        MyDouble result = new MyDouble();
        result.value = (Double) this.value - Double.valueOf(val.value.toString());
        return result;
    }

    @Override
    public Value mul(Value val) {
        MyDouble result = new MyDouble();
        result.value = (Double) this.value * Double.valueOf(val.value.toString());
        return result;
    }

    @Override
    public Value div(Value val) {
        MyDouble result = new MyDouble();

        try {
            result.value = (Double) this.value / Double.valueOf(val.value.toString());
        } catch (ArithmeticException e) {
            System.out.println("Cannot divide by zero");
        }

        return result;
    }

    @Override
    public Value pow(Value val) {
        MyDouble result = new MyDouble();
        result.value = Math.pow((Double) this.value, Double.valueOf(val.value.toString()));
        return result;
    }

    @Override
    public boolean eq(Value val) {
        return (Double) this.value == Double.valueOf(val.value.toString());
    }

    @Override
    public boolean lte(Value val) {
        return (Double) this.value <= Double.valueOf(val.value.toString());
    }

    @Override
    public boolean gte(Value val) {
        return (Double) this.value >= Double.valueOf(val.value.toString());
    }

    @Override
    public boolean neq(Value val) {
        return (Double) this.value != Double.valueOf(val.value.toString());
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        if (other == null || getClass() != other.getClass()) {
            return false;
        }
        MyDouble myDouble = (MyDouble) other;
        return this.value == myDouble.value;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 18;
        result = prime * result + ((this.value == null) ? 0 : this.value.hashCode());
        return result;
    }
}
