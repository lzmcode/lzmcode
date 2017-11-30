#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Rational {
    private:
        int num, den; 
        //numerator and denominator
    public:
        Rational();
        Rational(int, int);
        friend Rational operator+(Rational& a, Rational& b);
        friend Rational operator-(Rational& a, Rational& b);
        friend Rational operator*(Rational& a, Rational& b);
        friend Rational operator/(Rational& a, Rational& b);
        friend istream &operator>>(istream &is, Rational &r);
        friend ostream &operator<<(ostream &os, Rational &r);
};

int gcd(int x, int y) {
    //this function back gcd 
    int big = (x > y) ? x : y;
    int small = (x < y) ? x : y;
    return (small == 0) ? big : gcd(small, big % small); 
}

Rational::Rational(){};
Rational::Rational(int N, int D):num(N), den(D){};

Rational operator+(Rational& a, Rational& b) {
    Rational t;
    t.num = a.num * b.den + a.den * b.num;
    t.den = a.den * b.den;
    int gcdnum = gcd(t.num, t.den);
    t.num = t.num / gcdnum;
    t.den = t.den / gcdnum;
    return t;
}

Rational operator-(Rational& a, Rational& b) {
    Rational t;
    t.num = a.num * b.den - a.den * b.num;
    t.den = a.den * b.den;
    int gcdnum = gcd(t.num, t.den);
    t.num = t.num / gcdnum;
    t.den = t.den / gcdnum;
    return t;
}

Rational operator*(Rational& a, Rational& b) {
    Rational t;
    t.num = a.num * b.num;
    t.den = a.den * b.den;
    int gcdnum = gcd(t.num, t.den);
    t.num = t.num / gcdnum;
    t.den = t.den / gcdnum;
    return t;
}

Rational operator/(Rational& a, Rational& b) {
    Rational t;
    t.num = a.num * b.den;
    t.den = a.den * b.num;
    int gcdnum = gcd(t.num, t.den);
    t.num = t.num / gcdnum;
    t.den = t.den / gcdnum;
    return t;
}

istream& operator>>(istream &is, Rational &r) {
    is >> r.num >> r.den;
    return is;
}

ostream& operator<<(ostream &os, Rational &r) {
    if (r.num == 0) {
        cout << 0;
        return os;
    }
    if (0 == r.num % r.den)
        cout << r.num / r.den;
    else
        os << r.num << "/" << r.den;
    return os;
}

int main()
{
    Rational r1(5, 10);
    Rational r2(5, 10);
    cout << r1 << endl;
    cout << r2 << endl;
    
    Rational r3;
    r3 = r1 + r2;
    cout << r3 << endl;
    r3 = r1 - r2;
    cout << r3 << endl;
    r3 = r1 * r2;
    cout << r3 << endl;
    r3 = r1 / r2;
    cout << r3 << endl;
    
    return 0;
} 
