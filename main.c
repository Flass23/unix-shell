#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "get_input.h"

#include <dirent.h>
#include <stddef.h>
#include <unistd.h>


#define MAX_QUEUE_SIZE 10
char buffersize[1024];

char command[20];


int main(){
    do
    
    {
        printf( "\n [Pie Shell]-[%s] \n", getcwd(buffersize, sizeof(buffersize)));
        printf("__$ ");
        

       if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("Error reading input \n");
        }
        // Remove trailing newline character from fgets
        size_t length = strlen(command);
        
        if (length > 0 && command[length - 1] == '\n') {
            command[length - 1] = '\0';
            parse_str(command);   
        }
        else{
            printf(" " );
        }
    } while (true);
    
    
    return EXIT_SUCCESS;;
}    


