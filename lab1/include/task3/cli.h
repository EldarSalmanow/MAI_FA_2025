#ifndef MAI_FA_2025_CLI_H
#define MAI_FA_2025_CLI_H

#include <stdint.h>

typedef enum {
    SOLVE_EQUATION,
    CHECK_MULTIPLICITY,
    CHECK_TRIANGLE,

    ACTIONS_COUNT
} Action;

typedef struct {
    int64_t int_numbers[2];
    double float_numbers[4];

    Action action;
} Arguments;

int32_t ParseArguments(int argc,
                       char **argv,
                       Arguments *arguments);

#endif //MAI_FA_2025_CLI_H
