#include <stdio.h>
#include <stdlib.h>

#include <task2/cli.h>

Arguments *CreateArguments(uint64_t *requests,
                           uint64_t requests_count) {
    Arguments *arguments = (Arguments *) malloc(sizeof(Arguments));

    if (!arguments) {
        return NULL;
    }

    arguments->requests = requests;
    arguments->requests_count = requests_count;

    return arguments;
}

void DestroyArguments(Arguments *arguments) {
    free(arguments->requests);
    free(arguments);
}

Arguments *ParseInput(void) {
    int64_t requests_count = 0;
    printf("Enter requests count: ");

    if (scanf("%li", &requests_count) != 1
     || getchar() != '\n') {
        printf("[ERROR] Requests count must be only one positive number!\n");

        return NULL;
    }

    if (requests_count <= 0) {
        printf("[ERROR] Requests count must be positive!\n");

        return NULL;
    }

    uint64_t *requests = (uint64_t *) malloc(requests_count * sizeof(uint64_t));
    if (!requests) {
        printf("[INTERNAL] Can`t allocate memory for requests!\n");

        return NULL;
    }

    for (uint64_t i = 0; i < (uint64_t) requests_count; ++i) {
        int64_t request = 0;
        printf("Enter prime number: ");
        if (scanf("%li", &request) != 1
         || getchar() != '\n') {
            printf("[ERROR] Prime number must be only one positive number!\n");

            free(requests);

            return NULL;
        }

        if (request <= 0) {
            printf("[ERROR] Prime number must be positive!\n");

            free(requests);

            return NULL;
        }

        requests[i] = request;
    }

    Arguments *arguments = CreateArguments(requests,
                                           requests_count);

    if (!arguments) {
        printf("[INTERNAL] Can`t create arguments!\n");

        free(requests);

        return NULL;
    }

    return arguments;
}
