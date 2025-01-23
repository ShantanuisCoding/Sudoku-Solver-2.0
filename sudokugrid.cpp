#include "SudokuGrid.h"

// Default constructor definition
SudokuGrid::SudokuGrid() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            grid[i][j] = 0;
        }
    }
}

// Constructor with initial grid definition
SudokuGrid::SudokuGrid(int initialGrid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = initialGrid[i][j];
        }
    }
}

// Set cell value
void SudokuGrid::setCellValue(int row, int col, int key) {
    grid[row][col] = key;
}

// Get cell value
int SudokuGrid::getCellValue(int row, int col) const {
    return grid[row][col];
}
