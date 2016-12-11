//string
#include<stdio.h>
#include<string.h>
int main()
{
    char name[10001];
    scanf("%s",&name);
    unsigned int i;
    unsigned int s=0;
    unsigned int s1=0;
    for(i=0;i<strlen(name);i++)
    {
        if(name[i] >=65 && name[i] <=90)
            s++;
        if(name[i] >= 97 && name[i] <=122)
            s1++;
    }
    if(s==strlen(name) && s1 == 0)
        printf("All Capital Letter");
     if(s==0 && s1 == strlen(name))
        printf("All Small Letter");
    if(s1 !=0 && s !=0)
        printf("Mix");
    return 0;
}
