#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
   pid_t r = fork();
    if (r == -1) {
        perror("fork");
        exit(-1);
    }
    if (r == 0) {
        for (int i = 1; i < 6; i++) {
            printf("%d\n", i);
            sleep(1);
        }
        exit(0);
    }
    else {
        wait(NULL);
        for (int i = 6; i < 11; i++) {
            printf("%d\n", i);
            sleep(1);
        }
    }
    return 0;
}
