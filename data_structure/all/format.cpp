#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void welcome()
{
    printf("�Ƚ���Ҫ�Ż��Ĵ��븴�Ƶ����\n\n��һ�»س�����Ȼ�󰴡�Ctrl + Z����ϼ����ٰ�һ�»س�������ܿ���Ư���Ĵ�����\n");
    for(int i = 0; i < 80; i++)
    printf("=");
    printf("\n\n");
}
int main()
{
    welcome();
    char a[1000];
    int i, len, tab = 0, j, flag = 0, tag = 0; //flag����Ƿ���ע��
    FILE *fp;
    fp = fopen("temp.txt", "w");
    if(fp == NULL)
    {
        printf("�ļ���ʧ��");
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
        //�����������пո���Ʒ��� 
        while(a[i] == ' ' || a[i] == '\t')
        i++;
        //����Ϊ#  
        if(a[i] == '#')
        {
            while(a[i] == ' ' || a[i] == '\t')
            i++;
            for(; i < len; i++)
            {
                //�ļ��������ո� 
                if((a[i] == '<' || a[i] == '"') && a[i-1] != ' ')
                fprintf(fp, " ");
                fprintf(fp, "%c", a[i]);
            }
            fprintf(fp, "\n");
            continue;
        }
        //���ײ�ȫ�ո� 
        if(a[i] == '}' && !flag)
        tab--;
        for(j = 1; j <= 4*tab; j++)
        fprintf(fp, " ");
        //��һ����ĸ����}��ֱ�����
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
        //�������Ԫ�� 
        for(; i < len; i++)
        {
            //ɾ�������еĶ���ո�,ֻ����һ��
            while(a[i] == ' ' && a[i + 1] == ' ' || a[i] == '\t' && a[i + 1] == '\t')
            {
                i++;
            }
            //����ע��,,ֱ��ԭ�����
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
            //���ע��flag
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
            //˫б��ע��ֱ��ԭ�����
            if(a[i] == '/' && a[i + 1] == '/')
            {
                while(i < len)
                {
                    fprintf(fp, "%c", a[i]);
                    i++;
                }
                continue;
            }
            //�������ڵ�����
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
            //����  '
            if(a[i] == '\'' && a[i + 2] == '\'')
            {
                fprintf(fp, "%c%c%c", a[i], a[i + 1], a[i + 2]);
                i += 2;
                continue;
            }
            // "{" ����,�����������򲻻���
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
            //����'}'
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
            //���´��������ַ�
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
