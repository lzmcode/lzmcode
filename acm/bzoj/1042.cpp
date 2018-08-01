/**
»›≥‚‘≠¿Ì
 
**/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long;
using namespace std;

int T;
int c[5],d[5];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

int main()
{
    T = read();
    cout << T; 
    return 0;
}


