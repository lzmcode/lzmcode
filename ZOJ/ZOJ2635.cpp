#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[105][30];
int main()
{
	int T; cin>>T;
	char key[30];
	char cipher[105];
	int i,j,k,p,min,minwhere,line,last;
	int lenkey,lencip;
	while (T--)
	{
		scanf("%s",&key);
		scanf("%s",&cipher);
		
		lenkey = strlen(key);
		lencip = strlen(cipher);
		
		line = lencip / lenkey;
		last = lencip % lenkey;
		//cout<<"last: "<<last<<endl;
		p=0;
		while (p < lencip) //还有字母没有放进去;
		{
			min=255;
			for (i=0; i<lenkey; i++)
			{
				if (key[i] < min)
				{
					min = key[i];
					minwhere = i;
				}
			}
			key[minwhere]='Z'+1;
			/* 
			cout<<"min: "<<min<<endl;
			cout<<"minwhere: "<<minwhere<<endl;
			cout<<key<<endl;
			*/ 
			for (i=0; i<line; i++)
				s[i][minwhere] = cipher[p++];
			if (minwhere < last)
				s[line+1][minwhere] = cipher[p++];
		}
		/*
		cout<<"line: "<<line<<endl;
		cout<<"lenkey: "<<lenkey<<endl;
		cout<<"lencip: "<<lencip<<endl;
		for (i=0;i<line;i++)
		{
			for (j=0;j<lenkey;j++)
				cout<<s[i][j];
			cout<<endl;
		}
		for (j=0;j<last;j++)
			cout<<s[line+1][j];
		*/
		for (i=0;i<line;i++)
		{
			for (j=0;j<lenkey;j++)
				printf("%c",s[i][j]+32); 
		}
		for (i=0;i<last;i++)
			printf("%c",s[line+1][i]+32);
		printf("\n");
	}
	return 0;
}
