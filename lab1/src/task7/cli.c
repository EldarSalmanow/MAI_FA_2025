#include <stdio.h>
#include <string.h>

#include <task7/cli.h>


int32_t ParseString(char *in_string,
                    char *out_string,
                    uint64_t max_size) {
    uint64_t length = strlen(in_string);

    if (length > max_size) {
        printf("[ERROR] Too long string from command line arguments!\n");

        return 1;
    }

    strcpy(out_string, in_string);

    return 0;
}

int32_t ParseArguments(int argc,
                       char **argv,
                       Arguments *arguments) {
    if (argc != 3) {
        printf("[ERROR] Input arguments must contain only input and output filenames!\n");

        return 1;
    }

    if (ParseString(argv[1],
                    arguments->input_filename,
                    MAX_FILENAME_SIZE)) {
        return 1;
    }

    if (ParseString(argv[2],
                    arguments->output_filename,
                    MAX_FILENAME_SIZE)) {
        return 1;
    }

    return 0;
}
