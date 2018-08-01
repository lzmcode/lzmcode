#include <iostream>
#include <cstring>
#define MAXN 100
using namespace std;

void backPrint(char s[]) {
    int ilen = strlen(s);
    for (int i=0; i<=ilen; i++) {
        cout << s[ilen-i];
    }
    cout << endl;
}
int main()
{
    char s[MAXN];
    cin.getline(s, 20);
    backPrint(s);
    return 0;
}
