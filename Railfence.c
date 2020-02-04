#include<stdio.h>
#include<string.h>
void encmess(char msg[],int key){
    int k=0,i,j,cntr;
    int msglen=strlen(msg);
    char railmatrix[key][key];
    for(i=0;i<msglen;i++)
        printf("%c",msg[i]);

    printf("\n");

    for(i=0;i<key;i++)
        for(j=0;j<key;j++)
            railmatrix[i][j]=msg[k++];
    for(i=0;i<key;i++)
        for(j=0;j<key;j++)
            printf("%c",railmatrix[i][j]);

    printf("\n");

    printf("\nEncrypted text:");
    for(i=0;i<key;i++)
        for(j=0;j<key;j++)
            if(i==j)
                printf("%c",railmatrix[i][j]);

    printf(" ");

    for(i=0;i<key;i++)
        for(j=0;j<key;j++)
               if((i-j==1)|| (i-j==-1))
                printf("%c",railmatrix[i][j]);

    printf(" ");
    for(i=0;i<key;i++)
        for(j=0;j<key;j++)
            if((i-j==2)|| (i-j==-2))
                printf("%c",railmatrix[i][j]);
/*    for(i=0;i<msglen;i++)
        if(i==0)
        cntr=key+1;
            printf("%c",railmatrix[0][0]);
            printf("%c",railmatrix[0][cntr]);
            printf("%c",railmatrix[0][cntr+cntr]);
*/

}
void main(){
    char msg[]="saurabrai";
    int key=3;
    encmess(msg,key);




}
