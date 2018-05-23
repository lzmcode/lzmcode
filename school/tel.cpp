#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <iostream>
using namespace std;

typedef struct Node {   //结点类型定义--单链表（数据域、指针域）
    string no,name,sex,number,address;
    struct Node *next;
} *LinkList, *pNode, ListNode;

void printLine() {
    cout << "========================" << endl;
}

void print(pNode p) {
    cout << p->no << "\t"
         << p->name << "\t"
         << p->sex << "\t"
         << p->number << "\t"
         << p->address << endl;
}

LinkList createList() {           
    LinkList head = (pNode)new Node;
    if (head == NULL) cout << "分配失败..." << endl; 
    head->next = NULL;
    return head;            //返回链表头指针
}

bool InsertNode(LinkList LL){
    pNode p = (pNode)new Node;
    cin >> p->no;
    if (p->no == "0") {
        return false;
    } else {
        printf("编号\t姓名\t性别\t电话\t地址\n");
        cin >> p->name >> p->sex >> p->number >> p->address;
        p->next = LL->next;
        LL->next = p;
    }
    return true;
}

void BuildList(LinkList LL) {
    printLine();
    printf("编号\t姓名\t性别\t电话\t地址\n");
    printLine();
    while (InsertNode(LL));
}

ListNode* ListFind(LinkList LL)
{
    // 有序通讯录链表上的查找
    printf("==================\n");
    printf("  1. 按编号查询     \n");
    printf("  2. 按姓名查询     \n");
    printf("请选择：");
    int k;
    cin>>k;
    if(k==1){
        string no;
        cout<<"请输入编号："; 
        cin>>no;
        while(LL->next){
            if(LL->next->no==no)
                break;
            LL=LL->next;    
        }
    }
    if(k==2){
        string name;
        cout<<"请输入姓名：";
        cin>>name;
        while(LL->next){
            if(LL->next->name==name)
                break;
            LL=LL->next;    
        }
    }
    return LL;
}

void DelNode(LinkList LL)
{
    pNode p = (pNode)new Node;
    pNode q = (pNode)new Node;
    p=ListFind(LL);   //调用查找函数
    if (p->next==NULL) {
        printf("没有查到要删除的通讯者!\n");
        return;
    }
    char c;
    printf("真的要删除该结点吗？（y/n）:");
    cin>>c;
    if(c=='y'){
        q=p->next;
        p->next=q->next;
        free(q);    
    } else if (c=='n') {
        printf("放弃删除！\n");
        return;
    }
    printf("通讯者已被删除！\n");
}

void PrintList(LinkList LL) //输出链表
{                                                         
    printf("编号\t姓名\t性别\t电话\t地址\n");
    while(LL){
        print(LL);
        LL=LL->next;
    }
}

int main()
{
    //良好的菜单引导程序功能
    //如1：建立；2：添加；3：查询；4删除；5：输出；0：退出；
    printLine();
    printf("    通讯录管理系统\n");
    printLine();
    printf("    1.通讯链表的建立\n");
    printf("    2.通讯者结点的插入\n");
    printf("    3.通讯者结点的查询\n");
    printf("    4.通讯者结点的删除\n");
    printf("    5.通讯录链表的输出\n");
    printf("    0.退出管理系统\n");
    printLine(); 
    LinkList LL = createList();
    while (true) {
        cout << "   请选择 0-5: "; 
        int k; cin >> k;
        if (k == 0) break;
        switch(k){
            case 1: { BuildList(LL); break; }
            case 2: { 
                printf("编号\t姓名\t性别\t电话\t地址\n");
                InsertNode(LL); 
                break; }
            case 3: { 
                pNode p = ListFind(LL);
                if (p->next) {
                    printf("编号\t姓名\t性别\t电话\t地址\n");
                    print(p->next);
                } else {
                    cout << "不存在" << endl; 
                }
                break; }
            case 4: { DelNode(LL); break; }
            case 5: { PrintList(LL); break; }
            default:
                break;
        }
        printLine();
    }
    delete(LL);
    return 0;
}

