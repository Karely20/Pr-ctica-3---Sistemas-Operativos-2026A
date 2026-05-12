
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        // PROCESO PADRE
        printf("Padre durmiendo... PID: %d. El hijo es un Zombie ahora.\n", getpid());
        // El padre duerme 20 segundos para darte tiempo de ver el zombie en otra terminal
        sleep(20); 
        printf("Padre despierta y termina.\n");
    } 
    else if (pid == 0) {
        // PROCESO HIJO
        printf("Hijo terminando... PID: %d\n", getpid());
        exit(0); // El hijo muere y se convierte en zombie porque el padre no hace wait()
    }

    return 0;
}


