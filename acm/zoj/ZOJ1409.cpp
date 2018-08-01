#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
set <int> s;
set <int> ::iterator it;
int band[105][105], price[105][105], m[105];
int main()
{
    int T, n, i, j;
    scanf("%d",&T);
    while(T--) 
    {
        scanf("%d",&n);
        s.clear();
        for(i = 0; i < n; i++)
        {
            scanf("%d",&m[i]);
            for(j = 0; j < m[i]; j++)
            {
                scanf("%d%d",&band[i][j], &price[i][j]);
                s.insert(band[i][j]);
            }  
        }  
        double rate = 0;
        for(it = s.begin(); it != s.end(); it++)
        {
            int k = *it, sum_price = 0;
            for(i = 0; i < n; i++)
            {
                int min_price = 0x3fffff;
                for(j = 0; j < m[i]; j++)
                {
                    if(band[i][j] >= k && price[i][j] < min_price)
                    {
                        min_price = price[i][j];
                    }
                }
                sum_price += min_price;
            }
            if(k * 1.0 / sum_price > rate)
                rate = k * 1.0 / sum_price;
        }
        printf("%.3lf\n",rate);
    }
    return 0;  
}  
