#include <stdio.h>

int main(void)
{
    float float_total = 0.0f;
    long long paise_total = 0;
    for (int i = 0; i < 4000; ++i) {
        float_total += 0.01f; /* one paise expressed as rupees */
        paise_total += 1;
    }
    printf("Float total: Rs %.9f\n", float_total);
    printf("Integer paise total: %lld paise = Rs %lld.%02lld\n",
           paise_total, paise_total / 100, paise_total % 100);
    return 0;
}
