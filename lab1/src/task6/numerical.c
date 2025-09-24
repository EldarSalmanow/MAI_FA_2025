#include <math.h>

#include <task6/numerical.h>


double Trapezoid(double a,
                 double b,
                 uint64_t partition,
                 IntegralFn function) {
    double width = (b - a) / partition;

    double integral = 0;
    for (uint64_t step = 0; step < partition; ++step) {
        double x1 = a + step * width;
        double x2 = x1 + width;

        integral += 0.5 * width * (function(x1) + function(x2));
    }

    return integral;
}

double TrapezoidRunge(double a,
                      double b,
                      uint64_t start_partition,
                      IntegralFn function,
                      double epsilon,
                      uint64_t max_iterations) {
    uint64_t partition = start_partition;
    uint64_t iteration = 2;

    double i_n = Trapezoid(a, b, partition, function);

    partition *= 2;

    double i_2n = Trapezoid(a, b, partition, function);

    while (fabs(i_2n - i_n) >= epsilon
        && iteration < max_iterations) {
        i_n = i_2n;

        partition *= 2;

        i_2n = Trapezoid(a, b, partition, function);

        ++iteration;
    }

    return i_2n;
}
