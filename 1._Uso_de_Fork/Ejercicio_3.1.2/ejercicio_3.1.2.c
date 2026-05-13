#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
	int pid;
	int i;
	int variable = 0;
	int pipefd[2]; 

	//Verifica si falló la creación de pipe
	if(pipe(pipefd) == -1){
		perror("Error creando pipe");
		exit(1);
	}

	pid = fork();

	switch(pid){

		case -1:
			perror("Error al crear el proceso");
			return 1;

		case 0: //Proceso hijo

			{
				close(pipefd[1]); //El hijo no puede escribir por pipe

				printf("Soy el hijo con el PID: %d\n", getpid());

				FILE *archivo = fopen("log.txt", "w"); //Creación de un archivo
				if(archivo == NULL) exit(1);
				int valor_recibido;
				for(i = 0; i < 10; i++){
					read(pipefd[0], &valor_recibido, sizeof(int)); //El hijo obtiene el valor del padre
					fprintf(archivo, "Hijo lee valor de variable: %d\n", valor_recibido); //Escribe los datos en el archivo
				}

				fclose(archivo);
				close(pipefd[0]);
				exit(0);
			}
			break;

		default: //Proceso padre

			close(pipefd[0]); //El padre no puede leer lo que el mismo envía

			printf("Soy el padre con el PID: %d\n", getpid());
			for(i = 0; i < 10; i++){
				variable += 10; //Incrementa una variable
				printf("Padre incrementa variable a: %d\n", variable);
				write(pipefd[1], &variable, sizeof(int)); //Envìa los valores al hijo
			}

			close(pipefd[1]);
			wait(NULL);
			break;

	}

	return 0;
}
