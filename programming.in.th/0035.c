// area = x1y2 + x2y3 +x3y1 - y1x2 - y2x3 - y3x1/2
#include<stdio.h>
#include <math.h>
int main()
{
    int n,i=0,j=0,k=0;
    scanf("%d",&n);
    float x[n],y[n];
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&x[i],&y[i]);
    }
    float max=0;
   for(i=0;i<n;i++)
   {
       for(j=1;j<n;j++)
       {
            for(k=2;k<n;k++)
            {
                if(fabs((x[i]*y[j])+(x[j]*y[k])+(x[k]*y[i]) - (y[i]*x[j])-(y[j]*x[k])-(y[k]*x[i]))/2.00 >= max)
                {
                    max = fabs((x[i]*y[j])+(x[j]*y[k])+(x[k]*y[i]) - (y[i]*x[j])-(y[j]*x[k])-(y[k]*x[i]))/2.00;
                }
            }
       }
   }
   printf("%.3f\n",max);
    return 0;
}
