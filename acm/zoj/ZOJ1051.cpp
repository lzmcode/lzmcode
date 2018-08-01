#include <stdio.h>
#include <stdlib.h>

int a[22][22];
int d[16];
int b[20][20];
int main(void)
{
    int t;
    int n;
    int i, j;
    int k;
    
    //freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < 16; ++i)
        {
            scanf("%d", &d[i]);
        }
        for (i = 1; i < 21; ++i)
        {
            for (j = 1; j < 21; ++j)
            {
                scanf("%d", &a[i][j]);
            }
        }
        while (n--)
        {
            for (i = 1; i < 21; ++i)
            {
                for (j = 1; j < 21; ++j)
                {
                    k = a[i-1][j] + a[i][j-1] + a[i+1][j] + a[i][j+1] +a[i][j];
                    b[i-1][j-1] = d[k];
                }
            }
            for (i = 1; i < 21; ++i)
            {
                for (j = 1; j < 21; ++j)
                {
                    a[i][j] += b[i-1][j-1];
                    if (a[i][j] < 0)
                        a[i][j] = 0;
                    else if (a[i][j] > 3)
                        a[i][j] = 3;
                }
            }
        }
        for (i = 1; i < 21; ++i)
        {
            for (j = 1; j < 21; ++j)
            {
                switch(a[i][j])
                {
                case 0:putchar('.');break;
                case 1:putchar('!');break;
                case 2:putchar('X');break;
                case 3:putchar('#');break;
                }
            }
            printf("\n");
        }
        if (t != 0)
            printf("\n");
    }
    return 0;
}
