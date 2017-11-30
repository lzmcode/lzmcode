#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Time {
    private:
        int h, m, s;
    public:
        Time();
        Time(int, int, int);
        Time& operator++();
        Time& operator++(int);
        Time& operator--();
        Time& operator--(int);
        friend istream &operator>>(istream &is, Time &t);
        friend ostream &operator<<(ostream &os, Time &t);
        void display();
};

Time::Time(){};
Time::Time(int H=0, int M=0, int S=0):h(H), m(M), s(S) {};

Time& Time::operator++() {
	s++;
    if (s >= 60) { m++; s=0; }
    if (m >= 60) { h++; m=0; }
	return *this;
}

Time& Time::operator++(int) {
	Time tmp(h,m,s);
	s++;
    if (s >= 60) { m++; s=0; }
    if (m >= 60) { h++; m=0; }
    return tmp;
}

Time& Time::operator--() {
    s--;
    if (s <= 0) { m--; s = 59; }
    if (m <= 0) { h--; m = 59; }
    if (h < 0) { h = 23; m = 59; s = 59; } 
	return *this;
}

Time& Time::operator--(int) {
	Time tmp(h,m,s);
    s--;
    if (s <= 0) { m--; s = 59; }
    if (m <= 0) { h--; m = 59; }
    if (h < 0) { h = 23; m = 59; s = 59; } 
    return tmp;
}

istream& operator>>(istream &is, Time &t) {
	cout << "请输入小时.分和秒: ";
	cin >> t.h >> t.m >> t.s;
    return is;
}

ostream& operator<<(ostream &os, Time &t) {
    cout << " " << t.h << ":" << t.m << ":" << t.s;
    return os;
}

int main()
{
    Time t1(1, 2, 59);
    cout << t1 << endl;
    ++t1;
    cout << t1 << endl;
    Time t2(1, 59, 59);
    cout << t2 << endl;
    t2++;
    cout << t2 << endl;
    
	Time t3(1, 0, 0);
	t3--;
	cout << t3 << endl;
	
	Time t4(0, 0, 0);
	t4--;
	cout << t4 << endl;
    
    Time t();
    cin >> t;
    cout << "t1时间为: ";
	cout << "++t1时间为: ";
	cout << "t2时间为: ";
	cout << "t2时间为"; 
	return 0;
} 
