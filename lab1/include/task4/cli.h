#ifndef MAI_FA_2025_CLI_H
#define MAI_FA_2025_CLI_H

#include <stdint.h>

typedef struct {
    double epsilon;
} Arguments;

int32_t ParseArguments(int argc,
                       char **argv,
                       Arguments *arguments);

#endif //MAI_FA_2025_CLI_H
