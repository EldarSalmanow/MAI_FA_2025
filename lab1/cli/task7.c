#include <task7/bases.h>
#include <task7/cli.h>

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

    if (MinBases(in_file,
                 out_file)) {
        return 1;
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}
