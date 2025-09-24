#include <ctype.h>
#include <stdio.h>

#include <task5/actions.h>


int32_t RemoveDigits(FILE *in_file,
                     FILE *out_file) {
    char symbol;
    while ((symbol = getc(in_file)) != EOF) {
        if (isdigit(symbol)) {
            continue;
        }

        fputc(symbol, out_file);
    }

    return 0;
}

int32_t CountLatins(FILE *in_file,
                    FILE *out_file) {
    uint64_t count = 0;

    char symbol;
    while ((symbol = getc(in_file)) != EOF) {
        if (isalpha(symbol)) {
            ++count;
        } else if (symbol == '\n') {
            char number[65];
            sprintf(number, "%lu", count);

            fputs(number, out_file);
            fputc('\n', out_file);

            count = 0;
        }
    }

    char number[65];
    sprintf(number, "%lu", count);

    fputs(number, out_file);

    return 0;
}

int32_t CountSpecials(FILE *in_file,
                      FILE *out_file) {
    uint64_t count = 0;

    char symbol;
    while ((symbol = getc(in_file)) != EOF) {
        if (!isalpha(symbol)
         && !isdigit(symbol)
         && !isspace(symbol)) {
            ++count;
        } else if (symbol == '\n') {
            char number[65];
            sprintf(number, "%lu", count);

            fputs(number, out_file);
            fputc('\n', out_file);

            count = 0;
        }
    }

    char number[65];
    sprintf(number, "%lu", count);

    fputs(number, out_file);

    return 0;
}

int32_t ReplaceSymbols(FILE *in_file,
                       FILE *out_file) {
    char symbol;
    while ((symbol = getc(in_file)) != EOF) {
        if (isdigit(symbol)) {
            fputc(symbol, out_file);

            continue;
        }

        char number[5];
        sprintf(number, "%x", symbol);

        fputs(number, out_file);
    }

    return 0;
}
