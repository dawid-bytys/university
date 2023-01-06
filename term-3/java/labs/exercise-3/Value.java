public abstract class Value {
    protected Object value;

    public abstract Value create(String val);

    public abstract Value add(Value val);

    public abstract Value sub(Value val);

    public abstract Value mul(Value val);

    public abstract Value div(Value val);

    public abstract Value pow(Value val);

    public abstract boolean eq(Value val);

    public abstract boolean lte(Value val);

    public abstract boolean gte(Value val);

    public abstract boolean neq(Value val);

    public abstract boolean equals(Object other);

    public abstract int hashCode();

    public String toString() {
        return value.toString();
    }

    public void print() {
        System.out.println(toString());
    }
}