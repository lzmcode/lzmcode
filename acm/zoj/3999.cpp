#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 1010

int  p1[MAXN],   p2[MAXN];     //exp
char op1[MAXN],  op2[MAXN];    //operate 
int  coe1[MAXN], coe2[MAXN];   //coefficient

int min(int x, int y) {
    return x < y ? x : y;
}

int find(char op, string str) {
    int strLen = str.length();
    for (int i=1; i<strLen; i++) {
        if (str[i] == op)
            return i;
    }
    return -1;
}

string substr(string str, int n) {
    string newStr = "";
    for (int i=0; i<n; i++)
        newStr += str[i];
    return newStr;
}

string delstr(string str, int n) {
    char s[MAXN];
    int strLen = str.length();
    for (int i=n; i<=strLen; i++)
        s[i-n] = str[i];
    cout << s << "ֹͣ" << endl;
    return s;
}

void insert(string str) {
    //TODO:
}

void search(string str) {
    int strLen = str.length();
    cout << "Len: " << strLen << endl;
    //string sub = substr(str, min(add, minus));
    int add = 0, minus = 0, k;
    while (add != -1 || minus != -1) {
        add = find('+', str);
        minus = find('-', str);
        
        cout << "add:   " << add    << "\t"
             << "minus: " << minus  << endl;
        k = min(add, minus);
        //insert(substr(str,k));
        cout << "sub:  " << substr(str,k) << "     ";
        str = delstr(str,k);
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    int T;
    cin >> T;
    while (T--) {
        string s1,s2;
        int limit;
        cin >> s1 >> s2 >> limit;
        cout << s1 << " / " << s2 << endl;
        
        //clear;
        for (int i=0; i<6; i++) {
            p1[i] = 0;
            op1[i] = '+';
            coe1[i] = 0;
        }
        
        search(s1);
        cout << endl;
        for (int i=0; i<6; i++) {
            cout << p1[i] << "\t";
        }
        
        cout << endl;
        for (int i=0; i<6; i++) {
            cout << op1[i] << "\t";
        }
        for (int i=0; i<4; i++)
            cout << endl;
        
    }
    fclose(stdin);
    return 0;
}
