#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 10050
using namespace std;

void GetNextval(char p[], int nextval[])
{
    int pLen = strlen(p);
    nextval[0] = -1;
    int j = 0, k = -1;
    while (j < pLen-1)
    {
        if (k == -1 || p[j] == p[k])
        {
            j++;k++;
            if (p[j] != p[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }   
}

void KMPSearch(char s[], char p[], int nextval[])
{
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i = 0, j = 0;
    while (i < sLen && j < pLen)
    {
        if (j == -1 || s[i] == p[j])
        {
            i++; j++;
        }
        else
            j = nextval[j];
    }
    if (j == pLen)
        cout<<i-j+1<<" "<<i<<endl;
    else
        cout<<"none"<<endl; 
}

int main()
{
    char s[MAX], p[MAX];
    int nextval[MAX];
    cin>>s;
    cin>>p;
    GetNextval(p, nextval);
    KMPSearch(s, p, nextval); 
    return 0; 
} 
