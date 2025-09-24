#ifndef MAI_FA_2025_ACTIONS_H
#define MAI_FA_2025_ACTIONS_H

#include <stdint.h>

int32_t SolveEquation(double a,
                      double b,
                      double c,
                      double epsilon);

int32_t CheckMultiplicity(int64_t a,
                          int64_t b);

int32_t CheckTriangle(double a,
                      double b,
                      double c,
                      double epsilon);

#endif //MAI_FA_2025_ACTIONS_H
