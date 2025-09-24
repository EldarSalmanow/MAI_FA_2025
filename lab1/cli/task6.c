#include <math.h>
#include <stdio.h>

#include <task6/cli.h>
#include <task6/integrals.h>
#include <task6/numerical.h>

int main(int argc,
         char **argv) {
    const double Borders[] = {
            LBorderA, RBorderA,
            LBorderB, RBorderB,
            LBorderC, RBorderC,
            LBorderD, RBorderD
    };
    const IntegralFn Integrals[] = {
            IntegralA,
            IntegralB,
            IntegralC,
            IntegralD
    };
    const char *IntegralNames[] = {
            "A",
            "B",
            "C",
            "D"
    };
    const uint64_t IntegralsCount = sizeof(Integrals) / sizeof(Integrals[0]);
    const uint64_t StartPartition = 2;
    const uint64_t MaxIterations = 25;

    Arguments arguments;

    if (ParseArguments(argc,
                       argv,
                       &arguments)) {
        return 1;
    }

    int32_t precision = ceil(-log10(arguments.epsilon));

    for (uint64_t i = 0; i < IntegralsCount; ++i) {
        double integral = TrapezoidRunge(Borders[i * 2],
                                         Borders[i * 2 + 1],
                                         StartPartition,
                                         Integrals[i],
                                         arguments.epsilon,
                                         MaxIterations);

        printf("Integral %s : %.*f\n",
               IntegralNames[i],
               precision,
               integral);
    }

    return 0;
}
