#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef struct Node{
    int num;
    struct Node *next;
}*LinkList, *pNode;

LinkList GetEmptyList()
{
    LinkList head = (pNode)malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
}

void AddNode(LinkList head,pNode newnode)
{
    newnode->next = head->next;
    head->next = newnode;
    return;
}

void ShowList(LinkList head)
{
    pNode p=head,q;
    while (p->next != NULL)
    {
         printf("%d ",p->next->num);
         q = p->next;
         p = p->next;
         free(q);
    }
    return;
}

int main()
{
    LinkList head=GetEmptyList();
    for (int i=0; i<10; i++)
    {
         pNode newnode = (pNode)malloc(sizeof(struct Node));
         newnode->num = i;         
         AddNode(head,newnode);
    }
    ShowList(head);
    return 0;
}

