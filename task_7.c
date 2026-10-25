
#include <stdio.h>

int main(void)
{
    int units = 150;
    int rate_paise = 225;

    int wrong_bill = units * rate_paise / 100;
    double correct_bill = (double)(units * rate_paise) / 100.0;

    printf("Units: %d\n", units);
    printf("Rate: %d paise\n", rate_paise);
    printf("Integer calculation: Rs %d\n", wrong_bill);
    printf("Correct calculation: Rs %.2f\n", correct_bill);

    return 0;
}
