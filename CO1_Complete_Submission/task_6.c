#include <stdio.h>

int main(void)
{
    int previous, current;
    unsigned int units;
    long long bill_paise;

    printf("Enter previous meter reading (0-65535): ");
    if (scanf("%d", &previous) != 1 || previous < 0 || previous > 65535) {
        fprintf(stderr, "Invalid previous reading.\n");
        return 1;
    }
    printf("Enter current meter reading (0-65535): ");
    if (scanf("%d", &current) != 1 || current < 0 || current > 65535) {
        fprintf(stderr, "Invalid current reading.\n");
        return 1;
    }

    units = (unsigned int)(unsigned short)(current - previous);
    bill_paise = 5000LL;
    if (units > 200U) bill_paise += (long long)(units - 200U) * 450LL;
    if (units > 100U) {
        unsigned int slab2 = units < 200U ? units - 100U : 100U;
        bill_paise += (long long)slab2 * 225LL;
    }

    printf("Units consumed: %u\n", units);
    printf("Total bill: Rs %lld.%02lld\n",
           bill_paise / 100LL, bill_paise % 100LL);
    return 0;
}
