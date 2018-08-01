#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int i,j,k,sum;
	char sip[40];
	while (T--)
	{
		scanf("%s",&sip);
		for (i=0; i<4; i++)
		{
			k=1; sum=0;
			for (j=i*8+7; j>=i*8; j--)
			{
		 	 	sum+=(sip[j]-'0')*k;
		 	 	k*=2;
			}
			if (i!=3)
                printf("%d.",sum);
            else
                printf("%d\n",sum); 
		}
	}
} 
