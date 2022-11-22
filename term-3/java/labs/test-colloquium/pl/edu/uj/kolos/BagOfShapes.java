package pl.edu.uj.kolos;

import java.util.ArrayList;
import java.util.List;

class BagOfShapes extends Shape {
    private List<Shape> shapes = new ArrayList<>();

    public BagOfShapes() {
        this.name = "BagOfShapes";
    }

    double calculateSurfaceArea() {
        double surfaceArea = 0;
        for (Shape shape : shapes) {
            surfaceArea += shape.calculateSurfaceArea();
        }
        return surfaceArea;
    }

    double calculatePerimeter() {
        double perimeter = 0;
        for (Shape shape : shapes) {
            perimeter += shape.calculatePerimeter();
        }
        return perimeter;
    }

    public Shape scale(final double scalingFactor) throws ScalingFactorException {
        if (scalingFactor <= 0) {
            throw new ScalingFactorException("Scaling factor must be positive");
        }
        for (Shape shape : shapes) {
            shape.scale(scalingFactor);
        }
        return this;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Shape shape : shapes) {
            sb.append(shape.getName() + " ");
        }
        return sb.toString();
    }

    void addShape(final Shape shape) {
        shapes.add(shape);
    }

    void removeShape(final int index) {
        shapes.remove(index);
    }
}