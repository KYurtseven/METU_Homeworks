#include "quiz1.hpp"
void printReverse(ListNode* p){
   if(!p)
      return;
   printReverse(p->next);
   cout << (p->val) << "->";
   //cout << endl;
   return;
}