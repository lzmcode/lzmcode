#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 65
using namespace std;

int main()
{
    char str[MAXN * 3 + 5];
    char cstr[MAXN * 3 + 5];
    while (scanf("%s", &str) != EOF) {
        strcpy(cstr, str);
        int len = strlen(str);
        int num[130];
        memset(num, 0, sizeof(num));
        
        char temp;
        for (int i=0; i<len / 2; i++) {
            temp = str[i];
            str[i] = str[len - i -1];
            str[len - i -1] = temp;
        }
        for (int i=0; i<len; i++) { 
            str[len + i] = str[i];
            str[2 * len + i] = str[i];
            num[i] = str[i] - '0';
        }
        str[3 * len] = '\0';
        bool flag = true;
        int n = 1;
        int ans[130];
        while (n <= len && flag) {
            memset(ans, 0, sizeof(ans));
            for (int i=0; i<len; i++)
                ans[i] = num[i] * n;
            
            int k = 0;
            while (ans[k] >= 10 || k < len) {
                ans[k + 1] += ans[k] / 10;
                ans[k] %= 10;
                k++;
            }
            
            char check[MAXN];
            for (int i=0; i<k; i++) {
                check[i] = ans[i] + '0';
            }
            check[k] = '\0';
            char *s = strstr(str, check);
            if (s == NULL) {
                flag = false;
                break; 
            }
            n++;
        }
        if (flag) {
            printf("%s is cyclic\n", cstr);
        } else {
            printf("%s is not cyclic\n", cstr);
        }
    }
    return 0;
}
