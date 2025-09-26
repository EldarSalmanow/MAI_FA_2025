#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <task4/cli.h>


int32_t ParseDouble(char *string,
                    double *number) {
    char *end;
    *number = strtod(string, &end);

    if (*end != '\0') {
        return 1;
    }

    return 0;
}

int32_t ParseArguments(int argc,
                       char **argv,
                       Arguments *arguments) {
    if (argc != 2) {
        printf("[ERROR] Input arguments must contain only one argument!\n");

        return 1;
    }

    if (ParseDouble(argv[1],
                    &arguments->epsilon)) {
        printf("[ERROR] Can`t parse epsilon!\n");

        return 1;
    }

    if (isnan(arguments->epsilon)
     || isinf(arguments->epsilon)
     || arguments->epsilon <= 0.0) {
        printf("[ERROR] Epsilon must be positive non-special number!\n");

        return 1;
    }

    return 0;
}
