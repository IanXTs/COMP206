#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Producer.h"
#include "Consumer.h"

//parter
//Bridget Liu
//260705926


int main(int argc, const char * argv[]) {
    //create TURN and DATA files
    fclose(fopen(DATAFILE, "w"));
    FILE * temp = fopen(TURNFILE, "w");
    fputc('0', temp);
    fclose(temp);
    //process created using fork()
    int pid = fork();
    
    if (pid<0) {
        printf("fork error!");
        exit(0);
    }
    
    //call producer
    if (pid>0) {
    producer();
   	usleep(2000);
	 }
    //call consumer
	if(pid==0) {
        consumer();
    }
    
    
    return 0;
}
