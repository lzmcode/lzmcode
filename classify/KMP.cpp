#include <iostream>  
#include <cstring>  
#include <sstream> 
#define I_N_MAX 10000  
using namespace std;  
  
void KmpSearch(char[], char[], int[]);  
void GetNextval(char[], int next[]);  
void GetNext(char* p,int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀  
        if (k == -1 || p[j] == p[k])   
        {  
            ++k;  
            ++j;  
            next[j] = k;  
        }  
        else   
        {  
            k = next[k];  
        }  
    }
    for (int i=0; i<pLen-1; i++)
		cout<< next[i] <<" "; 
}  
int main(){  
    int nextarr[I_N_MAX];
	int next[I_N_MAX]; 
    char cArr1[I_N_MAX];  
    char cArr2[I_N_MAX];  
    cin >> cArr1;  
    cin >> cArr2;  
    GetNext(cArr2,next);
    GetNextval(cArr2, nextarr);  
    KmpSearch(cArr1, cArr2, nextarr);   
}  

void KmpSearch(char s[], char p[], int nextarr[]){  
  
    int i = 0, j = 0;  
    int sLenth = strlen(s);  
    int pLenth = strlen(p);  
    while (i < sLenth&&j < pLenth)  
    {  
        if (j == -1 || s[i] == p[j]){  
            i++, j++;  
        }  
        else{  
            j = nextarr[j];  
        }  
    }  
    if (j == pLenth){  
        stringstream ss;  
        int temp = i - j + 1;  
        ss << "第" << temp << "个字母到第" << i << "个字母为匹配字符";  
        cout << ss.str()<<endl;  
    }  
    else  
    {  
        cout << "None" << endl;  
    }  
}  

void GetNextval(char p[], int nextarr[]){  
  
    int pLenth = strlen(p);  
    nextarr[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLenth-1)  
    {  
        if (k == -1 || p[j] == p[k]){  
            j++; k++;  
            if (p[j] != p[k]){  
                nextarr[j] = k;  
            }  
            else  
            {  
                nextarr[j] = nextarr[k];  
            }  
        }  
        else  
        {  
            k = nextarr[k];  
        }  
    }
	cout<<endl;
    for (int i=0; i<pLenth-1; i++)
		cout<< nextarr[i] <<" "; 
}  
