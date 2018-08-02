#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int main()
{
    unsigned long i;
    unsigned long m;
    const unsigned long N=10000000;
    double x,y,pi;
    srand((unsigned) time(NULL));
    for(i=0,m=0;i<N;i++)
    {
        /*x,yÔÚÇø¼ä(-1,1)*/
        x=2.0*rand()/RAND_MAX-1;
        y=2.0*rand()/RAND_MAX-1;
        if((x*x+y*y)<=1)
        { 
              m++;
        }
    }
    pi=4.0*m/N;
    printf("%lf\n",pi);
    return 0;
}
