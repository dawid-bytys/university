package pl.edu.uj.kolos;

import java.util.ArrayList;
import java.util.List;

public class Robot implements Movable {
    private List<Position> positions = new ArrayList<Position>();

    public Robot() {
        this.positions.add(new Position(0, 0));
    }

    @Override
    public void moveTo(final Position position, final World world) throws OutsideTheWorldException {
        if (position.getXCoordinate() < 0 || position.getXCoordinate() > world.getWidth()
                || position.getYCoordinate() < 0 || position.getYCoordinate() > world.getHeight()) {
            throw new OutsideTheWorldException("Robot is outside the world");
        }
        positions.add(position);
    }

    @Override
    public void moveBack() {
        if (positions.size() > 1) {
            positions.remove(positions.size() - 1);
        }
    }

    public Position getPosition() {
        return positions.get(positions.size() - 1);
    }

    public Position getPreviousPosition() {
        return positions.get(positions.size() - 2);
    }
}
