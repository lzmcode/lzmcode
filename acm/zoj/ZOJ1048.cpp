#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int i;
	double x[12],num=0;
	for (i=0;i<12;i++)
	{
		scanf("%lf",&x[i]);
		num+=x[i];
	}
	printf("$%.2lf\n",(double)num/12);
}
