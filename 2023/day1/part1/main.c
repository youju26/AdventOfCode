#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int value = 0;

    stream = fopen(argv[1], "r");

    while ((nread = getline(&line, &len, stream)) != -1) {

        int first = 0;
        int last = 0;

        for (int i = 0; i < nread; i++) {
            char c = line[i];
            if( c >= '0' && c <= '9' ){
                first = c - '0';
                break;
            }
        }
        for (int i = nread; i >= 0; i--) {
            char c = line[i];
            if( c >= '0' && c <= '9' ){
                last = c - '0';
                break;
            }
        }

        value += first * 10 + last;

    }

    printf("%d \n", value);

    free(line);
    fclose(stream);
    exit(EXIT_SUCCESS);
}