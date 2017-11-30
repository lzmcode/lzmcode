#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class TwoCoord {
    private:
        int x, y; 
        //numerator and denominator
    public:
        TwoCoord();
        TwoCoord(int, int);
        friend TwoCoord operator+(TwoCoord& a, TwoCoord& b);
        friend TwoCoord operator-(TwoCoord& a, TwoCoord& b);
        friend istream &operator>>(istream &is, TwoCoord &p);
        friend ostream &operator<<(ostream &os, TwoCoord &p);
        friend double getDistance(TwoCoord&, TwoCoord&);
};

TwoCoord::TwoCoord(){};
TwoCoord::TwoCoord(int X, int Y):x(X), y(Y){};

TwoCoord operator+(TwoCoord& a, TwoCoord& b) {
    TwoCoord t;
    t.x = a.x + b.x;
    t.y = a.y + b.y; 
    return t;
}

TwoCoord operator-(TwoCoord& a, TwoCoord& b) {
    TwoCoord t;
    t.x = a.x - b.x;
    t.y = a.y - b.y; 
    return t;
}

istream& operator>>(istream &is, TwoCoord &p) {
	cin >> p.x >> p.y;
    return is;
}

ostream& operator<<(ostream &os, TwoCoord &p) {
    cout << "(" << p.x << "," << p.y << ")";
    return os;
}

double getDistance(TwoCoord &a, TwoCoord &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
}

int main()
{
    TwoCoord p1, p2, p3;
    cout << "ÇëÊäÈëp1: ";
    cin >> p1;
    cout << "p1: " << p1 << endl; 
    cout << "ÇëÊäÈëp2: ";
    cin >> p2;
    cout << "p2: " << p2 << endl;
    p3 = p1 + p2;
    cout << "p1+p2=" << p3 << endl;
    cout << "p1-p2=" << p3 << endl;
    cout << "¾àÀë=" <<  getDistance(p1, p2) << endl;
    return 0;
} 
