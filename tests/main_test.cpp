#include "grid.h"
#include "update_system.h"
#include <gtest/gtest.h>



//gtest for grid class getWidth()
TEST(GridTest, GetWidth) {
    Grid grid(5, 5);
    EXPECT_EQ(grid.getWidth(), 5);
}
//gtest for grid class getHeight()
TEST(GridTest, GetHeight) {
    Grid grid(5, 5);
    EXPECT_EQ(grid.getHeight(), 5);
}
//gtest for grid class getCell() and setCell()
TEST(GridTest, GetSetCell) {
    Grid grid(5, 5);
    grid.setCell(2, 2, true);
    EXPECT_TRUE(grid.getCell(2, 2));
    grid.setCell(2, 2, false);
    EXPECT_FALSE(grid.getCell(2, 2));
}
//gtest for grid class countNeighbours()
TEST(GridTest, CountNeighbours) {
    Grid grid(5, 5);
    grid.setCell(1, 1, true);
    grid.setCell(1, 2, true);
    grid.setCell(2, 1, true);
    EXPECT_EQ(grid.countNeighbours(1, 1), 2);
    EXPECT_EQ(grid.countNeighbours(1, 2), 2);
    EXPECT_EQ(grid.countNeighbours(2, 1), 2);
    EXPECT_EQ(grid.countNeighbours(0, 0), 1);
}
//gtest for update_system class updateGrid()
TEST(UpdateSystemTest, UpdateGrid) {
    Grid grid(5, 5);
    grid.setCell(1, 1, true);
    grid.setCell(1, 2, true);
    grid.setCell(2, 1, true);
    Grid nextGrid(5, 5);
    update(grid, nextGrid);
    EXPECT_TRUE(nextGrid.getCell(1, 1));
    EXPECT_TRUE(nextGrid.getCell(1, 2));
    EXPECT_TRUE(nextGrid.getCell(2, 1));
    EXPECT_FALSE(nextGrid.getCell(0, 0));
    EXPECT_FALSE(nextGrid.getCell(0, 1));
    EXPECT_FALSE(nextGrid.getCell(0, 2));
    EXPECT_FALSE(nextGrid.getCell(1, 0));
    EXPECT_FALSE(nextGrid.getCell(1, 3));
    EXPECT_FALSE(nextGrid.getCell(2, 0));
    EXPECT_TRUE(nextGrid.getCell(2, 2));
    EXPECT_FALSE(nextGrid.getCell(3, 1));
}