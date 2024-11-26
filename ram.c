#include <stdio.h>
//#include <string.h>

#define MAX_BUFF 25

long getTotalRam(void){
   
    FILE *meminfo = fopen("/proc/meminfo", "r");

    char buffRead[MAX_BUFF];

    long TotalRam;

    if (!meminfo){
        fprintf(stderr, "Error: Open /proc/meminfo Failed");

        return 2;
    }

    /*

    ToDo:
    
    Tomar solo los numeros de la cadena de texto.

    + esto usando fseek() para posicionar el cursor por detras de los numeros y leer la cadena de texto

    convertirlo a un long long int y asignarlo a la variable TotalRam.
    
    */

    fgets(buffRead, sizeof(buffRead), meminfo);

    fprintf(stdout, "%s\n", buffRead);

    fclose(meminfo);

    return TotalRam;
}
