#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
double cost[101][101];
int i,j,k,m,n,x,y,p;
void floyd()
{
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(cost[i][j]<cost[i][k]*cost[k][j]) //×¢ÒâÊÇ³Ë·¨
                    cost[i][j]=cost[i][k]*cost[k][j];

}
void init()
{
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(i==j) cost[i][j]=1;
            else
                cost[i][j]=0;
        }
}
void read()
{
    scanf("%d",&m);
    for(i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&p);
        cost[x][y]=cost[y][x]=(double)p/100;
    }
}
int main()
{
    while(cin>>n&&n)
    {
        init();
        read();
        floyd();
        printf("%.6lf percent\n",cost[1][n]*100);
    }
    return 0;
} 
