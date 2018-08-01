#include <iostream>
using namespace std;
void swap(int &x, int &y) {
    if (x < y) {
        int t = x;
        x = y;
        y = t;
    }
}
int main()
{
    int i1, i2, i3;
    cin >> i1 >> i2 >> i3;
    swap(i1, i2);
    swap(i2, i3);
    swap(i1, i3);
    cout << i1 << " "<< i2 << " " << i3 << endl;
    return 0;
}

