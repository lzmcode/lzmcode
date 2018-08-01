#include <iostream>  
#include <cstring>  
#include <cstdlib> 
#include <cmath> 
using namespace std;  
  
int main()  
{  
    int len, i, j;  
    int count[3];//计算每一部分的元音字符数！  
    string input;  
    while (getline(cin, input))  
    {  
        if (input == "e/o/i")  break;  
        memset(count, 0, sizeof(count));  
        input += '0';  
        len = input.length();  
        for (i = 0, j = 0; i < len; i++)  
        {  
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'y')  
            {  
                if (input[i+1] == 'a' || input[i+1] == 'e' || input[i+1] == 'i' || input[i+1] == 'o' || input[i+1] == 'u' || input[i+1] == 'y')  
                    continue;  
                else  
                    count[j]++;  
            }  
            if (input[i] == '/')  
                j++;  
            if (input[i] == '0')  
                continue;  
        }  
        if (count[0] == 5 && count[1] == 7 && count[2] == 5)  
            cout << "Y" << endl;  
        else if (count[0] != 5 )  
            cout << "1" << endl;  
        else if (count[1] != 7 )  
            cout << "2" << endl;  
        else if (count[2] != 5)  
            cout << "3" << endl;  
    }  
}
