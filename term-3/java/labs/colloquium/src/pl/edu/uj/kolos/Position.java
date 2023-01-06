package pl.edu.uj.kolos;

public class Position {
    private double x;
    private double y;

    public Position(final double x, final double y) {
        this.x = x;
        this.y = y;
    }

    public double getXCoordinate() {
        return x;
    }

    public double getYCoordinate() {
        return y;
    }

    public void setXCoordinate(final double x) {
        this.x = x;
    }

    public void setYCoordinate(final double y) {
        this.y = y;
    }

    public double distance(final Position position) {
        return Math.sqrt(Math.pow(position.getXCoordinate() - x, 2) + Math.pow(position.getYCoordinate() - y, 2));
    }

    @Override
    public String toString() {
        return String.format("(%.2f,%.2f)", x, y);
    }
}
