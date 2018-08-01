#include <stdio.h>
#include <math.h>
#define pi 3.141592653
int main()
{
    double r1=0,r2,x,y;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&x,&y);
        double distance=x*x+y*y;
        int year=1;
 
        for(r1=0;r2=(100/pi+r1*r1),r2<distance;r1=sqrt(r2))
            year++;
 
        printf("Property %d: This property will begin eroding in year %d.\n",i,year);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
