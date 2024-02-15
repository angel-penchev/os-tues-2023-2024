#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("pipe 1");
    }

    if (pipe(pipefd) == -1)
    {
        perror("pipe 2");
    }

    int pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    if (pid == 0)
    {
        // Child
        // ls -la

        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO); // dup2 closes stdout automatically
        write(1, "hello\n", 7);
        close(pipefd[1]);
        if (execlp("ls", "ls", "-la", NULL) == -1)
        {
            perror("exec ls");
            return 1;
        }
    }

    // waitpid(pid, NULL, 0);

    pid = fork();
    if (pid == -1)
    {
        perror("fork pid_second");
    }
    if (pid == 0)
    {
        // Child - run grep .c
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        if (execlp("grep", "grep", ".c", NULL) == -1)
        {
            perror("exec grep");
            return - 1;
        }
    }
    // waitpid(pid, NULL, 0);
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    if (execlp("cowsay", "cowsay", NULL) == -1)
    {
        perror("exec cowsay");
        return 1;
    }

    return 0;
}
