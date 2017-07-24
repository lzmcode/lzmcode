#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    int pre,now,i,ans;
    while (scanf("%d", &n)!=EOF && n!=0)
    {
        scanf("%d", &pre);
        ans = pre * 6 + n * 5;
        for (i=2; i<=n; i++)
        {
            scanf("%d", &now);
            if (now > pre)
                ans += 6 * (now - pre);
            else ans += 4 * (pre - now);
            pre = now; 
        }
        printf("%d\n", ans);
    }
    return 0;
}
