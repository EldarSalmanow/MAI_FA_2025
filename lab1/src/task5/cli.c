#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <task5/cli.h>


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

int32_t ParseArguments(int argc_,
                       char **argv,
                       Arguments *arguments) {
    const char OptionsSymbols[ACTIONS_COUNT] = {'d', 'i', 's', 'a'};
    const Action OptionsActions[ACTIONS_COUNT] = {REMOVE_DIGITS, COUNT_LATINS, COUNT_SPECIALS, REPLACE_SYMBOLS};

    uint32_t argc = argc_;

    bool action_handled = false;

    for (uint32_t i = 1; i < argc; ++i) {
        uint32_t index = 0;

        if (argv[i][index] == '-'
         || argv[i][index] == '/') {
            if (action_handled) {
                printf("[ERROR] Two flags in input arguments!\n");

                return 1;
            }

            ++index;

            bool has_out = false;
            if (argv[i][index] == 'n') {
                has_out = true;
                ++index;
            }

            for (uint32_t j = 0; j < ACTIONS_COUNT; ++j) {
                if (argv[i][index] == OptionsSymbols[j]) {
                    arguments->action = OptionsActions[j];
                    action_handled = true;

                    break;
                }
            }

            if (!action_handled) {
                printf("[ERROR] Unknown flag!\n");

                return 1;
            }

            ++i;
            if (i >= argc) {
                printf("[ERROR] Expected input filename!\n");

                return 1;
            }

            if (ParseString(argv[i],
                            arguments->input_filename,
                            MAX_FILENAME_SIZE)) {
                return 1;
            }

            if (!has_out) {
                if (strlen(arguments->input_filename) + 4 > MAX_FILENAME_SIZE) {
                    printf("[ERROR] Too long input filename!\n");

                    return 1;
                }

                strcpy(arguments->output_filename,
                       "out_");
                strcpy(arguments->output_filename + 4,
                       arguments->input_filename);

                continue;
            }

            ++i;
            if (i >= argc) {
                printf("[ERROR] Expected output filename!\n");

                return 1;
            }

            if (ParseString(argv[i],
                            arguments->output_filename,
                            MAX_FILENAME_SIZE)) {
                return 1;
            }

            continue;
        }

        printf("[ERROR] Unknown flag!\n");

        return 1;
    }

    if (!action_handled) {
        printf("[ERROR] Expected flag in input arguments!\n");

        return 1;
    }

    return 0;
}
