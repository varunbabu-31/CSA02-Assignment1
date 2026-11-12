#include <stdio.h>
#include <limits.h>

typedef unsigned short meter_t;

_Static_assert(USHRT_MAX == 65535U, "This task requires a 16-bit unsigned short meter register");

/* For a 16-bit register, conversion back to meter_t performs modulo 65536.
   This intentionally uses no if-else, as required by the assignment. */
unsigned int consumption(meter_t previous, meter_t current)
{
    return (unsigned short)(current - previous);
}

int main(void)
{
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",
           sizeof(meter_t), (unsigned)USHRT_MAX);
    printf("Consumption: %u units\n", consumption(1200, 1530));
    printf("Consumption: %u units\n", consumption(65400, 120));
    return 0;
}
