#include <stdio.h>

#include <task3/actions.h>
#include <task3/cli.h>

int main(int argc,
         char **argv) {
    Arguments arguments;

    if (ParseArguments(argc,
                       argv,
                       &arguments)) {
        return 1;
    }

    switch (arguments.action) {
        case SOLVE_EQUATION:
            if (SolveEquation(arguments.float_numbers[1],
                              arguments.float_numbers[2],
                              arguments.float_numbers[3],
                              arguments.float_numbers[0])) {
                return 1;
            }

            break;
        case CHECK_MULTIPLICITY:
            if (CheckMultiplicity(arguments.int_numbers[0],
                                  arguments.int_numbers[1])) {
                return 1;
            }

            break;
        case CHECK_TRIANGLE:
            if (CheckTriangle(arguments.float_numbers[1],
                              arguments.float_numbers[2],
                              arguments.float_numbers[3],
                              arguments.float_numbers[0])) {
                return 1;
            }

            break;
        default:
            printf("[INTERNAL] Unknown action!\n");

            return 1;
    }

    return 0;
}