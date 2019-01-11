#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Producer.h"

void producer(void){
    
    //open my txt file
    FILE * src = fopen(FILEPATH, "rt");
    FILE * turn=NULL;
    char bf;// we set bf to use producer/consumer
    int c = 0;
    
    while (1) {
       //while the end of the txt file is not reached
       //loop
    do{
	 turn = fopen(TURNFILE, "rt");
	 usleep(1000);
     bf = fgetc(turn);
	 }while(bf=='1');
	 fclose(turn);
        
        //read the next char
        c = fgetc(src);
        
        
        if (c==EOF) {
            //we exit when we reach EOF
        fclose(src);
	    remove(DATAFILE);
        remove(TURNFILE);
	    return;
        }

        //write a data file
        FILE* data = fopen(DATAFILE, "wt");
        fprintf(data, "%c",(char)c);
        fclose(data);
        
        //update turn file
        FILE * turn = fopen(TURNFILE, "w");
        fputc('1',turn);
        fclose(turn);
    }
}
