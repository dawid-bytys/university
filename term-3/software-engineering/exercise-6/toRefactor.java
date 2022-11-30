/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package z21;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Tomek
 */
public class Z21 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        List<item> towary=new ArrayList<item>();
        towary.add(new item("bułka",0.50,0.05));
        towary.add(new item("ananas",4.77,0.08));
        towary.add(new item("pepsi",3.21,0.22));
        for(item X : towary)
        {
            System.out.println(X.opis());
        }        
    }    
}

//Klasa przechowująca ceny produktów w sklepie internetowym
class item
{
    //nazwa produktu
    String N;
    //cena netto produktu
    double CN;
    //stawka vat
    double SV;    
    //
    //***********************
    //Konstruktor.
    //Przyjmuje jako argumenty nazwę produktu, cenę netto oraz stawkę VAT
    //*********************** 
    //
    public item(String iN, double iCN, double iSV)
    {
        N=iN;
        CN=iCN;
        SV=iSV;
    }
    
    //zwraca cenę brutto
    public double calcGV()
    {
        return CN*(1+SV);
    }    
    //zwraca wartość podatku VAT
    public double calcVV()
    {
        return CN*SV;
    }    
    
    //zwraca stringa z opisem obiektu :)
    public String opis()
    {
        return N+"  cena netto: "+CN+"  stawka VAT: "+SV+"   cena brutto: "+calcGV()+"  VAT: "+calcVV();
    }
          
}
