#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;

void read(int &x)
{
    int f = 1; x = 0;
    char t = getchar();
    while(t < 48 or t > 57) {
        if (t == '-')
            f = -1;
        t = getchar();    
    }
    while(t >= 48 && t<=57) {
        x = x*10 + t - 48;
        t=getchar();
    }
    x *= f;
}

void init()
{
    ;
}

int main()
{
    int tot;
    read(tot);
    init();
    cout << tot << endl;
    return 0;
}
