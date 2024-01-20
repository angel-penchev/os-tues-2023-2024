#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#define READERS_COUNT 20
#define READER_PROCESSES_TO_START 30

int read_and_print_file(sem_t *sem_readers, int id);

int main() {
    sem_t *sem_readers = sem_open("library_readers", O_CREAT | O_RDWR, 0664, READERS_COUNT);
    if (sem_readers == NULL) {
        perror("sem_open");
    }

    pid_t pids[READER_PROCESSES_TO_START];
    for (int i = 0; i < READER_PROCESSES_TO_START; i++) {
        pids[i] = fork();

        if (pids[i] == -1) {
            // error
            perror("fork()");
        } else if (pids[i] == 0) {
            // child
            return read_and_print_file(sem_readers, i);
        }
    }

    for (int i = 0; i < READER_PROCESSES_TO_START; i++) {
        waitpid(pids[i], NULL, 0);
    }
    if (sem_close(sem_readers) == -1) {
        perror("sem_close");
    }

    return 0;
}

int read_and_print_file(sem_t *sem_readers, int id) {
    if (sem_wait(sem_readers) == -1) {
        perror("sem_wait");
    };

    // start of readers critical section 
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
    }

    char out_name[] = "A.txt";
    out_name[0] = 'A' + id;
    int fd_out = open(out_name, O_WRONLY | O_CREAT, 0666);
    if (fd_out == -1)
    {
        perror("open fd_out");
    }
    

    unsigned char buff[10];
    int read_return;
    while ((read_return = read(fd, buff, 10))) {
        if (read_return == -1) {
            perror("read");
        }

        printf("%d\n", id);
        if (write(fd_out, buff, read_return) == -1) {
            perror("write");
        }
    }

    if (close(fd) == -1) {
        perror("close");
    }
    if (close(fd_out) == -1) {
        perror("close");
    }

    // end of readers critical section 

    if (sem_post(sem_readers) == -1) {
        perror("sem_wait");
        return 1;
    };
    return 0;
}