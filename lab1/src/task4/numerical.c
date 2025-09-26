#include <math.h>

#include <task4/numerical.h>


double Sum(double a,
           double b) {
    return a + b;
}

double Product(double a,
               double b) {
    return a * b;
}

double SolveLimit(LimitFn function,
                  double epsilon,
                  uint64_t max_iterations) {
    double previous = function(0.0, 1);
    double current = function(previous, 2);

    uint64_t epsilon_count = 0;
    for (uint64_t n = 3, iteration = 3; epsilon_count < 10000 && iteration < max_iterations; ++n, ++iteration) {
        if (fabs(current - previous) < epsilon) {
            epsilon_count += 1;
        } else {
            epsilon_count = 0;
        }

        previous = current;

        current = function(previous, n);
    }

    return current;
}

double SolveSeries(SeriesFn function,
                   OperatorFn operator,
                   uint64_t start,
                   double epsilon,
                   uint64_t max_iterations) {
    double term = function(0.0, start);
    double result = term;

    uint64_t epsilon_count = 0;
    for (uint64_t n = start + 1, iteration = 2; epsilon_count < 10000 && iteration < max_iterations; ++n, ++iteration) {
        if (fabs(term) < epsilon) {
            epsilon_count += 1;
        } else {
            epsilon_count = 0;
        }

        term = function(term, n);

        result = operator(result, term);
    }

    return result;
}

double BisectionMethod(double a,
                       double b,
                       EquationFn function,
                       double epsilon,
                       uint64_t max_iterations) {
    double c = 0.0;
    for (uint64_t iteration = 0; fabs(b - a) >= epsilon && iteration < max_iterations; ++iteration) {
        c = (a + b) / 2;

        if (fabs(function(c)) < epsilon) {
            break;
        }

        if (function(c) * function(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}

double SecantMethod(double a,
                    double b,
                    EquationFn function,
                    double epsilon,
                    uint64_t max_iterations) {
    double x_prev = a;
    double x = b;
    double x_next;
    uint64_t iteration = 0;

    do {
        if (fabs(function(x) - function(x_prev)) < epsilon) {
            x_next = (x + x_prev) / 2;
        } else {
            x_next = x - function(x) * (x - x_prev) / (function(x) - function(x_prev));
        }

        x_prev = x;
        x = x_next;

        ++iteration;

        if (iteration >= max_iterations) {
            break;
        }
    } while (fabs(x - x_prev) > epsilon && fabs(function(x)) > epsilon);

    return x;
}
