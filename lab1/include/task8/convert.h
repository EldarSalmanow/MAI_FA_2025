#ifndef MAI_FA_2025_CONVERT_H
#define MAI_FA_2025_CONVERT_H

#include <stdint.h>

int32_t CharToInt(char symbol,
                  uint64_t *result);

int32_t IntToChar(uint64_t digit,
                  char *result);

const char *CleanupNumber(const char *number);

int32_t ConvertNTo10(const char *number,
                     uint64_t base,
                     uint64_t *result);

int32_t Convert10ToN(uint64_t number,
                     uint32_t base,
                     char *result);

#endif //MAI_FA_2025_CONVERT_H
