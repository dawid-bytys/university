abstract class Value {
    protected Object value;

    public abstract Value create(String v);

    public abstract Value add(Value v);

    @Override
    public String toString() {
        return value.toString();
    }

    public void print() {
        System.out.print(toString());
    }
}