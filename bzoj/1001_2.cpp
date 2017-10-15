#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#define inf 0x7fffffff
using namespace std;
const int maxn=2000000+10;
const int M = maxn*3+10;

int n,m,nn,mm;
int from,to;
struct Edge
{
    int v,flow;
    int next;
}edge[M];
int head[maxn],edgenum;

void add(int u,int v,int flow)
{
    edge[edgenum].v=v ;edge[edgenum].flow=flow ;
    edge[edgenum].next=head[u] ;head[u]=edgenum++ ;

    edge[edgenum].v=u ;edge[edgenum].flow=flow ;
    edge[edgenum].next=head[v] ;head[v]=edgenum++ ;
}

struct node
{
    int v,w;
    friend bool operator < (node a,node b)
    {
        return a.w > b.w;
    }
}cur,tail;
int d[maxn],vis[maxn];
void Dijkstra(int from,int to)
{
    for (int i=0 ;i<maxn ;i++) d[i]=inf;
    memset(vis,0,sizeof(vis));
    d[from]=0;
    priority_queue<node> Q;
    cur.v=from ;cur.w=0 ;
    Q.push(cur);
    while (!Q.empty())
    {
        cur=Q.top() ;Q.pop() ;
        int x=cur.v;
        if (vis[x]) continue;
        vis[x]=1;
        for (int i=head[x] ;i!=-1 ;i=edge[i].next)
        {
            if (d[edge[i].v ]>d[x]+edge[i].flow)
            {
                d[edge[i].v ]=d[x]+edge[i].flow;
                tail.v=edge[i].v;
                tail.w=d[edge[i].v ];
                Q.push(tail);
            }
        }
    }
    printf("%d\n",d[to]);
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        edgenum=0;
        from=0;
        to=2*(n-1)*(m-1)+1;
        int x,y,cost;
        for (int i=1 ;i<=n ;i++)
        {
            for (int j=1 ;j<m ;j++)
            {
                scanf("%d",&cost);
                x= i==1 ? from : (2*(i-1)-1)*(m-1)+j;
                y= i==n ? to : (2*(i-1))*(m-1)+j;
                add(x,y,cost);
            }
        }
        for (int i=1 ;i<n ;i++)
        {
            for (int j=1 ;j<=m ;j++)
            {
                scanf("%d",&cost);
                x= j==1 ? to : (2*(i-1))*(m-1)+j-1;
                y= j==m ? from : (2*(i-1))*(m-1)+j-1+m;
                add(x,y,cost);
            }
        }
        for (int i=1 ;i<n ;i++)
        {
            for (int j=1 ;j<m ;j++)
            {
                scanf("%d",&cost);
                x=(2*(i-1))*(m-1)+j;
                y=(2*(i-1)+1)*(m-1)+j;
                add(x,y,cost);
            }
        }
        Dijkstra(from,to);
    }
    return 0;
}
