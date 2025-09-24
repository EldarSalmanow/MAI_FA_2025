#ifndef MAI_FA_2025_NUMERICAL_H
#define MAI_FA_2025_NUMERICAL_H

#include <stdint.h>

typedef double (*IntegralFn) (double);

double Trapezoid(double a,
                 double b,
                 uint64_t partition,
                 IntegralFn function);

double TrapezoidRunge(double a,
                      double b,
                      uint64_t start_partition,
                      IntegralFn function,
                      double epsilon,
                      uint64_t max_iterations);

#endif //MAI_FA_2025_NUMERICAL_H
