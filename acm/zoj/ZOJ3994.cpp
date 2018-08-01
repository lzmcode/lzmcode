#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, num;
        scanf("%d", &n);
        int A = 0, B = 0;
        for (int i=0; i<n; i++) {
            scanf("%d", &num);
            A += num;
        }
        for (int i=0; i<n; i++) {
            scanf("%d", &num);
            B += num;
        }
        if (A > B) {
            printf("BaoBao\n");
        } else {
            printf("DreamGrid\n"); 
        }
    }
    
    return 0;
} 
