#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
int f(char ch)
{
	if (ch==' ') return 0;
	return (ch-'A'+1);
}
int main()
{
	char str[256];
	int i,len,sum;
	while (gets(str) && str[0]!='#')
	{
		len=strlen(str);
		sum=0;
		for (i=1;i<=len;i++)
			sum+=i*f(str[i-1]);
		printf("%d\n",sum);
	}
	return 0;
}
