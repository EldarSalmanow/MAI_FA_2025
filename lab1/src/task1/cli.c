#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <task1/cli.h>

int32_t ParseInt64(char *string,
                   int64_t *number) {
    char *end;
    *number = strtoll(string, &end, 10);

    if (*end != '\0') {
        return 1;
    }

    return 0;
}

int32_t ParseArguments(int argc_,
                       char **argv,
                       Arguments *arguments) {
    const char Options[ACTIONS_COUNT] = {'h', 'p', 's', 'e', 'a', 'f'};
    const Action Actions[ACTIONS_COUNT] = {PRINT_NATURALS, IS_PRIME, SEPARATE_NUMBER,
                                           PRINT_TABLE, CALCULATE_SUM, CALCULATE_FACTORIAL};

    uint32_t argc = argc_;

    bool option_handled = false;

    for (uint32_t i = 1; i < argc; ++i) {
        if (argv[i][0] == '-'
         || argv[i][0] == '/') {
            if (option_handled) {
                printf("[ERROR] Two options in input arguments!\n");

                return 1;
            }

            for (uint32_t j = 0; i < ACTIONS_COUNT; ++i) {
                if (argv[i][1] == Options[j]) {
                    arguments->action = Actions[j];

                    option_handled = true;

                    break;
                }
            }

            if (!option_handled) {
                printf("[ERROR] Unknown option!\n");

                return 1;
            }

            ++i;
            if (i >= argc) {
                printf("[ERROR] Expected number in input arguments!\n");

                return 1;
            }

            if (ParseInt64(argv[i],
                           &arguments->number)) {
                printf("[ERROR] Can`t parse number in input arguments!\n");

                return 1;
            }

            continue;
        }

        printf("[ERROR] Expected option in input arguments!\n");

        return 1;
    }

    if (arguments->number < 0) {
        printf("Number from command line arguments must be non-negative!\n");

        return 1;
    }

    return 0;
}
