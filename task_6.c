
#include <stdio.h>

int main(void)
{
    int previous, current;
    unsigned int units;
    long bill_paise;

    printf("Enter previous meter reading: ");
    if (scanf("%d", &previous) != 1 || previous < 0 || previous > 65535)
    {
        printf("Invalid previous reading\n");
        return 1;
    }

    printf("Enter current meter reading: ");
    if (scanf("%d", &current) != 1 || current < 0 || current > 65535)
    {
        printf("Invalid current reading\n");
        return 1;
    }

    if (current >= previous)
        units = (unsigned int)(current - previous);
    else
        units = (unsigned int)(65536 - previous + current);

    bill_paise = 5000L;

    if (units > 200)
        bill_paise += (long)(units - 200) * 450;

    if (units > 100)
    {
        unsigned int slab2 = (units < 200) ? units - 100 : 100;
        bill_paise += (long)slab2 * 225;
    }

    printf("Units consumed: %u\n", units);
    printf("Total bill: Rs %ld.%02ld\n",
           bill_paise / 100, bill_paise % 100);

    return 0;
}
