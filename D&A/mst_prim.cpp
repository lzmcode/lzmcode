#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 100
#define INF (~(0x1<<31))
using namespace std;

int map[MAX][MAX];
int vis[MAX];
int dis[MAX];

int prim(int n)
{
    int pos, min, mst = 0;
    vis[1] = 1;
    pos = 1;
    for (int i=2; i<=n; i++)
    {
        if (map[pos][i] == 0)
            dis[i] = INF;
        else
            dis[i] = map[pos][i];
        //更新到每个点的距离 
    }
    for (int i=1; i<=n-1; i++)
    {
        min=INF;
        for (int j=1; j<=n; j++)
        {
            if (vis[j] == 0 && min > dis[j])
            {
                min = dis[j];
                pos = j; //记录找到的最小 
            }
        }
        vis[pos] = 1; //标记已经访问过了
        mst += min;
        for (int j=1; j<=n; j++)
        {
            if (vis[j] == 0 && dis[j] > map[pos][j])
                if (map[pos][j] != 0)
                    dis[j] = map[pos][j];
        } 
    }
    return mst;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(map, 0, sizeof(map));
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
            {
                int edge;
                cin >> edge;
                map[i][j] = map[j][i] = edge;
            }
        int ans = prim(n);
        cout << ans <<endl; 
    }
    return 0;
}
