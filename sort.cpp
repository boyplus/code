#include <cstdio>
#include <stdlib.h>
using namespace std;
struct Student
{
    int ID;
    float GPA;
};
int compare(const void * a,const void * b)
{
    Student *StudentA = (Student*)a;
    Student *StudentB = (Student*)b;
    return (StudentA->ID - StudentB->ID);
}
int main()
{
    Student data[3];
    for(int i=0;i<3;i++)
    {
        scanf("%d %f",&data[i].ID,&data[i].GPA);
    }
    qsort(data,3,sizeof(Student),compare);
    for(int i=0;i<3;i++)
    {
        printf("%d %f\n",data[i].ID,data[i].GPA);
    }
    return 0;
}
