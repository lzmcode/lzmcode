#include <cstdio>
#include <cstring>
#include <iostream>
#define INF 99999
#define MAX 100
using namespace std;

int dis[MAX]; //保存距离 
int vis[MAX]; //是否访问过 
int map[MAX][MAX]; //矩阵保存
 
int main()
{
    int i,j;
    int point, edge; 
    cin >> point >> edge;
    
    for (i=1; i<=point; i++)
    {
        for (j=1; j<=point; j++)
        {
            if (i == j)
                map[i][j] = 0;
            else
                map[i][j] = INF;
        }
    }
    
    int x, y, cost;
    for (i=1; i<=edge; i++)
    {
        cin >> x >> y >> cost;
        map[x][y] = cost;
        //map[y][x] = cost;
    }
    
    for (i=1; i<=point; i++)
    {
        dis[i] = map[1][i];
        vis[i] = 0;
    }
    dis[1] = 0; 
    vis[1] = 1;
    
    int min, pos;
    for (i=1; i<point; i++)
    {
        min = INF;
        for (j=1; j<point; j++)
        {
            if (vis[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                pos = j;
            } 
        } 
        vis[pos] = 1;
        //更新最短距离 
        for (int k=1; k<=point; k++)
        {
            if (map[pos][k] < INF)
            {
                if (map[pos][k] + dis[pos] < dis[k]) //确定符号 
                {
                    dis[k] = map[pos][k] + dis[pos];
                }
            }           
        } 
        for (int b=1; b<=point; b++)
            cout << dis[b] << " ";
        cout << endl;
    }
    for (i=1; i<=point; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}
