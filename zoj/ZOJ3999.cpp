#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 1010

int  num1[MAXN], num2[MAXN];  //save coefficient
char  op1[MAXN],  op2[MAXN];  //save operate
int  exp1[MAXN], exp2[MAXN];  //save exp
int limit;

void init() {
    for (int i=0; i<MAXN; i++) {
        num1[i] = 0;   num2[i] = 0;
         op1[i] = '+';  op2[i] = '+';
        exp1[i] = 0;   exp2[i] = 0;
    }
}

void check1() {
    for (int i=0; i<5; i++) {
        cout << op1[i] << "\t";
    }
    cout << endl;
    for (int i=0; i<5; i++) {
        cout << num1[i] << "\t";
    }
    cout << endl; 
    for (int i=0; i<5; i++) {
        cout << exp1[i] << "\t";    
    }
}

int pow() {
    ;
}

void readStr1() {
    char ch, op = '+';
    int num = 0, exp = 0;
    int read = 1; //1的时候读系数, 2的时候读指数 
    int count = 0;
    
    while ((ch = getchar()) != '\n') {
        if (read == 1 && '0' <= ch && ch <= '9') {
            num = num * 10 + (ch - '0');
        }
        if (ch == '^') read = 2;
        if (read == 2 && '0' <= ch && ch <= '9') {
            exp = exp * 10 + (ch - '0');
        }
        if (ch == '+') {
            if (num == 0) num = 1;
            if (exp == 0) exp = 1;
            num1[count] = num;
            op1[count] = op;
            exp1[count] = exp;
            num = 0; exp = 0;
            read = 1;
            count++;
            op = '+';
            continue;
        }
        if (ch == '-') {
            if (num == 0) num = 1;
            if (exp == 0) exp = 1;
            num1[count] = num;
            op1[count] = op;
            exp1[count] = exp;
            num = 0; exp = 0; 
            read = 1;
            count++;
            op = '-';
            continue;
        }
    }
    check1();
}

void readStr2() {
    //TODO:
    //读取第二个字符串 
}

int cal() {
    //TODO:
    
    /** 
     * 这里计算出当前函数值 
     */
}

int main()
{
    freopen("input.txt","r",stdin);
    int T;
    cin >> T;
    while (T--) {
        init();
        getchar();
        readStr1();
        readStr2();
        scanf("%d", &limit);
        cal();
    }
    fclose(stdin);
    return 0;
}
