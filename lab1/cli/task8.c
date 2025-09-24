#include <stdio.h>
#include <stdint.h>

#include <task8/cli.h>
#include <task8/convert.h>

int main(void) {
    const uint64_t Bases[] = {9, 18, 27, 36};
    const uint64_t BasesCount = sizeof(Bases) / sizeof(Bases[0]);

    uint64_t base = 0;
    char number[MAX_NUMBER_SIZE + 1];

    if (ReadInput(&base,
                  number)) {
        return 1;
    }

    uint64_t decimal_number = 0;
    if (ConvertNTo10(number,
                     base,
                     &decimal_number)) {
        return 1;
    }

    printf("%lu : %s\n", base, number);

    char new_number[128];
    for (uint64_t i = 0; i < BasesCount; ++i) {
        if (Convert10ToN(decimal_number,
                         Bases[i],
                         new_number)) {
            return 1;
        }

        printf("%lu : %s\n", Bases[i], new_number);
    }

    return 0;
}
