#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

const int max_n=105;
const int max_m=25;
const int max_e=max_m*max_m*2;
const int INF=2e9;

int n,m,k,e,x,y,z,d,p,a,b;
int tot,point[max_m],nxt[max_e],v[max_e],c[max_e];
int dis[max_m]; bool broken[max_m][max_n],vis[max_m],flag[max_m];
int f[max_n],cost[max_n][max_n];
queue <int> q;

inline void addedge(int x,int y,int z)
{
    ++tot; nxt[tot]=point[x]; point[x]=tot; v[tot]=y; c[tot]=z;
    ++tot; nxt[tot]=point[y]; point[y]=tot; v[tot]=x; c[tot]=z;
}
inline int spfa()
{
    memset(dis,0x7f,sizeof(dis)); dis[1]=0;
    memset(vis,0,sizeof(vis)); vis[1]=true;
    while (!q.empty()) q.pop(); q.push(1);

    while (!q.empty())
    {
        int now=q.front(); q.pop();
        vis[now]=false;
        for (int i=point[now];i;i=nxt[i])
            if (dis[v[i]]>dis[now]+c[i]&&!flag[v[i]])
            {
                dis[v[i]]=dis[now]+c[i];
                if (!vis[v[i]])
                {
                    vis[v[i]]=true;
                    q.push(v[i]);
                }
            }
    }
    return dis[m];
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&e);
    for (int i=1;i<=e;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
    }
    scanf("%d",&d);
    for (int i=1;i<=d;++i)
    {
        scanf("%d%d%d",&p,&a,&b);
        for (int j=a;j<=b;++j) broken[p][j]=true;
    }
    for (int i=1;i<=n;++i)
        for (int j=i;j<=n;++j)
        {
            memset(flag,0,sizeof(flag));
            for (int k=1;k<=m;++k)
                for (int l=i;l<=j;++l)
                    flag[k]|=broken[k][l];
            cost[i][j]=spfa();
        }
    for (int i=1;i<=n;++i)
        for (int j=i;j<=n;++j)
            if (cost[i][j]<INF) cost[i][j]*=(j-i+1);
    memset(f,0x7f,sizeof(f));
    for (int i=1;i<=n;++i) f[i]=cost[1][i];
    for (int i=2;i<=n;++i)
        for (int j=1;j<i;++j)
            f[i]=min(f[i],f[j]+cost[j+1][i]+k);
    printf("%d\n",f[n]);
}
