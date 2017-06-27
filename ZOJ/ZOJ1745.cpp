#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int pos,now,temp=0,flag=0;  
    while(cin>>pos && pos<5280)
	{
        if(flag++)cout<<endl; //控制格式的代码，没有此行会报错PE
        while(cin>>now){
            if(now==pos){
                cout<<"Moving from "<<temp<<" to "<<now<<": found it!"<<endl;
                break;
            }
            else{
            if(abs(now-pos)>abs(temp-pos)){
                cout<<"Moving from "<<temp<<" to "<<now<<": colder."<<endl;
            }
            else if(abs(now-pos)<abs(temp-pos)){
                cout<<"Moving from "<<temp<<" to "<<now<<": warmer."<<endl;
            }
            else if(abs(now-pos)==abs(temp-pos)){
                cout<<"Moving from "<<temp<<" to "<<now<<": same."<<endl;
            }
            }   
            temp = now;
        }
        temp=0;
    }
    return 0;
}
