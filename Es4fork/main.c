#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
    int numero;
    pid_t figlio = fork();
    if (figlio == -1) {
        perror("Errore");
    }
    if (figlio == 0) {
        printf("Inserisci un numero");
        scanf("%d", &numero);
        if (numero <= 1) {
            if (numero % 2 == 0) {
                exit(2);
            }
            else {
                exit(3);
            }
        }
        for (int i = 2; i*i <= numero; i++) {
            if (numero % i == 0) {
                if (numero % 2 == 0) {
                    exit(2);
                }
                else {
                    exit(3);
                }
            }
        }
        exit(1);
    }
    else {
        int stato;
        wait(&stato);
        if (WIFEXITED(stato)) {
            int codice = WEXITSTATUS(stato);
            if (codice == 1) {
                printf("Il numero è primo");
            }
            if (codice == 2) {
                printf("Il numero è pari");
            }
            if (codice == 3) {
                printf("Il numero è dispari");
            }
        }
    }
    return 0;
}
