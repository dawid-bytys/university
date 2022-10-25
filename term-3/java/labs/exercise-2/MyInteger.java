public class MyInteger extends Value {
    @Override
    public Value create(String val) {
        MyInteger v = new MyInteger();
        v.value = Integer.parseInt(val);
        return v;
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
}
