#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
   int a[4],i,j,k,s,p,y;
   while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])!=EOF)
   {
       for(i=0;i<=1;i++)
       for(j=0;j<=1;j++)
       for(k=0;k<=1;k++)
       {
           y=(a[3]+12-a[1]-a[2]-j-k)/3;
           p=y+a[1]+j;
           s=p+a[0]+i;
           if(y+p+s==a[3]+12)
           {
               printf("%d %d %d\n",s,p,y);//有多种年龄的组合可能，只取其中一种，故跳出。
              // break;//break只能跳出一层循环。用goto
              goto xx;
           }
       }
       xx:;
   }
    return 0;
}
