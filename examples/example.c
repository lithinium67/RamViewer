#include <stdio.h>

#include "ram.h"

int main(){
    const unsigned long total_ram = getTotalRam();

    printf("%lu\n", total_ram);

    const unsigned long ava_ram = getAvaibleRam();

    printf("%lu\n", ava_ram);

    const unsigned long used_ram = getUsedRam();

    printf("%lu\n", used_ram);
}