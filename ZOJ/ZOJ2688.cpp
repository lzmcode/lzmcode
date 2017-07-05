#include <cstdio>
#include <cstring>
#include <iostream>
const double INF = 1e10;
using namespace std;
double x[100050][5];
int main()
{
	int op[10];
	double min,max,ans,final=-1.0;
	int i,j,k,n,now;
	while (scanf("%d",&n)!=EOF && n!=0)
	{
		for (i=0;i<n;i++)
		{
			for (j=0;j<5;j++)
			{
				scanf("%lf",&x[i][j]);
			}
		}
		
		for (i=0;i<32; i++)
		{
			//set op;
			memset(op,0,sizeof(op));
			now=i; k=0;
			while (now>0)
			{
				op[k++] = now % 2;
				now /= 2;
			}
			//for (j=0;j<5;j++)
			//	printf("%d",op[j]);
			//printf("\n");
			min=INF; max=-INF;
			for (j=0; j<n; j++)
			{
				ans=0.0;
				for (k=0; k<5; k++)
				{
					if (op[k])
						ans+=x[j][k];
					else
						ans-=x[j][k];
				}
				if (max < ans) max=ans;
				if (min > ans) min=ans;
			}
			if (max-min > final)
				final = max -min;
		}
		printf("%.2f\n",final); 
	}
	return 0; 
} 
