#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <task4/sieve.h>

uint64_t UpperEstimateForNPrime(uint64_t n) {
    if (n <= 10) {
        return 30;
    }

    double lnn = log(n);
    double lnlnn = log(lnn);

    return n * (lnn + lnlnn) + 1;
}

Sieve *CreateSieve(uint64_t size) {
    Sieve *sieve = (Sieve *) malloc(sizeof(Sieve));

    if (!sieve) {
        return NULL;
    }

    sieve->primes = (bool *) malloc((size + 1) * sizeof(bool));

    if (!sieve->primes) {
        free(sieve);

        return NULL;
    }

    sieve->size = size + 1;

    for (uint64_t i = 0; i < sieve->size; ++i) {
        sieve->primes[i] = true;
    }

    sieve->primes[0] = false;
    sieve->primes[1] = false;
    for (uint64_t i = 2; i * i < sieve->size; ++i) {
        if (sieve->primes[i]) {
            for (uint64_t j = i * i; j < sieve->size; j += i) {
                sieve->primes[j] = false;
            }
        }
    }

    return sieve;
}

void DestroySieve(Sieve *sieve) {
    free(sieve->primes);
    free(sieve);
}

bool IsPrime(Sieve *sieve,
             uint64_t n) {
    if (n >= sieve->size) {
        printf("[INTERNAL] No number found in sieve!\n");

        return false;
    }

    return sieve->primes[n];
}

uint64_t GetNPrime(Sieve *sieve,
                   uint64_t n) {
    for (uint64_t i = 0, j = 0; i < sieve->size; ++i) {
        if (sieve->primes[i]) {
            ++j;
        }

        if (j == n) {
            return i;
        }
    }

    printf("[INTERNAL] No number found in the sieve!\n");

    return 0;
}
