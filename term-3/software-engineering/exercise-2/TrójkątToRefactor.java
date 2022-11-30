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
public class Trójkąt
{
	public double A, H, pole;
	public Trójkąt(double iA, double iH)
	{
		A = iA;
		H = iH;
		pole = 0.5 * A * H;
	}
}
