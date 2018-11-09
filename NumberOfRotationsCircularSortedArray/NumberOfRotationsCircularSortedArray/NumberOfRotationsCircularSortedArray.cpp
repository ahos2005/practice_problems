// NumberOfRotationsCircularSortedArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int findRotationCount(int arr[], int n) {
    int result = -1;
    int low = 0, high = n-1;
    int mid = high + low / 2, next, prev;

    while (low <= high) {
        if (arr[low] < arr[high]) {
            return low;
        }
        mid = high + low / 2;
        next = (mid + 1 % n);
        prev = (mid - 1 % n);

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
            return mid;
        }
        else if (arr[mid] <= arr[high]) {
            high = mid - 1;
        }
        else if (arr[mid] >= arr[low]) {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int arr[6] = { 6, 8, 9, 10, 2, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int count = findRotationCount(arr, n);
    cout << "The array is rotated " << count << " times.";
    return 0;
}

