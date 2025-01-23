#include "SudokuSolver.h"

bool SudokuSolver::isSafe(int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (grid.getCellValue(row, x) == num || grid.getCellValue(x, col) == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid.getCellValue(i + startRow, j + startCol) == num)
                return false;

    return true;
}

bool SudokuSolver::solve() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid.getCellValue(row, col) == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(row, col, num)) {
                        grid.setCellValue(row, col, num);
                        if (solve())
                            return true;
                        grid.setCellValue(row, col, 0);
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver::solvePuzzle() {
    return solve();
}
