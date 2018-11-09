// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

#define DEBUG 0

using namespace std;

int main()
{
    string str = "abcabcbb", input = "", maxString = "";
    unordered_map<string, int> strMap;
    unordered_map<string, int>::iterator mapIter;

    unordered_set<char> strSet;

    int walker = 0, max = 0;
    for (int i = 0; i < str.size(); i++) {
        walker = i;
        while (strSet.find(str[walker]) == strSet.end() && walker < str.size()) {
            strSet.insert(str[walker]);
            if (DEBUG) cout << "Adding " << str[walker] << " to the set." << endl;
            input.push_back(str[walker]);
            walker++;
        }
        if(DEBUG) cout << "Found a duplicate char, clearing set.\n";

        mapIter = strMap.find(input);
        if (mapIter != strMap.end()) {
            mapIter->second += 1;
            if (DEBUG) cout << "Found string: " << input << " in the map." << endl;
            if (max < mapIter->second) {
                maxString = input;
                max = mapIter->second;
            }
        }
        else {
            strMap.insert(make_pair(input, 1));
            if (DEBUG) cout << "Adding string: " << input << " to the map." << endl;
        }
        strSet.clear();
        input = "";

    }

    cout << "The longest substring is " << maxString << endl;

    return 0;
}

