//function แบบที่2
#include<stdio.h>
#include<math.h>
int main()
{
     double a,b;
    scanf("%lf %lf",&a,&b);
    double c = a*a + b*b;
    c = sqrt(c);
    if(a>0 && b>0 && a+b >=c)
        printf("%lf",c);
    return 0;
}
