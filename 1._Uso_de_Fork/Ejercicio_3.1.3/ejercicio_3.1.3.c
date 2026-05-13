#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int pid;

int main(){
	pid = fork();

	switch(pid){
		case -1:
			printf("\nNo he podido crear el proceso hijo");
			break;
		case 0:
			printf("\nSoy el hijo, mi PID es %d y mi PPID es %d", getpid(), getppid());
			wait(0);
			break;
		default:
			printf("\nSoy el padre, mi PID es %d y el PID de mi hijo es %d", getpid(), pid);
			wait(0); //El padre espera a que el hijo termine de ejecutarse
	}

	printf("\nFinal de ejecución de %d\n", getpid());
	exit(0);
}
