#ifndef SUDOKUWIDGET_H
#define SUDOKUWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include "SudokuGrid.h"
#include "SudokuSolver.h"

class SudokuWidget : public QWidget {
    Q_OBJECT

private:
    QLineEdit* cells[9][9];
    SudokuGrid* grid;
    SudokuSolver* solver;

public:
    SudokuWidget(QWidget* parent = nullptr);

private slots:
    void solveSudoku();
};

#endif
