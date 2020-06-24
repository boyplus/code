#include <stdio.h>
#include <string.h>
char a[1000000],b[1000000];
int count_string_b_a(const char *a, const char *b,int lenb)
{
    int count = 0;
    const char *p = a;
    while(NULL != (p = strstr(p, b)))
    {
        ++count;
        p+=2;
    }
    return count;
}
int main()
{
    int cont=0,lena=0,lenb=0;
    scanf("%d %d",&lena,&lenb);
    scanf("%s %s",&a,&b);
    cont = count_string_b_a(a, b,lenb);
    printf("%d",cont);
    return 0;
}
