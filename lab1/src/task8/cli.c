#include <stdio.h>
#include <string.h>

#include <task8/cli.h>
#include <task8/convert.h>

int32_t ReadInput(uint64_t *base,
                  char *number) {
    int64_t tmp_base = 0;
    if (scanf("%ld", &tmp_base) != 1
     || getchar() != '\n') {
        printf("[ERROR] First input must contain only base!\n");

        return 1;
    }

    if (tmp_base < 2
     || tmp_base > 36) {
        printf("[ERROR] Wrong base!\n");

        return 1;
    }

    *base = (uint64_t) tmp_base;

    char token[MAX_NUMBER_SIZE + 1];

    uint64_t max_abs_value = 0;
    strcpy(number, "0");

    while (scanf("%64s", token) == 1) {
        if (strcmp(token, "Stop") == 0) {
            break;
        }

        const char *clean = CleanupNumber(token);

        uint64_t value = 0;
        if (ConvertNTo10(clean,
                         *base,
                         &value)) {
            return 1;
        }

        if (value > max_abs_value) {
            max_abs_value = value;
            strcpy(number, clean);
        }
    }

    return 0;
}
