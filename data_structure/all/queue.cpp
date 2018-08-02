#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAXN 100   //存储数据元素的最大个数
#define ERROR -1   //ElementType的特殊值，标志错误

typedef struct {
    int data[MAXN];
    int front;     //记录队列头元素位置
    int rear;      //记录队列尾元素位置
    int size;      //存储数据元素的个数
}*Queue, pNode;

Queue getEmptyQueue() {
    Queue q = new pNode;
    if (!q) {
        printf("空间不足\n");
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
        printf("队列已满\n");
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
        cout << "空队列" << endl;
        return ERROR;
    }
    q->front++;
    q->front %= MAXN;
    q->size--;
    return q->data[q->front];
}

void printQueue(Queue q) {
    if (isEmptyQ(q)) {
        cout << "空队列" << endl;
        return;
    }
    cout << "打印队列数据元素: ";
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
