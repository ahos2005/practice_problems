// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node() { next = NULL; }
    Node(int incVal) { next = NULL; val = incVal; }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList() { head = NULL; tail = NULL; }
    LinkedList(int num) {
        int digit = 0;
        while (num > 0) {
            digit = num % 10;
            num /= 10;
            if (head == NULL) {
                head = new Node(digit);
                tail = head;
            }
            else {
                tail->next = new Node(digit);
                tail = tail->next;
            }
        }
    }

    void addNode(int num) {
        if (tail) {
            tail->next = new Node(num);
            tail = tail->next;
        }
        else {
            head = new Node(num);
            tail = head;
        }
    }

    void print() const{
        Node* iter = head;
        int count = 0, multiplier = 1;
        int sum = 0;
        while (iter) {
            sum += iter->val*multiplier;
            multiplier *= 10;
            //cout << iter->val << " ";
            count++;
            iter = iter->next;
        }
        cout << sum << endl;
        //cout << endl << "Printed " << count << " Nodes.\n";
    }

    ~LinkedList() {
        while (head) {
            tail = head;
            head = head->next;
            tail->next = NULL;
            delete tail;
        }

        head = NULL;
        tail = NULL;
    }
};

int main()
{
    int first = 100;
    int second = 1;
    LinkedList firstLL(first), secondLL(second);
    LinkedList result;
    Node* iter1 = firstLL.head;
    Node* iter2 = secondLL.head;

    int sum = 0;
    int carry = 0;
    while (iter1 && iter2) {
        sum = iter1->val + iter2->val + carry;
        result.addNode(sum % 10);
        carry = (sum >= 10) ? 1: 0;
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    Node* whatsLeft = NULL;
    if (iter1)
        whatsLeft = iter1;
    else if (iter2)
        whatsLeft = iter2;
    while (whatsLeft) {
        sum = whatsLeft->val + carry;
        result.addNode(sum % 10);
        carry = (sum >= 10) ? 1 : 0;
        whatsLeft = whatsLeft->next;
    }
    cout<< first << " + " << second << " = ";
    result.print();

    return 0;
}

