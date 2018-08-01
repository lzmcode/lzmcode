#include<cstdio>
#include<cstring>
const int MAXN = 1001*1001;
inline int min(int a, int b) {return a < b ? a : b;}
int ecnt = -1;
struct node {
    int v, w, nxt;
}Edge[MAXN*6];
int Adj[MAXN], q[MAXN];
bool vis[MAXN];
void Addedge(int u, int v, int w) {
    node *t = &Edge[++ ecnt];
    t->v = v; t->w = w; t->nxt = Adj[u];
    Adj[u] = ecnt;
    t = &Edge[++ ecnt];
    t->v = u; t->w = w; t->nxt = Adj[v];
    Adj[v] = ecnt;
}
char c;
inline void GET(int &n) {
    n = 0;
    do c = getchar(); while(c > '9' || c < '0');
    while('0' <= c && c <= '9') {n=n*10+c-'0';c=getchar();}
}
int n, m, ans, S, T, d[MAXN], vd[MAXN], N;
int aug(int u, int augco) {
    int dmin = N-1, augc = augco, delta;
    if(u == T) return augco;
    for(int i = Adj[u]; ~i; i = Edge[i].nxt)
        if(Edge[i].w > 0) {
            if(d[Edge[i].v]+1 == d[u]) {
                delta = min(augc, Edge[i].w);
                delta = aug(Edge[i].v, delta);
                Edge[i].w -= delta;
                Edge[i^1].w += delta;
                augc -= delta;
                if(d[S] >= N) return augco - augc;
                if(!augc) return augco;
            }
            if(dmin > d[Edge[i].v]) dmin = d[Edge[i].v];
        }
    if(augco == augc) {
        -- vd[d[u]];
        if(!vd[d[u]]) d[S] = N;
        d[u] = ++ dmin;
        ++ vd[dmin];
    }
    return augco - augc;

}
void bfs() {
    int l = 0, r = 0, u;
    q[++ r] = T; vis[T] = 1; vd[0] ++;
    while(l < r) {
        u = q[++ l];
        for(int i = Adj[u]; ~i; i = Edge[i].nxt) {
            if(vis[Edge[i].v]) continue;
            d[Edge[i].v] = d[u] + 1;
            ++ vd[d[u]+1];
            vis[Edge[i].v] = 1;
            q[++r] = Edge[i].v;
        }
    }
}
void sap() {
    bfs();
    while(d[S] < N)
        ans += aug(S, 0x7fffffff);
}
int main()
{
    int w;
    memset(Adj, -1, sizeof Adj);
    GET(n); GET(m);
    for(int i = 0; i < n; ++ i)
    for(int j = 0; j < m-1; ++ j) {
        GET(w);
        Addedge(i*m+j, i*m+j+1, w);
    }
    for(int i = 0; i < n-1; ++ i)
    for(int j = 0; j < m; ++ j) {
        GET(w);
        Addedge(i*m+j, (i+1)*m+j, w);
    }
    for(int i = 0; i < n-1; ++ i)
    for(int j = 0; j < m-1; ++ j) {
        GET(w);
        Addedge(i*m+j, (i+1)*m+j+1, w);
    }
    T = n*m-1; N = n*m;
    sap();
    printf("%d\n", ans);
    return 0;
}
