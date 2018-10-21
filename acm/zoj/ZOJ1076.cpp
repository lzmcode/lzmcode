#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<memory.h>
#include<cstdio>
#include<list>
#include<string>
#include<map>
#include<cmath>
#include <algorithm>
#include <queue>
 
#define NUM 1001
#define maxint 10000000
#define INF 0x3f3f3f3f
#define Max 5001
using namespace std;
 
int c[NUM][NUM];//用邻接矩阵存储边和权
int dist[NUM];
string a;
int k;
 
struct Node
{
    int start;
    int end;
    int index;
};
 
bool cmp(const Node & a , const Node  & b)
{
    return a.end<b.end;
}
 
int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    Node gene[NUM];
    while(cin>>n && n!=0)
    {
        memset(gene, 0, sizeof(gene));
        for(int i = 0;i<n;i++)
        {
            
            cin>>gene[i].start>>gene[i].end;
            gene[i].index= i+1;
        }
        sort(gene, gene+n, cmp);
        int pre = gene[0].end;
        cout<<gene[0].index;
        for(int i = 1;i<n;i++)
        {
            if(gene[i].start>pre)
            {
                cout<<" "<<gene[i].index;
                pre = gene[i].end;
            }
        }
        cout<<endl;
    }
    
}
