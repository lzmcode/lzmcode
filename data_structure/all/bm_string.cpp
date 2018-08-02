#include <iostream>  
#include <cstring>  
using namespace std;  
  
int Dist(char *t,char ch)  
{  
    int len = strlen(t);  
    int i = len - 1;  
    if(ch == t[i])  
      return len;  
    i--;  
    while(i >= 0)  
    {  
      if(ch == t[i])  
         return len - 1 - i;  
      else  
         i--;  
    }  
    return len;  
}  
  
int BM(char *s,char *t)  
{  
    int n = strlen(s);  
    int m = strlen(t);  
    int i = m-1;  
    int j = m-1;  
    while(j>=0 && i<n)  
    {  
    if(s[i] == t[j])  
    {  
        i--;  
        j--;  
    }  
    else  
    {  
        i += Dist(t,s[i]);  
        j = m-1;  
    }  
    }  
    if(j < 0)  
    {  
        return i+1;  
    }  
    return -1;  
}  
  
int main()  
{  
    char p1[]="substring searching algorithm search";  
    char p2[]="search";  
    cout<<BM(p1,p2);  
    return 0;  
}  
