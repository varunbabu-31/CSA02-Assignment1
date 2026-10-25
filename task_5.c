#include <stdio.h>
#include "billing.h"

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    if (units > 200)
        paise += (long)(units - 200) * RATE3_PAISE;

    if (units > 100)
    {
        int slab2 = (units < 200) ? units - 100 : 100;
        paise += (long)slab2 * RATE2_PAISE;
    }

#ifdef DEBUG
    printf("DEBUG: units=%d, bill=%ld paise\n", units, paise);
#endif

    return paise;
}

int main(void)
{
    int units = 150;
    long bill = compute_bill(units);

    printf("Units: %d\n", units);
    printf("Bill: Rs %ld.%02ld\n", bill / 100, bill % 100);

    return 0;
}