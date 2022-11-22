package pl.edu.uj.kolos;

abstract class Shape {
    protected String name;

    abstract double calculateSurfaceArea();

    abstract double calculatePerimeter();

    public abstract Shape scale(final double scalingFactor) throws ScalingFactorException;

    String getName() {
        return name;
    }
}