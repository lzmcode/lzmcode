#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double DISTANCE = 4.50;
    while (true) {
        int n;
        scanf("%d",&n);
        if (n == 0) break;
        double v,t,x;
        double min = 1e100;
        for (int i=0; i<n; i++) {
            scanf("%lf%lf",&v,&t);
            if (t >= 0 && (x = DISTANCE * 3600 / v + t) < min)
                min = x;
        }
        printf("%.0lf\n",ceil(min));
    } 
    return 0;
} 
