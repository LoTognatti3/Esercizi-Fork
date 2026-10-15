#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
    pid_t processo1 = fork();
    if (processo1 == -1)
    {
        perror("fork");
        exit(-1);
    }
    if (processo1 == 0) {
        printf("%ld\n", (long)getpid());
        exit(0);
    }
    sleep(2);
    pid_t processo2 = fork();
    if (processo2 == -1)
    {
        perror("fork");
        exit(-1);
    }
    if (processo2 == 0) {
        printf("%ld\n", (long)getpid());
        exit(0);
    }
    sleep(2);
    pid_t processo3 = fork();
    if (processo3 == -1)
    {
        perror("fork");
        exit(-1);
    }
    if (processo3 == 0) {
        printf("%ld\n", (long)getpid());
        exit(0);
    }
    sleep(2);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    printf("Tutti e tre i processi figli hanno finito di stampare i corrispondenti pid");
    return 0;
}
