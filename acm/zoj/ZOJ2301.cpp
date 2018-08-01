#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    double d1, d2, d3;
    while (scanf("%lf%lf%lf", &d1, &d2, &d3) != EOF) {
        if (d1 == 0.0 && d2 == 0.0 && d3 == 0.0)
            break;
        bool f1 = false, f2 = false, f3 = false;
        if (d1 <= 4.5 && d2 >= 150 && d3 >= 200)
            f1 = true;
        if (d1 <= 6.0 && d2 >= 300 && d3 >= 500)
            f2 = true;
        if (d1 <= 5.0 && d2 >= 200 && d3 >= 300)
            f3 = true;
        //print
        if (f1)
            printf("Wide Receiver");
        if (f2) {
            if (f1)
                printf(" ");
            printf("Lineman");
        }
        if (f3) {
            if (f1 || f2)
                printf(" ");
            printf("Quarterback");
        }
        if (!f1 && !f2 && !f3)
            printf("No positions");
        printf("\n");
    }
    return 0;
} 
