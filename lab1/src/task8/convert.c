#include <limits.h>
#include <stdio.h>

#include <task8/convert.h>

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

int32_t IntToChar(uint64_t digit,
                  char *result) {
    if (digit < 10) {
        *result = '0' + digit;
    } else if (digit <= 36) {
        *result = 'A' + (digit - 10);
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

int32_t Convert10ToN(uint64_t number,
                     uint32_t base,
                     char *result) {
    if (base < 2
     || base > 36) {
        return 1;
    }

    char buffer[128];
    uint64_t index = 0;
    do {
        uint64_t digit = number % base;
        number /= base;

        if (IntToChar(digit,
                      &buffer[index])) {
            return 1;
        }

        ++index;

        if (index + 1 >= sizeof(buffer)) {
            return 1;
        }
    } while (number > 0);

    for (uint64_t i = 0, j = index; j > 0; ++i, --j) {
        result[i] = buffer[j - 1];
    }
    result[index] = '\0';

    return 0;
}
