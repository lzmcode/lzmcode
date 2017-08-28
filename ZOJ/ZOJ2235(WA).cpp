#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAXN 55
using namespace std;

struct node{
    int x,y;
    int w;
};

bool cmp(node a,node b)
{
    return (a.w > b.w);
}

inline int abs(int x)
{
    return (x > 0 ? x : -x);
}

int dis(node a,node b)
{
    return (abs(a.x-b.x) + abs(a.y-b.y));
}

int main()
{
    //freopen("2235.in","r+",stdin);
    int T;
    cin >> T;
    while (T--)
    {
        int m,n,k;
        cin >> m >> n >> k;
        int map[MAXN][MAXN];
        vector<node> num;
        num.clear();
        struct node temp;
        
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                scanf("%d",&map[i][j]);
                if (map[i][j] != 0)
                {
                    temp.x = i;
                    temp.y = j;
                    temp.w = map[i][j];
                    num.push_back(temp);
                }
            }
        }
        sort(num.begin(),num.end(),cmp);
        
        int ans = 0;
        if (k >= 2*(num[0].x + 1) + 1) //可以到达第一个位置
        {
            k -= (num[0].x+2);
            ans += num[0].w;
            //cout << num[0].x << " " << num[0].y << " " << num[0].w << " " << (num[0].x+2) << endl;
        }
        if (k > 0) //继续向下一个节点
        {
            for (int i=1; i<num.size(); i++)
            {
                int cost = dis(num[i],num[i-1]); //欧几里德距离
                if (cost + 1 + (num[i].x+1) <= k) //还可以走到下一个节点
                {
                    ans += num[i].w;
                    k -= (cost+1);
                    //cout << num[i].x << " " << num[i].y << " " << num[i].w  << " "  << cost+1 << endl;
                }
                else //走不到了
                {
                    break;
                }
            }
        }
        printf("%d\n",ans);
        /*
        //test
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                printf("%3d",map[i][j]);
            }
            printf("\n");
        }
        for (int i=0; i<num.size(); i++)
        {
            printf("%d %d %d \n",num[i].x,num[i].y,num[i].w);
        }       
        printf("\n");
        */
    }
    //fclose(stdin);
    return 0;
}
