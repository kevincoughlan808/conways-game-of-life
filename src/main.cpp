#include "grid.h"
#include "update_system.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

const int GRID_WIDTH = 80;
const int GRID_HEIGHT = 60;
const int CELL_SIZE = 10;   // 80*10=800, 60*10=600


int main() {
    // create window with sf::RenderWindow
    sf::RenderWindow window(sf::VideoMode({GRID_WIDTH * CELL_SIZE, GRID_HEIGHT * CELL_SIZE}), "Conway's Game of Life");
    window.setFramerateLimit(60); // Set the frame rate limit to 60 FPS
    Grid grid(GRID_WIDTH, GRID_HEIGHT); // Create a grid of specified width and height
    Grid nextGrid(GRID_WIDTH, GRID_HEIGHT); // Create a second grid for the next state
    //seed some live cells in the grid
    grid.setCell(1, 0, true);
    grid.setCell(2, 1, true);
    grid.setCell(0, 2, true);
    grid.setCell(1, 2, true);
    grid.setCell(2, 2, true);
    bool paused = false; // Variable to track whether the simulation is paused
    sf::Clock clock; // Create a clock to manage the update timing
    bool wasClicked = false; // Variable to track whether the mouse button was clicked in the previous frame

    double runningTotalTime = 0.0; // Variable to accumulate the total elapsed time for updates
    int updateCounter = 0; // Variable to count the number of updates performed

    //Game loop
    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                if (keyEvent->code == sf::Keyboard::Key::Space) {
                    paused = !paused;
                }
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (!wasClicked) {
                wasClicked = true;
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int x = mousePos.x / CELL_SIZE;
                int y = mousePos.y / CELL_SIZE;
                if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
                    grid.setCell(x, y, !grid.getCell(x, y));
                }
            }

        } else {
            wasClicked = false; // reset the flag if the button is not pressed
        }
        //Update logic
        if (!paused && clock.getElapsedTime().asSeconds() >= 0.5f) { // Update every 0.5 seconds
            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); // Record the start time of the update
            update(grid, nextGrid);
            std::swap(grid, nextGrid); // Swap the current grid with the next grid after updating
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); // Record the end time of the update
            std::chrono::duration<double> elapsed = end - start; // Calculate the elapsed time
            runningTotalTime += elapsed.count();
            updateCounter++;
            double averageTime = runningTotalTime / updateCounter;
            std::cout << "Average elapsed time: " << averageTime << " seconds" << std::endl; // Print the average elapsed time to the console

            clock.restart(); // Restart the clock after updating
        }
        window.clear(sf::Color::Black); // Clear the window with black color
        //Render Loop
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            for (int x = 0; x < GRID_WIDTH; ++x) {
                if (grid.getCell(x, y)) { // If the cell is alive
                    sf::RectangleShape cellShape(sf::Vector2f(CELL_SIZE, CELL_SIZE)); // Create a rectangle shape for the cell
                    cellShape.setPosition({(float)(x * CELL_SIZE), (float)(y * CELL_SIZE)}); // Set the position of the cell shape based on its grid coordinates
                    cellShape.setFillColor(sf::Color::White); // Set the fill color to white for alive cells
                    window.draw(cellShape); // Draw the cell shape on the window
                }
            }
        }
        window.display(); // Display the rendered frame

    }
}