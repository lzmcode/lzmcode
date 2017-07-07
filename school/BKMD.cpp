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
	int t;            //编号 
	char id[20];      //学号 
	char cla[50];     //班级 
	char cur[50];     //课程
	char teacher[20]; //教师 
	char dep[20];     //系别 Department
	char time[100];   //时间
	char address[20]; //地点 
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
	printf("补考号:%d\t学号:%s\t班级%s\t姓名:%s\t课程:%s\n",exam[i].t, exam[i].id, exam[i].cla, name, exam[i].teacher);
	printf("指导老师:%s\t所在系:%s\t考试时间:%s\t考试地点:%s\n",exam[i].cur, exam[i].dep, exam[i].time, exam[i].address, exam[i].address);
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
		printf("%s %s同学是学霸，没有挂科！\n",str,name);
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
