#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    const int counts[] = {4000, 60000, 800000};
    const long long one_bill_paise = 95000LL;
    printf("One household bill: Rs 950.00\n\n");
    for (size_t i = 0; i < sizeof counts / sizeof counts[0]; ++i) {
        const int n = counts[i];
        long long total_paise = 0;
        float total_float = 0.0f;
        for (int j = 0; j < n; ++j) {
            total_paise += one_bill_paise;
            total_float += 950.0f;
        }
        printf("Households: %d\n", n);
        printf("Integer paise total: Rs %lld.%02lld\n", total_paise / 100, total_paise % 100);
        printf("Float total:          Rs %.2f\n", total_float);
        printf("Float minus integer:  Rs %.2f\n\n", (double)total_float - (double)total_paise / 100.0);
    }
    printf("sizeof(int)=%zu, INT_MAX=%d\n", sizeof(int), INT_MAX);
    printf("sizeof(long)=%zu, LONG_MAX=%ld\n", sizeof(long), LONG_MAX);
    printf("sizeof(long long)=%zu, LLONG_MAX=%lld\n", sizeof(long long), LLONG_MAX);
    printf("FLT_MANT_DIG=%d, FLT_EPSILON=%.8g\n", FLT_MANT_DIG, FLT_EPSILON);
    return 0;
}
