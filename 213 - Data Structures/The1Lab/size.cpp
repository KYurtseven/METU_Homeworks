#include "quiz1.hpp"

size_t size(ListNode* head){
    int i=0;
    ListNode *p = head;
    while(p){
        i++;
        p = p->next;
    }
    return i;
}