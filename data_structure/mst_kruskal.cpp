#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int father[MAX]; //并查集 

struct _Edge {
    int from, des;
    int cost;
    friend bool operator < (const _Edge& a, const _Edge& b) {
        return (a.cost > b.cost);
    } 
};
priority_queue<_Edge> SQ; //优先队列 

int find(int x) {
    return (x == father[x] ? x : find(father[x]));
} 

int Kruskal(int n) {
    int mst = 0;
    for (int i=1; i<=n; i++)
        father[i] = i;
    int num = 0;
    while (!SQ.empty() && num != n-1) { //只要N-1条边即可 
        _Edge temp = SQ.top();
        SQ.pop();
        int x = find(temp.from);
        int y = find(temp.des);
        if (x != y) {
            father[y] = find(father[x]);
            mst += temp.cost;
            num++;
        } 
    }
    for (int i=1; i<=n; i++)
        father[i] = find(father[i]);
    return mst;
}

bool judge(int n) {
    int flag = father[1];
    for (int i=2; i<=n; i++) {
        if (flag != find(father[i]))
            return false;
    }
    return true;
}

int main()
{
    int n,e;
    cin >> n >> e;
    while (!SQ.empty())
        SQ.pop();
    while (e--)
    {
        _Edge E;
        int from, des, cost;
        cin >> from >> des >> cost;
        E.from = from;
        E.des = des;
        E.cost = cost;
        SQ.push(E);
    }
    int mst = Kruskal(n);
    if (judge(n))
        cout << mst << endl;
    else
        cout << "none" << endl;
    return 0;
}
