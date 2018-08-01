#include<iostream> 
#include<vector>
#include<algorithm> 
#include<cstdio>
using namespace std;  
  
int main()  
{  
    string line;  
    int count = 0;  
    while (getline(cin, line), line != "")  
    {  
        vector<string> all;  
        all.push_back(line);  
        while (getline(cin, line), line != "9")  
            all.push_back(line);  
        sort(all.begin(), all.end());  
        bool decodable = true;  
        for (size_t i = 1; i != all.size() && decodable; i++)  
            if (all[i].find(all[i - 1]) == 0)  
                decodable = false;  
        printf("Set %d is %simmediately decodable\n", ++count,  
                decodable ? "" : "not ");  
    }  
    return 0;  
}  
