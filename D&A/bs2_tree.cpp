#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TREE_TYPE int
#define size 15

/**�������νṹ*/
typedef struct Tree
{
    TREE_TYPE value;
    struct Tree *left;
    struct Tree *right;
}Tree_node;

/**���ڵ���Ϊȫ�־�̬����*/
static Tree_node *root;

/**��ʼ����*/
void create_tree()
{
    root = NULL;
}

/**�����ֲ�������*/
Tree_node* insert(Tree_node *node,TREE_TYPE value)
{
    if(node == NULL)
    {
        node = (Tree_node*)malloc(sizeof(Tree_node) * 1);
        node-> value = value;
        node -> left = NULL;
        node -> right = NULL;
        if(root == NULL) //���Ϊ���ڵ�
            root = node;
    }
    else
    {
        if(value < node->value) //�ȸýڵ�ֵС��д��������
            node->left = insert(node->left,value);
        else //�ȸýڵ�ֵ��д��������
            node->right = insert(node->right,value);
    }
    return node;
}

/**��ʾ�������нڵ�����*/
void show_all(Tree_node *node)
{
    if(node != NULL)
    {
        if(node->left != NULL)
            show_all(node->left);
        printf("%d ",node->value);
        if(node->right != NULL);
            show_all(node->right);
    }
}

/**����ֵ����ĳһ�ض��ڵ�*/
Tree_node* search(Tree_node *node,TREE_TYPE value)
{
    Tree_node *result = NULL;
    if(node != NULL)
    {
        if(value == node->value)
            result = node;
        else if(value < node->value)
            result = search(node->left,value);
        else
            result = search(node->right,value);
    }
    return result;
}

/**�ҵ�ĳһֵ��Ӧ�ڵ�ĸ��ڵ�*/
Tree_node* find_parent(Tree_node *parent,TREE_TYPE value)
{
    Tree_node *result = NULL;
    if(parent != NULL)
    {
        if(value < parent->value && parent->left != NULL) //�ȸ��ڵ�ֵС������������
        {
            if(value == parent->left->value)
                result = parent;
            else
            {
                result = find_parent(parent->left,value);
                if(result == NULL)
                    result = find_parent(parent->right,value);
            }
        }
        if(value > parent->value && parent->right != NULL) //�ȸ��ڵ�ֵ�󣬷���������
        {
            if(value == parent->right->value)
                result = parent;
            else
            {
                result = find_parent(parent->left,value);
                if(result == NULL)
                    result = find_parent(parent->right,value);
            }
        }
    }
    return result;
}

void Delete(TREE_TYPE value)
{
    Tree_node *parent = find_parent(root,value); //�ҵ���ɾ�ڵ�ĸ��ڵ�
    Tree_node *node = search(root,value); //�ҵ���ɾ�ڵ�
    if(node == NULL) //��ɾ�ڵ㲻����
        printf("û�д�ɾ�ڵ�\n");
    else //��ɾ�ڵ����
    {
        if(node->left == NULL && node->right == NULL) //�����ɾ�ڵ���Ҷ�ӽڵ�
        {
           // assert(parent != NULL);
            if(parent == NULL) //����Ǹ��ڵ�
                root = NULL;
            else //�����ڵ�
            {
                if(node == parent->left)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
        }
        else if(node->right == NULL) //�����ɾ�ڵ�ֻ���������ڵ�
        {
            if(parent == NULL) //����Ǹ��ڵ�
                root = node->left;
            else //�����ڵ�
            {
                if(node == parent->left)
                    parent->left = node->left;
                else
                    parent->right = node->left;
            }
        }
        else if(node->left == NULL) //�����ɾ�ڵ�ֻ���������ڵ�
        {
            if(parent == NULL) //����Ǹ��ڵ�
                root = node->right;
            else //�����ڵ�
            {
                if(node == parent->left)
                    parent->left = node->right;
                else
                    parent->right = node->right;
            }
        }
        else //�����ɾ�ڵ����������ڵ㶼����
        {
            Tree_node *new_node = node->right; //��Ҫ�ҵ��������������Ǹ�
            Tree_node *new_node_parent = NULL;
            while(new_node->left != NULL)
            {
                new_node_parent = new_node;
                new_node = new_node->left;
            }
            if(new_node != node->left)
                new_node->left = node->left;
            if(new_node != node->right)
                new_node->right = node->right;
            if(parent == NULL)
                root = new_node;
            else
            {
                if(node == parent->left) //�����ɾ�ڵ��Ǹ��ڵ����ڵ�
                    parent->left = new_node;
                else //�����ɾ�ڵ��Ǹ��ڵ���ҽڵ�
                    parent->right = new_node;
            }
            if(new_node_parent != NULL)//��ԭ��������������ڵ�ɾ��
                new_node_parent->left = NULL;
        }
    }
}

int main()
{
    /**��ʼ��*/
    create_tree();

    /**����*/
    TREE_TYPE list[size] = {8,4,11,2,6,10,13,1,3,5,7,9,15,14,16};
    int i;
    for(i = 0; i < size; i++)
        insert(root,list[i]);

    /**��ʾȫ��*/
    show_all(root);
    putchar('\n');

    /**����ֵ����ĳ�ڵ�*/
    Tree_node *result = search(root,14);
    if(result != NULL)
        printf("To find %d,result is %d\n",14,result->value);
    else
        printf("Not find\n");

    /**����ֵ�����丸�ڵ�*/
    Tree_node *parent_result = find_parent(root,14);
    if(parent_result != NULL)
        printf("To find %d's parent,result is %d\n",14,parent_result->value);
    else
        printf("Cannot find %d's parent\n",14);

    /**ɾ��*/
    Delete(14); //ɾ��Ҷ�ӽڵ�
    show_all(root);
    putchar('\n');
    Delete(13); //ɾ��ֻ���������Ľڵ�
    show_all(root);
    putchar('\n');
    Delete(11); //ɾ��ֻ���������Ľڵ�
    show_all(root);
    putchar('\n');
    Delete(4); //ɾ�������������еĽڵ�
    show_all(root);
    putchar('\n');

    return 0;
}
