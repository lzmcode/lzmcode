#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define mod 10000
#define maxn 1111
int ans[111111],len;
void mul(int n)
{
    int k=0;
    for(int i=0;i<len;i++)
    {
        int temp=ans[i]*n+k;
        ans[i]=temp%mod;
        k=temp/mod;
    }
    if(k!=0)ans[len]=k,len++;
}
void output()
{
    printf("%d",ans[len-1]);
    for(int i=len-2;i>=0;i--)
        printf("%04d",ans[i]);
    printf("\n");
}
int prime[maxn],res,mark[maxn];
void get_prime()
{
    memset(mark,0,sizeof(mark));
    res=0;
    for(int i=2;i<maxn;i++)
        if(!mark[i])
        {
            prime[res++]=i;
            for(int j=i;j<maxn;j+=i)mark[j]=1;
        }
}
int n,a[maxn],sum,cnt,num[maxn];
void deal(int n,int sta)
{
    for(int i=0;i<res&&prime[i]<=n;i++)
    {
        int m=n;
        while(m)
        {
            num[i]+=sta*(m/prime[i]);
            m/=prime[i];
        }
    }   
}
int main()
{
    get_prime();
    scanf("%d",&n);
    int gg=0;
    memset(num,0,sizeof(num));
    cnt=sum=0;
    len=1,ans[0]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0||a[i]>=n)gg=1;
        if(a[i]==-1)continue;
        cnt++,sum+=a[i]-1;
    }
    if(n==1)
    {
        if(a[1]==-1||a[1]==0)printf("1\n");
        else printf("0\n");
        return 0;
    }
    if(n==2)
    {
        if((a[1]==-1||a[1]==1)&&(a[2]==-1||a[2]==1))printf("1\n");
        else printf("0\n");
        return 0;
    }
    if(gg||sum>n-2)
    {
        printf("0\n");
        return 0;
    }
    deal(n-2,1),deal(n-2-sum,-1);
    for(int i=1;i<=n;i++)
        if(a[i]!=-1)deal(a[i]-1,-1);
    for(int i=0;i<res;i++)
        while(num[i]--)mul(prime[i]);
    for(int i=1;i<=n-2-sum;i++)mul(n-cnt);
    output();
    return 0;
}
