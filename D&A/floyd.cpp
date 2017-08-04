#include <stdio.h>
#include <algorithm>
#define INF (~(0x1<<31))
#define MAX 1000
using namespace std;  
int map[MAX][MAX],dis[MAX][MAX];  
int main()  
{  
    int i,n,j,k;  
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            map[i][j] = INF;
        }
    }
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<n;j++)  
        {  
            for(k=0;k<n;k++)  
            {  
                if(map[j][k]>map[j][i]+map[i][k])  
                    map[j][k]=map[j][i]+map[i][k];  
            }  
        }  
    }  
}  
