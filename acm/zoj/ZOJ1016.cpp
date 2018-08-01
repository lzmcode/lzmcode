#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int p[30];
int w[30];
int s[100];
int main()
{
    int t,n,i,j,k,q;
    int sum1,sum2,head,rear,t1,t2,headw,rearw;
    scanf("%d",&t);
    while(t--)
    {
        sum1=0,sum2=0,head=0,rear=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
            if(sum1<p[i])
            {
                for(j=0;j<p[i]-sum1;j++)
                    s[rear++]=0;
                sum1=p[i];
            }
            s[rear++]=1;
            sum2++;
        }
        rearw=headw=0;
        while(head!=rear)
        {
            t1=0,t2=0;
            if(s[head]==1)
            {
                t1++;
                if(s[head-1]==0)
                    w[rearw++]=1;
                else
                {
                    t1++;
                    q=head-1;
                    while(t1!=t2)
                    {
                        q--;
                        if(s[q]==0)
                            t2++;
                        else
                            t1++;
                    }
                    w[rearw++]=t1;
                }
                head++;
            }
            else
                head++;
        }
        for(k=0;k<rearw;k++)
            printf("%d%c",w[k],k==rearw-1?'\n':' ');
    }
    return 0;
}
