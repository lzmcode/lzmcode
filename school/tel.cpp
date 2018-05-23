#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <iostream>
using namespace std;

typedef struct Node {   //������Ͷ���--������������ָ����
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
    if (head == NULL) cout << "����ʧ��..." << endl; 
    head->next = NULL;
    return head;            //��������ͷָ��
}

bool InsertNode(LinkList LL){
    pNode p = (pNode)new Node;
    cin >> p->no;
    if (p->no == "0") {
        return false;
    } else {
        printf("���\t����\t�Ա�\t�绰\t��ַ\n");
        cin >> p->name >> p->sex >> p->number >> p->address;
        p->next = LL->next;
        LL->next = p;
    }
    return true;
}

void BuildList(LinkList LL) {
    printLine();
    printf("���\t����\t�Ա�\t�绰\t��ַ\n");
    printLine();
    while (InsertNode(LL));
}

ListNode* ListFind(LinkList LL)
{
    // ����ͨѶ¼�����ϵĲ���
    printf("==================\n");
    printf("  1. ����Ų�ѯ     \n");
    printf("  2. ��������ѯ     \n");
    printf("��ѡ��");
    int k;
    cin>>k;
    if(k==1){
        string no;
        cout<<"�������ţ�"; 
        cin>>no;
        while(LL->next){
            if(LL->next->no==no)
                break;
            LL=LL->next;    
        }
    }
    if(k==2){
        string name;
        cout<<"������������";
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
    p=ListFind(LL);   //���ò��Һ���
    if (p->next==NULL) {
        printf("û�в鵽Ҫɾ����ͨѶ��!\n");
        return;
    }
    char c;
    printf("���Ҫɾ���ý���𣿣�y/n��:");
    cin>>c;
    if(c=='y'){
        q=p->next;
        p->next=q->next;
        free(q);    
    } else if (c=='n') {
        printf("����ɾ����\n");
        return;
    }
    printf("ͨѶ���ѱ�ɾ����\n");
}

void PrintList(LinkList LL) //�������
{                                                         
    printf("���\t����\t�Ա�\t�绰\t��ַ\n");
    while(LL){
        print(LL);
        LL=LL->next;
    }
}

int main()
{
    //���õĲ˵�����������
    //��1��������2����ӣ�3����ѯ��4ɾ����5�������0���˳���
    printLine();
    printf("    ͨѶ¼����ϵͳ\n");
    printLine();
    printf("    1.ͨѶ����Ľ���\n");
    printf("    2.ͨѶ�߽��Ĳ���\n");
    printf("    3.ͨѶ�߽��Ĳ�ѯ\n");
    printf("    4.ͨѶ�߽���ɾ��\n");
    printf("    5.ͨѶ¼��������\n");
    printf("    0.�˳�����ϵͳ\n");
    printLine(); 
    LinkList LL = createList();
    while (true) {
        cout << "   ��ѡ�� 0-5: "; 
        int k; cin >> k;
        if (k == 0) break;
        switch(k){
            case 1: { BuildList(LL); break; }
            case 2: { 
                printf("���\t����\t�Ա�\t�绰\t��ַ\n");
                InsertNode(LL); 
                break; }
            case 3: { 
                pNode p = ListFind(LL);
                if (p->next) {
                    printf("���\t����\t�Ա�\t�绰\t��ַ\n");
                    print(p->next);
                } else {
                    cout << "������" << endl; 
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

