#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s1[50], s2[50];
    int T;
    cin >> T;
    while (T--) {
        scanf("%s%s", &s1, &s2);
        s2[0] = s2[0] + 'A' - 'a';
        printf("%s%s\n", s2, s1);
    }
    return 0;
} 
