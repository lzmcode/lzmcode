#include <iostream>
#include "ex4.h"
#define MAXN 100
using namespace std;

MyDate::MyDate(int y, int m, int d):year(y), month(m), day(d) {}
void MyDate::calc(int &y, int &m, int &d) {
    y = year; m = month; d = day + 1;
    int num[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool flag = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? true : false;
    if (((m == 2) && ((!flag && d == 29) || (flag && d == 30))) || (m != 2 && num[m] < d)) {
        m++; d=1;
        if (m == 13) {
            y++; m = 1;
        }
    }
}

