#include <math.h>

#include <task6/integrals.h>


double IntegralA(double x) {
    if (x == 0) {
        return 1;
    }

    return log(1 + x) / x;
}

double IntegralB(double x) {
    return exp(-x * x / 2);
}

double IntegralC(double x) {
    if (x == 1) {
        return 0;
    }

    return log(1 / (1 - x));
}

double IntegralD(double x) {
    return pow(x, x);
}
