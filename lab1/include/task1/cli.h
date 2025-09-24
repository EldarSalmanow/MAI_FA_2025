#ifndef MAI_FA_2025_CLI_H
#define MAI_FA_2025_CLI_H

#include <stdint.h>

typedef enum {
    PRINT_NATURALS,
    IS_PRIME,
    SEPARATE_NUMBER,
    PRINT_TABLE,
    CALCULATE_SUM,
    CALCULATE_FACTORIAL,

    ACTIONS_COUNT
} Action;

typedef struct {
    int64_t number;
    Action action;
} Arguments;

int32_t ParseArguments(int argc,
                       char **argv,
                       Arguments *arguments);

#endif //MAI_FA_2025_CLI_H
