#include "ex4.cpp" 
int main()
{
    while (true) {
        int y, m, d;
        cout << "��������ȷ������: ";
        cin >> y >> m >> d;
        MyDate date(y, m, d);
        date.calc(y, m, d);
        cout << "����һ�������Ϊ" << y << "-" << m << "-" << d << endl;
        cout << endl;
    }
    return 0;
}

