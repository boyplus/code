#include<stdio.h>
int main(){
    int x,y,m,i;
    scanf("%d%d",&x,&y);
    if(x>y)
         m=y;
    else
         m=x;
    for(i=m;i>=1;i--){
         if(x%i==0&&y%i==0){
             printf("%d",i) ;
             break;
         }
    }
    return 0;
}
