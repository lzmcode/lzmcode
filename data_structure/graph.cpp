#include <cstdio>
#include <iostream>
using namespace std;

struct Edge
{
    int from;
    int to;
    int weight;

    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};

int num_nodes;
int num_edges;
vector<Edge> edges;
vector<int> G[max_nodes]; // 每个节点出发的边编号
int p[max_nodes]; // 当前节点单源最短路中的上一条边
int d[max_nodes]; // 单源最短路径长

typedef pair<int, int> HeapNode;
void Dijkstra(int s)
{
    priority_queue< HeapNode, vector<HeapNode>, greater<HeapNode> > Q;
    for (int i=0; i<num_nodes; ++i)
        d[i] = __inf; //初始化所有节点的距离是oo 
    d[s] = 0; //到节点自己的距离是0 
    Q.push(make_pair(0, s)); //将源点放入优先队列 
    while (!Q.empty()) { //当优先队列不为空的时候 
        pair<int, int> N = Q.top(); 
        Q.pop();
        int u = N.second;
        if (N.first != d[u]) continue;
        for (int i=0; i<G[u].size(); ++i) {
            Edge &e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.weight) {
                d[e.to] = d[u] + e.weight;
                p[e.to] = G[u][i];
                Q.push(make_pair(d[e.to], e.to));
            }
        }
    }
}

bool Bellman_Ford(int s)
{
    for (int i=0; i<num_nodes; ++i)
        d[i] = __inf;

    d[s] = 0;
    for (int i=0; i<num_nodes; ++i) {
        bool changed = false;
        for (int e=0; e<num_edges; ++e) {
            if (d[edges[e].to] > d[edges[e].from] + edges[e].weight 
               && d[edges[e].from] != __inf) {
                d[edges[e].to] = d[edges[e].from] + edges[e].weight;
                p[edges[e].to] = e;
                changed = true;
            }
        }
        if (!changed) return true;
        if (i == num_nodes && changed) return false;
    }
    return false; // 程序应该永远不会执行到这里
}

bool in_queue[max_nodes];
int cnt[max_nodes];
bool SPFA(int s)
{
    int u;
    queue<int> Q;
    memset(in_queue, 0, sizeof(in_queue));
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<num_nodes; ++i)
        d[i] = __inf; //初始化所有节点的距离为oo 
 
    d[s] = 0;
    in_queue[s] = true; //顶点入队 
    Q.push(s);
    while (!Q.empty()) { //当队列非空的时候 
        in_queue[u=Q.front()] = false; //弹出队列中的第一项 
        Q.pop();
        for (int i=0; i<G[u].size(); ++i) {
            Edge &e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.weight) {
                d[e.to] = d[u] + e.weight; //松弛操作 
                p[e.to] = G[u][i];
                if (!in_queue[e.to]) {
                    Q.push(e.to); //不在队列中就入队 
                    in_queue[e.to] = true;
                    if (++cnt[e.to] > num_nodes)
                        return false; //循环超过节点数，说明有负权圈 
                }
            }
        }
    }
    return true;
}

int indegree[max_nodes]; //入度数组 
void asp(int s)
{
    //初始化 
    queue<int> Q;
    for (int i=0; i<num_nodes; ++i) {
        d[i] = __inf; //到每个点的距离都是oo 
        indegree[i] = 0; //每个点的入度都是0 
    }
    for (int i=0; i<num_edges; ++i)
        ++indegree[edges[i].to]; //确定每个点的实际入度 
    for (int i=0; i<num_nodes; ++i)
        if (indegree[i] == 0) Q.push(i); //把入度为0的点放入队列 

    d[s] = 0; //到自己的距离为0 
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop(); //获得队列中的第一个点 
        for (int i=0; i<G[w].size(); ++i) {
            if (d[edges[G[w][i]].to] > d[w] + edges[G[w][i]].weight && d[w] != __inf) { 
                d[edges[G[w][i]].to] = d[w] + edges[G[w][i]].weight;
                p[edges[G[w][i]].to] = G[w][i];
            }
            if (--indegree[edges[G[w][i]].to] == 0)
                Q.push(edges[G[w][i]].to);
            //如果能放进去，入度-1，入度减少到0就继续放入队列 
        }
    }
}

int dist[max_nodes][max_nodes]; // 记录路径长
int path[max_nodes][max_nodes]; // 记录实际路径
bool Floyd_Warshall()
{
    for (int i=0; i<num_nodes; ++i)
        for (int j=0; j<num_nodes; ++j)
            path[i][j] = j;

    for (int k=0; k<num_nodes; ++k) {
        for (int i=0; i<num_nodes; ++i) {
            for (int j=0; j<num_nodes; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]
                 && dist[i][k] != __inf && dist[k][j] != __inf) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k];
                    if (i == j && dist[i][j] < 0)
                        return false;
                }
            }
        }
    }
    return true;
}

void printpath(int from, int to, bool firstcall = true)
{
    if (from == to) {
        printf("%d", from);
        return;
    }
    if (p[to] == -1) return;
    if (firstcall) printf("%d ->", from);
    int v = edges[p[to]].from;
    if (v == from) {
        if (firstcall) printf(" %d", to);
        return;
    }
    printpath(from, v, false);
    printf(" %d ->", v+1);
    if (firstcall) printf(" %d", to);
}

void showpath(int from, int to)
{
    int c = from;
    printf("%d -> %d:(%2d)  %d", from, to, dist[from][to], from);
    while (c != to) {
        printf(" -> %d", path[c][to]);
        c = path[c][to];
    }
    printf("\n");
}



