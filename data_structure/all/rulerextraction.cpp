#include <cstdio>
#include <iostream>
using namespace std;
int x[100005];
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,s;
        scanf("%d%d",&n,&s);
        
        int num = 0, min;
        for (int i=0; i<n; i++)
        {
            scanf("%d",&x[i]);
            num += x[i];
        }
        
        if (num < s)
        {
            printf("0\n");
        }
        else
        {
            num = 0;
            min = n;
            int i = 0, j = 0;
            while (j < n)
            {
                if (num < s)
                {
                    num += x[j];
                    j++;
                    //cout<<i<<" "<<j<<" "<<num<<endl;
                }
                else
                {
                    if (j-i < min)
                    {
                        min = j-i;
                    }
                    num -= x[i];
                    i++;
                    //cout<<i<<" "<<j<<" "<<num<<endl;
                }
            }
            while (num > s)
            {
                num -= x[i++];
                if (j-i+1 < min && num > s)
                {
                    min = j-i;
                }
                //cout<<i<<" "<<j<<" "<<num<<endl;
            }
            printf("%d\n",min);
        }
        
    }
    return 0;
}

