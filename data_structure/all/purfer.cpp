/*
����purfer��������ʣ�ÿ����һ�����ӦΨһһ��n-2���ȵ�purfer sequence
���ﲻҪ��������ƣ�����n-2��ÿ��λ����n��ѡ�񣬴�Ϊn^(n-2) mod M 
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
