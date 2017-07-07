#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define num 5725
#define times 1901
using namespace std;

struct STUDENT{
	char id[20];
	char name[20];
}stu[10050];

struct EXAM{
	int t;            //��� 
	char id[20];      //ѧ�� 
	char cla[50];     //�༶ 
	char cur[50];     //�γ�
	char teacher[20]; //��ʦ 
	char dep[20];     //ϵ�� Department
	char time[100];   //ʱ��
	char address[20]; //�ص� 
}exam[2000];

void print(int i)
{
	char name[20];
	for (int j=0; j<num; j++)
	{
		if (strcmp(stu[j].id, exam[i].id) == 0)
		{
			strcpy(name,stu[j].name);
		}
	}
	printf("--------------------------------------------");
	printf("--------------------------------------------\n");
	printf("������:%d\tѧ��:%s\t�༶%s\t����:%s\t�γ�:%s\n",exam[i].t, exam[i].id, exam[i].cla, name, exam[i].teacher);
	printf("ָ����ʦ:%s\t����ϵ:%s\t����ʱ��:%s\t���Եص�:%s\n",exam[i].cur, exam[i].dep, exam[i].time, exam[i].address, exam[i].address);
} 

void choice_id(char str[])
{
	int flag=0;
	for (int i=0; i<times; i++)
	{
		if (strcmp(exam[i].id, str) == 0)
		{
			print(i);
			flag=1;
		}
	}
	
	if (!flag)
	{
		char name[20];
		for (int j=0; j<num; j++)
		{
			if (strcmp(stu[j].id, str) == 0)
			{
				strcpy(name,stu[j].name);
			}
		}
		printf("%s %sͬѧ��ѧ�ԣ�û�йҿƣ�\n",str,name);
	}
}

void choice_name(char str[])
{
	for (int i=0; i<num; i++)
	{
		if (strcmp(stu[i].name, str) == 0)
		{
			choice_id(stu[i].id);
		}
	}
}

int main()
{
	FILE *ps,*pl,*pw; //s = student; l = list;
	ps = fopen("name.txt","r");
	pl = fopen("bkmd.txt","r");
	pw = fopen("write.txt","w");
	
	int i,j,k;
	 
	for (i=0; i<num; i++)
	{
		fscanf(ps,"%s %s", stu[i].id, stu[i].name );
	}
	
	for (i=0; i<times; i++)
	{
		fscanf(pl, "%d", &exam[i].t);
		fscanf(pl, "%s", exam[i].id);
		fscanf(pl, "%s", exam[i].cla);
		fscanf(pl, "%s", exam[i].teacher);
		fscanf(pl, "%s", exam[i].cur);
		fscanf(pl, "%s", exam[i].dep);
		fscanf(pl, "%s", exam[i].time);
		fscanf(pl, "%s", exam[i].address);
	}

	char str[20];
	while (scanf("%s",&str) != EOF)
	{
		if (str[0] == 'X')
			choice_id(str);
		else
			choice_name(str);
		printf("\n"); 
	}
	fclose(ps);
	fclose(pl);
	fclose(pw);
}
