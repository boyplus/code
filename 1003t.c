#include<stdio.h>
//#include<conio.h>

int check(int);

int main()
{
 int i=0, j=0, k=0, check1=0 ;
 int num=0, num1=0, num2=0 ;

 scanf("%d",&num);

 // check number if number is nugget number check1=1 , else check1=0
 for(i=0;i<17;i++)
  {
   for(j=0;j<12;j++)
   {
    for(k=0;k<6;k++)
    {
       num1=(6*i)+(9*j)+(20*k);
       if(num1>0)
       {
       num2=num%num1;
       }
       if(num2==0 && num1>0){ check1=1;}
    }
   }
  }

 /*if check1=1 and number more than 6 will send
 number to check function else will print "no"*/

 if(num>=6 && check1==1 && num<=100 && num>0)
 {
  check(num);
 }
 else{ printf("no"); }

 //getch();
 return 0;
}

// check function for check nugget number
int check(int num)
{
  int num1=0 ;
  int i=0, j=0, k=0, l=0 ;
  int total[300]={0} ;
  int temp=0, num2=0, check1=0 ;

// check nugget number
  for(i=0;i<17;i++)
  {
   for(j=0;j<12;j++)
   {
    for(k=0;k<6;k++)
    {
     num1=(6*i)+(9*j)+(20*k);

     if(num1<=num && num1>0)
     {
      total[l]=num1;
      l++;
     }
    }
   }
  }

// sort nugget number for less to more
  for(i=1;i<l;i++)
  {
   for(j=0;j<l-1;j++)
   {
    if(total[j]>total[j+1])
    {
     temp = total[j] ;
     total[j] = total[j+1] ;
     total[j+1] = temp ;
    }
   }
  }

// print nugget number for less to more
  for(i=0;i<l;i++)
  {
   check1=1;
   for(j=i-1;j>0;j--)
   {
    if(total[i]==total[j]){ check1=0; }
   }
   if(check1==1)
   { printf("%d\n",total[i]); }
  }

}
