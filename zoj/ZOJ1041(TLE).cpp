#include <cstdio>
#include <iostream>
#include <cmath>
#define MAXN 1010
#define PI 3.1415926
using namespace std;

struct Point{
    int x, y;
};

/*
//������뷨 ������ 
double calc(Point a, Point b, int cx, int cy) {
    cout << a.x * b.x + a.y * b.y << endl;
    return a.x * b.x + a.y * b.y;
}
*/

/*
//������뷨2 ������ 
double calc(Point a, Point b, int cx, int cy) {
    return double dis2 = (x - cx) * (x - cx) + (y - cy) * (y - cy);
}
*/

/*
//������뷨3 ���ٱ任 
double calc(Point a, Point b, int cx, int cy) {
    cout << a.x * b.x + a.y * b.y << endl;
    return a.x * b.x + a.y * b.y;
}
*/

//����뷨Ҳ���� 
bool calc(Point a, Point b) {
    //cout << ((double)a.y * (double)b.x <= (double)b.y * (double)a.x) << endl;
    return ((double)a.y * (double)b.x <= (double)b.y * (double)a.x) ? true : false;
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
        r2 = r * r; //����뾶��ƽ�� 
        scanf("%d", &n);
        int count = 0;
        for (int i=0; i<n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            double dis2 = (x - cx) * (x - cx) + (y - cy) * (y - cy); 
            if (dis2 <= r2) {//��Բ�� 
                p[count].x = x - cx;
                p[count].y = y - cy;
                count++;
            }
        }
        /*
        for (int i=0; i<count; i++) {
            cout << p[i].x << " "
                 << p[i].y << " " << endl;
        }
        */
        //������
        int num, max = 0;
        for (int i=0; i<count; i++) {
            num = 0;
            //cout << "����" << endl; 
            for (int j=0; j<count; j++) {
                if (calc(p[i], p[j]))
                    num++;
            }
            if (max < num)
                max = num;
            //cout << "num : " << num << endl; 
        }
        cout <<  max << endl;
        //cout << "-------------------------" << endl;
    }
    fclose(stdin);
    return 0;
} 
