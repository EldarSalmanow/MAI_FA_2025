#ifndef MAI_FA_2025_CONSTANTS_H
#define MAI_FA_2025_CONSTANTS_H

#include <stdint.h>

double ELimit(double epsilon,
              uint64_t max_iterations);

double ESeries(double epsilon,
               uint64_t max_iterations);

double EEquation(double epsilon,
                 uint64_t max_iterations);

double PiLimit(double epsilon,
               uint64_t max_iterations);

double PiSeries(double epsilon,
                uint64_t max_iterations);

double PiEquation(double epsilon,
                  uint64_t max_iterations);

double Ln2Limit(double epsilon,
                uint64_t max_iterations);

double Ln2Series(double epsilon,
                 uint64_t max_iterations);

double Ln2Equation(double epsilon,
                   uint64_t max_iterations);

double Sqrt2Limit(double epsilon,
                  uint64_t max_iterations);

double Sqrt2Series(double epsilon,
                   uint64_t max_iterations);

double Sqrt2Equation(double epsilon,
                     uint64_t max_iterations);

double GammaLimit(double epsilon,
                  uint64_t max_iterations);

double GammaSeries(double epsilon,
                   uint64_t max_iterations);

double GammaEquation(double epsilon,
                     uint64_t max_iterations);

#endif //MAI_FA_2025_CONSTANTS_H
