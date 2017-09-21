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
vector<int> G[max_node]; //每个节点出发的边编号
int p[max_nodes]; //当前节点单源最短路中的上一条边
int d[max_nodes]; //单源最短路径长

 
