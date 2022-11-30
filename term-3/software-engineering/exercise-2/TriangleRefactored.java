package javaapplication1;

/**
 *
 * @author Dawid
 */
public class Triangle {
	public double A, H, area;

	/**
	 * @param A the side of the triangle
	 * @param H the height of the triangle
	 */
	public Triangle(final double A, final double H) {
		this.A = A;
		this.H = H;
		this.area = (A * H) / 2;
	}

	@Override
	public String toString() {
		return "Side: " + String.valueOf(this.A) + " Height: " + String.valueOf(this.H) + " Area: "
				+ String.valueOf(this.area);
	}
}
