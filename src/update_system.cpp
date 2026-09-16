#include "update_system.h"

void update(Grid& grid) {
    int width = grid.getWidth();
    int height = grid.getHeight();
    Grid newGrid(width, height); // Create a new grid to store the updated state

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int aliveNeighbours = grid.countNeighbours(x, y);
            bool currentState = grid.getCell(x, y);

            // Apply the rules of Conway's Game of Life
            if (currentState) {
                // Rule 1 or 3: Any live cell with two or three live neighbors survives.
                newGrid.setCell(x, y, aliveNeighbours == 2 || aliveNeighbours == 3);
            } else {
                // Rule 4: Any dead cell with exactly three live neighbors becomes a live cell.
                newGrid.setCell(x, y, aliveNeighbours == 3);
            }
        }
    }

    // Update the original grid with the new state
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid.setCell(x, y, newGrid.getCell(x, y));
        }
    }
}