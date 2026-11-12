# C Programming Assignment 1 (CO1)

**Grama Jyothi Rural Electricity Billing System**

This repository contains the completed CO1 assignment: analysis, C programs, test evidence, compilation-stage outputs, pseudocode, a UML-style flowchart, and the smart-meter redesign.

## Contents

- `Assignment_Report.md` – full report for Tasks 1–12, including data-type justifications, alternatives, complexity, test tables and design recommendations.
- `Assignment_Report.docx` – formatted Word copy of the report (available as the accompanying download).
- `task_2.c` … `task_12.c` – C programs for the practical tasks. Task 1 is an analysis task documented in the report.
- `task_2_types.c` and `task_2_float.c` – supplementary type-range and floating-point experiments.
- `billing.h` – shared tariff constants and function declaration used in Task 5.
- `tariff.cfg` – runtime tariff configuration for Task 12 (`base_rate_paise_per_kWh fixed_charge_paise`).
- `evidence/` – recorded program outputs and GCC preprocessing/assembly/object outputs. Existing uploaded images are retained; text logs provide reproducible test evidence.
- `diagrams/` – Mermaid flowchart source.
- `run_tests.sh` – reproducible GCC build and smoke tests.

## Compile

Use GCC with C11 support. From the repository root:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror task_2.c -o task_2
./task_2
```

Compile the debug version of Task 5:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -DDEBUG task_5.c -o task_5_debug
```

Test the tariff revision in Task 3:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -DRATE2_PAISE=230 task_3.c -o task_3_rate230
```

For Task 12, keep `tariff.cfg` in the program's working directory. Its first value is the base rate in paise per kWh; its second value is the fixed charge in paise. Edit the file to revise the tariff without recompiling.

## Important assumptions

- The original meter is a 16-bit register with modulus 65,536.
- The Task 9 demonstration uses a 10,000-unit plausibility limit per billing period. This is an explicit example safeguard and must be adjusted to the actual meter and billing-period policy.
- Task 12 uses explicit defensive upper bounds for annual energy and tariff values. These must be reviewed against the co-operative's actual meter specifications before deployment.
- The float totals are compiler/platform dependent. The report records the actual output from GCC 14.2.0 in a 64-bit Linux environment.

## Student verification

The report is intended as a study and submission aid. Run the programs on your own computer, capture your own terminal screenshots if required, and make sure you can explain the rollover formula, paise arithmetic, compiler stages, and smart-meter redesign during the viva.

The old `C Programming Assignment 1.docx` file is retained as the earlier Task 1 draft. Use `Assignment_Report.md` for the complete report.
