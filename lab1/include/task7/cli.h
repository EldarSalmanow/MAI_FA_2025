#ifndef MAI_FA_2025_CLI_H
#define MAI_FA_2025_CLI_H

#include <stdint.h>

#define MAX_FILENAME_SIZE 255

typedef struct {
    char input_filename[MAX_FILENAME_SIZE + 1];
    char output_filename[MAX_FILENAME_SIZE + 1];
} Arguments;

int32_t ParseArguments(int argc,
                       char **argv,
                       Arguments *arguments);

#endif //MAI_FA_2025_CLI_H
