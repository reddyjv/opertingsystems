#include<stdio.h>
#include<stdlib.h>
int mutex=1,x=0,full=0,empty=3;
int wait(int s){
    return --s;
}
int signal(int s){
    return ++s;
}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    ++x;
    printf("\nproducer produced item %d:\n",x);
    mutex=signal(mutex);

}
void consumer(){
     mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    
    printf("\n consumer consumed item %d:\n",x);
    --x;
    mutex=signal(mutex);
}
int main(){
    int ch,i;
    while(1){
    printf("\n 1.producer\n2.consumer\nexit\n");
    printf("enter choice\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:if(mutex==1 && empty!=0){
            producer();
        }
        else{
            printf("\nbuffer is full\n");
        }
        break;
        case 2:if(mutex==1 && full!=0){
            consumer();
        }
        else{
            printf("\nbuffer is empty\n");
        }
        break;
        case 3:exit(0);
    }
    }
}
