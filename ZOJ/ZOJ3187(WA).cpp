#include <cstdio>
#include <iostream>
using namespace std;

struct Node{
    int x,y;
    int s1,p1,s2,p2;   
}r[105];

int GetMoney(int i, int mid)
{
    int need = r[i].x * mid - r[i].y;
    
    //if all but small;
    int small,big;
    if (need % r[i].s1 == 0)
        small = need /r[i].s1;
    else
        small = need /r[i].s1 + 1;
    int min = small * r[i].p1;
    
    for (int k=0; k<=small; k++)
    {
        int bigneed = need - k * r[i].s1;
        if (bigneed % r[i].s2 == 0)
            big = bigneed / r[i].s2;
        else
            big = bigneed / r[i].s2 +1;
        int nowcost = k * r[i].p1 + big * r[i].p2;
        if (nowcost < min)
            min = nowcost; 
    }
    return min;
}

int main()
{
    int n,m;
    while (scanf("%d%d", &n, &m) != EOF && (n != 0 && m != 0))
    {
        int i;
        for (i=0; i<n; i++)
        {
            scanf("%d%d", &r[i].x, &r[i].y);
            scanf("%d%d", &r[i].s1, &r[i].p1);
            scanf("%d%d", &r[i].s2, &r[i].p2);
        }
        int min = 0, max = 100000;
        int mid;
        int cost;
        while (max - min > 1)
        {
            mid = (max + min) / 2;
            //cout<<"min="<<min<<" max="<<max<<" mid="<<mid<<endl;
            cost = 0;
            for (i=0; i<n; i++)
            {
                cost += GetMoney(i,mid);
            }
            if (cost > m)
            {
                //people too much; 
                max = mid;
            }
            else
            {
                //people too less;
                min = mid;
            } 
        }
        cout<<mid<<endl; 
    }
    return 0;
}
