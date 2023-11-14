#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
    //...
    if (execle("/usr/bin/ls", "/usr/bin/ls", "/", NULL, "", NULL) == -1) {
        perror("exec()");
    }

    int pid = fork();
    if (pid > 0) {
        // Parent
        int return_code;
        if (waitpid(pid, &return_code, 0) == -1) {
            perror("waitpid()");
            return -1;
        }
        printf("return_code: %b\n", return_code);
        printf("return value: %d\n", WEXITSTATUS(return_code));
        printf("exited: %d\n", WIFEXITED(return_code));
        printf("signaled: %d\n", WIFSIGNALED(return_code));

        printf("child is awaited\n");
        printf("parent\n");
    } else if (pid == 0) {
        // Child
        printf("child\n");
        sleep(60);
        return 2;
        // execl("/usr/bin/cat", "/usr/bin/cat" "example.txt", NULL);
    } else {
        perror("fork()");
        return -1;
    }
    return 0;
}

