#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    printf("Hello World (pid %d)\n",(int)getpid());
    int rc = fork();
    if(rc<0){
            fprintf(stderr,"fork failed\n");
            exit(1);
    }else{
        if(rc ==0){
            printf("Hello,i'm a child (pid %d)\n",(int)getpid);
        }else{
            printf("Hello, i'm a parent of %d (pid:%d)\n",rc,(int)getpid());
        }
    }
    return 0;
}