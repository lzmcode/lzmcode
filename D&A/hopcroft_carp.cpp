/**==================================================*\
 二分图匹配（Hopcroft－Carp 的算法）
 INIT: g[][]邻接矩阵;
 CALL: res = MaxMatch(); Nx, Ny要初始化！！！
 Mx，My为match
 时间复杂度为O（V^0.5 E）
==================================================**/
#include <cstdio>
#include <memory.h>
#include <queue>
using namespace std;

const int MAXN = 310;
const int INF = 1 << 28;
bool flag;
int p,n;
int  Mx[MAXN], My[MAXN], Nx, Ny;
int dx[MAXN], dy[MAXN], dis;
bool vst[MAXN],g[110][310];
bool searchP(void)    //BFS 
{
    queue <int> Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 1; i <= Nx; i++)
    if (Mx[i] == -1){
       Q.push(i); dx[i] = 0;
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (dx[u] > dis) break;        //说明该增广路径长度大于dis还没有结束，等待下一次BFS在扩充
           for (int v = 1; v <= Ny; v++)
               if (g[u][v] && dy[v] == -1) {        //v是未匹配点
                  dy[v] = dx[u]+1;
                if (My[v] == -1) dis = dy[v];    //得到本次BFS的最大遍历层次
                else{
                     dx[My[v]] = dy[v]+1;         //v是匹配点，继续延伸
                     Q.push(My[v]);
                     }
                }
    }
    return dis != INF;
}

bool DFS(int u){
    for (int v = 1; v <= Ny; v++)
    if (!vst[v] && g[u][v] && dy[v] == dx[u]+1) {
       vst[v] = 1;
       if (My[v] != -1 && dy[v] == dis) continue;   //层次（也就是增广路径的长度）大于本次查找的dis，是searchP被break的情况，也就是还不确定是否是增广路径，只有等再次调用searchP()在判断。
       if (My[v] == -1 || DFS(My[v])) {     //是增广路径，更新匹配集
       My[v] = u; Mx[u] = v;
       return 1;
       }
    }
 return 0;
}

int MaxMatch(void){
    int res = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (searchP()) {
          memset(vst, 0, sizeof(vst));
          for (int i = 1; i <= Nx; i++)
              if (Mx[i] == -1 && DFS(i)) res++;   //查找到一个增广路径，匹配数res++
    }
    return res;
}

/**********************************************************************/
int main()
{
    int i,j,k,t,v,cnt;
    scanf("%d",&t);
    while (t--)
    {
          scanf("%d %d", &p, &n);
          for (i = 1; i <= p; i++)
              for (j = 1; j <= n; j++)
                  g[i][j] = false;
          flag = true;
          for (i = 1; i <= p; i++)
          {
              scanf("%d",&k);
              if (k == 0)
                 flag = false;
              while (k--)
              {
                    scanf("%d",&v);
                    g[i][v]  = true;
              }
          }
          Nx = p; Ny = n;
          if (flag)
          {
               cnt = MaxMatch();
               if (cnt == p)
                  printf("YES\n");
               else printf("NO\n");   
          } 
          else printf("NO\n"); 
    }
    
    return 0;
}
