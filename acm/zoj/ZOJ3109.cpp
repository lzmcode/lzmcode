#include<stdio.h>  
  
int main()  
{  
    int r, c;  
    char a[20][20];  
    while (scanf("%d %d", &r, &c), r && c)  
    {  
        getchar();  
        int i, j, index = 0;  
        for (i = 0; i < r; i++)  
            for (j = 0; j < c; j++)  
                a[i][j] = getchar();  
        getchar();  
  
        int isRow = 1, isOrder = 1, rb = 0, re = c - 1, cb = 0, ce = r - 1;  
        while (1)  
        {  
            if (isRow)  
            {  
                if (rb > re)  
                    break;  
  
                if (isOrder)  
                {  
                    for (i = rb; i <= re; i++)  
                        putchar(a[index][i] - 7);  
                    index = re;  
                    cb++;  
                }  
                else  
                {  
                    for (i = re; i >= rb; i--)  
                        putchar(a[index][i] - 7);  
                    index = rb;  
                    ce--;  
                }  
                isRow = !isRow;  
            }  
            else  
            {  
                if (cb > ce)  
                    break;  
  
                if (isOrder)  
                {  
                    for (i = cb; i <= ce; i++)  
                        putchar(a[i][index] - 7);  
                    index = ce;  
                    re--;  
                }  
                else  
                {  
                    for (i = ce; i >= cb; i--)  
                        putchar(a[i][index] - 7);  
                    index = cb;  
                    rb++;  
                }  
                isOrder = !isOrder;  
                isRow = !isRow;  
            }  
        }  
        putchar('\n');  
    }  
    return 0;  
}  
