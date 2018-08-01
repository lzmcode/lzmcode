#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 1010
#define PI 3.1415926
using namespace std;

struct Point{
    int x, y;
};

bool cmp(const Point p1, const Point p2) {
    return atan2(p1.y, p1.x) < atan2(p2.y, p2.x);
}

int main()
{
    int cx, cy;
    double r, r2;
    Point p[MAXN]; 
    int n;
    freopen("input.txt", "r", stdin);
    while (scanf("%d%d%lf", &cx, &cy, &r)){
        if (r < 0) break;
        r2 = r * r; //计算半径的平方 
        scanf("%d", &n);
        int count = 0;
        for (int i=0; i<n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            double dis2 = (x - cx) * (x - cx) + (y - cy) * (y - cy); 
            if (dis2 <= r2) {//在圆内 
                p[count].x = x - cx;
                p[count].y = y - cy;
                count++;
            }
        }
        
        for (int i=0; i<count; i++) {
            cout << p[i].x << " "
                 << p[i].y << " " << endl;
        }
        
        sort(p, p+count, cmp);
        cout << "---排序--------" << endl;
        for (int i=0; i<count; i++) {
            cout << p[i].x << " "
                 << p[i].y << " " << endl;
        }
        cout << "-------------------------" << endl;
    }
    fclose(stdin);
    return 0;
} 
