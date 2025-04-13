#include "Queue.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_QUEUE_SIZE 10




void copyFromQueue(Queue *myq, char *execParams[]){
    int i = 0;
    while(isEmpty(myq) == false){
        execParams[i] = front(myq);
        printf("%s", front(myq));
        dequeue(myq);
        i++;
    }//execParams[0]= NULL;
    
    //printf("\n copying done \n");
}

void execute_command(char* command, Queue *arguments){
    char* execParams[MAX_QUEUE_SIZE - 1];
    int found = 1;
    int status;
    pid_t wpid;
    
    if(found==1){
    copyFromQueue(arguments, execParams);
    __pid_t pid = fork();
    
    if(pid==0){
        
        execv(command, execParams);
        //if returns anything then the process had failed
        perror("execv failed");
        exit(EXIT_FAILURE);

    }   
    else if (pid > 0){
        do{
            wpid = waitpid(pid, &status, WUNTRACED);

        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
   
        //exit(EXIT_SUCCESS);
    }
    else{
        perror("fork failed");
        exit(EXIT_FAILURE);
}

    }
    
   




    
   

    

}