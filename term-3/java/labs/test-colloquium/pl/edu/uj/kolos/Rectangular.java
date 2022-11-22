package pl.edu.uj.kolos;

class Rectangular extends Shape {
    private double x;
    private double y;
    private double width;
    private double height;

    public Rectangular(final double x, final double y, final double width, final double height) {
        this.name = "Rect";
        this.x = x;
        this.y = x;
        this.width = width;
        this.height = height;
    }

    double calculateSurfaceArea() {
        return width * height;
    }

    double calculatePerimeter() {
        return 2 * (width + height);
    }

    public Shape scale(final double scalingFactor) throws ScalingFactorException {
        if (scalingFactor <= 0) {
            throw new ScalingFactorException("Scaling factor must be positive");
        }
        width *= scalingFactor;
        height *= scalingFactor;
        return this;
    }
}