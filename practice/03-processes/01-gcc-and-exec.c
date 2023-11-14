#include <unistd.h>
#include <error.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define SYS_ERROR_CHECK(syscall, error) \
    if (syscall == -1)                  \
    {                                   \
        perror(error);                  \
    }
#define CHILD_PROC_ERR "err"

int main(int argc, char const *argv[])
{

    int pid = fork();

    if (pid == -1)
    {
        perror("fork()");
    }
    else if (pid == 0)
    {
        // child
        SYS_ERROR_CHECK(
            execlp("gcc", "gcc", "01-helloworld.c", "-o", "helloworld", NULL),
            "exec()");

        const char *args[] = {"ls", "-la", NULL};
        if (execvp("ls", args) == -1)
        {
            perror("execvp()");
        }
    }
    else if (pid > 0)
    {
        // parent
        // await child
        int return_code;
        if (waitpid(pid, &return_code, 0) == -1)
        {
            perror("waitpid()");
        }

        if (WIFEXITED(return_code) && WEXITSTATUS(return_code) == 0)
        {
            // printf("return_code: %b\n", return_code);
            // printf("return value: %d\n", WEXITSTATUS(return_code));
            // printf("exited: %d\n", WIFEXITED(return_code));
            // printf("signaled: %d\n", WIFSIGNALED(return_code));
        }
        else
        {
            // gcc has failed
            write(STDERR_FILENO, CHILD_PROC_ERR, strlen(CHILD_PROC_ERR) * sizeof(char));
            return 1;
        }

        // ./helloworld
        SYS_ERROR_CHECK(execlp("./helloworld", "./helloworld", NULL), "exec()");
    }
    return 0;
}
