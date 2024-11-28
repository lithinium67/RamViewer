/*

Copyright (c) 2024 Lithinium

This code is licensed under the MIT license

See the LICENSE File for Details

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_BUFF 64

unsigned long getTotalRam(void){
   
    char buffRead[MAX_BUFF];
    
    unsigned long totalRam;

    FILE *memInfo = fopen("/proc/meminfo", "r");

    if (!memInfo){
        fprintf(stderr, "Error: Open /proc/meminfo Failed");

        return 2;
    }


    fseek(memInfo, 16, SEEK_SET);

    fgets(buffRead, sizeof(buffRead), memInfo);

    fclose(memInfo);
    
    int buffLength = strlen(buffRead);

    // remove " Kb"
    for (int i = buffLength - 1; i >= 0; i--) {
        if (!isdigit(buffRead[i])) {
            buffRead[i] = '\0';
        } else {
            break;
        }
    }

    totalRam = strtol(buffRead, NULL, 10);
    
    return totalRam;
}

unsigned long getAvaibleRam(){

    FILE *memInfo = fopen("/proc/meminfo", "r");

    if (!memInfo){
        fprintf(stderr, "Error: Open /proc/meminfo Failed");

        return 2;
    }

    char buffRead[MAX_BUFF];

    unsigned long freeRam;

    char* tempStr = (char *) malloc(MAX_BUFF);

    fgets(tempStr, sizeof(buffRead), memInfo); // jump to second line
    fgets(tempStr, sizeof(buffRead), memInfo); // jump to Three line

    free(tempStr);


    fseek(memInfo, 16, SEEK_CUR);

    fgets(buffRead, sizeof(buffRead), memInfo); // read line

    fclose(memInfo);

    int buffLength = strlen(buffRead);

    // remove " Kb"
    for (int i = buffLength - 1; i >= 0; i--) {
        if (!isdigit(buffRead[i])) {
            buffRead[i] = '\0';
        } else {
            break;
        }
    }

    freeRam = strtol(buffRead, NULL, 10);

    return freeRam;
}

unsigned long getUsedRam(){
    long totalRam = getTotalRam();
    long freeRam = getAvaibleRam();

    return totalRam - freeRam;
}