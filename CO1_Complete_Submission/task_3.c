#include <stdio.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#ifndef RATE2_PAISE
#define RATE2_PAISE 225
#endif
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000LL

long long compute_bill(int units)
{
    long long paise = FIXED_CHARGE_PAISE;
    int slab2_units = 0;

    if (units < 0) return -1;
    if (units > SLAB2_UNITS)
        paise += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;
    if (units > SLAB1_UNITS) {
        slab2_units = (units < SLAB2_UNITS)
                    ? units - SLAB1_UNITS
                    : SLAB2_UNITS - SLAB1_UNITS;
        paise += (long long)slab2_units * RATE2_PAISE;
    }
    /* RATE1_PAISE is zero, but the first slab is explicit in the design. */
    return paise;
}

int main(void)
{
    const int tests[] = {0, 100, 150, 200, 350};
    const size_t count = sizeof tests / sizeof tests[0];
    for (size_t i = 0; i < count; ++i) {
        long long p = compute_bill(tests[i]);
        printf("%3d units -> Rs %lld.%02lld\n", tests[i], p / 100, p % 100);
    }
    return 0;
}
