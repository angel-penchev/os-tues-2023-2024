#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
    }

    // if (pipe2(pipefd, O_NONBLOCK) == -1) {
    //     perror("pipe");
    // }

    // For macOS users (pipe2 is not available on macOS)
    // pipe(pipefd);
    // fcntl(pipefd[0], O_NONBLOCK);
    // fcntl(pipefd[1], O_NONBLOCK);
    printf("%d %d\n", pipefd[0], pipefd[1]);
    //                   ^ read     ^ write

    // On files, even if the file is empty, read doesn't block
    // int fd = open("./empty.txt", O_RDONLY);
    // int read_bytes = read(fd, NULL, 6);
    // printf("%d\n", read_bytes);

    int pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid > 0) {
        // Parent
        char *buf = "hello";
        // write(pipefd[1], buf, 6); // add error checking
        close(pipefd[1]);
        wait(NULL);
    }


    if (pid == 0) {
        // Child
        char buf[6];
        // Read will return error if O_NONBLOCK is set
        // otherwise it will block the process until
        if (read(pipefd[0], &buf, 6) == -1) {
            perror("read");
        }
        printf("%s\n", buf);
    }
    return 0;
}
