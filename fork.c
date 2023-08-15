#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        printf("error:fork failed");
        return 1;

    }
    else if(pid==0){
        printf("\n This is child process pid id %d\n",getpid());
        printf("this is parent process pid is %d\n",getppid());
        execlp("/bin/ls","Is",NULL);
        printf("this should not be printed if exec() is succesful\n");
        return 0;
    }
    else{
        printf("this is parent process with pid %d\n",getpid());
        printf("this is child process pid is %d\n",pid);
        int status;
        wait(&status);
        printf("child process exited with status;%d\n",status);
        return 0;


    }


}