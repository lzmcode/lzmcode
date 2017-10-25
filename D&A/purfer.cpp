/*
运用purfer编码的性质，每棵树一定会对应唯一一种n-2长度的purfer sequence
这里不要求度数限制，所以n-2的每个位置有n种选择，答案为n^(n-2) mod M 
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
using namespace std;
const int M=10003; 

int T;
int n;
int qk(int x,int y)
{
	int res=1;
	while (y) {
		if(y&1)res=((res%M)*(x%M))%M;
		y>>=1;
		x=((x%M) * (x%M)) % M;
	}
	return res;
}
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		printf("%d\n",qk(n,n-2));
	}
	return 0;
}
