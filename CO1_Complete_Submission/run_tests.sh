#!/usr/bin/env bash
set -euo pipefail
mkdir -p build evidence
FLAGS='-std=c11 -Wall -Wextra -Wpedantic -Werror'
for n in 2 3 4 5 6 7 8 9 10 11 12; do
  gcc $FLAGS "task_${n}.c" -o "build/task_${n}"
done
gcc $FLAGS task_2_types.c -o build/task_2_types
gcc $FLAGS task_2_float.c -o build/task_2_float
gcc $FLAGS -DDEBUG task_5.c -o build/task_5_debug
gcc $FLAGS -DRATE2_PAISE=230 task_3.c -o build/task_3_rate230
gcc -E task_4.c -o evidence/task_4_preprocessed.i
gcc -E task_8.c -o evidence/task_8_preprocessed.i
gcc -S task_8.c -o evidence/task_8_assembly.s
gcc -c task_8.c -o evidence/task_8_object.o
gcc evidence/task_8_object.o -o build/task_8_linked
./build/task_2 > evidence/task_2_output.txt
./build/task_2_types > evidence/task_2_types_output.txt
./build/task_2_float > evidence/task_2_float_example.txt
./build/task_3 > evidence/task_3_output.txt
./build/task_3_rate230 > evidence/task_3_rate230_output.txt
./build/task_4 > evidence/task_4_output.txt
./build/task_5 > evidence/task_5_output.txt
./build/task_5_debug > evidence/task_5_debug_output.txt
printf '1200\n1530\n' | ./build/task_6 > evidence/task_6_output.txt
./build/task_7 > evidence/task_7_output.txt
./build/task_8_linked > evidence/task_8_output.txt
printf '65400\n120\n' | ./build/task_9 > evidence/task_9_rollover_output.txt
printf '65535\n0\n' | ./build/task_9 > evidence/task_9_full_rollover_output.txt
./build/task_10 > evidence/task_10_output.txt
./build/task_11 > evidence/task_11_output.txt
printf '1000\n1000\n' | ./build/task_12 > evidence/task_12_output.txt
cp tariff.cfg build/tariff.cfg
printf '230 5000\n' > build/tariff.cfg
(cd build && printf '1000\n1000\n' | ./task_12) > evidence/task_12_rate_change_output.txt
# Negative and malformed inputs must fail.
if printf 'abc\n' | ./build/task_6 >/dev/null 2>&1; then echo 'Task 6 accepted letters unexpectedly' >&2; exit 1; fi
if printf -- '-1\n0\n' | ./build/task_6 >/dev/null 2>&1; then echo 'Task 6 accepted a negative reading unexpectedly' >&2; exit 1; fi
if printf '5000\n4500\n' | ./build/task_9 >/dev/null 2>&1; then echo 'Task 9 accepted an implausible decrease unexpectedly' >&2; exit 1; fi
printf 'All C11 builds and smoke/negative-input tests passed.\n'
