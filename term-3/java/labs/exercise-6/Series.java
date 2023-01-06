import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;

public class Series {
    private ArrayList<Value> values = new ArrayList<>();
    private String name;
    private Class<? extends Value> type;

    public Series(Class<? extends Value> type, String name) {
        this.name = name;
        this.type = type;
    }

    public void addValue(final String val) {
        try {
            values.add(type.getDeclaredConstructor().newInstance().create(val));
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
    }

    public Series iloc(final int startIndex, final int endIndex) {
        Series result = new Series(type, name);
        for (int i = startIndex; i < endIndex && i < this.values.size(); ++i) {
            result.addValue(this.values.get(i).toString());
        }
        return result;
    }

    public String getName() {
        return name;
    }

    public Integer getSize() {
        return values.size();
    }

    public Value getValue(final int index) {
        return values.get(index);
    }

    public Class<? extends Value> getType() {
        return type;
    }

    public void setValue(final int index, final Value val) {
        values.set(index, val);
    }
}