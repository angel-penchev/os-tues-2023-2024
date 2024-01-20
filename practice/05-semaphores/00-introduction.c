#include <fcntl.h>
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>

int main() {
    sem_t *sem_bobcho = sem_open("bobcho", O_CREAT | O_RDWR, 0664, 10);
    if (sem_bobcho == NULL) {
        perror("sem_open");
    }

    if (sem_wait(sem_bobcho) == -1) {
        perror("sem_wait");
    };
    // critical section 
    if (sem_post(sem_bobcho) == -1) {
        perror("sem_wait");
        return 1;
    };
 
    if (sem_close(sem_bobcho) == -1) {
        perror("sem_close");
    }

    if (sem_unlink("bobcho") == -1) {
        perror("sem_unlink");
    }
    return 0;
}
