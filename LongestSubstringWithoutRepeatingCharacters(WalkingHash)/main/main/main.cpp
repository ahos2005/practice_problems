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
    unordered_map<char, int>::iterator mapIter;
    unordered_map<char, int> strMap;

    int walker = 0, count = 0, max = 0;
    for (int i = 0; i < str.size(); i++) {
        walker = i;
        while (strMap.find(str[walker]) == strMap.end() && walker < str.size()) {
            strMap.insert(make_pair(str[walker], walker));
            if (DEBUG) cout << "Adding " << str[walker] << " to the set." << endl;
            input.push_back(str[walker]);
            walker++;
            count++;
            if (max < count){
                max = count;
                maxString = input;
            }
        }
        mapIter = strMap.find(str[walker]);
        if (mapIter != strMap.end()) {
            i = mapIter->second;
            if (DEBUG) cout << "Shifted it to index " << i << endl;
        }
        if(DEBUG) cout << "Found a duplicate char, clearing set.\n";

        strMap.clear();
        input = "";
        count = 0;

    }

    cout << "The longest substring is " << maxString << endl;

    return 0;
}

