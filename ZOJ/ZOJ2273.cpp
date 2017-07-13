#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Node{
    int num;
    struct Node *next;
}*LinkList, *pNode;

LinkList get_empty_list()
{
    LinkList head = (pNode)malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
}

void add_node(LinkList head, pNode newnode)
{
    newnode->next = head->next;
    head->next = newnode;
    return;
}

void show_list(LinkList head)
{
    pNode p = head, q;
    while (p->next != NULL)
    {
        printf("%d ", p->next->num);
        p = p->next;
    }
}

void del_node(LinkList head, bool *del, int *count)
{
    pNode p,q;
    if (*del)
    {
        p = head->next;
        *del = false;
    }else
    {
        p = head;
        *del = true;
    }
    
    int k = *count/2;
    for (int i=0; i<k; i++)
    {
        q = p->next;
        p->next = p->next->next;
        p = p->next;
        free(q);
        (*count)--;
    }
}
int main()
{
    freopen("out.txt","w",stdout);
    LinkList head = get_empty_list();
    int n,count=0;
    //while (scanf("%d",&n)!=EOF && n!=0)
    for (int n=1; n<10000; n++)
    {
        head = get_empty_list();
        for (int i=n; i>0; i--)
        {
            int k = i;
            while (k>0)
            {
                pNode newnode = (pNode)malloc(sizeof(struct Node));
                newnode->num = k % 10;
                add_node(head,newnode);
                k = k/10;
                count++;
            }
        }
        //show_list(head);
        bool del = true;
        while (count>1)
        {
            del_node(head,&del,&count);
            //show_list(head);
            //printf("\n");
        }
        show_list(head);
        count=0;
    }
    fclose(stdout);
    return 0;
}


























