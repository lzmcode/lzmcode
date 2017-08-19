#include <cstdio>
#include <iostream>
int main()
{
    int n;
    while (scanf("%d",&n) != EOF && n != -1)
    {
        int miles = 0;
        int now = 0;
        int v,h;
        for (int i=0; i<n; i++)
        {
            scanf("%d%d",&v,&h);
            miles += v * (h - now);
            now = h;
        }
        printf("%d miles\n",miles);
    }
    return 0;
}
