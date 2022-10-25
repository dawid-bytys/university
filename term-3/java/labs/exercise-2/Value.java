public abstract class Value {
    protected Object value;

    public abstract Value create(String val);

    public abstract Value add(Value val);

    public String toString() {
        return value.toString();
    }

    public void print() {
        System.out.println(toString());
    }
}