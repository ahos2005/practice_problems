//
//  Node.hpp
//  ScratchPadCode
//
//  Created by Ahmed Elhosseiny on 4/20/18.
//  Copyright © 2018 Ahmed Elhosseiny. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node {
public:
    int data;
    Node* next;
    Node(const int val);
};

#endif /* Node_hpp */
