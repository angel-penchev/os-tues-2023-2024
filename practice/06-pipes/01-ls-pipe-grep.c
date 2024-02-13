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

    int pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid > 0) {
        // Parent
        // grep

        // waitpid(pid, NULL, 0);

        // close write end of pipe, because it won't be used
        close(pipefd[1]);

        // eqivalent to dup2 below:
        //
        // close(STDIN_FILENO);
        // dup(pipefd[0]);


        dup2(pipefd[0], STDIN_FILENO);
        if (execlp("grep", "grep", ".c", NULL) == -1) {
            perror("exec grep");
        }
    }

    if (pid == 0) {
        // Child
        // ls -la

        // close read end of pipe, because it won't be used
        close(pipefd[0]);

        // eqivalent to dup2 below:
        //
        // close(STDOUT_FILENO);
        // dup(pipefd[1]);

        dup2(pipefd[1], STDOUT_FILENO); // dup2 closes stdout automatically
        if (execlp("ls", "ls", "-la", NULL) == -1) {
            perror("exec ls");
        }
    }
    return 0;
}
