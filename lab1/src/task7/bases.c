#include <limits.h>
#include <stdio.h>

#include <task7/bases.h>

int32_t CharToInt(char symbol,
                  uint64_t *result) {
    if (symbol >= '0'
     && symbol <= '9') {
        *result = symbol - '0';
    } else if (symbol >= 'A'
            && symbol <= 'Z') {
        *result = 10 + (symbol - 'A');
    } else if (symbol >= 'a'
            && symbol <= 'z') {
        *result = 10 + (symbol - 'a');
    } else {
        return 1;
    }

    return 0;
}

const char *CleanupNumber(const char *number) {
    while (*number == '0') {
        ++number;
    }

    if (*number == '\0') {
        --number;
    }

    return number;
}

int32_t MinBase(const char *number,
                uint64_t *result) {
    uint64_t max_digit = 0;

    while (*number != '\0') {
        uint64_t digit = 0;

        if (CharToInt(*number,
                      &digit)) {
            printf("[ERROR] Unknown symbol input file!\n");

            return 1;
        }

        if (digit > max_digit) {
            max_digit = digit;
        }

        ++number;
    }

    if (max_digit + 1 < 2) {
        *result = 2;
    } else {
        *result = max_digit + 1;
    }

    return 0;
}

int32_t ConvertNTo10(const char *number,
                     uint64_t base,
                     uint64_t *result) {
    uint64_t decimal = 0;
    uint64_t digit = 0;

    while (*number != '\0') {
        if (CharToInt(*number,
                      &digit)) {
            return 1;
        }

        if (digit >= base) {
            printf("[INTERNAL] Base of input string and input base are different!\n");

            return 1;
        }

        if (decimal > (ULLONG_MAX - digit) / base) {
            printf("[ERROR] Too big input number!\n");

            return 1;
        }

        decimal = decimal * base + digit;
        ++number;
    }

    *result = decimal;

    return 0;
}

int32_t MinBases(FILE *in_file,
                 FILE *out_file) {
    char number[64];

    while (fscanf(in_file, "%63s", number) == 1) {
        const char *clean = CleanupNumber(number);

        uint64_t base = 0;
        if (MinBase(number,
                    &base)) {
            return 1;
        }

        uint64_t decimal = 0;
        if (ConvertNTo10(clean,
                         base,
                         &decimal)) {
            return 1;
        }

        fprintf(out_file,
                "%s %lu %lu\n",
                clean,
                base,
                decimal);
    }

    return 0;
}
