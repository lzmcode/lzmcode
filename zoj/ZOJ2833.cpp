#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 100010

int f[MAXN];
int cnt[MAXN];

int find(int x)
{
    if(f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

void make(int a,int b)
{
    int f1 = find(a);
    int f2 = find(b);
    if (f1 != f2) {
        cnt[f1] = cnt[f1] + cnt[f2];
        f[f2] = f1;
    }
}

int main()
{

    int n,m,test=0,blank=0;
    while (scanf("%d%d",&n,&m)!=EOF) {
        if (blank) printf("\n");
        blank = 1;
        test++;
        for (int i=1; i<=n; i++) {
            f[i] = i;
            cnt[i] = 1;
        }
        printf("Case %d:\n",test);
        for (int i=0; i<m; i++) {
            int a,b;
            char k; getchar();
            scanf("%c",&k);
            if (k == 'M') {
                scanf("%d%d",&a,&b);
                make(a,b);
            } else { 
                scanf("%d",&a); 
                int t = find(a);
                printf("%d\n",cnt[t]);
            }
        }
    }
    return 0;
}
