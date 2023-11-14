#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
    int fd = open("./example.txt", O_RDONLY);
    if (fd == -1) {
        printf("error open()\n");
        return -1;
    }

    char buf;
    if (read(fd, &buf, sizeof(char)) == -1) {
        printf("error read()\n");
        return -1;
    }

    write(STDOUT_FILENO, &buf, sizeof(char));
    lseek(fd, 1, SEEK_SET);
    
    if (close(fd) == -1) {
        printf("error close()\n");
        return -1;
    }

    return 0;
}
