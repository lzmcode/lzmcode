#include <iostream>  
#include <cstring>  
#include <sstream> 
#define I_N_MAX 10000  
using namespace std;  
  
void KmpSearch(char[], char[], int[]);  
void GetNextval(char[], int next[]);  
  
int main(){  
    int nextarr[I_N_MAX];  
    char cArr1[I_N_MAX];  
    char cArr2[I_N_MAX];  
    cin >> cArr1;  
    cin >> cArr2;  
    GetNextval(cArr1, nextarr);  
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
    while (j < pLenth - 1)  
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
}  
