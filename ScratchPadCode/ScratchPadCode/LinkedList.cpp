//
//  LinkedList.cpp
//  ScratchPadCode
//
//  Created by Ahmed Elhosseiny on 4/19/18.
//  Copyright © 2018 Ahmed Elhosseiny. All rights reserved.
//

using namespace std;

#include <iostream>
#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    destroy();
}

LinkedList::LinkedList(const vector<int>& incVector)
{
    head = NULL;
    insertElementSet(incVector);
}

void LinkedList::insertElementSet(const vector<int>& incVector)
{
    Node* iter = NULL;
    for(unsigned long i = 0, _i = incVector.size(); i < _i; i++){
        if(head == NULL){
            head = new Node(incVector[i]);
            iter = head;
        } else {
            if(head && !iter){
                iter = head;
                while(iter->next){
                    iter = iter->next;
                }
            }
            
            iter->next = new Node(incVector[i]);
            iter = iter->next;
        }
    }
}

void LinkedList::reverse()
{
    Node* iter = head;
    Node* iter2 = head;
    Node* iter3 = NULL;
    while(iter2){
        iter2 = iter2->next;
        iter->next = iter3;
        iter3 = iter;
        iter = iter2;
    }
    head = iter3;
}

void LinkedList::sort(){
    
}

void LinkedList::destroy()
{
    Node* iter = head;
    Node* iter2 = head;
    while(iter){
        iter = iter->next;
        iter2->next = NULL;
        delete iter2;
        iter2 = iter;
    }
    head = NULL;
}

void LinkedList::print()
{
    Node* iter = head;
    while(iter != NULL){
        cout<<iter->data<<" ";
        iter = iter->next;
    }
    cout<<endl;
}
