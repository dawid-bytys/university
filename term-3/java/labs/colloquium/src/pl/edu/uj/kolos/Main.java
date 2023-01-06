package pl.edu.uj.kolos;

import java.util.Scanner;

public class Main {
    static boolean isDouble(final String s) {
        try {
            Double.parseDouble(s);
            return true;
        } catch (final NumberFormatException e) {
            return false;
        }
    }

    // interpretuję czytanie argumentów poprzez flagi -w i -h
    // jeśli nie podano flagi -w lub -h, to domyślnie ustawiamy szerokość i wysokość
    // na 100
    static void validateArguments(final String[] args) throws IllegalArgumentException {
        if (args.length != 0 && args.length != 4) {
            throw new IllegalArgumentException("Wrong number of arguments");
        }
        if (args.length == 4) {
            if (!args[0].equals("-w") || !args[2].equals("-h")) {
                throw new IllegalArgumentException("Wrong arguments");
            }
            if (!isDouble(args[1]) || !isDouble(args[3])) {
                throw new IllegalArgumentException("Wrong arguments");
            }
        }
    }

    public static void main(final String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            validateArguments(args);
            World world;
            if (args.length == 0) {
                world = new World();
            } else {
                world = new World(Double.parseDouble(args[1]), Double.parseDouble(args[3]));
            }
            Robot robot = new Robot();
            final Treasure treasure = world.getTreasure();

            while (true) {
                System.out.println("1. moveLeft");
                System.out.println("2. moveRight");
                System.out.println("3. moveUp");
                System.out.println("4. moveDown");
                System.out.println("5. moveBack");
                System.out.println("6. Print current position");
                System.out.println("7. Exit");
                System.out.print("Enter your choice: ");

                final int option = scanner.nextInt();
                switch (option) {
                    case 1:
                        robot.moveTo(new Position(robot.getPosition().getXCoordinate() - 1,
                                robot.getPosition().getYCoordinate()), world);
                        if (robot.getPosition().equals(treasure)) {
                            System.out.println("You found the treasure!");
                            return;
                        }
                        if (robot.getPosition().distance(treasure) < robot.getPreviousPosition().distance(treasure)) {
                            System.out.println("Hot!");
                        } else {
                            System.out.println("Cold!");
                        }
                        break;
                    case 2:
                        robot.moveTo(new Position(robot.getPosition().getXCoordinate() + 1,
                                robot.getPosition().getYCoordinate()), world);
                        if (robot.getPosition().equals(treasure)) {
                            System.out.println("You found the treasure!");
                            return;
                        }
                        if (robot.getPosition().distance(treasure) < robot.getPreviousPosition().distance(treasure)) {
                            System.out.println("Hot!");
                        } else {
                            System.out.println("Cold!");
                        }
                        break;
                    case 3:
                        robot.moveTo(new Position(robot.getPosition().getXCoordinate(),
                                robot.getPosition().getYCoordinate() + 1), world);
                        if (robot.getPosition().equals(treasure)) {
                            System.out.println("You found the treasure!");
                            return;
                        }
                        if (robot.getPosition().distance(treasure) < robot.getPreviousPosition().distance(treasure)) {
                            System.out.println("Hot!");
                        } else {
                            System.out.println("Cold!");
                        }
                        break;
                    case 4:
                        robot.moveTo(new Position(robot.getPosition().getXCoordinate(),
                                robot.getPosition().getYCoordinate() - 1), world);
                        if (robot.getPosition().equals(treasure)) {
                            System.out.println("You found the treasure!");
                            return;
                        }
                        if (robot.getPosition().distance(treasure) < robot.getPreviousPosition().distance(treasure)) {
                            System.out.println("Hot!");
                        } else {
                            System.out.println("Cold!");
                        }
                        break;
                    case 5:
                        robot.moveBack();
                        if (robot.getPosition().equals(treasure)) {
                            System.out.println("You found the treasure!");
                            return;
                        }
                        if (robot.getPosition().distance(treasure) < robot.getPreviousPosition().distance(treasure)) {
                            System.out.println("Hot!");
                        } else {
                            System.out.println("Cold!");
                        }
                        break;
                    case 6:
                        System.out.println(robot.getPosition());
                        break;
                    case 7:
                        return;
                    default:
                        System.out.println("Invalid choice");
                }
            }
        } catch (final IllegalArgumentException e) {
            System.out.println(e.getMessage());
            System.exit(1);
        } catch (final BoundaryException e) {
            System.out.println(e.getMessage());
            System.exit(2);
        } catch (final OutsideTheWorldException e) {
            System.out.println(e.getMessage());
            System.exit(3);
        }
    }
}
