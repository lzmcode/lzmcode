#include <iostream>
#include <queue>
using namespace std;
class T
{
 public:
    int x, y, z;
   T(int a, int b, int c):x(a), y(b), z(c)
  {
 	
  }
};
 bool operator < (const T &t1, const T &t2)
{
   return t1.z < t2.z; // 按照z 的顺序来决定t1 和t2 的顺序
}
main()
{
    priority_queue<T> q;
    q.push(T(4,4,3));
    q.push(T(2,2,5));
    q.push(T(1,5,4));
    q.push(T(3,3,6));
  while (!q.empty())
 {
   T t = q.top(); q.pop();
   cout << t.x << " " << t.y << " " << t.z << endl;
 }
  return 1;
}
