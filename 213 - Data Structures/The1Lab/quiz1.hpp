#ifndef _QUIZ_1_H_
#define _QUIZ_1_H_

#include <iostream>
#include <cstddef>
#include <stdexcept>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// print a linked list
inline void print(ListNode* head){
    while(head){
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

// add digits 
inline int sum(int a, int b, int c=0){
    if ( a<0 || a>9 || b<0 || b>9 || c<0 || c>9 )
        throw invalid_argument("numbers must be single digits");
    return a+b+c;
}

// no need, but just in case
inline int inc(int i){
    return ++i;
}


// task function declarations

size_t size(ListNode* head);

void printReverse(ListNode* head);

ListNode* add(ListNode* num1, ListNode* num2);

#endif