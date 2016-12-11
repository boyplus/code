#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,n,m=1;
    scanf("%d",&n);
    char mook[n][31],word[31],temp[31];
    for(i=0;i<n;i++){
        scanf(" %s",word);
        for(j=0;j<m;j++){
            if(!strcmp(mook[j],word)){
                goto m1;
            }
            else if(j==m-1){
                strcpy(mook[j],word);
                ++m;
                goto m1;
            }
            else{
                for(k=0;k<strlen(word);k++){
                    if(mook[j][k]>word[k]||(strlen(mook[j])>strlen(word)&&k==strlen(word)-1)){
                        strcpy(temp,mook[j]);
                        strcpy(mook[j],word);
                        strcpy(word,temp);
                        goto m2;
                    }
                    else if(mook[j][k]<word[k]||k==strlen(mook[j])){
                        goto m2;
                    }
                }
                m2 : m=m;
            }
        }
        m1 : m=m;
    }
    for(i=0;i<m-1;i++){
        printf("%s\n",mook[i]);
    }
}

