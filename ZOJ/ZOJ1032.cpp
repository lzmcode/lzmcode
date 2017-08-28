#include<stdio.h>
#include<cmath>
#include<iostream>
#include<algorithm>
#define MAXN 10000
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int CrossMul(int x1,int y1,int x2,int y2)
{
    return x1*y2-x2*y1;
}
int main()
{
    int T,times=0;
    cin>>T;
    while (T--)
    {
        times++;
        int N;
        cin>>N;
        int area=0;
        int x=0,y=0,dx=0,dy=0;
        int cnt=0;
        for (int i=1;i<=N;i++)
        {
            int tx,ty;
            cin>>tx>>ty;
            dx=x+tx,dy=y+ty;
            cnt+=gcd(abs(tx),abs(ty));
            area+=CrossMul((x,y,dx,dy);
            x=dx,y=dy;
        }
        area=area>0?area:-area;
        double ans3=(double)area/2.0;
        int ans2=cnt;
        int ans1=(area+2-ans2)/2;
        printf("Scenario #%d:\n",times);
        printf("%d %d %.1lf\n\n",ans1,ans2,ans3);
    }

    return 0;
}
