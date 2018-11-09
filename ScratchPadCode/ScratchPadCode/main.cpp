//
//  main.cpp
//  ScratchPadCode
//
//  Created by Ahmed Elhosseiny on 4/19/18.
//  Copyright © 2018 Ahmed Elhosseiny. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> v;
    
    for(unsigned int i = 0; i < 6; i++){
        v.push_back(i);
    }
    LinkedList ll(v);
    
    ll.print();
    ll.reverse();
    ll.print();
    ll.insertElementSet(v);
    v.push_back(7);
    ll.insertElementSet(v);
    ll.print();
    
    
    return 0;
}
