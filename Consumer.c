#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Consumer.h"
//contains only the forked consumer() function
//read data from DATAPATH defined in Producer.h and print on the screen
void consumer(){
	
    // initialization
    char tmp;
    char check;
    FILE *turn=NULL;
	
	//infinite loop
    while (1) {
		
        //wait producer to create the turnfile
		
        do{
	        FILE * data;
            if ( (data=fopen(DATAFILE, "r")) == NULL) { return; }
            turn = fopen(TURNFILE,"rt");  
	        check = fgetc(turn);
            fclose(data);
            fclose(turn);
            usleep(5000);
        }while(check == '0'); 
        
		//extracts the value from the DATA then print to stdout
        FILE * data = fopen(DATAFILE, "rt");
        tmp = fgetc(data);
        printf("%c",tmp);
        fclose(data);
        
        //update status and gives the TURN back to the producer
        turn = fopen(TURNFILE, "w");
        fprintf(turn, "%c", '0');//write 0 to indicate producer TURN
        fclose(turn);
    }
	
}
