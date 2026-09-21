#include "grid.h"
#include <stdexcept> // Include for std::out_of_range exception

Grid::Grid(int width, int height) 
    // initialize cells_ as a 2d vector of size height_ x width_, all set to false (dead)
    : width_(width), height_(height), cells_(height, std::vector<bool>(width, false)) {}

bool Grid::getCell(int x, int y) const {// Method to get the state of a cell at (x, y)
    // Check if the coordinates are within bounds
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("Coordinates out of bounds");
    }
    return cells_[y][x]; // Return the state of the cell at (x, y)
}
void Grid::setCell(int x, int y, bool state) {// Set the state of the cell at (x, y)
    // Check if the coordinates are within bounds
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("Coordinates out of bounds");
    }
    cells_[y][x] = state; // Set the state of the cell at (x, y)
}
int Grid::getWidth() const {
    return width_; // Return the width of the grid
}
int Grid::getHeight() const {
    return height_; // Return the height of the grid
}
int Grid::countNeighbours(int x, int y) const {
    // Check if the coordinates are within bounds
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("Coordinates out of bounds");
    }

    int count = 0; // Initialize the count of alive neighbors
    // Iterate through the neighboring cells
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            // Skip the cell itself
            if (i == 0 && j == 0) continue;
            int neighborX = (x + i + width_) % width_;
            int neighborY = (y + j + height_) % height_;
            count += cells_[neighborY][neighborX];

        }
    }
    return count; // Return the total count of alive neighbors
}