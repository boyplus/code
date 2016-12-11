#include<stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
int main()
{
    double r,n,m;
    scanf("%lf",&r);
    n = M_PI *r*r;
    m = 2*r*r;
    printf("%.6lf\n%.6lf",n,m);


    return 0;
}
