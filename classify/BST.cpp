#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 7   //插入查找树数组长度 

/* 二叉查找树 操作*/
typedef int Elemtype;
typedef struct BSTNode
{
    Elemtype data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*PNode;

//查找结点,树中存在结点值为data的结点返回true，否则返回false 
bool SearchBST(PNode T,Elemtype data)
{
    if(T == NULL)
        return false;
    if(data < T->data)
        return SearchBST(T->lchild,data);
    else if(data > T->data)
        return SearchBST(T->rchild,data);
    else 
        return true;    
 } 

 //向树中插入节点，若此节点在不在树中则插入，已在树中则不插入 
 PNode insertBST(Elemtype data,PNode root)
 {
    if(root == NULL)
    {
        root = (PNode)malloc(sizeof(BSTNode));
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        printf("%d插入树中\n",data);
        return root;
     }
     if(data < root->data)
        root->lchild = insertBST(data,root->lchild);
     else if(data > root->data)
        root->rchild = insertBST(data,root->rchild);
     else
        printf("%d已在树中，不能再次插入!!!\n",data);
     return root;
 }

//查找二叉查找树中最大、最小节点值;从根节点开始查找左儿子，
//只要存在左儿子就一直查找，终点就是最小的元素，最大的为右儿子查找终点 
PNode findMin(PNode root)
{
    if(root == NULL)
        return NULL;
    else if(root->lchild == NULL)
        return root;
    return findMin(root->lchild);     //递归查找 
 } 

 PNode findMax(PNode root)
 {
    if(root == NULL)                   //非递归查找 
        while(root->rchild != NULL)
            root = root->rchild;
    return root;
 }

 //删除一个结点：如果是叶结点则直接删除；如果结点有一个孩子，
 //则直接用该结点父节点连接此结点孩子结点，删除此节点；如果结点有两个孩子结点
 //则用其右子树的最小数据代替该结点的数据并递归的删除那个最小结点，因为右子树的
 //最小结点不可能有左儿子因此第二次删除比较容易
 PNode deleteBST(PNode root,Elemtype data)
 {
    if(root == NULL)
        return root;

    if(data < root->data)
        root->lchild = deleteBST(root->lchild,data);
    else if(data > root->data)
        root->rchild = deleteBST(root->rchild,data);
    else if(root->lchild != NULL && root->rchild != NULL)
    {
        root->data = findMin(root->rchild)->data;
        root->rchild = deleteBST(root->rchild,root->data);
     }
     else
        root = (root->lchild != NULL) ? root->lchild : root->rchild;
    return root;
  } 

//中序输出:中序遍历二叉查找树可以得到原关键字有序序列 
void print(PNode root)
{
    if(root!=NULL)
    {
        print(root->lchild);
        printf("%d ",root->data);
        print(root->rchild);
    }
 } 

int main(int argc, char *argv[]) {
    Elemtype data[N] = {45,24,53,45,12,24,90};
    int i;
    PNode root = NULL; //二叉查找树根节点 
    for(i=0;i<N;i++)    //创建二叉查找树 
    {
        root = insertBST(data[i],root);
    }
    print(root);
    printf("\n");
    root = insertBST(55,root);
    print(root);
    printf("\n");
    root = deleteBST(root,24);
    print(root);
    printf("\n");
    return 0;
}
