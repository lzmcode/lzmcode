#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 51 //������������ֵ 
int main()
{
	int now_i,now_j;
	//��������е�ǰ��λ��
	int time_limit,a_i,a_j,T;
	//����ʱ�����ƣ�����ľ�������д�С 
	int i,j;
	int a[MAXN][MAXN];
	//���뻨�������� 
	int peanuts_count;
	//��ժ���Ļ�������
	
	scanf("%d",&T); 
	while(T--)
	{
		scanf("%d %d %d",&a_i,&a_j,&time_limit);
		peanuts_count = 0;
		for(i = 1;i <= a_i;i++)  //ע��������������ʱ���±��1��ʼ 
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
		//��໨���ĺ��������λ�� 
		int max_peanuts = 0;
		//���Ļ��������� 
		int time_count = 0; 
		//��ǰ�����ѵ�ʱ�� 
		while(time_count < time_limit)
		{
			//time_count = 0;
			max_peanuts = 0;//�����Ļ�����������
			//����������ѡ�����������ģ���¼�µ�ǰ�±��Լ��������� 
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
			if(max_peanuts == 0)    //��������û�л��� 
			break;
			if(now_i == 0)
			now_j = max_j; 
			//�����ʱ���ڴ�·�ϣ������䵱ǰ�����������໨������������ͬ����ô�Ϳ��Գ���ʱ���������ʱ����� 
			if((time_count+max_i+abs(now_i-max_i)+abs(now_j-max_j) + 1)<= time_limit) 
			//��ǰ�����ѵ�ʱ�� +������������ش�·ʱ�ĺ�����+��ǰλ����������ĺ�����Ĳ�+��ǰλ�������������������Ĳ� 
			{
				time_count = time_count+abs(now_i-max_i)+abs(now_j-max_j) + 1;//���ش�·��Ҫ��λʱ��1
				now_i = max_i;
				now_j = max_j;
				peanuts_count = peanuts_count + max_peanuts;
				a[max_i][max_j] = 0;//��Ϊ�Ѿ����꣬���԰�����±�λ�ô��Ļ��������� 
			}
			else
			break; 
		}	
		printf("%d\n",peanuts_count);
	}
	return 0;
}

