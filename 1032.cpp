#include <stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    int start_table[9][9]= {0};
    int count=0;
    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            scanf("%d",&start_table[i][j]);
    int num[n][9][9];
    for(i=0; i<n; i++)
        for(j=0; j<9; j++)
            for(k=0; k<9; k++)
                scanf("%d",&num[i][j][k]);
    bool chk_1 = false;
    bool chk_2 = false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<9; j++)
        {
            for(k=0; k<9; k++)
            {
                if(num[i][j][k] != start_table[j][k] && start_table[j][k]!=0)
                {
                    chk_1 = true;
                    break;
                }
            }
            if(chk_1==true)
                break;
        }
        if(chk_1 == false)
        {
            int num_check1[9]= {0};
            int num_check2[9]={0};
            int num_check3[9]={0};
            int num_check4[9]={0};
            int num_check5[9]={0};
            int num_check6[9]={0};
            int num_check7[9]={0};
            int num_check8[9]={0};
            int num_check9[9]={0};
            int count_array=0;
            for(j=0;j<3;j++)
            {
                for(k=0;k<3;k++)
                {
                    num_check1[count_array] = num[i][j][k];
                    count_array++;
                }
            }
            count_array=0;
            for(j=0;j<3;j++)
            {
                for(k=3;k<6;k++)
                {
                    num_check2[count_array] = num[i][j][k];
                    count_array++;
                }
            }
            count_array=0;
            for(j=0;j<3;j++)
            {
                for(k=6;k<9;k++)
                {
                    num_check3[count_array] = num[i][j][k];;
                    count_array++;
                }
            }
            count_array=0;
            for(j=3;j<6;j++)
            {
                for(k=0;k<3;k++)
                {
                    num_check4[count_array] = num[i][j][k];
                    count_array++;
                }
            }
            count_array=0;
            for(j=3;j<6;j++)
            {
                for(k=3;k<6;k++)
                {
                    num_check5[count_array] = num[i][j][k];
                    count_array++;
                }
            }
            count_array=0;
            for(j=3;j<6;j++)
            {
                for(k=6;k<9;k++)
                {
                    num_check6[count_array] = num[i][j][k];
                    count_array++;
                }
            }
            count_array=0;
            for(j=6;j<9;j++)
            {
                for(k=0;k<3;k++)
                {
                    num_check7[count_array] = num[i][j][k];
                    count_array++;
                }
            }
            count_array=0;
            for(j=6;j<9;j++)
            {
                for(k=3;k<6;k++)
                {
                    num_check8[count_array] = num[i][j][k];
                    count_array++;
                }
            }
            count_array=0;
            for(j=6;j<9;j++)
            {
                for(k=6;k<9;k++)
                {
                    num_check9[count_array] = num[i][j][k];
                    count_array++;
                }
            }
            for(j=0; j<9; j++)
            {
                for(k=j+1; k<9; k++)
                {
                    if(num_check1[j] == num_check1[k])
                    {
                        chk_2 = true;
                        break;
                    }
                    if(num_check2[j] == num_check2[k])
                    {
                        chk_2 = true;
                        break;
                    }
                    if(num_check3[j] == num_check3[k])
                    {
                        chk_2 = true;
                        break;
                    }
                    if(num_check4[j] == num_check4[k])
                    {
                        chk_2 = true;
                        break;
                    }
                    if(num_check5[j] == num_check5[k])
                    {
                        chk_2 = true;
                        break;
                    }
                    if(num_check6[j] == num_check6[k])
                    {
                        chk_2 = true;
                        break;
                    }
                    if(num_check7[j] == num_check7[k])
                    {
                        chk_2 = true;
                        break;
                    }
                    if(num_check8[j] == num_check8[k])
                    {
                        chk_2 = true;
                        break;
                    }
                    if(num_check9[j] == num_check9[k])
                    {
                        chk_2 = true;
                        break;
                    }
                }
                if(chk_2 == true)
                    break;
            }
            if(chk_2 == false)
            {
                int num_row1[9]={0};
                int num_row2[9]={0};
                int num_row3[9]={0};
                int num_row4[9]={0};
                int num_row5[9]={0};
                int num_row6[9]={0};
                int num_row7[9]={0};
                int num_row8[9]={0};
                int num_row9[9]={0};
                int num_colum1[9]={0};
                int num_colum2[9]={0};
                int num_colum3[9]={0};
                int num_colum4[9]={0};
                int num_colum5[9]={0};
                int num_colum6[9]={0};
                int num_colum7[9]={0};
                int num_colum8[9]={0};
                int num_colum9[9]={0};
                for(j=0;j<9;j++)
                {
                    num_row1[j] = num[i][j][0];
                    num_colum1[j] = num[i][0][j];
                }
                for(j=0;j<9;j++)
                {
                    num_row2[j] = num[i][j][1];
                    num_colum2[j] = num[i][1][j];
                }
                for(j=0;j<9;j++)
                {
                    num_row3[j] = num[i][j][2];
                    num_colum3[j] = num[i][2][j];
                }
                for(j=0;j<9;j++)
                {
                    num_row4[j] = num[i][j][3];
                    num_colum4[j] = num[i][3][j];
                }
                for(j=0;j<9;j++)
                {
                    num_row5[j] = num[i][j][4];
                    num_colum5[j] = num[i][4][j];
                }
                for(j=0;j<9;j++)
                {
                    num_row6[j] = num[i][j][5];
                    num_colum6[j] = num[i][5][j];
                }
                for(j=0;j<9;j++)
                {
                    num_row7[j] = num[i][j][6];
                    num_colum7[j] = num[i][6][j];
                }
                for(j=0;j<9;j++)
                {
                    num_row8[j] = num[i][j][7];
                    num_colum8[j] = num[i][7][j];
                }
                for(j=0;j<9;j++)
                {
                    num_row9[j] = num[i][j][8];
                    num_colum9[j] = num[i][8][j];
                }
                bool chk_3 = false;
                for(j=0;j<9;j++)
                {
                    for(k=j+1;k<9;k++)
                    {
                        if(num_row1[j] == num_row1[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_row2[j] == num_row2[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_row3[j] == num_row3[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_row4[j] == num_row4[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_row5[j] == num_row5[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_row6[j] == num_row6[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_row7[j] == num_row7[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_row8[j] == num_row8[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_row9[j] == num_row9[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_colum1[j] == num_colum1[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_colum2[j] == num_colum2[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_colum3[j] == num_colum3[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_colum4[j] == num_colum4[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_colum5[j] == num_colum5[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_colum6[j] == num_colum6[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_colum7[j] == num_colum7[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_colum8[j] == num_colum8[k])
                        {
                            chk_3 = true;
                            break;
                        }
                        if(num_colum9[j] == num_colum9[k])
                        {
                            chk_3 = true;
                            break;
                        }
                    }
                    if(chk_3 == true)
                        break;
                }
                if(chk_3 == false)
                    printf("%d\n",i+1);
                chk_3 = false;
            }
            chk_2 = false;
        }
        chk_1 = false;
    }
    printf("END\n");
    return 0;
}
