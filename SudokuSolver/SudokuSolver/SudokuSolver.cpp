// SudokuSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_set>

using namespace std;
void solveSudoku(int puzzle[][9]);
void printSudoku(int puzzle[][9]);

int main()
{
    const int puzzleSize = 9;
    int puzzle[][puzzleSize] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    printSudoku(puzzle);
    solveSudoku(puzzle);
    cout << endl << endl;
    printSudoku(puzzle);
    return 0;
}

void printSudoku(int puzzle[][9]) {
    cout << "-------------------" << endl;
    for (int j = 0; j < 9; j++) {
        cout << "|";
        for (int i = 0; i < 9; i++) {
            cout << puzzle[j][i] << "|";
        }
        cout << endl<< "-------------------" << endl;

    }
}

void solveSudoku(int puzzle[][9]) {
    unordered_set<pair<int, int>> mySet;
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
            if (puzzle[j][i] == 0) {
                mySet.insert(make_pair(i, j));
            }
        }
    }
    for (int k = 1; k < 10; k++) {

    }
}

