#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 2020 
#define PI 3.1415926
using namespace std;

struct Point{
    int x, y;
    double angle = 0.0; 
};

double calc(double x, double y) {
    if (x >= 0.0 && y == 0.0)
        return 0.0; //在x轴+
    if (x == 0.0 && y >= 0.0)
        return 90.0; //在y轴+
    if (x <= 0.0 && y == 0.0)
        return 180.0; //在x轴+
    if (x == 0.0 && y <= 0.0)
        return 270.0; //在y轴+
    
    if (x > 0 && y > 0) { //第一象限
        return atan(y / x) * 180 / PI;
    }
    
    if (x < 0 && y > 0) { //第二象限 
        return atan(-x / y) * 180 / PI + 90; 
    }
    
    if (x < 0 && y < 0) { //第二象限 
        return atan(-y / -x) * 180 / PI + 180; 
    }
    
    if (x > 0 && y < 0) { //第二象限 
        return atan(x / -y) * 180 / PI + 270; 
    }
}

bool cmp(Point a, Point b) {
    return a.angle < b.angle; 
} 

int main()
{
    int cx, cy;
    double r, r2;
    Point p[MAXN]; 
    int n;
    //freopen("input.txt", "r", stdin);
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
                p[count].angle = calc((double)x - cx, (double)y - cy);
                count++;
            }
        }
        sort(p, p+count, cmp);
        /*
        cout <<  "排序结果" << endl;
        for (int i=0; i<count; i++) {
            cout << p[i].x << " "
                 << p[i].y << " " 
                 << p[i].angle << endl;
        }*/
        //
        int num = count;
        for (int i=0; i<count; i++) {
            if (p[i].angle <= 180) {
                //复制 
                p[num].x = p[i].x;
                p[num].y = p[i].y;
                p[num].angle = p[i].angle + 360;
                num++; 
            }
        }
        /*
        cout <<  "增加后结果" << endl;
        for (int i=0; i<num; i++) {
            cout << p[i].x << " "
                 << p[i].y << " "
                 << p[i].angle << endl;
        }
        */
        int max = 0;
        for (int i=0; i<num; i++) {
            int count1 = 0, count2 = 0;
            double range = p[i].angle;
            for (int j=0; j<num; j++) {
                if (range <= p[j].angle && p[j].angle <= range + 180.0)
                    count1++;
            }
            max = (max > count1) ? max : count1;
        }
        cout << max << endl;
        //cout << "-------------------------" << endl;
    }
    //fclose(stdin);
    return 0;
} 
