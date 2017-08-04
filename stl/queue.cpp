#include <cstdlib>
#include <iostream>
#include <queue>
#include<cstdio> 
using namespace std;

int main()
{
    int e,n,m;
    queue<int> q1;
    printf("push进去的：");
    for(int i=0;i<10;i++)
    {
    	q1.push(i); 
    	cout << i << " ";	
    }
    cout << endl;
       
       
    if(!q1.empty())
    cout << "队列不为空\n";
    
    n=q1.size();
    cout << n <<endl;
	 
    m=q1.back();
    cout << m << endl;
    
    printf("pop出来的：");
    for(int j=0; j<n; j++)
    {
       e=q1.front();
       cout << e << " ";
       q1.pop();
    }
    cout << endl;
    if(q1.empty())
    cout << "队列为空\n";
    return 0;
}
