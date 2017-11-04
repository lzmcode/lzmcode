#include <iostream>
#define MAXN 100
using namespace std;

class Animal {
    private:
        int age;
    public:
        void setAge(int iAge) { age = iAge; }
        //int queryAge() { return age; }
};

int main()
{
    Animal ani[MAXN];
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        int iAge;
        cin >> ani[i].age;
        cout << i+1 << " Age: " << ani[i].age << endl;
    }
    return 0;
}
