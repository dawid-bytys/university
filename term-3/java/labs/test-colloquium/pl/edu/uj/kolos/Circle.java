package pl.edu.uj.kolos;

class Circle extends Shape {
    private double radius;
    private double x;
    private double y;

    public Circle(final double x, final double y, final double radius) {
        this.name = "Circle";
        this.x = x;
        this.y = y;
    }

    double calculateSurfaceArea() {
        return Math.PI * Math.pow(radius, 2);
    }

    double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }

    public Shape scale(final double scalingFactor) throws ScalingFactorException {
        if (scalingFactor <= 0) {
            throw new ScalingFactorException("Scaling factor must be positive");
        }
        radius *= scalingFactor;
        return this;
    }
}