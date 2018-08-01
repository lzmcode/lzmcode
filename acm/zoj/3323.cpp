#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 100050

int main()
{
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int strLen = str.length();
        for (int i=0; i<strLen; i++)
            if (str[i] <='0' || '9' <= str[i])
                printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
