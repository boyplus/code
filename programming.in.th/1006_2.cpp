#include<stdio.h>

#define MAX 6
#define max 1001

int dice[MAX] = {1, 2, 3, 5, 4, 6};

void SWAP(int *a, int *b)
 {
    int c  = *a;
        *a = *b;
        *b = c;
 }

void Default()
 {
    dice[0] = 1;
    dice[1] = 2;
    dice[2] = 3;
    dice[3] = 5;
    dice[4] = 4;
    dice[5] = 6;
 }

int main()
 {
    int op[MAX];
    char a[max];
    int n;
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
     { scanf("%s",a);
       for(j = 0; a[j] != '\0'; j ++)
        { if(a[j] == 'F')
           { SWAP(&dice[0], &dice[1]);
             SWAP(&dice[0], &dice[5]);
             SWAP(&dice[0], &dice[3]);
           }
          else if(a[j] == 'B')
           { SWAP(&dice[0], &dice[1]);
             SWAP(&dice[1], &dice[3]);
             SWAP(&dice[1], &dice[5]);
           }
          else if(a[j] == 'L')
           { SWAP(&dice[0], &dice[2]);
             SWAP(&dice[0], &dice[4]);
             SWAP(&dice[4], &dice[5]);
           }
          else if(a[j] == 'R')
           { SWAP(&dice[0], &dice[4]);
             SWAP(&dice[0], &dice[2]);
             SWAP(&dice[2], &dice[5]);
           }
          else if(a[j] == 'C')
           { SWAP(&dice[1], &dice[2]);
             SWAP(&dice[1], &dice[3]);
             SWAP(&dice[1], &dice[4]);
           }
          else
           { SWAP(&dice[1], &dice[4]);
             SWAP(&dice[1], &dice[2]);
             SWAP(&dice[2], &dice[3]);
           }
        }
       op[i] = dice[1];
       Default();
     }
    for(j = 0; j < i; j ++)
     { printf("%d ", op[j]);
     }
    printf("\n");
    return 0;
 }
