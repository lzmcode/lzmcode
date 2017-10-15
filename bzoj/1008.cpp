#include <cstdio>
#include <iostream>
using namespace std;

#define ll long long
const int MOD = 100003;

ll qpow(ll x, ll n)
{
    //ÃÝº¯Êý¼ÆËã 
    ll ans = 1;
    while (n) {
        if (n & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ans;
}

int main()
{
    ll m,n; 
    cin >> m >> n;
    cout << (MOD + qpow(m, n) % MOD - m * qpow(m - 1, n - 1) % MOD) % MOD << endl;
    return 0;
}
