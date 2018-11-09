//
//  LinkedList.hpp
//  ScratchPadCode
//
//  Created by Ahmed Elhosseiny on 4/19/18.
//  Copyright © 2018 Ahmed Elhosseiny. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <vector>
#include "Node.hpp"

using namespace std;

class LinkedList {
    //Implied Private
    void destroy();

public:
    Node* head;
    
    LinkedList();
    ~LinkedList();
    LinkedList(const std::vector<int>&);
    void reverse();
    void sort();
    void print();
    void insertElementSet(const vector<int>& incVector);
};

#endif /* LinkedList_hpp */
