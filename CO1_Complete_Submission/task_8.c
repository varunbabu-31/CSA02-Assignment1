#include <stdio.h>

static int add_fixed_charge(int energy_paise)
{
    return energy_paise + 5000;
}

int main(void)
{
    const int energy_paise = 11250;
    printf("Energy charge: Rs %d.%02d\n", energy_paise / 100, energy_paise % 100);
    int total = add_fixed_charge(energy_paise);
    printf("Total bill: Rs %d.%02d\n", total / 100, total % 100);
    return 0;
}
