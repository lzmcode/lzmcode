#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXY 150
#define MAXM 20
using namespace std;

int days[MAXY][MAXM];

int calc(int m,int d,int y)
{
    int ans = 0;
    ans += 202214 * (y / 132);
    y = y % 132;
    if (y != 0) {
        ans += days[y][m-1];
    }
    ans += d;
    return ans;
}

int main()
{
    memset(days,0,sizeof(days));
    //处理每个月有几天
    for (int i=1; i<=132; i++) {
        for (int j=1; j<=(i%12)+1; j++) {
            days[i][j] = j*j*j;
        }
        if (i % 11 == 0) {
            //leap year
            days[i][1]++;
        }
    }
    //前缀和
    int num = 0;
    for (int i=1; i<=132; i++) {
        for (int j=1; j<=(i%12)+1; j++) {
            if (days[i][j] != 0) {
                num += days[i][j];
                days[i][j] = num;
            }
        }
        days[i+1][0] = num;
    }
    
    //test;
    /*
    for (int i=1; i<=132; i++) {
        printf("%3d year %8d : ",i,days[i][0]);
        for (int j=1; j<=12; j++) {
            //if (days[i][j] != 0)
                printf("%d ",days[i][j]);
        }
        cout << endl;
    }
    */
    int m1,d1,y1;
    int m2,d2,y2;
    
    while (scanf("%d-%d-%d",&m1,&d1,&y1) != EOF) {
        scanf("%d-%d-%d",&m2,&d2,&y2);
        int ans = calc(m2,d2,y2) - calc(m1,d1,y1) + 1;
        printf("%d\n",ans);
    }
    return 0;
}