// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> const &v, int l, int r, const int e);

int main()
{
    vector<int> a = { 0, 2, 3, 4, 10, 40, 44 };
    const int e = 110;
    cout << "Answer:" << binarySearch(a, 0, a.size()-1,e) << endl;
    return 0;
}

int binarySearch(vector<int> const &v, int l, int r, const int e){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (v[mid] == e) {
            return mid;
        }
        else if (v[mid] > e) {
            return binarySearch(v, l, mid - l, e);
        }
        else {
            return binarySearch(v, mid + l, r, e);
        }
    }
    else {
        return -1;
    }
    return 0;
}