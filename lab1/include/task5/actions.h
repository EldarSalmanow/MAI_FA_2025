#ifndef MAI_FA_2025_ACTIONS_H
#define MAI_FA_2025_ACTIONS_H

#include <stdint.h>
#include <stdio.h>

int32_t RemoveDigits(FILE *in_file,
                     FILE *out_file);

int32_t CountLatins(FILE *in_file,
                    FILE *out_file);

int32_t CountSpecials(FILE *in_file,
                      FILE *out_file);

int32_t ReplaceSymbols(FILE *in_file,
                       FILE *out_file);

#endif //MAI_FA_2025_ACTIONS_H
