#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    int s1,e1,s2,e2;
    puts("Program 3 by team X");
    puts("Initial time  Final time  Passes");
    while(scanf("%d%d%d%d",&s1,&s2,&e1,&e2)!=EOF)
    {
        int m1,m2;
        m1=(s1%12*60+s2);
        m2=(e1%12*60+e2);
        int ans=m2*11/(60*12)-m1*11/(60*12);
        if(m1>m2)
            ans+=11;
        printf("       %02d:%02d       %02d:%02d%8d\n",s1,s2,e1,e2,ans);
    }
    puts("End of program 3 by team X");
    return 0;
}
