#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 100010

int f[MAXN];
int cnt[MAXN];

inline void init(int n) {
    for (int i=0; i<=n; i++) {
        f[i] = i;
        cnt[i] = 1;
    }
} 

int find(int k) {
    int root = k;
    while (root != f[root])
        root = f[root];
    while (k != f[k]) {
		int tmp = f[k];
		f[k] = root;
		k = tmp;
	}
	return root;
}

void join(int a,int b)
{
	int roota = find(a);
	int rootb = find(b);
	if (roota != rootb) {
	    int sum = cnt[roota] + cnt[rootb];
		cnt[roota] = sum;
		cnt[rootb] = sum;
		f[roota] = rootb;
	}
}

int main()
{
    int n,m;
    int times = 0;
    while (scanf("%d%d",&n,&m) != EOF) {
        if (times != 0) printf("\n");
        printf("Case %d:\n",++times);
        init(n);
        int a,b;
        for (int i=0; i<m; i++) {
            getchar();
            char ch;
            scanf("%c",&ch);
            if (ch == 'M') {
                scanf("%d%d",&a,&b);
                join(a,b);
            } else {
                scanf("%d",&a);
                printf("%d\n",cnt[find(a)]);
            }
        }
    }
    return 0;
} 
