#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void welcome()
{
    printf("先将你要优化的代码复制到这里，\n\n按一下回车键，然后按“Ctrl + Z”组合键，再按一下回车，你就能看到漂亮的代码啦\n");
    for(int i = 0; i < 80; i++)
    printf("=");
    printf("\n\n");
}
int main()
{
    welcome();
    char a[1000];
    int i, len, tab = 0, j, flag = 0, tag = 0; //flag标记是否是注释
    FILE *fp;
    fp = fopen("temp.txt", "w");
    if(fp == NULL)
    {
        printf("文件打开失败");
        exit(1);
    }
    while(gets(a))
    {
        j = 0;
        len = strlen(a);
        while(j < len && (a[j] == ' ' || a[j] == '\t'))
        j++;
        if(j >= len)
        continue;
        i = 0;
        //消除行首所有空格和制符表 
        while(a[i] == ' ' || a[i] == '\t')
        i++;
        //行首为#  
        if(a[i] == '#')
        {
            while(a[i] == ' ' || a[i] == '\t')
            i++;
            for(; i < len; i++)
            {
                //文件包含补空格 
                if((a[i] == '<' || a[i] == '"') && a[i-1] != ' ')
                fprintf(fp, " ");
                fprintf(fp, "%c", a[i]);
            }
            fprintf(fp, "\n");
            continue;
        }
        //行首补全空格 
        if(a[i] == '}' && !flag)
        tab--;
        for(j = 1; j <= 4*tab; j++)
        fprintf(fp, " ");
        //第一个字母既是}则直接输出
        if(a[i] == '}')
        {
            fprintf(fp, "}");
            i++;
        }
        if(a[i] == '{' && a[i-1] != '\'' && a[i + 1] != '\'' && a[i-1] != '"' && a[i + 1] != '"')
        {
            fprintf(fp, "{");
            int j = i + 1;
            while(j < len && (a[j] == ' ' || a[j] == '\t'))
            j++;
            tab++;
            if(j >= len)
            {
                fprintf(fp, "\n");
                i = j;
                continue;
            }
            fprintf(fp, "\n");
            i = j;
            for(int k = 1; k <= 4*tab; k++)
            fprintf(fp, " ");
        }
        int k = i;
        //处理后续元素 
        for(; i < len; i++)
        {
            //删除程序中的多余空格,只保留一个
            while(a[i] == ' ' && a[i + 1] == ' ' || a[i] == '\t' && a[i + 1] == '\t')
            {
                i++;
            }
            //出现注释,,直接原样输出
            if(flag)
            {
                while(i < len)
                {
                    if(a[i] == '*' && a[i + 1] == '/')
                    flag = 0;
                    fprintf(fp, "%c", a[i]);
                    i++;
                }
                continue;
            }
            //标记注释flag
            if(a[i] == '/' && a[i + 1] == '*')
            {
                flag = 1;
                while(i < len)
                {
                    if(a[i] == '*' && a[i + 1] == '/')
                    flag = 0;
                    fprintf(fp, "%c", a[i]);
                    i++;
                }
                continue;
            }
            //双斜线注释直接原样输出
            if(a[i] == '/' && a[i + 1] == '/')
            {
                while(i < len)
                {
                    fprintf(fp, "%c", a[i]);
                    i++;
                }
                continue;
            }
            //处理“”内的内容
            if(a[i] == '"' && a[i-1] != '\'' && a[i + 1] != '\'')
            {
                while(a[i + 1] != '"')
                {
                    fprintf(fp, "%c", a[i]);
                    i++;
                }
                fprintf(fp, "%c%c", a[i], a[i + 1]);
                i++;
                continue;
            }
            //处理  '
            if(a[i] == '\'' && a[i + 2] == '\'')
            {
                fprintf(fp, "%c%c%c", a[i], a[i + 1], a[i + 2]);
                i += 2;
                continue;
            }
            // "{" 换行,若在引号内则不换行
            if(a[i] == '{' && a[i-1] != '\'' && a[i + 1] != '\'' && a[i-1] != '"' && a[i + 1] != '"')
            {
                if(i != k)
                {
                    fprintf(fp, "\n");
                    tag = 1;
                }
                if(tag == 0)
                for(j = 1; j <= 4*(tab-1);j++)
                fprintf(fp, " ");
                else
                if(tag == 1)
                for(j = 1; j <= 4*tab; j++)
                fprintf(fp, " ");
                fprintf(fp, "{");
                j = i + 1;
                while(j < len && (a[j] == ' ' || a[j] == '\t'))
                j++;
                if(j >= len)
                {
                    for(j = 1; j <= 4*(tab + 1);j++)
                    fprintf(fp, " ");
                    while(a[i + 1] == ' ')
                    i++;
                }
                else
                {
                    fprintf(fp, "\n");
                    for(j = 1; j <= 4*(tab + 1);j++)
                    fprintf(fp, " ");
                }
                tab++;
                continue;
            }
            //处理'}'
            if(a[i] == '}' && a[i + 1] == '}')
            {
                fprintf(fp, "}\n");
                tab--;
                for(j = 1; j <= 4*(tab-1);j++)
                fprintf(fp, " ");
                fprintf(fp, "}");
                tab--;
                i++;
                continue;
            }
            if(a[i] == '}' && a[i-1] != '\'' && a[i + 1] != '\'' && a[i-1] != '"' && a[i + 1] != '"')
            {
                j = i + 1;
                while(j < len && (a[j] == ' ' || a[j] == '\t'))
                j++;
                if(j >= len)
                {
                    if(k != i)
                    fprintf(fp, "\n");
                    for(j = 1; j <= 4*(tab-1);j++)
                    fprintf(fp, " ");
                }
                fprintf(fp, "}");
                tab--;
                continue;
            }
            //以下处理其他字符
            if((a[i] == ')' || a[i] == ',' || a[i] == ';')  && ((a[i + 1] == ')' || a[i + 1] == ';')))
            {
                fprintf(fp, "%c%c", a[i], a[i + 1]);
                i++;
                continue;
            }
            if(a[i] == ')' || a[i] == ',' || a[i] == ';')
            {
                fprintf(fp, "%c", a[i]);
                if(i != len-1 && a[i + 1] != ' ')
                fprintf(fp, " ");
                continue;
            }
            if(a[i] == '-' && a[i + 1] == '-' || a[i] == '+' && a[i + 1] == '+')
            {
                fprintf(fp, "%c%c", a[i], a[++i]);
                continue;
            }
            if(a[i] == '=' && a[i + 1] == '=' || a[i] == '&' && a[i + 1] == '&' || a[i] == '|' && a[i + 1] == '|' || a[i] == '!' && a[i + 1] == '=')
            {
                if(a[i-1] != ' ')
                fprintf(fp, " ");
                fprintf(fp, "%c%c", a[i], a[i + 1]);
                if(a[i + 2] != ' ')
                fprintf(fp, " ");
                i++;
                continue;
            }
            if(a[i] == '!' || a[i] == '~' || a[i] == '&')
            {
                fprintf(fp, "%c", a[i]);
                while(a[i + 1] == ' ')
                i++;
                continue;
            }
            if(a[i] == ' ' && (a[i + 1] == '[' || a[i + 1] == '.'))
            {
                i++;
                fprintf(fp, "%c", a[i]);
                continue;
            }
            if(a[i] == '-' && a[i + 1] == '>')
            {
                if(a[i-1] != ' ')
                fprintf(fp, " ");
                fprintf(fp, "%c%c", a[i], a[i + 1]);
                if(a[i + 2] != ' ')
                fprintf(fp, " ");
                i++;
                continue;
            }
            if((a[i] == '%' || a[i] == '-' || a[i] == '+' || a[i] == '*' || a[i] == '\\' || a[i] == '>' || a[i] == '<')  && a[i + 1] == '=')
            {
                if(a[i-1] != ' ')
                fprintf(fp, " ");
                fprintf(fp, "%c%c", a[i], a[i + 1]);
                if(a[i + 2] != ' ')
                fprintf(fp, " ");
                i++;
                continue;
            }
            if(a[i] == '>' && a[i + 1] == '>' || a[i] == '<' && a[i + 1] == '<')
            {
                if(a[i-1] != ' ')
                fprintf(fp, " ");
                fprintf(fp, "%c%c", a[i], a[i + 1]);
                if(a[i + 2] != ' ')
                fprintf(fp, " ");
                i++;
                continue;
            }
            if((a[i] == '=' || a[i] == '+' || a[i] == '^' || a[i] == '<' || a[i] == '>')  && a[i-1] != '\'' && a[i + 1] != '\'' && a[i-1] != '"' && a[i + 1] != '"')
            {
                if(a[i-1] != ' ')
                fprintf(fp, " ");
                fprintf(fp, "%c", a[i]);
                if(a[i + 1] != ' ')
                fprintf(fp, " ");
                continue;
            }
            fprintf(fp, "%c", a[i]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    system("start temp.txt");
    return 0;
}
