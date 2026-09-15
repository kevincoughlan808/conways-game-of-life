#include <vector>

class Grid {
    public:
        Grid(int width, int height);// Constructor to initialize the grid with specified width and height 
        bool getCell(int x, int y) const; // Method to get the state of a cell at (x, y)
        void setCell(int x, int y, bool state); // Method to set the state of a cell at (x, y)
        int countNeighbours(int x, int y) const; // Method to count the number of alive neighbors for a cell at (x, y)
        int getWidth() const; // Method to get the width of the grid
        int getHeight() const; // Method to get the height of the grid
    private:
        int width_;
        int height_;
        std::vector<std::vector<bool>> cells_; // 2D vector to store the state of each cell (alive or dead)
};