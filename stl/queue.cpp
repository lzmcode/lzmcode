#include <cstdlib>
#include <iostream>
#include <queue>
#include<cstdio> 
using namespace std;

int main()
{
    int e,n,m;
    queue<int> q1;
    printf("push��ȥ�ģ�");
    for(int i=0;i<10;i++)
    {
    	q1.push(i); 
    	cout << i << " ";	
    }
    cout << endl;
       
       
    if(!q1.empty())
    cout << "���в�Ϊ��\n";
    
    n=q1.size();
    cout << n <<endl;
	 
    m=q1.back();
    cout << m << endl;
    
    printf("pop�����ģ�");
    for(int j=0; j<n; j++)
    {
       e=q1.front();
       cout << e << " ";
       q1.pop();
    }
    cout << endl;
    if(q1.empty())
    cout << "����Ϊ��\n";
    return 0;
}
