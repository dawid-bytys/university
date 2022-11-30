import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        SuperStack stack = new SuperStack();
        stack.push("hello");
        stack.push(124);
        stack.push("world");
        stack.push(4335);

        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());

        System.out.println("Next");

        /*
         * X.push("hello");
         * X.push(124);
         * X.push("world");
         * X.push(4335);
         * 
         * X.clear(); /// Ale my takiej możliwości nie chcemy!!!
         * System.out.println(X.pop2());
         * System.out.println(X.pop2());
         * System.out.println(X.pop2());
         * System.out.println(X.pop2());
         * // Proszę to poprawić
         */
    }
}

class SuperStack {
    private ArrayList<Object> container = new ArrayList<Object>();

    /**
     * Adds an element to the top of the stack.
     * 
     * @param item the item to be pushed
     */
    public void push(Object item) {
        container.add(item);
    }

    /**
     * Removes the second item from the top of the stack and returns it.
     * 
     * @return the last item
     */
    public Object pop() {
        if (container.size() < 2) {
            return null;
        }
        return container.remove(container.size() - 2);
    }
}