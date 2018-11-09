// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

#define DEBUG 1

using namespace std;

int main()
{
    string str = "abcabcbb", input = "", maxString = "";
    unordered_map<string, int>::iterator mapIter;

    unordered_set<char> strSet;

    int walker = 0, count = 0, max = 0;
    for (int i = 0; i < str.size(); i++) {
        walker = i;
        while (strSet.find(str[walker]) == strSet.end() && walker < str.size()) {
            strSet.insert(str[walker]);
            if (DEBUG) cout << "Adding " << str[walker] << " to the set." << endl;
            input.push_back(str[walker]);
            walker++;
            count++;
            if (max < count){
                max = count;
                maxString = input;
            }
        }
        if(DEBUG) cout << "Found a duplicate char, clearing set.\n";

        strSet.clear();
        input = "";
        count = 0;

    }

    cout << "The longest substring is " << maxString << endl;

    return 0;
}

