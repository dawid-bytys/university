/**
 * This class represents a complex number.
 * 
 * @author Dawid Bytys
 */
public class ComplexNumber {
    private double real;
    private double imaginary;

    /**
     * Constructor for ComplexNumber.
     * 
     * @param real      the real part of the complex number
     * @param imaginary the imaginary part of the complex number
     */
    public ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    /**
     * Returns the real part of the complex number.
     * 
     * @return the real part of the complex number
     */
    public final double getReal() {
        return this.real;
    }

    /**
     * Returns the imaginary part of the complex number.
     * 
     * @return the imaginary part of the complex number
     */
    public final double getImaginary() {
        return this.imaginary;
    }

    /**
     * Adds the given complex number to this complex number.
     */
    public final void add(double real, double imaginary) {
        this.real += real;
        this.imaginary += imaginary;
    }

    /**
     * Adds the given complex number to this complex number.
     */
    public final void add(ComplexNumber complexNumber) {
        this.real += complexNumber.getReal();
        this.imaginary += complexNumber.getImaginary();
    }

    /**
     * Subtracts the given complex number from this complex number.
     */
    public final void subtract(double real, double imaginary) {
        this.real -= real;
        this.imaginary -= imaginary;
    }

    /**
     * Subtracts the given complex number from this complex number.
     */
    public final void subtract(ComplexNumber complexNumber) {
        this.real -= complexNumber.getReal();
        this.imaginary -= complexNumber.getImaginary();
    }

    /**
     * Multiplies this complex number by the given complex number.
     */
    public final void multiply(double real, double imaginary) {
        double tempReal = this.real;
        this.real = (tempReal * real) - (this.imaginary * imaginary);
        this.imaginary = (tempReal * imaginary) + (this.imaginary * real);
    }

    /**
     * Multiplies this complex number by the given complex number.
     */
    public final void multiply(ComplexNumber complexNumber) {
        double tempReal = this.real;
        this.real = (tempReal * complexNumber.getReal()) - (this.imaginary * complexNumber.getImaginary());
        this.imaginary = (tempReal * complexNumber.getImaginary()) + (this.imaginary * complexNumber.getReal());
    }

    /**
     * Divides this complex number by the given complex number.
     */
    public final void divide(double real, double imaginary) {
        double tempReal = this.real;
        this.real = ((tempReal * real) + (this.imaginary * imaginary)) / ((real * real) + (imaginary * imaginary));
        this.imaginary = ((this.imaginary * real) - (tempReal * imaginary)) / ((real * real) + (imaginary * imaginary));
    }

    /**
     * Divides this complex number by the given complex number.
     */
    public final void divide(ComplexNumber complexNumber) {
        double tempReal = this.real;
        this.real = ((tempReal * complexNumber.getReal()) + (this.imaginary * complexNumber.getImaginary()))
                / ((complexNumber.getReal() * complexNumber.getReal())
                        + (complexNumber.getImaginary() * complexNumber.getImaginary()));
        this.imaginary = ((this.imaginary * complexNumber.getReal()) - (tempReal * complexNumber.getImaginary()))
                / ((complexNumber.getReal() * complexNumber.getReal())
                        + (complexNumber.getImaginary() * complexNumber.getImaginary()));
    }
}