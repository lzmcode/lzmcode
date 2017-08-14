#include<stdio.h>  
#include<string.h>  
int main()  
{   
    int n,num1,num2,i,len,k;  
    char a[200000];  
    scanf("%d",&n);  
    getchar();  
    while(n--)  
    {  
        num1=num2=0;  
        while(gets(a),strcmp(a,"##")!=0)  
        {  
            len=strlen(a);  
            for(i=k=0;i<len;i++)  
            {  
                if(a[i]=='\t')  
                {  
                    k+=4;  
                    num2++;  
                    continue;  
                }  
                if(a[i]==' ')  
                {  
                   k++;  
                   continue;  
                }  
                k=0;  
           }  
           num1+=k;  
       }  
       printf("%d tab(s) replaced\n%d trailing space(s) removed\n",num2,num1);  
    }    
     return 0;  
  }  
