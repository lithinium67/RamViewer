/*
MIT License

Copyright (c) 2024 Lithinium

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <ram.h>

/* Remove 'Kb' at the end of the line read */
static void removeKb(int length, char *string){
    for (int i = length - 1; i >= 0; i--) {
        if (!isdigit(string[i])) {
            string[i] = '\0';
        } else {
            break;
        }
    }

    return;
}

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

    removeKb(buffLength, buffRead);

    totalRam = strtol(buffRead, NULL, 10);
    
    return totalRam;
}

unsigned long getAvaibleRam(){

    char buffRead[MAX_BUFF];

    unsigned long freeRam;

    char* tempStr = (char *) malloc(MAX_BUFF);
    
    FILE *memInfo = fopen("/proc/meminfo", "r");

    if (!memInfo){
        fprintf(stderr, "Error: Open /proc/meminfo Failed");

        return 2;
    }

    fgets(tempStr, sizeof(buffRead), memInfo); // jump to second line
    fgets(tempStr, sizeof(buffRead), memInfo); // jump to Three line

    free(tempStr);


    fseek(memInfo, 16, SEEK_CUR);

    fgets(buffRead, sizeof(buffRead), memInfo); // read line

    fclose(memInfo);

    int buffLength = strlen(buffRead);

    removeKb(buffLength, buffRead);

    freeRam = strtol(buffRead, NULL, 10);

    return freeRam;
}

unsigned long getUsedRam(){
    long totalRam = getTotalRam();
    long freeRam = getAvaibleRam();

    return totalRam - freeRam;
}
