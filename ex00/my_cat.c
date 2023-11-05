#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
**
** This function prints the contents of a file to stdout.
**
** @param {char *} filename
**
*/
void print(char *filename) {
    int file;
    char *buff;
    const int buff_size = 1024;
    size_t byte_read = 0;

    buff = malloc(buff_size * sizeof(*buff));
    if (buff == NULL) {
        perror("Memory allocation failed");
        return;
    }
    file = open(filename, O_RDONLY);
    if (file == -1) {
        perror("Opening file failed");
        return;
    }
    while ((byte_read = read(file, buff, buff_size)) != 0) {
        write(1, buff, byte_read);
    }
    close(file);
    free(buff);
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        print(argv[i]);
    }
    return 0;
}