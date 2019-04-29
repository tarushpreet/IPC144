


#include <stdio.h>
#include <string.h>

int main (void)
{
    char backup[9],rightPwd[9],guessPwd[9];
    int loop=8,len,j;

    printf("Password Game\n=============\n");
    printf("Enter your name (up to 8 characters): ");
    scanf("%8[^\n]%*c",backup);

    if(strlen(backup)<=0)
    {
        printf("wrong user name, abort game\n");
        return 0;
    }
    len=strlen(backup);
 
    printf("WELCOME ");
    printf("%s\n",backup);
     strcpy(rightPwd,backup); 
    for (j=0;j<len;j++){
        rightPwd[j]=(int)rightPwd[j]-1;
    }
   
   
    loop=len;
    do{
        if (loop==len){
            printf("Guess the password (up to 8 characters) %s: ",backup);
           
            
        }else if(loop==0){
            printf("Thou has failed\n");
            break;
        }else{
            printf("FALSE: Guess the password (up to 8 characters) ");
            for (j=0;j<loop;j++){
                printf("%c",backup[j]);
            }
            printf(": ");
        }
       
        scanf("%8[^\n]%*c",guessPwd);
        if(strcmp(rightPwd,guessPwd)==0){
            printf("You got it, %s!!!\n",backup);
            break;
        }
         
        loop--;
    
    }while(loop>=0);
    printf("Game Over!");
return 0;
}


