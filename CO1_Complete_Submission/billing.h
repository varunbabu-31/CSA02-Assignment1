#ifndef BILLING_H
#define BILLING_H

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#ifndef RATE2_PAISE
#define RATE2_PAISE 225
#endif
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000LL

long long compute_bill(int units);

#endif
