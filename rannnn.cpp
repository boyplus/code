#include <stdio.h>
int main()
{
    int num;
    FILE *f1 = fopen("jj.txt","w");
    fprintf(f1,"1000");
    for(int i=0;i<1000;i++)
        fprintf(f1,"10 ");
    return 0;
}
