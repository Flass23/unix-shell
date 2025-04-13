#include <stdc-predef.h>
#include <stdio.h>
#include "Queue.h"
#include <string.h>
#include "execute.h"
#include <sys/stat.h>

void parse_str(char* str){
    char commanddir[MAX_QUEUE_SIZE] = "usr/bin/";

    Queue* arguments = createQueue();

  
    char* token = strtok(str, " ");
  
    while(token != NULL){
        enqueue(arguments, token);
        token = strtok(NULL, " ");
    

    char* command = front(arguments); // get the first arguments which is the command
    //size_t lenth = strlen(commanddir1);
    //memset(commanddir1,lenth, 0);
    //strcpy(commanddir, commanddir1);
 
    strcat(commanddir, command);

    if (command != NULL) {
       
        execute_command(commanddir, arguments); // call the execute_command func from execute.h
       
            
          
        }
    else {
        printf("No command!\n");
    }

    //execute the command with argz
   

}
 }