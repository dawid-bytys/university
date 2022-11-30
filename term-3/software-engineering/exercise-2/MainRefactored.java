package javaapplication1;

/**
 *
 * @author Dawid
 */
public class Main {

	/**
	 * @param args the command line arguments
	 */

	public static void main(String[] args) {
		Triangle T1 = new Triangle(10, 12);
		Triangle T2 = new Triangle(4, 5);
		Triangle T3 = new Triangle(1, 3);
		Triangle T4 = new Triangle(7, 2);
		Triangle T5 = new Triangle(3, 6);

		Triangle[] triangles = { T1, T2, T3, T4, T5 };

		for (Triangle triangle : triangles) {
			System.out.println(triangle);
		}
	}

}
