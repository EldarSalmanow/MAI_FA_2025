#include <math.h>
#include <stdio.h>

#include <task4/cli.h>
#include <task4/constants.h>

int main(int argc,
         char **argv) {
    const uint64_t MaxIterations = 10000000;

    Arguments arguments;

    if (ParseArguments(argc,
                       argv,
                       &arguments)) {
        return 1;
    }

    uint32_t precision = ceil(-log10(arguments.epsilon));

    printf("e      :  limit=%.*f series=%.*f equation=%.*f\n",
           precision, ELimit(arguments.epsilon, MaxIterations),
           precision, ESeries(arguments.epsilon, MaxIterations),
           precision, EEquation(arguments.epsilon, MaxIterations));
    printf("pi     :  limit=%.*f series=%.*f equation=%.*f\n",
           precision, PiLimit(arguments.epsilon, MaxIterations),
           precision, PiSeries(arguments.epsilon, MaxIterations),
           precision, PiEquation(arguments.epsilon, MaxIterations));
    printf("ln2    :  limit=%.*f series=%.*f equation=%.*f\n",
           precision, Ln2Limit(arguments.epsilon, MaxIterations),
           precision, Ln2Series(arguments.epsilon, MaxIterations),
           precision, Ln2Equation(arguments.epsilon, MaxIterations));
    printf("sqrt2  :  limit=%.*f series=%.*f equation=%.*f\n",
           precision, Sqrt2Limit(arguments.epsilon, MaxIterations),
           precision, Sqrt2Series(arguments.epsilon, MaxIterations),
           precision, Sqrt2Equation(arguments.epsilon, MaxIterations));
    printf("gamma  :  limit=%.*f series=%.*f equation=%.*f\n",
           precision, GammaLimit(arguments.epsilon, MaxIterations),
           precision, GammaSeries(arguments.epsilon, MaxIterations),
           precision, GammaEquation(arguments.epsilon, MaxIterations));

    return 0;
}
