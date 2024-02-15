#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
    int pipefd1[2], pipefd2[2];
    if (pipe(pipefd1) == -1) {
        perror("pipe 1");
    }

    if (pipe(pipefd2) == -1) {
        perror("pipe 2");
    }

    int pid_first, pid_second;
    pid_first = fork();
    if (pid_first == -1) {
        perror("fork");
        return 1;
    }
    if (pid_first == 0) {
        // Child
        // ls -la

        // close read end of pipe, because it won't be used
        close(pipefd1[0]);

        // eqivalent to dup2 below:
        //
        // close(STDOUT_FILENO);
        // dup(pipefd[1]);

        dup2(pipefd1[1], STDOUT_FILENO); // dup2 closes stdout automatically
        close(pipefd1[1]);
        if (execlp("ls", "ls", "-la", NULL) == -1) {
            perror("exec ls");
        }
    }

    if (pid_first > 0) {
        // Parent
        // creating child
        
        waitpid(pid_first, NULL, 0);
        close(pipefd1[1]);         // close write end of pipe, because it won't be used
        
        pid_second = fork();
        if(pid_second == -1){
            perror("fork pid_second");
        }
        if(pid_second == 0){
            close(pipefd2[0]);

            dup2(pipefd1[0], STDIN_FILENO);
            dup2(pipefd2[1], STDOUT_FILENO); // dup2 closes stdout automatically
            close(pipefd2[1]);
            if (execlp("grep", "grep", ".c", NULL) == -1) {
                perror("exec grep");
            }
        }
        if(pid_second > 0){
            waitpid(pid_second, NULL, 0);
            close(pipefd2[1]);
            dup2(pipefd2[0], STDIN_FILENO);
            close(pipefd2[0]);
            if (execlp("head", "head", "-n", "2", NULL) == -1) {
                perror("exec head");
            }
        }


    }

    
    return 0;
}
