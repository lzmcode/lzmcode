#include <cstring>
#include <cstdio>
#include <queue>
#include <iostream>
#define INF 0x3f3f3f3f
#define MAX 100
using namespace std;

int map[MAX][MAX];
int dis[MAX];
int vis[MAX];
int num[MAX]; //每个节点入队的次数

struct cmp
{
     bool operator()(int x,int y)
     {
          return x>y;
     }
};

bool SPFA(int s, int n)
{
    priority_queue<int, vector<int>, cmp> q;
    memset(vis, false, sizeof(vis));
    memset(num, 0, sizeof(num));
    for (int i=0; i<n; i++)
        dis[i] = INF;
    dis[s] = 0;
    q.push(s);
    vis[s] = true;
    /*
        等价写法 
        for (int i=0; i<n; i++)
            dis[i] = (i == s) ? 0 : INF; 
    */
    num[s]++;
    while (!q.empty())
    {
        int p = q.top();
        q.pop();
        for (int i=0; i<n; i++)
        {
            if (dis[p] + map[p][i] < dis[i])
            {
                dis[i] = dis[p] + map[p][i];
                if (!vis[i])
                {
                    q.push(i);
                    num[i]++;
                    if (num[i] > n)
                        return false;
                    vis[i] = true; 
                } 
            }
        }
        vis[p] = false;
    }
    return true;
}

int main()
{
    int vernum, edgenum, source;
    cin >> vernum >> edgenum;
    for (int i=0; i<vernum; i++)
        for (int j=0; j<vernum; j++)
            cin >> map[i][j];
    if (!SPFA(0, vernum))
        printf("have nagetive circle\n");
    else
        for (int i=0; i<vernum; i++)
            printf("%d ",dis[i]);
    return 0;
}
