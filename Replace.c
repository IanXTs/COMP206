//
//  Replace.c
//  A4
//
//  Copyright © 2017 Ian Tsai. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FindRecord(char *filename, char *name, char record[]) {
    FILE *opfile = fopen(filename, "rt");
    if (opfile == NULL) {
        exit(1);
    }
    char singleLine[1000] = {'\0'};
    while(fgets(singleLine, 1000, opfile)) {
        int sameb = 1;
        for (int i = 0; singleLine[i]!=','; i++) {
            if(name[i] != singleLine[i]){
                sameb = 0;
                break;
            }
        }
        if (sameb == 1) {
            for(int j = 0; j < sizeof(singleLine); j++){
                record[j]=singleLine[j];
            }
        }
    }
    if (record[0] == '\0') {
        printf("This name does not exist on the list.\n");
        exit(0);
    }
    fclose(opfile);
}

void Replace(char *name, char *newname, char record[]) {
    char tmp[1000] = {'\0'};
    int i = 0;
    while(*(record+i) != ','){
        i++;
    }
    int j = 0;
    while (*(newname+j) != '\n') {
        *(tmp+j) = *(newname+j);
        j++;
    }
    int k = 0;
    while (*(record+i+k) != '\0') {
        *(tmp+j+k) = *(record+i+k);
        k++;
    }
    *(tmp+j+k) = '\0';
    int l = 0;
    while (*(tmp+l) != '\0') {
        *(record+l) = *(tmp+l);
        l++;
    }
    *(record+l)='\0';
}

void SaveRecord(char *filename, char *name, char record[]) {
     char singleLine[1000] = {'\0'};
     FILE *opfile = fopen(filename, "rt");
     FILE *tmp = fopen("tmp.csv", "wt");
     int n=0;
       while(fgets(singleLine, 1000, opfile)) {
           int sameb = 1;
         for (int i = 0; singleLine[i]!=','; i++) {
                if(name[i] != singleLine[i]){
                     sameb = 0;
                break;
                 }
             }
             if (sameb == 1) {
                 fprintf(tmp, "%s", record);
            } else {
                fprintf(tmp, "%s", singleLine);
            }
           n++;
       }
       fclose(opfile);
       fclose(tmp);
    char newLine[1000] = {'\0'};
    FILE *tmpNew = fopen("tmp.csv", "rt");
    FILE *opfileNew = fopen(filename, "wt");
    while(fgets(newLine, 1000, tmpNew)){
        fprintf(opfileNew, "%s", newLine);
    }
    fclose(opfileNew);
    fclose(tmpNew);

}

int main() {
    printf("Please enter a name: ");
    char name[150] = "\0";
    char newname[150] = "\0";
    char *filename = "phonebook.csv";
    char record[1000] = {'\0'};
    fgets(&name, 150, stdin);
    FindRecord(filename, name, record);
    printf("record: %s\n", record);
    printf("Please enter the replacement name: ");
    fgets(&newname, 150, stdin);
    Replace(name, newname, record);
    printf("replaced record: %s\n", record);
    SaveRecord(filename, name, record);
    return 0;
}

//Ian Tsai 260741766

