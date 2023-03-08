package Localization;

import java.util.ResourceBundle;

public class Localization {
    public static void main(String[] args) {
        ResourceBundle bundle = ResourceBundle.getBundle("resources");

        for (String key : bundle.keySet()) {
            System.out.println(key + " = " + bundle.getString(key));
        }
    }
}