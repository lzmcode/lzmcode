#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 30050
#define INF (~(0x1<<31))
using namespace std;

int u[MAXN];
int t[MAXN];

int FindRoot(int x)
{
    while (u[x] != x)
    {
        x = u[x];
    }
    return x;
}
int main()
{
    freopen("1789.txt", "r", stdin);
    int n,m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            return 0;
        
        //init
        for (int i=0; i<n; i++) //��ʼ�����нڵ�ĸ��ڵ�Ϊ�Լ� 
            u[i] = i;
        
        //work 
        for (int i=0; i<m; i++) //����ÿһ������ 
        {
            int k;
            int now, min = INF;
            scanf("%d", &k);
            for (int j=0; j<k; j++)
            {
                scanf("%d", &t[j]);
                if (t[j] < min)
                    min = t[j]; //��ÿһ�����Сֵ
            }
            for (int j=0; j<k; j++)
            {
                if (u[t[j]] > min)
                    u[t[j]] = min;  //ÿһ�����������ָ����Сֵ
            }
        }
        
        //test
        /*
        cout << "����" << endl; 
        for (int i=0; i<n; i++)
        {
            printf("%d ",u[i]);
        }
        printf("\n");
        */
        int ans = 0;
        for (int i=0; i<n; i++)
        {
            if (0 == FindRoot(i))
            {
                //cout << i <<" ";
                ans++;   
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    return 0;
}






















