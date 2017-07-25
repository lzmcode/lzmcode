#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 7   //������������鳤�� 

/* ��������� ����*/
typedef int Elemtype;
typedef struct BSTNode
{
    Elemtype data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*PNode;

//���ҽ��,���д��ڽ��ֵΪdata�Ľ�㷵��true�����򷵻�false 
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

 //�����в���ڵ㣬���˽ڵ��ڲ�����������룬���������򲻲��� 
 PNode insertBST(Elemtype data,PNode root)
 {
    if(root == NULL)
    {
        root = (PNode)malloc(sizeof(BSTNode));
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        printf("%d��������\n",data);
        return root;
     }
     if(data < root->data)
        root->lchild = insertBST(data,root->lchild);
     else if(data > root->data)
        root->rchild = insertBST(data,root->rchild);
     else
        printf("%d�������У������ٴβ���!!!\n",data);
     return root;
 }

//���Ҷ���������������С�ڵ�ֵ;�Ӹ��ڵ㿪ʼ��������ӣ�
//ֻҪ��������Ӿ�һֱ���ң��յ������С��Ԫ�أ�����Ϊ�Ҷ��Ӳ����յ� 
PNode findMin(PNode root)
{
    if(root == NULL)
        return NULL;
    else if(root->lchild == NULL)
        return root;
    return findMin(root->lchild);     //�ݹ���� 
 } 

 PNode findMax(PNode root)
 {
    if(root == NULL)                   //�ǵݹ���� 
        while(root->rchild != NULL)
            root = root->rchild;
    return root;
 }

 //ɾ��һ����㣺�����Ҷ�����ֱ��ɾ������������һ�����ӣ�
 //��ֱ���øý�㸸�ڵ����Ӵ˽�㺢�ӽ�㣬ɾ���˽ڵ㣻���������������ӽ��
 //����������������С���ݴ���ý������ݲ��ݹ��ɾ���Ǹ���С��㣬��Ϊ��������
 //��С��㲻�������������˵ڶ���ɾ���Ƚ�����
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

//�������:�������������������Եõ�ԭ�ؼ����������� 
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
    PNode root = NULL; //������������ڵ� 
    for(i=0;i<N;i++)    //������������� 
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
