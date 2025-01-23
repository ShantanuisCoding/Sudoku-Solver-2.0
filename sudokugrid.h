#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

class SudokuGrid {
private:
    int grid[9][9];

public:
    SudokuGrid();  // Default constructor declaration
    SudokuGrid(int initialGrid[9][9]);  // Constructor declaration

    void setCellValue(int row, int col, int key);
    int getCellValue(int row, int col) const;
};

#endif // SUDOKUGRID_H
