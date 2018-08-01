#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b,c;
        cin >> a >> b >>c;
        //300 100 50
        double min = 0, max = 0;
        int combo = 0;
        
        for (int i=0; i<a; i++)
            min += 300 * ((combo++)*2 + 1);
        for (int i=0; i<b; i++)
            min += 100 * ((combo++)*2 + 1);
        for (int i=0; i<c; i++)
            min += 50 * ((combo++)*2 + 1);
        
        combo = 0;
        for (int i=0; i<c; i++)
            max += 50 * ((combo++)*2 + 1);
        for (int i=0; i<b; i++)
            max += 100 * ((combo++)*2 + 1);
        for (int i=0; i<a; i++)
            max += 300 * ((combo++)*2 + 1);
        
        printf("%.0lf %.0lf\n",min,max);
    }
    return 0;
}
