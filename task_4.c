#include <stdio.h>

#define RUPEES_TO_PAISE(r) ((r) * 100)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static inline int square(int x)
{
    return x * x;
}

static inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int a = 5, b = 8;

    printf("5 rupees = %d paise\n", RUPEES_TO_PAISE(5));
    printf("Square of 5 = %d\n", SQUARE(5));
    printf("Square of 5+1 = %d\n", SQUARE(5 + 1));
    printf("Maximum of 5 and 8 = %d\n", MAX(a, b));
    printf("Inline square of 6 = %d\n", square(6));
    printf("Inline maximum = %d\n", maximum(a, b));

    return 0;
}