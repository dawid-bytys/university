package pl.edu.uj.kolos;

interface Movable {
    void moveTo(Position position, World world) throws OutsideTheWorldException;

    void moveBack();
}