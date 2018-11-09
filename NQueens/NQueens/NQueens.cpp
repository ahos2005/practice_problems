// NQueens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
#define N 8

bool checkColumn(char mat[][N], int r, int c);
bool checkRightDiagonal(char mat[][N], int r, int c);
bool checkLeftDiagonal(char mat[][N], int r, int c);
bool isSafe(char mat[][N], int r, int c);
void nQueen(char mat[][N], int r, int c);
static int counter = 1;

int main()
{
    char mat[N][N];

    memset(mat, '-', sizeof mat);
    nQueen(mat, 0, 0);
    return 0;
}

bool checkColumn(char mat[][N], int r, int c) {
    for (int i = 0; i < r; i++) {
        if (mat[i][c] == 'Q') {
            return false;
        }
    }
    return true;
}

bool checkRightDiagonal(char mat[][N], int r, int c) {
    for (int i = r, j = c; i >= 0 && j >= 0 ; i--, j--) {
        if (mat[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

bool checkLeftDiagonal(char mat[][N], int r, int c) {
    for (int i = r, j = c; i >= 0 && j < N; i--, j++) {
        if (mat[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

bool isSafe(char mat[][N], int r, int c) {
    bool check = true;
    check = checkColumn(mat, r, c);
    if (check)
        check = checkLeftDiagonal(mat, r, c);
    if (check)
        check = checkRightDiagonal(mat, r, c);
    return check;
}

void nQueen(char mat[][N], int r, int c) {
    if (c == 0 && r == N) {
        cout << "Solution #" << counter++ << endl;;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(mat, r, i)) {
            mat[r][i] = 'Q';
            nQueen(mat, r + 1, 0);
            mat[r][i] = '-';
        }
    }
}