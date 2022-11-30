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
        List<Item> products = new ArrayList<Item>();
        products.add(new Item("bułka", 0.50, 0.05));
        products.add(new Item("ananas", 4.77, 0.08));
        products.add(new Item("pepsi", 3.21, 0.22));
        for (Item X : products) {
            System.out.println(X.description());
        }
    }
}

/**
 * The Item class represents a product in an online store.
 */
class Item {
    private String name;
    private double netPrice;
    private double vatRate;

    /**
     * @param name     the product name
     * @param netPrice the product net price
     * @param vatRate  the vat rate
     */
    public Item(final String name, final double netPrice, final double vatRate) {
        this.name = name;
        this.netPrice = netPrice;
        this.vatRate = vatRate;
    }

    /**
     * @return the gross price
     */
    public double getGrossPrice() {
        return netPrice * (1 + vatRate);
    }

    /**
     * @return the vat value
     */
    public double getVatValue() {
        return netPrice * vatRate;
    }

    /**
     * @return the product description
     */
    public String description() {
        return String.format("%s: %.2f PLN netto, %.2f VAT Rate, %.2f PLN brutto, %.2f PLN VAT", name, netPrice, vatRate,
                getGrossPrice(),
                getVatValue());
    }
}
