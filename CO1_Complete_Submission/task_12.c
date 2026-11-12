#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

#define READINGS_PER_YEAR 35040ULL
#define MAX_YEAR_ENERGY_WH 100000000000ULL
#define MAX_RATE_PAISE_PER_KWH 1000000ULL
#define PEAK_MULTIPLIER_PERCENT 120ULL

static int charge_from_wh(uint64_t wh, uint64_t rate_paise, int peak, uint64_t *charge)
{
    uint64_t multiplier = peak ? PEAK_MULTIPLIER_PERCENT : 100ULL;
    uint64_t denominator = 100000ULL; /* Wh-to-kWh (1000) and percent (100). */
    if (wh > MAX_YEAR_ENERGY_WH || rate_paise > MAX_RATE_PAISE_PER_KWH) return 0;
    if (wh != 0 && rate_paise > (UINT64_MAX - denominator / 2ULL) / (wh * multiplier)) return 0;
    *charge = (wh * rate_paise * multiplier + denominator / 2ULL) / denominator;
    return 1;
}

int main(void)
{
    uint64_t offpeak_wh, peak_wh, rate_paise, fixed_paise;
    uint64_t offpeak_charge, peak_charge, total;
    FILE *config = fopen("tariff.cfg", "r");
    if (!config) {
        fprintf(stderr, "Cannot open tariff.cfg. Place it beside the executable.\n");
        return 1;
    }
    if (fscanf(config, "%" SCNu64 " %" SCNu64, &rate_paise, &fixed_paise) != 2) {
        fclose(config);
        fprintf(stderr, "tariff.cfg must contain: base_rate_paise_per_kWh fixed_charge_paise\n");
        return 1;
    }
    fclose(config);
    if (rate_paise > MAX_RATE_PAISE_PER_KWH || fixed_paise > UINT64_MAX / 2ULL) {
        fprintf(stderr, "Tariff values exceed the permitted range.\n");
        return 1;
    }

    printf("Enter annual off-peak energy (Wh): ");
    if (scanf("%" SCNu64, &offpeak_wh) != 1 || offpeak_wh > MAX_YEAR_ENERGY_WH) {
        fprintf(stderr, "Invalid off-peak energy.\n"); return 1;
    }
    printf("Enter annual peak energy (Wh): ");
    if (scanf("%" SCNu64, &peak_wh) != 1 || peak_wh > MAX_YEAR_ENERGY_WH) {
        fprintf(stderr, "Invalid peak energy.\n"); return 1;
    }
    if (offpeak_wh > MAX_YEAR_ENERGY_WH - peak_wh) {
        fprintf(stderr, "Combined annual energy exceeds the configured limit.\n"); return 1;
    }
    if (!charge_from_wh(offpeak_wh, rate_paise, 0, &offpeak_charge) ||
        !charge_from_wh(peak_wh, rate_paise, 1, &peak_charge) ||
        offpeak_charge > UINT64_MAX - peak_charge ||
        offpeak_charge + peak_charge > UINT64_MAX - fixed_paise) {
        fprintf(stderr, "Bill calculation overflow.\n"); return 1;
    }
    total = fixed_paise + offpeak_charge + peak_charge;
    printf("Readings per year: %" PRIu64 "\n", (uint64_t)READINGS_PER_YEAR);
    printf("Base tariff: %" PRIu64 " paise/kWh\n", rate_paise);
    printf("Peak tariff: 20%% surcharge\n");
    printf("Off-peak charge: Rs %" PRIu64 ".%02" PRIu64 "\n", (uint64_t)(offpeak_charge / 100ULL), (uint64_t)(offpeak_charge % 100ULL));
    printf("Peak charge: Rs %" PRIu64 ".%02" PRIu64 "\n", (uint64_t)(peak_charge / 100ULL), (uint64_t)(peak_charge % 100ULL));
    printf("Fixed charge: Rs %" PRIu64 ".%02" PRIu64 "\n", (uint64_t)(fixed_paise / 100ULL), (uint64_t)(fixed_paise % 100ULL));
    printf("Total bill: Rs %" PRIu64 ".%02" PRIu64 "\n", (uint64_t)(total / 100ULL), (uint64_t)(total % 100ULL));
    return 0;
}
