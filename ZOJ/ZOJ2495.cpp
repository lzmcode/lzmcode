#include<stdio.h>  
  
int main()  
{  
    int n;  
    int s[19][19];  
    scanf("%d", &n);  
    while (n--)  
    {  
        int i, j;  
        for (i = 0; i < 19; i++)  
            for (j = 0; j < 19; j++)  
                scanf("%d", &s[i][j]);  
  
        int flag = 0;  
        for (i = 0; i < 19 && !flag; i++)  
            for (j = 0; j < 19; j++)  
            {  
                if (s[i][j] == 0)  
                    continue;  
                if (j + 4 < 19 && s[i][j + 1] == s[i][j]  
                        && s[i][j + 2] == s[i][j] && s[i][j + 3] == s[i][j]  
                        && s[i][j + 4] == s[i][j])  
                {  
                    if (((j + 5 < 19 && s[i][j + 5] != s[i][j]) || (j + 5 >= 19))  
                            && ((j - 1 >= 0 && s[i][j - 1] != s[i][j])  
                                    || (j - 1 < 0)))  
                    {  
                        printf("%d\n%d %d\n", s[i][j], i + 1, j + 1);  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (i + 4 < 19 && s[i + 1][j] == s[i][j]  
                        && s[i + 2][j] == s[i][j] && s[i + 3][j] == s[i][j]  
                        && s[i + 4][j] == s[i][j])  
                {  
                    if (((i + 5 < 19 && s[i + 5][j] != s[i][j]) || (i + 5 >= 19))  
                            && ((i - 1 >= 0 && s[i - 1][j] != s[i][j])  
                                    || (i - 1 < 0)))  
                    {  
                        printf("%d\n%d %d\n", s[i][j], i + 1, j + 1);  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (i + 4 < 19 && j + 4 < 19 && s[i + 1][j + 1] == s[i][j]  
                        && s[i + 2][j + 2] == s[i][j]  
                        && s[i + 3][j + 3] == s[i][j]  
                        && s[i + 4][j + 4] == s[i][j])  
                {  
                    if (((i + 5 < 19 && j + 5 < 19 && s[i + 5][j + 5] != s[i][j])  
                            || (i + 5 >= 19 || j + 5 >= 19))  
                            && ((i - 1 >= 0 && j - 1 >= 0  
                                    && s[i - 1][j - 1] != s[i][j])  
                                    || (i - 1 < 0 || j - 1 < 0)))  
                    {  
                        printf("%d\n%d %d\n", s[i][j], i + 1, j + 1);  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (i - 4 >= 0 && j + 4 < 19 && s[i - 1][j + 1] == s[i][j]  
                        && s[i - 2][j + 2] == s[i][j]  
                        && s[i - 3][j + 3] == s[i][j]  
                        && s[i - 4][j + 4] == s[i][j])  
                {  
                    if (((i - 5 >= 0 && j + 5 < 19 && s[i - 5][j + 5] != s[i][j])  
                            || (i - 5 < 0 || j + 5 >= 19))  
                            && ((i + 1 < 19 && j - 1 >= 0  
                                    && s[i + 1][j - 1] != s[i][j])  
                                    || (i + 1 >= 19 || j - 1 < 0)))  
                    {  
                        printf("%d\n%d %d\n", s[i][j], i + 1, j + 1);  
                        flag = 1;  
                        break;  
                    }  
                }  
            }  
        if (!flag)  
            printf("0\n");  
    }  
    return 0;  
}  
