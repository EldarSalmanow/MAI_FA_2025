#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <task3/cli.h>

int32_t ParseInt64(char *string,
                   int64_t *number) {
    char *end;
    *number = strtoll(string, &end, 10);

    if (*end != '\0') {
        return 1;
    }

    return 0;
}

int32_t ParseDouble(char *string,
                    double *number) {
    char *end;
    *number = strtod(string, &end);

    if (*end != '\0') {
        return 1;
    }

    return 0;
}

int32_t ParseOptQ(uint32_t *current,
                  uint32_t argc,
                  char **argv,
                  Arguments *arguments) {
    arguments->action = SOLVE_EQUATION;

    ++*current; // skip '-q'

    for (uint32_t i = 0; i < 4; ++i, ++*current) {
        if (*current >= argc) {
            printf("[ERROR] No such numbers for option '-q'!\n");

            return 1;
        }

        if (ParseDouble(argv[*current],
                        &arguments->float_numbers[i])) {
            printf("[ERROR] Can`t parse number for option '-q'!\n");

            return 1;
        }
    }

    return 0;
}

int32_t ParseOptM(uint32_t *current,
                  uint32_t argc,
                  char **argv,
                  Arguments *arguments) {
    arguments->action = CHECK_MULTIPLICITY;

    ++*current; // skip '-m'

    for (uint32_t i = 0; i < 2; ++i, ++*current) {
        if (*current >= argc) {
            printf("[ERROR] No such numbers for option '-m'!\n");

            return 1;
        }

        if (ParseInt64(argv[*current],
                       &arguments->int_numbers[i])) {
            printf("[ERROR] Can`t parse number for option '-m'!\n");

            return 1;
        }
    }

    return 0;
}

int32_t ParseOptT(uint32_t *current,
                  uint32_t argc,
                  char **argv,
                  Arguments *arguments) {
    arguments->action = CHECK_TRIANGLE;

    ++*current; // skip '-t'

    for (uint32_t i = 0; i < 4; ++i, ++*current) {
        if (*current >= argc) {
            printf("[ERROR] No such numbers for option '-t'!\n");

            return 1;
        }

        if (ParseDouble(argv[*current],
                        &arguments->float_numbers[i])) {
            printf("[ERROR] Can`t parse number for option '-t'!\n");

            return 1;
        }
    }

    return 0;
}

int32_t ParseArguments(int argc_,
                       char **argv,
                       Arguments *arguments) {
    typedef int32_t (*ActionHandler) (uint32_t*, uint32_t, char**, Arguments*);

    const char OptionsSymbols[ACTIONS_COUNT] = {'q', 'm', 't'};
    const ActionHandler OptionsHandlers[ACTIONS_COUNT] = {ParseOptQ, ParseOptM, ParseOptT};

    uint32_t argc = argc_;

    bool action_handled = false;

    for (uint32_t i = 1; i < argc; ++i) {
        if (argv[i][0] == '-'
         || argv[i][0] == '/') {
            if (action_handled) {
                printf("[ERROR] Two flags in input arguments!\n");

                return 1;
            }

            for (uint32_t j = 0; j < ACTIONS_COUNT; ++j) {
                if (argv[i][1] == OptionsSymbols[j]) {
                    if (OptionsHandlers[j](&i, argc, argv, arguments)) {
                        return 1;
                    }

                    action_handled = true;

                    break;
                }
            }

            if (!action_handled) {
                printf("[ERROR] Unknown flag!\n");

                return 1;
            }

            continue;
        }

        printf("[ERROR] Unknown flag!\n");
    }

    if (!action_handled) {
        printf("[ERROR] Expected flag in input arguments!\n");

        return 1;
    }

    if (arguments->action != CHECK_MULTIPLICITY) {
        double epsilon = arguments->float_numbers[0];

        if (isnan(epsilon)
         || isinf(epsilon)
         || epsilon <= 0.0) {
            printf("[ERROR] Epsilon must be positive non-special number!\n");

            return 1;
        }
    }

    return 0;
}
