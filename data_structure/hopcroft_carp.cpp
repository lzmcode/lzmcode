/**==================================================*\
 ����ͼƥ�䣨Hopcroft��Carp ���㷨��
 INIT: g[][]�ڽӾ���;
 CALL: res = MaxMatch(); Nx, NyҪ��ʼ��������
 Mx��MyΪmatch
 ʱ�临�Ӷ�ΪO��V^0.5 E��
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
        if (dx[u] > dis) break;        //˵��������·�����ȴ���dis��û�н������ȴ���һ��BFS������
           for (int v = 1; v <= Ny; v++)
               if (g[u][v] && dy[v] == -1) {        //v��δƥ���
                  dy[v] = dx[u]+1;
                if (My[v] == -1) dis = dy[v];    //�õ�����BFS�����������
                else{
                     dx[My[v]] = dy[v]+1;         //v��ƥ��㣬��������
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
       if (My[v] != -1 && dy[v] == dis) continue;   //��Σ�Ҳ��������·���ĳ��ȣ����ڱ��β��ҵ�dis����searchP��break�������Ҳ���ǻ���ȷ���Ƿ�������·����ֻ�е��ٴε���searchP()���жϡ�
       if (My[v] == -1 || DFS(My[v])) {     //������·��������ƥ�伯
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
              if (Mx[i] == -1 && DFS(i)) res++;   //���ҵ�һ������·����ƥ����res++
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
