#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Node {
    int num;
    struct Node *next;
}*LinkList, *pNode;
 
LinkList getEmptyList() {
    LinkList head = new Node;
    head->next = NULL;
    return head;
}
 
void addNode(LinkList head, pNode newNode) {
    newNode->next = head->next;
    head->next = newNode;
}
 
void deleteNum(LinkList head, int num) {
    pNode p = head,q;
    while (p->next) {
        if(p->next->num == num) {
            q = p->next;
            p->next = q->next;
            delete(q);
        }
        else p = p->next;
    }
}
 
void showList(LinkList head) {
    pNode p = head->next;
    while (p) {
        cout << p->num << endl; 
        p = p->next;
    }
    cout << endl; 
}
 
int main()
{
    pNode newNode;
    LinkList L = getEmptyList();
    for (int i = 0; i < 10; i++) {
        newNode = new Node;
        newNode->num = i;
        addNode(L, newNode);
    }
    showList(L);
    deleteNum(L,5);
    showList(L);
    return 0;
}

