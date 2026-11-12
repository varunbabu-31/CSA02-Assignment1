#include <stdio.h>
#include <limits.h>

#define METER_MAX 65535
#define METER_MODULUS 65536U
#define MAX_VALID_UNITS_PER_PERIOD 10000U
#define SLAB1_UNITS 100U
#define SLAB2_UNITS 200U
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL

static int get_consumption(int previous, int current, unsigned int *units)
{
    if (previous < 0 || previous > METER_MAX || current < 0 || current > METER_MAX)
        return 0;
    *units = (unsigned int)(unsigned short)(current - previous);
    /* Operational safeguard: a huge modulo difference is likely a bad/out-of-order reading.
       The co-operative must set this limit from its actual meter and billing-period policy. */
    if (*units > MAX_VALID_UNITS_PER_PERIOD) return 0;
    return 1;
}

static long long compute_bill(unsigned int units)
{
    long long bill = FIXED_CHARGE_PAISE;
    if (units > SLAB2_UNITS)
        bill += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;
    if (units > SLAB1_UNITS) {
        unsigned int slab2 = units < SLAB2_UNITS ? units - SLAB1_UNITS : SLAB2_UNITS - SLAB1_UNITS;
        bill += (long long)slab2 * RATE2_PAISE;
    }
    return bill;
}

int main(void)
{
    int previous, current;
    unsigned int units;
    const unsigned int sample_units[] = {0, 100, 150, 200, 350};
    long long five_bill_total = 0;

    printf("Enter previous meter reading: ");
    if (scanf("%d", &previous) != 1) { fprintf(stderr, "Invalid previous reading.\n"); return 1; }
    printf("Enter current meter reading: ");
    if (scanf("%d", &current) != 1) { fprintf(stderr, "Invalid current reading.\n"); return 1; }
    if (!get_consumption(previous, current, &units)) {
        fprintf(stderr, "Invalid or implausible meter readings.\n");
        return 1;
    }
    printf("Units consumed: %u\n", units);
    printf("Total bill: Rs %lld.%02lld\n", compute_bill(units) / 100, compute_bill(units) % 100);

    puts("\nFive-bill hand-check:");
    for (size_t i = 0; i < sizeof sample_units / sizeof sample_units[0]; ++i) {
        long long p = compute_bill(sample_units[i]);
        printf("%3u units -> Rs %lld.%02lld\n", sample_units[i], p / 100, p % 100);
        five_bill_total += p;
    }
    printf("Five-bill total: Rs %lld.%02lld\n", five_bill_total / 100, five_bill_total % 100);
    return 0;
}
