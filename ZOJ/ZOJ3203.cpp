/*
    ZOJ3203
    三分 或者 推公式 
*/ 

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int T;
    double H,h,D;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&H,&h,&D);
        double temp=sqrt((H-h)*D);
        double temp2=(H-h)*D/H;
        if(temp>=D)printf("%.3lf\n",h);
        else if(temp<temp2)printf("%.3lf\n",h*D/H);
        else
        {
            double ans=D+H-temp-(H-h)*D/temp;
            printf("%.3lf\n",ans);
        }
    }
    return 0;
}
