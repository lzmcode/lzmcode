#include <cstdio>
#include <iostream>
using namespace std;

struct Edge{
    int from;
    int to;
    int weight;
    
    Edge(int f, int t, int w):from(f), to(t), weight(w){}
};

int num_nodes;
int num_edges;
vector<Edge> edges;
vector<int> G[max_node]; //ÿ���ڵ�����ı߱��
int p[max_nodes]; //��ǰ�ڵ㵥Դ���·�е���һ����
int d[max_nodes]; //��Դ���·����

 
