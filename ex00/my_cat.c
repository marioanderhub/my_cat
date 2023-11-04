#include <stdio.h>
#include <stdlib.h>

void print(char *filename) {

    // open file
    // read
    // print
    // clean up and close

    FILE *file;
    char *buff;
    int buff_size = 2;

    buff = malloc(sizeof(*buff) * buff_size);
    if (buff == NULL) {
        perror("Memory allocation failed.");
        return;
    }
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Opening file failed.");
        return;
    }
    while (fgets(buff, buff_size, file) != NULL) {
        printf("%s", buff);
    }

    fclose(file);
    free(buff);
}

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        print(argv[i]);
    }
    return 0;
}