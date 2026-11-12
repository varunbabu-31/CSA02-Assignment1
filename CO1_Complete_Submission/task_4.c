#include <stdio.h>

#define RUPEES_TO_PAISE(r) ((r) * 100)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static inline int square_inline(int x) { return x * x; }
static inline int max_inline(int a, int b) { return a > b ? a : b; }

int main(void)
{
    int i = 3, j = 5;
    int side_effect_i = 12;
    int macro_result;

    printf("5 rupees = %d paise\n", RUPEES_TO_PAISE(5));
    printf("SQUARE(5) = %d\n", SQUARE(5));
    printf("SQUARE(5 + 1) = %d\n", SQUARE(5 + 1));
    printf("MAX(3, 5) = %d\n", MAX(i, j));
    macro_result = MAX(side_effect_i++, 10);
    printf("MAX(side_effect_i++, 10) = %d; i is now %d\n",
           macro_result, side_effect_i);
    printf("inline square(6) = %d\n", square_inline(6));
    printf("inline max(3, 5) = %d\n", max_inline(i, j));
    return 0;
}
