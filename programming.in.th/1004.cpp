#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int i,j,k,n,nc,ns;
    scanf("%d %d",&nc,&ns);
    int num_class[ns];
    int num_student[ns];
    for(i=0; i<ns; ++i)
    {
        scanf("%d %d",&num_class[i],&num_student[i]);
    }
    vector <int> row_class;
    vector <int> row_student;
    char cmd;
    int cmd_student=0;
    int cmd_class=0;
    int this_class =0;
    int temp_class =0;
    bool chk = false;
    bool check_class = false;
    while(1)
    {
        scanf(" %c",&cmd);
        if(cmd == 'X')
        {
            printf("0\n");
            return 0;
        }
        else if(cmd == 'E')
        {
            scanf("%d",&cmd_student);
            for(i=0; i<ns; ++i)
            {
                if(cmd_student == num_student[i])
                {
                    this_class = num_class[i];
                    chk = true;
                    break;
                }
            }
            if(chk)
            {
                int row_size = row_class.size();
                for(i=0; i<row_size; i++)
                {
                    if(this_class == row_class[i])
                    {
                        check_class = true;
                        int now_size = row_class.size();
                        for(j=i; j<now_size; j++)
                        {
                            if(this_class != row_class[j])
                            {
                                temp_class = j;
                                break;
                            }
                            if(j == row_size-1)
                                temp_class = j+1;
                        }
                    }
                }
                if(check_class)
                {
                    row_student.insert(row_student.begin()+temp_class,cmd_student);
                    row_class.insert(row_class.begin()+temp_class,this_class);
                }
            }
            if(!check_class)
            {
                row_student.push_back(cmd_student);
                row_class.push_back(this_class);
            }
        }
        else if(cmd == 'D')
        {
            printf("%d\n",row_student[0]);
            row_student.erase(row_student.begin());
            row_class.erase(row_class.begin());
        }
        chk = false;
        check_class = false;
        temp_class =0;
    }
    return 0;
}
