
#include <stdio.h>

typedef unsigned short meter_t;

int main(void)
{
    meter_t previous, current;
    unsigned int units;

    printf("Enter previous meter reading: ");
    if (scanf("%hu", &previous) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter current meter reading: ");
    if (scanf("%hu", &current) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if (current >= previous) {
        units = current - previous;
    } else {
        units = 65536U - previous + current;
    }

    printf("Units consumed: %u\n", units);

    return 0;
}
