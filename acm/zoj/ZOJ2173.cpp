#include<stdio.h>
int main()
{
    int n, w, h;
    while (scanf("%d", &n), n)
    {
        int width = -1, height = 0, cw = 0, ch = -1;
        while (scanf("%d %d", &w, &h), w != -1 && h != -1)
        {
            if (cw + w > n)
            {
                height += ch;
                if (cw > width)
                    width = cw;
                cw = w;
                ch = h;
            }
            else
            {
                if (h > ch)
                    ch = h;
                cw += w;
            }
        }
        if (cw > width)
            width = cw;
        height += ch;
        printf("%d x %d\n", width, height);
    }
    return 0;
}
