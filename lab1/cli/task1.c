#include <stdio.h>

#include <task1/actions.h>
#include <task1/cli.h>

int main(int argc,
         char **argv) {
    Arguments arguments;

    if (ParseArguments(argc,
                       argv,
                       &arguments)) {
        return 1;
    }

    switch (arguments.action) {
        case PRINT_NATURALS:
            if (PrintNaturals(arguments.number)) {
                return 1;
            }

            break;
        case IS_PRIME:
            if (IsPrime(arguments.number)) {
                return 1;
            }

            break;
        case SEPARATE_NUMBER:
            if (SeparateNumber(arguments.number)) {
                return 1;
            }

            break;
        case PRINT_TABLE:
            if (PrintTable(arguments.number)) {
                return 1;
            }

            break;
        case CALCULATE_SUM:
            if (CalculateSum(arguments.number)) {
                return 1;
            }

            break;
        case CALCULATE_FACTORIAL:
            if (CalculateFactorial(arguments.number)) {
                return 1;
            }

            break;
        default:
            printf("[INTERNAL] Unknown action!\n");

            return 1;
    }

    return 0;
}
