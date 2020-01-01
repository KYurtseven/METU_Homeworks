#include "quiz1.hpp"

int main(int argc, char const *argv[]){
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    a.next = &b;
    b.next = &c;

    ListNode* d = new ListNode(9);
    ListNode* e = new ListNode(8);
    ListNode* f = new ListNode(7);
    ListNode* g = new ListNode(6);
    ListNode* h = new ListNode(5);

    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;

    print(&a);
    print(&c);
    print(d);
    print(f);

    int x = 5, y = 9, z = 1;
    cout << sum(x,y) << endl;
    cout << sum(x,y,z) << endl;

    cout << inc(y) << endl;
    cout << inc(z) << endl;

    return 0;
}