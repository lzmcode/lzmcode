#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

class Worker {
    private:
        static int count;
        //Member variable
        string name;
        int age;
        string dept;
        double salary;
    public:
        Worker(){};
        Worker(string sName, int iAge, string sDept, double dSalary);
        Worker(const Worker& rhs) { ++count; };
        ~Worker() { count--; }
        void setWorker(string sName, int iAge, string sDept, double dSalary);
        static int getCount();
        void print();
};

Worker::Worker(string sName, int iAge, string sDept, double dSalary):
    name(sName), age(iAge), dept(sDept), salary(dSalary) {
    count++;
}
void Worker::setWorker(string sName, int iAge, string sDept, double dSalary) {
    name = sName;
    age = iAge;
    sDept = sDept;
    salary = dSalary;
}
void Worker::print(){
    cout << name << "\t" << age << "\t" << dept << " " << salary << " " << endl;
}
int Worker::count = 0;
int Worker::getCount(){  
   return count; 
}

typedef struct Node{
    int num;
    Worker *w = NULL;
    struct Node *next;
}*LinkList, *pNode;

LinkList getEmptyList(){
    LinkList head = (pNode)malloc(sizeof(struct Node));
    head->next = NULL;
    return head;
}

void addNode(LinkList head,pNode newnode){
    newnode->next = head->next;
    head->next = newnode;
}

void showList(LinkList head){
    pNode p = head,q;
    while (p->next != NULL)
    {
         p->next->w->print();
         q = p->next;
         p = p->next;
         free(q);
    }
}

int main()
{
    string sName;
    int iAge;
    string sDept;
    double dSalary;
     
    LinkList head = getEmptyList();
    cout << "������Ϣ��������Ϊ0�ļ�¼����:" << endl;
    showList(head);
    while(true){
        cin >> sName >> iAge >> sDept >> dSalary;
        if (iAge == 0) break;
        pNode newnode = (pNode)malloc(sizeof(struct Node));
        //newnode->num = i;
        newnode->w = new Worker(sName, iAge, sDept, dSalary);
        addNode(head,newnode);
    }
    cout << "��Ϣ����:" << endl;
    showList(head);
    cout << "Ա����" << Worker::getCount() << "��" << endl; 
    return 0;
}
