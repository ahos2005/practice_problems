// RobotPath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int numberOfPaths(const int m, const int n);

int main()
{
    const int m = 3;
    const int n = 3;
    cout << "Recursive Solution:\nNumber of Paths is: " << numberOfPaths(m, n) << endl;;
    return 0;
}

int numberOfPaths(int m, int n) {
    if (m == 1 || n == 1) {
        return 1;
    }

    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
}

int numPaths(const int rows, const int cols) {
    int cache[rows][cols];
    for (unsigned row = 0; row < rows; row++) {
        for (unsigned col = 0; col < cols; col++) {
            if (row == 0 || col == 0) {
                cache[row][col] = 1;
            }
            else {
                cache[row][col] = cache[row - 1][col] + cache[row][col - 1];
            }
        }
    }
    return cache[rows - 1][cols - 1];
}

long binomial(int n, int k) {
    if (k > n - k)
        k = n - k;

    long b = 1;
    for (int i = 1, m = n; i <= k; i++, m--) {
        b = b * m / i;
    }
    return b;
}

long numpaths(int rows, int cols) {
    return binomial(rows + cols - 2, rows - 1);
}