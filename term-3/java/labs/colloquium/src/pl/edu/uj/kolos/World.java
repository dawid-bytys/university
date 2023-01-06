package pl.edu.uj.kolos;

public class World {
    private final double width;
    private final double height;
    private final Treasure treasure;

    public World() throws BoundaryException {
        this(100, 100);
    }

    public World(final double width, final double height) throws BoundaryException {
        if (width <= 0 || height <= 0) {
            throw new BoundaryException("World size must be positive");
        }
        this.width = width;
        this.height = height;
        this.treasure = new Treasure(Math.round(Math.random() * width), Math.round(Math.random() * height));
    }

    public double getWidth() {
        return width;
    }

    public double getHeight() {
        return height;
    }

    public Treasure getTreasure() {
        return treasure;
    }
}
