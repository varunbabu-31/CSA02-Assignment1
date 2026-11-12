#include <stdio.h>

int main(void)
{
    printf("5 / 2 = %d (integer division discards the fraction)\n", 5 / 2);
    printf("(double)(5 / 2) = %.1f (cast happens after division)\n", (double)(5 / 2));
    printf("5.0 / 2 = %.1f (floating-point division)\n", 5.0 / 2);
    printf("0.1 + 0.2 = %.17f\n", 0.1 + 0.2);
    printf("(0.1 + 0.2) == 0.3: %s\n", (0.1 + 0.2) == 0.3 ? "true" : "false");
    printf("(int)3.9 = %d (conversion truncates toward zero)\n", (int)3.9);
    printf("-7 / 2 = %d (integer division truncates toward zero)\n", -7 / 2);
    return 0;
}
