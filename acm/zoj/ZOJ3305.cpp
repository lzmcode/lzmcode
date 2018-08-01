#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ANS,maxn;
int dp[1<<16];
int main()
{
    while(2==scanf("%d%d",&n,&m))
    {
        ANS=1<<n;
        ANS-=1;
        maxn=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
        {
            int k,b;
            scanf("%d",&k);
            int s=0;
            for(int j=1;j<=k;j++)
            {
                scanf("%d",&b);
                s|=(1<<(b-1));
            }
            int res=ANS^s;
            dp[s]=max(dp[s],1);
            for(int j=res;j;j=(j-1)&res)//学到了，取一个集合的所有补集的方法
            {
                if(!dp[j])
                    continue;
                dp[s|j]=max(dp[s|j],dp[j]+1);
            }
        }
        int maxn=0;
        for(int i=1;i<=(1<<n)-1;i++)
            if(dp[i]>maxn)
                maxn=dp[i];
        printf("%d\n",maxn);
    }
    return 0;
}
