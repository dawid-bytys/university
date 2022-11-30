package com.company;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) {
        Rectangle rect = new Rectangle(10, 5);
        Triangle triangle = new Triangle(4, 3, 5);
        Circle circle = new Circle(3);

        Shape[] shapes = { rect, triangle, circle };
        for (int i = 0; i < shapes.length; ++i) {
            Shape temp = shapes[i];
            switch (temp.getShapeType()) {
                case 0:
                    System.out.println("Area of the rectangle: " + temp.getArea());
                    break;
                case 1:
                    System.out.println("Area of the triangle: " + temp.getArea());
                    break;
                case 2:
                    System.out.println("Area of the circle: " + temp.getArea());
                    break;
            }
        }
    }
}

interface Shape {
    /**
     * @return the area of the shape
     */
    double getArea();

    /**
     * @return the shape type
     */
    int getShapeType();
}

class Rectangle implements Shape {
    private double width;
    private double height;

    /**
     * @param width  the width of the rectangle
     * @param height the height of the rectangle
     */
    public Rectangle(final double width, final double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double getArea() {
        return width * height;
    }

    @Override
    public int getShapeType() {
        return 0;
    }
}

class Triangle implements Shape {
    private double firstSide;
    private double secondSide;
    private double thirdSide;

    /**
     * @param firstSide  the length of the first side
     * @param secondSide the length of the second side
     * @param thirdSide  the length of the third side
     */
    public Triangle(final double firstSide, final double secondSide, final double thirdSide) {
        this.firstSide = firstSide;
        this.secondSide = secondSide;
        this.thirdSide = thirdSide;
    }

    @Override
    public double getArea() {
        final double halfOfCircuit = 0.5 * (firstSide + secondSide + thirdSide);
        return Math.sqrt(halfOfCircuit * (halfOfCircuit - firstSide) * (halfOfCircuit - secondSide)
                * (halfOfCircuit - thirdSide));
    }

    @Override
    public int getShapeType() {
        return 1;
    }
}

class Circle implements Shape {
    private double radius;

    /**
     * @param radius the radius length
     */
    public Circle(final double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public int getShapeType() {
        return 2;
    }
}