#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
    pid_t pid;
    pid=vfork();
    if(pid==-1){
        perror("vfork");
        return 1;
    }
    else if(pid==0){
        printf("child process: hello i'm the child");
        printf("child process :my pid is %d\n",getpid());
        printf("child process:my parents id is %d\n",getppid());
        _exit(0);
    }
        else{
                printf("parent process: hello i'm the parent");
        printf("child process :my pid is %d\n",getpid());
        printf("child process:my parents id is %d\n",pid);
        int status;
        waitpid(pid,&status,0);
        if(WIFEXITED(status)){
            printf("parent process:child process terminated normally\n");
        }
        else{
            printf("parent process:child process terminated abnormally\n");
        }
    }
    return 0;
}