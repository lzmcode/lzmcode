#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 51 //矩阵的最大行列值 
int main()
{
	int now_i,now_j;
	//定义矩阵中当前的位置
	int time_limit,a_i,a_j,T;
	//定义时间限制，输入的矩阵的行列大小 
	int i,j;
	int a[MAXN][MAXN];
	//填入花生的数量 
	int peanuts_count;
	//采摘到的花生数量
	
	scanf("%d",&T); 
	while(T--)
	{
		scanf("%d %d %d",&a_i,&a_j,&time_limit);
		peanuts_count = 0;
		for(i = 1;i <= a_i;i++)  //注意往矩阵填数的时候下标从1开始 
		{
			for(j = 1;j <= a_j;j++)
			{
				scanf("%d",&a[i][j]); 
			}
		}
		now_i = 0;
		now_j = 0;
		int num_peanuts = 0; 
		int max_i = 0,max_j = 0;  
		//最多花生的横纵坐标的位置 
		int max_peanuts = 0;
		//最多的花生的数量 
		int time_count = 0; 
		//当前所花费的时间 
		while(time_count < time_limit)
		{
			//time_count = 0;
			max_peanuts = 0;//将最多的花生重置清零
			//遍历矩阵，挑选花生个数最多的，记录下当前下标以及花生个数 
			for(i = 1;i <= a_i;i++)
			{
				for(j = 1;j <= a_j;j++)
				{
					if(max_peanuts < a[i][j])
					{
						max_peanuts = a[i][j];
						max_i = i;
						max_j = j; 
					}
				}
			}
			if(max_peanuts == 0)    //花生田里没有花生 
			break;
			if(now_i == 0)
			now_j = max_j; 
			//如果此时还在大路上，则让其当前的纵坐标和最多花生的纵坐标相同，那么就可以出发时最近，所花时间最短 
			if((time_count+max_i+abs(now_i-max_i)+abs(now_j-max_j) + 1)<= time_limit) 
			//当前所花费的时间 +从最大花生处返回大路时的横坐标+当前位置与最大花生的横坐标的差+当前位置与最大花生处的纵坐标的差 
			{
				time_count = time_count+abs(now_i-max_i)+abs(now_j-max_j) + 1;//返回大路还要单位时间1
				now_i = max_i;
				now_j = max_j;
				peanuts_count = peanuts_count + max_peanuts;
				a[max_i][max_j] = 0;//因为已经加完，所以把最大下标位置处的花生数清零 
			}
			else
			break; 
		}	
		printf("%d\n",peanuts_count);
	}
	return 0;
}

