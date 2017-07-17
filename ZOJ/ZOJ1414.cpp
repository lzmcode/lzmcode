#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int x,y,ans=-1;
		scanf("%d%d",&x,&y);
		if (x == y)
		{
			if (x % 2 == 0)
				ans = x * 2;
			else
		 	 	ans = 2 * x - 1;
			printf("%d\n",ans);
		}
		else if (y == x-2)
		{
			if (x % 2 == 0)
			   ans = 2 * x - 2;
            else
            	ans = 2 * x - 3;
           	printf("%d\n",ans);
		}
		else
			printf("No Number\n"); 
		
	}
	return 0;
}
