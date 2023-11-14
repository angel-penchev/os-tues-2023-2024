#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("wrong number of arguments\n");
        return -1;
    }

    int fd = open(argv[1], O_CREAT | O_RDONLY, 0700);
    if (fd == -1) {
        perror("open()");
        return -1;
    }

    char buf;
    int read_result;
    while ((read_result = read(fd, &buf, sizeof(char))) != 0) {
        if (read_result == -1) {
            perror("read()");
            return -1;
        }
        write(STDOUT_FILENO, &buf, read_result * sizeof(char));
    }

    if (close(fd) == -1) {
        perror("close()");
        return -1;
    }

    return 0;
}
