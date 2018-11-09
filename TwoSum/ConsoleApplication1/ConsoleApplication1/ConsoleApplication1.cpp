// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    unordered_map<int, int> result;
    unordered_map<int, int>::iterator iter;
    for (int i = 0; i < nums.size(); i++) {
        iter = result.find(nums[i]);
        if (iter != result.end()) {
            cout << "Sum found at index " << iter->second << " and index " << i << endl;
            break;
        }
        else {
            //cout << "Inserting" << endl;
            result.insert(make_pair(target - nums[i], i));
        }
    }
    return 0;
}

