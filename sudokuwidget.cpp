#include "SudokuWidget.h"

SudokuWidget::SudokuWidget(QWidget* parent) : QWidget(parent), grid(nullptr), solver(nullptr) {
    QGridLayout* layout = new QGridLayout(this);

    int initialGrid[9][9] = {0};  // Start with an empty grid

    // Set up the grid of QLineEdits
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cells[i][j] = new QLineEdit(this);
            cells[i][j]->setMaxLength(1);
            cells[i][j]->setAlignment(Qt::AlignCenter);
            layout->addWidget(cells[i][j], i, j);
        }
    }

    QPushButton* solveButton = new QPushButton("Solve", this);
    layout->addWidget(solveButton, 9, 0, 1, 9);
    connect(solveButton, &QPushButton::clicked, this, &SudokuWidget::solveSudoku);

    setLayout(layout);
    setWindowTitle("Sudoku Solver");
}

void SudokuWidget::solveSudoku() {
    int inputGrid[9][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            QString cellText = cells[i][j]->text();
            if (!cellText.isEmpty()) {
                inputGrid[i][j] = cellText.toInt();
            }
        }
    }

    grid = new SudokuGrid(inputGrid);
    solver = new SudokuSolver(*grid);

    if (solver->solvePuzzle()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cells[i][j]->setText(QString::number(grid->getCellValue(i, j)));
            }
        }
        QMessageBox::information(this, "Sudoku Solver", "Puzzle solved!");
    } else {
        QMessageBox::warning(this, "Sudoku Solver", "No solution found.");
    }

    delete grid;
    delete solver;
}
