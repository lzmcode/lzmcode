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
vector<int> G[max_nodes]; // ÿ���ڵ�����ı߱��
int p[max_nodes]; // ��ǰ�ڵ㵥Դ���·�е���һ����
int d[max_nodes]; // ��Դ���·����

typedef pair<int, int> HeapNode;
void Dijkstra(int s)
{
    priority_queue< HeapNode, vector<HeapNode>, greater<HeapNode> > Q;
    for (int i=0; i<num_nodes; ++i)
        d[i] = __inf; //��ʼ�����нڵ�ľ�����oo 
    d[s] = 0; //���ڵ��Լ��ľ�����0 
    Q.push(make_pair(0, s)); //��Դ��������ȶ��� 
    while (!Q.empty()) { //�����ȶ��в�Ϊ�յ�ʱ�� 
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
    return false; // ����Ӧ����Զ����ִ�е�����
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
        d[i] = __inf; //��ʼ�����нڵ�ľ���Ϊoo 
 
    d[s] = 0;
    in_queue[s] = true; //������� 
    Q.push(s);
    while (!Q.empty()) { //�����зǿյ�ʱ�� 
        in_queue[u=Q.front()] = false; //���������еĵ�һ�� 
        Q.pop();
        for (int i=0; i<G[u].size(); ++i) {
            Edge &e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.weight) {
                d[e.to] = d[u] + e.weight; //�ɳڲ��� 
                p[e.to] = G[u][i];
                if (!in_queue[e.to]) {
                    Q.push(e.to); //���ڶ����о���� 
                    in_queue[e.to] = true;
                    if (++cnt[e.to] > num_nodes)
                        return false; //ѭ�������ڵ�����˵���и�ȨȦ 
                }
            }
        }
    }
    return true;
}

int indegree[max_nodes]; //������� 
void asp(int s)
{
    //��ʼ�� 
    queue<int> Q;
    for (int i=0; i<num_nodes; ++i) {
        d[i] = __inf; //��ÿ����ľ��붼��oo 
        indegree[i] = 0; //ÿ�������ȶ���0 
    }
    for (int i=0; i<num_edges; ++i)
        ++indegree[edges[i].to]; //ȷ��ÿ�����ʵ����� 
    for (int i=0; i<num_nodes; ++i)
        if (indegree[i] == 0) Q.push(i); //�����Ϊ0�ĵ������� 

    d[s] = 0; //���Լ��ľ���Ϊ0 
    while (!Q.empty()) {
        int w = Q.front();
        Q.pop(); //��ö����еĵ�һ���� 
        for (int i=0; i<G[w].size(); ++i) {
            if (d[edges[G[w][i]].to] > d[w] + edges[G[w][i]].weight && d[w] != __inf) { 
                d[edges[G[w][i]].to] = d[w] + edges[G[w][i]].weight;
                p[edges[G[w][i]].to] = G[w][i];
            }
            if (--indegree[edges[G[w][i]].to] == 0)
                Q.push(edges[G[w][i]].to);
            //����ܷŽ�ȥ�����-1����ȼ��ٵ�0�ͼ���������� 
        }
    }
}

int dist[max_nodes][max_nodes]; // ��¼·����
int path[max_nodes][max_nodes]; // ��¼ʵ��·��
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



