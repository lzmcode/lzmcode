#include <cstdio>
#include <iostream>
using namespace std;

typedef struct Node {
    int num;
    struct Node *next;
}*CircleLinkList, *pNode;

CircleLinkList getEmptyList(int n) {
    CircleLinkList head = new Node;
    head->num = n; 
    head->next = head;
    return head;
}

void addNode(CircleLinkList head, pNode newNode) {
    newNode->next = head->next;
    head->next = newNode;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        int k = 1;
        while (true) {
            CircleLinkList CLL = getEmptyList(n);
            pNode newNode;
            for (int j=n-1; j>0; j--) {
                newNode = new Node;
                newNode->num = j;
                addNode(CLL, newNode);
            }
            pNode p = newNode, q;
            for (int i=0; i<n-1; i++) {
                q = p->next;
                p->next = q->next;
                delete(q);
                for (int j=0; j<k-1; j++)
                    p = p->next;
            }
            //cout << k << "£º" << p->num << endl;
            if (p->num != 3) k++;
            else break;
            delete(p);
        }
        cout << k << endl;
    } 
    
    return 0;
}
