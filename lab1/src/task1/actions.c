#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include <task1/actions.h>

int32_t PrintNaturals(uint64_t number) {
    if (number == 0) {
        printf("[ERROR] For printing naturals number must be positive!\n");

        return 1;
    }

    for (uint64_t i = 1; i <= 100; ++i) {
        if (i % number == 0) {
            printf("%lu ", i);
        }
    }

    printf("\n");

    return 0;
}

int32_t IsPrime(uint64_t number) {
    if (number < 2) {
        printf("[ERROR] For checking prime number must satisfy rule x >= 2!\n");

        return 1;
    }

    bool is_prime = true;
    for (uint64_t i = 2; i <= (uint64_t) sqrt(number) && is_prime; ++i) {
        if (number % i == 0) {
            is_prime = false;
        }
    }

    if (is_prime) {
        printf("%lu - prime number\n", number);
    } else {
        printf("%lu - composite number\n", number);
    }

    return 0;
}

int32_t SeparateNumber(uint64_t number) {
    const char *letters = "0123456789ABCDEF";

    char buffer[32];
    int32_t first = 31;
    while (number > 0) {
        uint64_t remainder = number % 16;
        number = (number - remainder) / 16;
        buffer[first] = letters[remainder];
        --first;
    }

    for (; first < 32; ++first) {
        printf("%c ", buffer[first]);
    }
    printf("\n");

    return 0;
}

int32_t PrintTable(uint64_t number) {
    if (number > 10) {
        printf("[ERROR] For printing table number must satisfy rule 1 <= x <= 10\n");

        return 1;
    }

    printf("n\n");

    for (uint64_t a = 1; a <= 10; ++a) {
        printf("%lu ", a);

        uint64_t a_n = a;

        for (uint64_t n = 1; n <= number; ++n) {
            printf("%lu ", a_n);

            a_n *= a;
        }

        printf("\n");
    }

    return 0;
}

int32_t CalculateSum(uint64_t number) {
    if (number < 1) {
        printf("[ERROR] Number for calculating sum must satisfy rule 1 <= x!\n");

        return 1;
    }

    uint64_t sum = 1;
    for (uint64_t i = 2; i <= number; ++i) {
        sum += i;
    }

    printf("1 + ... + x = %lu\n", sum);

    return 0;
}

int32_t CalculateFactorial(uint64_t number) {
    uint64_t factorial = 1;
    for (uint64_t i = 2; i <= number; ++i) {
        factorial *= i;
    }

    printf("%lu! = %lu\n", number, factorial);

    return 0;
}
