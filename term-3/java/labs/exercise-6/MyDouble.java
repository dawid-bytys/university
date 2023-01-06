public class MyDouble extends Value {
    @Override
    public Value create(String val) {
        MyDouble result = new MyDouble();
        result.value = Double.parseDouble(val);
        return result;
    }

    @Override
    public Value add(Value val) {
        MyDouble result = new MyDouble();
        result.value = (Double) this.value + Double.valueOf(val.value.toString());
        return result;
    }
}
