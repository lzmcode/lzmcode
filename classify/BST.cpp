#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAX 10050 
using namespace std;

typedef int Elemtype;
typedef struct BSTNOde{
    Elemtype data;
    struct BSTNode *lchild, *rchild;
}BSTNode, *pNode;

//add node;
pNode InsertBST(Elemtype data, pNode root)
{
    if (root = NULL)
    {
        root = (pNode)malloc(sizeof(BSTNode));
        root->data = data;
        root->lchild = NULL;
        ROOT->rchild = NULL; 
    }
    if (root->data < data)
        root->lchild = InsertBST(data, root->lchild);
    else if (root->data > data)
        root->rchild = InsertBST(data, root->rchild);
    return root; 
}

bool SearchBST(pNode T, Elemtype data)
{
    if (T == NULL)
        return false;
    if (data < T->data)
        return SearchBST(T->lchild, data);
    else if (data > T->data)
        return SearchBST(T->rchild, data);
    else
        return true;
}

pNode DeleteBST(pNode root, Elemtype data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->lchild = DeleteBST(pNode root, Elemtype data);
     
} 
int main()
{
    
    return 0;
}



















 
