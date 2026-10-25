
#include <stdio.h>

#define METER_MAX 65535
#define METER_RANGE 65536
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE2_PAISE 225
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000L

long compute_bill(unsigned int units)
{
    long bill = FIXED_CHARGE_PAISE;

    if (units > SLAB2_UNITS)
        bill += (long)(units - SLAB2_UNITS) * RATE3_PAISE;

    if (units > SLAB1_UNITS) {
        unsigned int slab2 =
            (units < SLAB2_UNITS) ? units - SLAB1_UNITS : 100;
        bill += (long)slab2 * RATE2_PAISE;
    }

    return bill;
}

int main(void)
{
    int previous, current;
    unsigned int units;
    long bill;
    int tests[] = {0, 100, 150, 200, 350};
    int i;

    printf("Enter previous meter reading: ");
    if (scanf("%d", &previous) != 1 ||
        previous < 0 || previous > METER_MAX) {
        printf("Invalid previous reading\n");
        return 1;
    }

    printf("Enter current meter reading: ");
    if (scanf("%d", &current) != 1 ||
        current < 0 || current > METER_MAX) {
        printf("Invalid current reading\n");
        return 1;
    }

    if (current >= previous)
        units = (unsigned int)(current - previous);
    else
        units = (unsigned int)(METER_RANGE - previous + current);

    bill = compute_bill(units);

    printf("\nUnits consumed: %u\n", units);
    printf("Energy and fixed charges: Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    printf("\nTest bills:\n");
    for (i = 0; i < 5; i++) {
        bill = compute_bill((unsigned int)tests[i]);
        printf("%3d units -> Rs %ld.%02ld\n",
               tests[i], bill / 100, bill % 100);
    }

    return 0;
}
