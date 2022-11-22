package pl.edu.uj.kolos;

import java.util.Scanner;

class Main {
    public static void main(final String[] args) {
        BagOfShapes bagOfShapes = new BagOfShapes();

        try (Scanner scanner = new Scanner(System.in)) {
            while (true) {
                System.out.println("1. Dodaj kwadrat");
                System.out.println("2. Dodaj okrąg");
                System.out.println("3. Wyświetl pole powierzchni");
                System.out.println("4. Wyświetl obwód");
                System.out.println("5. Skaluj obiekty");
                System.out.println("6. Wyświetl nazwy figur");
                System.out.println("7. Usuwa figurę o podanym indeksie");
                System.out.println("8. Wyjście");

                final int option = scanner.nextInt();

                switch (option) {
                    case 1:
                        System.out.println("1.1. Podaj długość boku: ");
                        final double sideLength = scanner.nextDouble();
                        System.out.println("1.2. Podaj współrzędną x: ");
                        final double x = scanner.nextDouble();
                        System.out.println("1.3. Podaj współrzędną y: ");
                        final double y = scanner.nextDouble();
                        bagOfShapes.addShape(new Rectangular(x, y, sideLength, sideLength));
                        System.out.println("1.4. Dodano kwadrat: ");
                        break;
                    case 2:
                        System.out.println("2.1. Podaj x: ");
                        final double x1 = scanner.nextDouble();
                        System.out.println("2.2. Podaj y: ");
                        final double y1 = scanner.nextDouble();
                        System.out.println("2.3. Podaj promień: ");
                        final double radius = scanner.nextDouble();
                        bagOfShapes.addShape(new Circle(x1, y1, radius));
                        System.out.println("2.4. Dodano okrąg o promieniu: " + radius);
                        break;
                    case 3:
                        System.out.println("3.1. Pole powierzchni: " + bagOfShapes.calculateSurfaceArea());
                        break;
                    case 4:
                        System.out.println("4.1. Obwód: " + bagOfShapes.calculatePerimeter());
                        break;
                    case 5:
                        System.out.println("5.1. Podaj współczynnik skalowania: ");
                        final double scalingFactor = scanner.nextDouble();
                        bagOfShapes.scale(scalingFactor);
                        System.out.println("5.2. Przeskalowano wszystkie figury");
                        break;
                    case 6:
                        System.out.println("6.1. Nazwy figur: " + bagOfShapes);
                        break;
                    case 7:
                        System.out.println("7.1. Podaj indeks");
                        final int index = scanner.nextInt();
                        bagOfShapes.removeShape(index);
                        System.out.println("7.2. Usunięto figurę o indeksie: " + index);
                        break;
                    case 8:
                        scanner.close();
                        return;
                    default:
                        System.out.println("Nie ma takiej opcji");
                        break;
                }
            }
        } catch (final ScalingFactorException e) {
            System.out.println("Wystąpił błąd: " + e.getMessage());
        } catch (final Exception e) {
            System.out.println("Wystąpił błąd: " + e.getMessage());
        } finally {
            System.out.println("Koniec programu");
        }
    }
}