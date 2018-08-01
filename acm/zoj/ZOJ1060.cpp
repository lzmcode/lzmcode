#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#define mem(a , b) memset(a , b , sizeof(a))
using namespace std ;
const int MAXN = 100 ;
int ind[MAXN] ;
int idtmp[MAXN] ;
char ans[MAXN] ;
vector<int> G[MAXN] ;
int n , m ;
void chu()
{
    mem(ind , 0) ;
    mem(idtmp , 0) ;
    mem(ans , 0) ;
    int i ;
    for(i = 0 ; i <= n ; i ++)
    G[i].clear() ;
}
int topo()
{
    int i ;
    mem(idtmp , 0) ;
    for(i = 0 ; i < n ; i ++)
    {
        idtmp[i] = ind[i] ;
    }
    int k = 0 ;
    int sumd0  ;
    int u , v ;
    bool flag1 , flag2 , flag3 ;
    flag2 = false ;
    flag3 = true ;
    for(k = 0 ; k < n ; k ++)
    {
        sumd0 = 0 ;
        for(i = 0 ; i < n ; i ++)
        {
            if(idtmp[i] == 0)
            {
                sumd0 ++ ;
                u = i ;
            }
        }
        if(sumd0 > 0)
        {
            ans[k] = u + 'A';
            idtmp[u] -- ;
            for(int j = 0 ; j < G[u].size() ; j ++)
            {
                v = G[u][j] ;
                idtmp[v] -- ;
            }
            if(sumd0 > 1)
            {
                flag2 = true ;
            }
        }
        else
        {
            flag3 = false ;
            break ;
        }
    }
    if(!flag3)
    {
        return 3 ;
    }
    else
    {
        if(flag2)
        {
            return 2 ;
        }
        else
        {
            return 1 ;
        }
    }
}
void init()
{
    chu() ;
    int i ;
    char a , op , b ;
    bool f = false ;
    for(i = 0 ; i < m ; i ++)
    {
        cin >> a >> op >> b ;
        if(f)
        continue ;
        int ta , tb ;
        ta = a - 'A' ;
        tb = b - 'A' ;
        G[ta].push_back(tb) ;
        ind[tb] ++ ;
        int pan ;
        pan = topo() ;
        if(pan == 3)
        {
            f = true ;
            printf("Inconsistency found after %d relations.\n" , i + 1) ;
        }
        else if(pan == 1)
        {
            ans[n] = '\0' ;
            f = true ;
            printf("Sorted sequence determined after %d relations: %s.\n" , i + 1 , ans) ;
        }
        else if(pan == 2 && i == m - 1)
        {
            puts("Sorted sequence cannot be determined.") ;
        }
    }
}
int main()
{
    while (scanf("%d%d" , &n , &m) != EOF)
    {
        if(n == 0 && m == 0)
        break ;
        init() ;
    }
    return 0 ;
}
