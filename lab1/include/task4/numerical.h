#ifndef MAI_FA_2025_NUMERICAL_H
#define MAI_FA_2025_NUMERICAL_H

#include <stdint.h>

typedef double (*LimitFn) (double, uint64_t);
typedef double (*SeriesFn) (double, uint64_t);
typedef double (*EquationFn) (double);
typedef double (*OperatorFn) (double, double);

double Sum(double a,
           double b);

double Product(double a,
               double b);

double SolveLimit(LimitFn function,
                  double epsilon,
                  uint64_t max_iterations);

double SolveSeries(SeriesFn function,
                   OperatorFn operator,
                   uint64_t start,
                   double epsilon,
                   uint64_t max_iterations);

double BisectionMethod(double a,
                       double b,
                       EquationFn function,
                       double epsilon,
                       uint64_t max_iterations);

double SecantMethod(double a,
                    double b,
                    EquationFn function,
                    double epsilon,
                    uint64_t max_iterations);

#endif //MAI_FA_2025_NUMERICAL_H
