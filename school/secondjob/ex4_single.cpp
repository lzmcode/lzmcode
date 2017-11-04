#include <iostream>
#define MAXN 100
using namespace std;

class MyDate {
    private:
        int year, month, day;
    public:
        MyDate(int y, int m, int d);
        void calc(int &y, int &m, int &d);
        int queryYear() { return year; }
        int queryMonth() { return month; }
        int queryDay() { return day; }
};

MyDate::MyDate(int y, int m, int d):year(y), month(m), day(d) {}
void MyDate::calc(int &y, int &m, int &d) {
    y = year; m = month; d = day;
    int num[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool flag = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? true : false;
    if (day < num[month]) {
        d++;
    } else {
        if (flag && m == 2) {
            d = 29;
        } else {
            d = 1; m++;
        }
        if (m == 13) {
            y++; m = 1;
        }
    }
}

int main()
{
    while (true) {
        int y, m, d;
        cout << "请输入正确的日期: ";
        cin >> y >> m >> d;
        MyDate date(y, m, d);
        date.calc(y, m, d);
        cout << "增加一天后日期为" << y << "-" << m << "-" << d << endl;
        cout << endl;
    }
    return 0;
}
