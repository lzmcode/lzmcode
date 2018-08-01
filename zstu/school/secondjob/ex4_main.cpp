#include "ex4.cpp" 
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

