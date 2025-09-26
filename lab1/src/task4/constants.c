#include <math.h>
#include <stdint.h>

#include <task4/constants.h>
#include <task4/numerical.h>
#include <task4/sieve.h>


uint64_t Factorial(uint64_t number) {
    uint64_t result = 1;

    for (uint64_t i = 2; i <= number; ++i) {
        result *= i;
    }

    return result;
}

double Combinations(uint64_t k,
                    uint64_t n) {
    return (double) Factorial(n) / (double) (Factorial(n - k) * Factorial(k));
}

double ELimitA_n(double previous,
                 uint64_t n) {
    (void) previous;

    return pow(1.0 + 1.0 / (double) n,
               (double) n);
}

double ESeriesA_n(double previous,
                  uint64_t n) {
    if (n == 0) {
        return 1;
    }

    return previous / (double) n;
}

double EEquationF_x(double x) {
    return log(x) - 1;
}

double PiLimitA_n(double previous,
                  uint64_t n) {
    if (n == 1) {
        return 4.0;
    }

    return previous * 4.0 * (double) n * (double) (n - 1) / pow(2 * (double) n - 1, 2);
}

double PiSeriesA_n(double previous,
                   uint64_t n) {
    (void) previous;

    double sign = -1.0;

    if ((n - 1) % 2 == 0) {
        sign = 1.0;
    }

    return sign / (2 * (double) n - 1);
}

double PiEquationF_x(double x) {
    return cos(x) + 1;
}

double Ln2LimitA_n(double previous,
                   uint64_t n) {
    (void) previous;

    return (double) n * (pow(2, 1 / (double) n) - 1);
}

double Ln2SeriesA_n(double previous,
                    uint64_t n) {
    (void) previous;

    double sign = -1.0;

    if ((n - 1) % 2 == 0) {
        sign = 1.0;
    }

    return sign / (double) n;
}

double Ln2EquationF_x(double x) {
    return exp(x) - 2;
}

double Sqrt2LimitA_n(double previous,
                     uint64_t n) {
    if (n == 0) {
        return -0.5;
    }

    return previous - pow(previous, 2) / 2 + 1;
}

double Sqrt2SeriesA_n(double previous,
                      uint64_t k) {
    (void) previous;

    return pow(2, 1 / pow(2, (double) k));
}

double Sqrt2EquationF_x(double x) {
    return x * x - 2;
}

double GammaLimitA_n(double previous,
                     uint64_t n) {
    (void) previous;

    double result = 0.0;
    int8_t sign = -1;
    for (uint64_t k = 1; k <= n; ++k) {
        result += Combinations(k, n) * sign / (double) k * log((double) Factorial(k));

        sign *= -1;
    }

    return result;
}

double GammaSeriesA_n(double previous,
                      uint64_t n) {
    (void) previous;

    uint64_t r = floor(sqrt((double) n));

    return 1.0 / (double) (r * r) - 1.0 / (double) n;
}

double GammaEquationA_n(Sieve *sieve,
                        double previous,
                        uint64_t n) {
    if (n == 1) {
        return 0.0;
    } else if (n == 2) {
        return log(2) / 2.0;
    }

    if (IsPrime(sieve, n)) {
        return previous * log((double) n) / log((double) n - 1) * (double) (n - 1) / (double) n;
    } else {
        return previous * log((double) n) / log((double) n - 1);
    }
}

double GammaEquationF_x(double limit_constant,
                        double x) {
    return 1 / pow(M_E, x) - limit_constant;
}

double ELimit(double epsilon,
              uint64_t max_iterations) {
    return SolveLimit(ELimitA_n,
                      epsilon,
                      max_iterations);
}

double ESeries(double epsilon,
               uint64_t max_iterations) {
    return SolveSeries(ESeriesA_n,
                       Sum,
                       0,
                       epsilon,
                       max_iterations);
}

double EEquation(double epsilon,
                 uint64_t max_iterations) {
    return BisectionMethod(2.0,
                           3.0,
                           EEquationF_x,
                           epsilon,
                           max_iterations);
}

double PiLimit(double epsilon,
               uint64_t max_iterations) {
    return SolveLimit(PiLimitA_n,
                      epsilon,
                      max_iterations);
}

double PiSeries(double epsilon,
                uint64_t max_iterations) {
    return 4 * SolveSeries(PiSeriesA_n,
                           Sum,
                           1,
                           epsilon,
                           max_iterations);
}

double PiEquation(double epsilon,
                  uint64_t max_iterations) {
    return SecantMethod(2.5,
                        3.0,
                        PiEquationF_x,
                        epsilon,
                        max_iterations);
}

double Ln2Limit(double epsilon,
                uint64_t max_iterations) {
    return SolveLimit(Ln2LimitA_n,
                      epsilon,
                      max_iterations);
}

double Ln2Series(double epsilon,
                 uint64_t max_iterations) {
    return SolveSeries(Ln2SeriesA_n,
                       Sum,
                       1,
                       epsilon,
                       max_iterations);
}

double Ln2Equation(double epsilon,
                   uint64_t max_iterations) {
    return BisectionMethod(0.0,
                           1.0,
                           Ln2EquationF_x,
                           epsilon,
                           max_iterations);
}

double Sqrt2Limit(double epsilon,
                  uint64_t max_iterations) {
    return SolveLimit(Sqrt2LimitA_n,
                      epsilon,
                      max_iterations);
}

double Sqrt2Series(double epsilon,
                   uint64_t max_iterations) {
    return SolveSeries(Sqrt2SeriesA_n,
                       Product,
                       2,
                       epsilon,
                       max_iterations);
}

double Sqrt2Equation(double epsilon,
                     uint64_t max_iterations) {
    return BisectionMethod(1.0,
                           2.0,
                           Sqrt2EquationF_x,
                           epsilon,
                           max_iterations);
}

double GammaLimit(double epsilon,
                  uint64_t max_iterations) {
    (void) max_iterations;

    return SolveLimit(GammaLimitA_n,
                      epsilon,
                      20);
}

double GammaSeries(double epsilon,
                   uint64_t max_iterations) {
    return -M_PI * M_PI / 6 + SolveSeries(GammaSeriesA_n,
                                          Sum,
                                          2,
                                          epsilon,
                                          max_iterations);
}

double GammaEquation(double epsilon,
                     uint64_t max_iterations) {
    double limit_result;

    {
        Sieve *sieve = CreateSieve(100000000);

        double previous = GammaEquationA_n(sieve, 0.0, 1);
        double current = GammaEquationA_n(sieve, previous, 2);

        for (uint64_t n = 3, iteration = 3;
             fabs(current - previous) >= epsilon && iteration < max_iterations; ++n, ++iteration) {
            previous = current;

            current = GammaEquationA_n(sieve, previous, n);
        }

        limit_result = current;

        DestroySieve(sieve);
    }

    double result;

    {
        double a = 0.0, b = 10.0;

        double c = 0.0;
        for (uint64_t iteration = 0; fabs(b - a) >= epsilon && iteration < max_iterations; ++iteration) {
            c = (a + b) / 2;

            if (fabs(GammaEquationF_x(limit_result, c)) < epsilon) {
                break;
            }

            if (GammaEquationF_x(limit_result, c) * GammaEquationF_x(limit_result, a) < 0) {
                b = c;
            } else {
                a = c;
            }
        }

        result = c;
    }

    return result;
}
