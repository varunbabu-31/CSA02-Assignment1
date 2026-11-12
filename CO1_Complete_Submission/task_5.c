#include <stdio.h>
#include "billing.h"

long long compute_bill(int units)
{
    long long paise = FIXED_CHARGE_PAISE;
    int slab2 = 0;
    if (units < 0) return -1;
    if (units > SLAB2_UNITS)
        paise += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;
    if (units > SLAB1_UNITS) {
        slab2 = (units < SLAB2_UNITS) ? units - SLAB1_UNITS : 100;
        paise += (long long)slab2 * RATE2_PAISE;
    }
#ifdef DEBUG
    printf("DEBUG: units=%d, bill=%lld paise\n", units, paise);
#endif
    return paise;
}

int main(void)
{
    const int units = 150;
    const long long bill = compute_bill(units);
    printf("Units: %d\nBill: Rs %lld.%02lld\n", units,
           bill / 100, bill % 100);
    return 0;
}
