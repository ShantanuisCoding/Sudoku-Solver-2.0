#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include "SudokuGrid.h"

class SudokuSolver {
private:
    SudokuGrid &grid;

    bool isSafe(int row, int col, int num);
    bool solve();

public:
    SudokuSolver(SudokuGrid &grid) : grid(grid) {}
    bool solvePuzzle();
};

#endif
