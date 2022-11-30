/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author Tomek
 */
public class MainFile {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        
                Trójkąt T1 = new Trójkąt(10, 12);
		Trójkąt T2 = new Trójkąt(4, 5);
		Trójkąt T3 = new Trójkąt(1, 3);
		Trójkąt T4 = new Trójkąt(7, 2);
		Trójkąt T5 = new Trójkąt(3, 6);

		System.out.println("podstawa: " + String.valueOf(T1.A) + " wysokość: " + String.valueOf(T1.H) + " pole: " + String.valueOf(T1.pole));
		System.out.println("podstawa: " + String.valueOf(T2.A) + " wysokość: " + String.valueOf(T2.H) + " pole: " + String.valueOf(T2.pole));
		System.out.println("podstawa: " + String.valueOf(T3.A) + " wysokość: " + String.valueOf(T3.H) + " pole: " + String.valueOf(T3.pole));
		System.out.println("podstawa: " + String.valueOf(T4.A) + " wysokość: " + String.valueOf(T4.H) + " pole: " + String.valueOf(T4.pole));
		System.out.println("podstawa: " + String.valueOf(T5.A) + " wysokość: " + String.valueOf(T5.H) + " pole: " + String.valueOf(T5.pole));
	    }
    
}



