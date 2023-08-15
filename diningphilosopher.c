#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define NUm_philosophers 5
#define Num_chopsticks 5
void dine(int);
pthread_t philosopher[NUm_philosophers];
pthread_mutex_t chopsticks[Num_chopsticks];
void dine(int n){
    printf("\n philosopher %d is thinking",n);
    pthread_mutex_lock(&chopsticks[n]);
    pthread_mutex_lock(&chopsticks[(n+1)%Num_chopsticks]);
    printf("\n philosopher %d is eating\n",n);
    sleep(3);
    pthread_mutex_unlock(&chopsticks[n]);
    pthread_mutex_unlock(&chopsticks[(n+1)%Num_chopsticks]);
    printf("\n philosopher %d is finished eating\n",n);


}
int main(){
    int i,status;
    void *msg;
    for(i=1;i<=Num_chopsticks;i++){
        status=pthread_mutex_init(&chopsticks[i],NULL);
        if(status==-1){
            printf("\n mutex initializationfailed");
            exit(1);
        }
    }
    for(i=1;i<=NUm_philosophers;i++){
        status=pthread_create(&philosopher[i],NULL,(void*)dine,(int*)i);
        if(status!=0){
            printf("thread creation error\n");
            exit(1);
        }

    }
    for(i=1;i<=NUm_philosophers;i++){
        status=pthread_join(philosopher[i],&msg);
        if(status!=0){
            printf("\n thread join failed");
            exit(1);
        }

    }
    for(i=1;i<=Num_chopsticks;i++){
        status=pthread_mutex_destroy(&chopsticks[i]);
        if(status!=0){
            printf("\n mutex destroyed\n");
            exit(1);
        }
    }
    return 0;
}
