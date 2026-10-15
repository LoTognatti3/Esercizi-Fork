#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
    printf("Processo nonno %d\n", getpid());
    pid_t processop = fork();
    if (processop == -1) {
        perror("fork");
        exit(-1);
    }
    if (processop == 0) {
        printf("Processo padre %d\n", getpid());
        pid_t processon = fork();
        if (processon == -1) {
            perror("fork");
            exit(-1);
        }
        if (processon == 0) {
            printf("Processo nipote %d\n", getpid());
            printf("Il processo nipote ha finito");
            exit(0);
        }
        else {
            wait(NULL);
            printf("Il processo padre ha finito\n");
            exit(0);
        }
    }
    else {
        wait(NULL);
        printf("Il processo nonno ha finito\n");
        exit(0);
    }
    return 0;
}
