
#include <stdio.h>

#define READINGS_PER_YEAR 35040LL

int main(void)
{
    long long offpeak_wh, peak_wh;
    long long rate_paise, fixed_paise;
    long long offpeak_charge, peak_charge, total;

    printf("Enter off-peak energy in Wh: ");
    if (scanf("%lld", &offpeak_wh) != 1 || offpeak_wh < 0) {
        printf("Invalid energy reading\n");
        return 1;
    }

    printf("Enter peak-hour energy in Wh: ");
    if (scanf("%lld", &peak_wh) != 1 || peak_wh < 0) {
        printf("Invalid energy reading\n");
        return 1;
    }

    printf("Enter base rate in paise per kWh: ");
    if (scanf("%lld", &rate_paise) != 1 || rate_paise < 0) {
        printf("Invalid tariff\n");
        return 1;
    }

    printf("Enter fixed charge in paise: ");
    if (scanf("%lld", &fixed_paise) != 1 || fixed_paise < 0) {
        printf("Invalid fixed charge\n");
        return 1;
    }

    /* Round charges to the nearest paise. */
    offpeak_charge =
        (offpeak_wh * rate_paise + 500) / 1000;

    /* Peak hours cost 20% extra. */
    peak_charge =
        (peak_wh * rate_paise * 120 + 50000) / 100000;

    total = fixed_paise + offpeak_charge + peak_charge;

    printf("\nReadings per year: %lld\n", READINGS_PER_YEAR);
    printf("Off-peak charge: Rs %lld.%02lld\n",
           offpeak_charge / 100, offpeak_charge % 100);
    printf("Peak-hour charge: Rs %lld.%02lld\n",
           peak_charge / 100, peak_charge % 100);
    printf("Fixed charge: Rs %lld.%02lld\n",
           fixed_paise / 100, fixed_paise % 100);
    printf("Total bill: Rs %lld.%02lld\n",
           total / 100, total % 100);

    return 0;
}
