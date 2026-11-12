#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("CHAR_BIT=%d\n", CHAR_BIT);
    printf("char: %zu byte(s), CHAR_MIN=%d, CHAR_MAX=%d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("unsigned char: %zu byte(s), UCHAR_MAX=%u\n", sizeof(unsigned char), UCHAR_MAX);
    printf("short: %zu byte(s), SHRT_MIN=%d, SHRT_MAX=%d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %zu byte(s), USHRT_MAX=%u\n", sizeof(unsigned short), USHRT_MAX);
    printf("int: %zu byte(s), INT_MIN=%d, INT_MAX=%d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned int: %zu byte(s), UINT_MAX=%u\n", sizeof(unsigned int), UINT_MAX);
    printf("long: %zu byte(s), LONG_MIN=%ld, LONG_MAX=%ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("long long: %zu byte(s), LLONG_MIN=%lld, LLONG_MAX=%lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("float: %zu byte(s), FLT_MIN=%g, FLT_MAX=%g, FLT_MANT_DIG=%d\n", sizeof(float), FLT_MIN, FLT_MAX, FLT_MANT_DIG);
    printf("double: %zu byte(s), DBL_MIN=%g, DBL_MAX=%g, DBL_MANT_DIG=%d\n", sizeof(double), DBL_MIN, DBL_MAX, DBL_MANT_DIG);
    return 0;
}
