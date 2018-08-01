#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 25
using namespace std;
char map[MAX][MAX];
int ans;
void BFS(int x, int y)
{
    if (map[x][y] == '.')
    {
        ans++;
        map[x][y] = '#';
        BFS(x+1,y);
        BFS(x-1,y);
        BFS(x,y-1);
        BFS(x,y+1);
    }
} 
int main()
{
    //freopen("input.txt","r",stdin); 
    int w,h;
    int x,y;
    while (scanf("%d%d", &w, &h) != EOF)
    {
        if (w == 0 || h == 0)
            return 0;
        int i,j;
        for (i=0; i<=h+1; i++)
        {
            for (j=0; j<=w+1; j++)
            {
                map[i][j] = '#';
            }
        }
        for (i=1; i<=h; i++)
        {
            getchar();
            for (j=1; j<=w; j++)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == '@')
                {
                    x = i;
                    y = j;
                    map[i][j] = '.';
                }
            }
        }
        ans = 0;
        BFS(x,y);
        printf("%d\n", ans); 
        //print
        /* 
        for (i=0; i<=h+1; i++)
        {
            for (j=0; j<=w+1; j++)
            {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
        */
    }
    //fclose(stdin);
    return 0;
}
