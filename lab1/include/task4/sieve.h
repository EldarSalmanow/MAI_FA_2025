#ifndef MAI_FA_2025_SIEVE_H
#define MAI_FA_2025_SIEVE_H

#include <stdbool.h>
#include <stdint.h>

uint64_t UpperEstimateForNPrime(uint64_t n);

typedef struct {
    bool *primes;
    uint64_t size;
} Sieve;

Sieve *CreateSieve(uint64_t size);

void DestroySieve(Sieve *sieve);

bool IsPrime(Sieve *sieve,
             uint64_t n);

uint64_t GetNPrime(Sieve *sieve,
                   uint64_t n);

#endif //MAI_FA_2025_SIEVE_H
