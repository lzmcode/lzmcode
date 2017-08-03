#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TREE_TYPE int
#define size 15

/**定义树形结构*/
typedef struct Tree
{
    TREE_TYPE value;
    struct Tree *left;
    struct Tree *right;
}Tree_node;

/**根节点作为全局静态变量*/
static Tree_node *root;

/**初始化树*/
void create_tree()
{
    root = NULL;
}

/**向树种插入数据*/
Tree_node* insert(Tree_node *node,TREE_TYPE value)
{
    if(node == NULL)
    {
        node = (Tree_node*)malloc(sizeof(Tree_node) * 1);
        node-> value = value;
        node -> left = NULL;
        node -> right = NULL;
        if(root == NULL) //如果为根节点
            root = node;
    }
    else
    {
        if(value < node->value) //比该节点值小，写向左子树
            node->left = insert(node->left,value);
        else //比该节点值大，写向右子树
            node->right = insert(node->right,value);
    }
    return node;
}

/**显示树中所有节点内容*/
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

/**根据值查找某一特定节点*/
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

/**找到某一值对应节点的父节点*/
Tree_node* find_parent(Tree_node *parent,TREE_TYPE value)
{
    Tree_node *result = NULL;
    if(parent != NULL)
    {
        if(value < parent->value && parent->left != NULL) //比父节点值小，访问左子树
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
        if(value > parent->value && parent->right != NULL) //比父节点值大，访问右子树
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
    Tree_node *parent = find_parent(root,value); //找到待删节点的父节点
    Tree_node *node = search(root,value); //找到待删节点
    if(node == NULL) //待删节点不存在
        printf("没有待删节点\n");
    else //待删节点存在
    {
        if(node->left == NULL && node->right == NULL) //如果待删节点是叶子节点
        {
           // assert(parent != NULL);
            if(parent == NULL) //如果是根节点
                root = NULL;
            else //其他节点
            {
                if(node == parent->left)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
        }
        else if(node->right == NULL) //如果待删节点只有左子树节点
        {
            if(parent == NULL) //如果是根节点
                root = node->left;
            else //其他节点
            {
                if(node == parent->left)
                    parent->left = node->left;
                else
                    parent->right = node->left;
            }
        }
        else if(node->left == NULL) //如果待删节点只有右子树节点
        {
            if(parent == NULL) //如果是根节点
                root = node->right;
            else //其他节点
            {
                if(node == parent->left)
                    parent->left = node->right;
                else
                    parent->right = node->right;
            }
        }
        else //如果带删节点左右子树节点都存在
        {
            Tree_node *new_node = node->right; //需要找到右子树的最左那个
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
                if(node == parent->left) //如果带删节点是父节点的左节点
                    parent->left = new_node;
                else //如果待删节点是父节点的右节点
                    parent->right = new_node;
            }
            if(new_node_parent != NULL)//将原来的右子树最左节点删掉
                new_node_parent->left = NULL;
        }
    }
}

int main()
{
    /**初始化*/
    create_tree();

    /**插入*/
    TREE_TYPE list[size] = {8,4,11,2,6,10,13,1,3,5,7,9,15,14,16};
    int i;
    for(i = 0; i < size; i++)
        insert(root,list[i]);

    /**显示全部*/
    show_all(root);
    putchar('\n');

    /**根据值查找某节点*/
    Tree_node *result = search(root,14);
    if(result != NULL)
        printf("To find %d,result is %d\n",14,result->value);
    else
        printf("Not find\n");

    /**根据值查找其父节点*/
    Tree_node *parent_result = find_parent(root,14);
    if(parent_result != NULL)
        printf("To find %d's parent,result is %d\n",14,parent_result->value);
    else
        printf("Cannot find %d's parent\n",14);

    /**删除*/
    Delete(14); //删除叶子节点
    show_all(root);
    putchar('\n');
    Delete(13); //删除只有右子树的节点
    show_all(root);
    putchar('\n');
    Delete(11); //删除只有左子树的节点
    show_all(root);
    putchar('\n');
    Delete(4); //删除左右子树都有的节点
    show_all(root);
    putchar('\n');

    return 0;
}
