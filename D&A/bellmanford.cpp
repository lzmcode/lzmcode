#include <iostream>
#include <cstdio>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 1000
int vernum, edgenum, original;

typedef struct Edge{
    int u,v;
    int cost;
}Edge;

Edge edge[MAX];
int dis[MAX], pre[MAX];

bool Bellman_Ford()
{
    for (int i=1; i<=vernum; i++)
        dis[i] = (i == original ? 0 : INF);
    for (int i=1; i<=vernum-1; i++)
    {
        for (int j=1; j<=edgenum; j++)
        {
            if (dis[edge[j].v] > dis[edge[j].u] + edge[j].cost)
            {
                dis[edge[j].v] = dis[edge[j].u] + edge[j].cost;
                pre[edge[j].v] = edge[j].u;
            }
        }
    }
    bool flag = 1;
    for (int i=1; i<=edgenum; i++)
    {
        if (dis[edge[i].v] > dis[edge[i].u] + edge[i].cost)
        {
            flag = 0;
            break;
        }
    }
    return flag; 
}

void print_path(int root)
{
    while (root != pre[root])
    {
        printf("%d-->", root);
        root = pre[root];
    }
    if (root == pre[root])
        printf("%d\n", root);
}

int main()
{
    cin >> vernum >> edgenum >> original;
    pre[original] = original;
    for (int i=1; i<=edgenum; i++)
    {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].cost);
    }
    
    if (Bellman_Ford())
    {
        for (int i=1; i<=vernum; i++)
        {
            printf("%d\n", dis[i]);
            printf("Path:");
            print_path(i); 
        }
    }
    else
        printf("have negative circle\n");
    return 0;
}
