#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *bankers_start_routine(void *arg);
void *clients_start_routine(void *arg);
void deposit(int *balance, int amount);
void withdraw(int *balance, int amount);

pthread_mutex_t balance_mutex;

int main() {
    int balance = 10000;
    pthread_mutex_init(&balance_mutex, NULL);
    pthread_t bankers_thread, clients_thread;
    pthread_create(&bankers_thread, NULL, bankers_start_routine, (void *) &balance);
    pthread_create(&clients_thread, NULL, clients_start_routine, (void *) &balance);

    pthread_join(bankers_thread, NULL);
    pthread_join(bankers_thread, NULL);
    printf("Balance - %d\n", balance);
    return 0;
}

void *bankers_start_routine(void *arg) {
    int *balance = (int *) arg;
    for (size_t i = 0; i < 50000; i++) {
        deposit(balance, i + 1);
    }
    pthread_exit(0);
}

void *clients_start_routine(void *arg) {
    int *balance = (int *) arg;
    for (size_t i = 0; i < 50000; i++) {
        withdraw(balance, i + 1);
    }
    pthread_exit(0);
}

void deposit(int *balance, int amount) {
    pthread_mutex_lock(&balance_mutex);
    (*balance) += amount;
    pthread_mutex_unlock(&balance_mutex);
}

void withdraw(int *balance, int amount) {
    pthread_mutex_lock(&balance_mutex);
    (*balance) -= amount;
    pthread_mutex_unlock(&balance_mutex);
}

