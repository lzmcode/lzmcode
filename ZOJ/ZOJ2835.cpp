#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
  
int Map[20][20],Sum[40],Flag[1100];  
  
int Judge(int N)  
{  
    memset(Sum,0,sizeof(Sum));  
    memset(Flag,0,sizeof(Flag));  
    for(int i = 0; i < N; ++i)  
        for(int j = 0; j < N; ++j)  
        {  
            if(!Flag[Map[i][j]])  
                Flag[Map[i][j]] = 1;  
            else  
                return 0;  
        }  
    for(int i = 0; i < N; ++i)  
    {  
        for(int j = 0; j < N; ++j)  
            Sum[i] += Map[i][j];  
    }  
    for(int i = 0; i < N; ++i)  
    {  
        for(int j = 0; j < N; ++j)  
            Sum[i+N] += Map[j][i];  
    }  
    for(int i = 0; i < N; ++i)  
        Sum[N+N] += Map[i][i];  
    for(int i = 0; i < N; ++i)  
        Sum[N+N+1] += Map[i][N-1-i];  
    int tmp = Sum[0];  
    for(int i = 0; i <= 2*N+1; ++i)  
        if(Sum[i] != tmp)  
            return 0;  
    return 1;  
}  
  
int main()  
{  
    int N;  
    while(~scanf("%d",&N) && N)  
    {  
        for(int i = 0; i < N; ++i)  
            for(int j = 0; j < N; ++j)  
                scanf("%d",&Map[i][j]);  
        if(Judge(N))  
            printf("Yes\n");  
        else  
            printf("No\n");  
    }  
  
    return 0;  
}  
