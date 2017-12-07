#include <cstdio>  
#include <cstring>  
#include <cstdlib>
#include <iostream>  
using namespace std;
struct Tree{  
    int num;  
    char s[15];  
    struct Tree *next[27];  
};  
struct Tree *root;  
void Initialize()  //初始化全部为空 
{  
    root = (struct Tree*)malloc(sizeof(struct Tree));  
    root->num = 0;  
    for(int i = 0 ; i < 26 ; ++i)  
        root->next[i] = NULL;  
}  
void Insert(char *s1,char *s2)//以s1为基础建立字典树   
{  
    int len = strlen(s1);  
    struct Tree *node,*p = root;  
      
    for(int i = 0 ; i < len ; ++i){  
        int pos = s1[i] - 'a';  
        if(p->next[pos] == NULL){   
            node = (struct Tree*)malloc(sizeof(struct Tree));  
            for(int j = 0 ; j < 26 ; ++j){  
                node->next[i] = NULL;  
                node->num = 0;  
            }  
            p->next[pos] = node;  
        }  
        p = p->next[pos];  
    }   
    p->num = 1;  //标记为1 
    strcpy(p->s,s2);  //存储字符串待输出 
}  
void Find(char *s)  
{  
    int len = strlen(s);  
    int i;  
    struct Tree *p = root;  
      
    for(i = 0 ; i < len ; ++i){  
        int pos = s[i] - 'a';  
        if(p->next[pos] != NULL)  
            p = p->next[pos];  
        else  
            break;  
    }  
    if(p->num == 1) //为1即表示如果存在 
        printf("%s\n",p->s);  
    else  
        printf("eh\n");  
}  
int main()  
{  
    char str[30];  
      
    Initialize();  
    while(gets(str)){  
        if(strlen(str) == 0)  
            break;  
        char str1[12],str2[12];  
        memset(str1,0,sizeof(str1));  
        memset(str2,0,sizeof(str2));  
        for(int i = 0 ; i < strlen(str) ; ++i){  
            if(str[i] == ' '){  
                strncpy(str1,str,i);  
                str1[i] = '\0';  
                strncpy(str2,str+i+1,strlen(str)-i-1);  
                str2[strlen(str) - i - 1] = '\0';  
            }  
        }  
        Insert(str2,str1);  
    }  
    while(scanf("%s",str) != EOF)  
        Find(str);  
    return 0;  
}  
