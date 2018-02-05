#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAXN 100   //�洢����Ԫ�ص�������
#define ERROR -1   //ElementType������ֵ����־����

typedef struct {
    int data[MAXN];
    int front;     //��¼����ͷԪ��λ��
    int rear;      //��¼����βԪ��λ��
    int size;      //�洢����Ԫ�صĸ���
}*Queue, pNode;

Queue getEmptyQueue() {
    Queue q = new pNode;
    if (!q) {
        printf("�ռ䲻��\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isFullQ(Queue q) {
    return (q->size == MAXN);
}

void inQueue(Queue q, int item) {
    if (isFullQ(q)) {
        printf("��������\n");
        return;
    }
    q->rear++;
    q->rear %= MAXN;
    q->size++;
    q->data[q->rear] = item;
}

int isEmptyQ(Queue q) {
    return (q->size == 0);
}

int outQueue(Queue q) {
    if (isEmptyQ(q)) {
        cout << "�ն���" << endl;
        return ERROR;
    }
    q->front++;
    q->front %= MAXN;
    q->size--;
    return q->data[q->front];
}

void printQueue(Queue q) {
    if (isEmptyQ(q)) {
        cout << "�ն���" << endl;
        return;
    }
    cout << "��ӡ��������Ԫ��: ";
    int index = q->front;
    int i;
    for (i = 0; i < q->size; i++) {
        index++;
        index %= MAXN;
        cout << q->data[index] << " ";
    }
    cout << endl;
}

int main() {
    Queue q = getEmptyQueue();
    
    inQueue(q, 0);
    inQueue(q, 1);
    inQueue(q, 2);
    inQueue(q, 3);
    inQueue(q, 4);
    inQueue(q, 5);
    printQueue(q);
    
    outQueue(q);
    outQueue(q);
    outQueue(q);
    printQueue(q);
    
    inQueue(q, 6);
    inQueue(q, 7);
    inQueue(q, 8);
    printQueue(q);

    return 0;
}
