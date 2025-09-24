#include <stdio.h>

#include <task5/actions.h>
#include <task5/cli.h>

int main(int argc,
         char **argv) {
    Arguments arguments;

    if (ParseArguments(argc,
                       argv,
                       &arguments)) {
        return 1;
    }

    FILE *in_file = fopen(arguments.input_filename,
                          "r");

    if (!in_file) {
        printf("[ERROR] Can`t open input file!\n");

        return 1;
    }

    FILE *out_file = fopen(arguments.output_filename,
                           "w");

    if (!out_file) {
        printf("[ERROR] Can`t open or create output file!\n");

        return 1;
    }

    switch (arguments.action) {
        case REMOVE_DIGITS:
            if (RemoveDigits(in_file,
                             out_file)) {
                return 1;
            }

            break;
        case COUNT_LATINS:
            if (CountLatins(in_file,
                            out_file)) {
                return 1;
            }

            break;
        case COUNT_SPECIALS:
            if (CountSpecials(in_file,
                              out_file)) {
                return 1;
            }

            break;
        case REPLACE_SYMBOLS:
            if (ReplaceSymbols(in_file,
                               out_file)) {
                return 1;
            }

            break;
        default:
            printf("[INTERNAL] Unknown action type!\n");

            return 1;
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}
