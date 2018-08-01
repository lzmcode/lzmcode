#include<iostream>  
#include<string.h>  
using namespace std;  
  
class String  
{  
    private :  
        char *ptr;  
        int size;  
    public :  
        String(int size = 1,char * str = "\0")  
        {  
            ptr = new char[size];  
            strcpy(ptr,str);  
            this->size = size;  
        }  
        
        char & operator[](int idx)  
        {  
            return ptr[idx];  
        }  
    
        ~String()  
        {  
            delete [] ptr;  
        }  
};

int main()  
{  
    String str1(10,"gaozhefeng"),str2(10,"Neo");  
    str2 = str1;//容易造成指针悬挂  
    return 0;  
}  

