
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int counts[] = {4000, 60000, 800000};
    int i, j;

    printf("Each household bill = Rs 950.00\n\n");

    for (i = 0; i < 3; i++) {
        int n = counts[i];
        long long total_paise = 0;
        float total_float = 0.0f;

        for (j = 0; j < n; j++) {
            total_paise += 95000LL;
            total_float += 950.0f;
        }

        printf("Households: %d\n", n);
        printf("Integer total: Rs %lld.%02lld\n",
               total_paise / 100, total_paise % 100);
        printf("Float total:   Rs %.2f\n", total_float);
        printf("Difference:    Rs %.2f\n\n",
               total_float - (float)(total_paise / 100));
    }

    printf("int size: %zu bytes\n", sizeof(int));
    printf("long size: %zu bytes\n", sizeof(long));
    printf("long long size: %zu bytes\n", sizeof(long long));
    printf("INT_MAX: %d\n", INT_MAX);
    printf("LLONG_MAX: %lld\n", LLONG_MAX);

    return 0;
}
