#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 256
void grep(const char *pattern, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, pattern) != NULL) {
            printf("%s:%d: %s", filename, line_number, line);
        }
        line_number++;
    }
    fclose(file);
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pattern> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *pattern = argv[1];
    const char *filename = argv[2];
    grep(pattern, filename);
    return EXIT_SUCCESS;
}
