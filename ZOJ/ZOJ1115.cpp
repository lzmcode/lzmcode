#include <iostream>  
#include <cstring> 
using namespace std;  
char str[100050]; 
int root (int n)  
{  
    if (n < 10)  
        return n;  
    else  
    {  
        int temp = n, ans = 0;  
        while (temp)  
        {  
            ans += temp % 10;  
            temp /= 10;  
            if (temp == 0)  
            {  
                if (ans >= 10)  
                    root(ans);  
                else   
                    return ans;  
            }  
        }  
    }  
}  
int main()  
{ 
    int length, i, sum;  
    while (cin >> str && str[0] != '0')  
    {  
        sum = 0;  
        length = strlen(str);
        for (i = 0; i < length; i++)  
            sum += str[i] - 48;  
        cout << root(sum) << endl;  
    }  
}  
