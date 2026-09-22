#include "update_system.h"

void update(Grid& current, Grid& next) {
    int width = current.getWidth();
    int height = current.getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int aliveNeighbours = current.countNeighbours(x, y);
            bool currentState = current.getCell(x, y);

            // Apply the rules of Conway's Game of Life
            if (currentState) {
                // Rule 1 or 3: Any live cell with two or three live neighbors survives.
                next.setCell(x, y, aliveNeighbours == 2 || aliveNeighbours == 3);
            } else {
                // Rule 4: Any dead cell with exactly three live neighbors becomes a live cell.
                next.setCell(x, y, aliveNeighbours == 3);
            }
        }
    }
}