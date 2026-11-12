#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    const uint64_t households = 800000ULL;
    const uint64_t sample_bill_paise = 95000ULL;
    const uint64_t district_total = households * sample_bill_paise;
    printf("Recommended meter type: uint16_t (%zu bytes)\n", sizeof(uint16_t));
    printf("Recommended household count type: uint32_t (%zu bytes)\n", sizeof(uint32_t));
    printf("Recommended money accumulator: uint64_t (%zu bytes)\n", sizeof(uint64_t));
    printf("District sample total: Rs %" PRIu64 ".%02" PRIu64 "\n",
           (uint64_t)(district_total / 100ULL), (uint64_t)(district_total % 100ULL));
    return 0;
}
