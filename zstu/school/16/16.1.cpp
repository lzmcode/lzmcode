#include <iostream>
using namespace std;

class Complex {
    private:
        double r, i;
    public:
        Complex();
        Complex(double, double);
        //Complex operator=(Complex& a);
        //Complex& operator-();
        friend Complex& operator-(Complex &a);
        void display();
};

Complex::Complex(double R, double I):r(R), i(I){};
/*
Complex Complex::operator=(Complex &a) {
    r = a.r;
    i = a.i;
    return (*this);
}
Complex& Complex::operator-() {
    r = -r;
    i = -i;
    return (*this);
}
*/
Complex& operator-(Complex &a) {  
   a.r = -a.r;
   a.i = -a.i;
   return a;
}

void Complex::display() {
    cout << r;
    if (i > 0) cout << "+";
    cout << i << "i" << endl;
}

int main()
{
    Complex c1(1, 2);
    c1.display();
    Complex c2(3, 4);
    c2 = c1;
    c2.display();
    (-c2).display();
    return 0;
} 
