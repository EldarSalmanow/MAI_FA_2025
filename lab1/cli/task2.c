#include <stdio.h>

#include <task2/cli.h>
#include <task2/sieve.h>

int main(void) {
    Arguments *arguments = ParseInput();

    if (!arguments) {
        return 1;
    }

    uint64_t maximum = 0;
    for (uint64_t i = 0; i < arguments->requests_count; ++i) {
        if (arguments->requests[i] > maximum) {
            maximum = arguments->requests[i];
        }
    }

    uint64_t upper_bound = UpperEstimateForNPrime(maximum);
    Sieve *sieve = CreateSieve(upper_bound);

    if (!sieve) {
        printf("[INTERNAL] Can`t create sieve!\n");

        return 1;
    }

    for (uint64_t i = 0; i < arguments->requests_count; ++i) {
        uint64_t prime = GetNPrime(sieve,
                                   arguments->requests[i]);

        printf("%lu prime number - %lu\n",
               arguments->requests[i],
               prime);
    }

    DestroySieve(sieve);
    DestroyArguments(arguments);

    return 0;
}
