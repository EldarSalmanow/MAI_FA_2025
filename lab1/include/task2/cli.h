#ifndef MAI_FA_2025_CLI_H
#define MAI_FA_2025_CLI_H

#include <stdint.h>

typedef struct {
    uint64_t *requests;
    uint64_t requests_count;
} Arguments;

Arguments *CreateArguments(uint64_t *requests,
                           uint64_t requests_count);

void DestroyArguments(Arguments *arguments);

Arguments *ParseInput(void);

#endif //MAI_FA_2025_CLI_H
