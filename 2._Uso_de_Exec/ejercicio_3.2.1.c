#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int ejecutarNuevoProc(char *programa, char *arg_list[]);

int main()
{
    char *programa = "ls";
    char *arg_list[] = {"ls", "-l", NULL};

    int pid = ejecutarNuevoProc(programa, arg_list);

    wait(0);

    fprintf(stdout, "el proceso hijo con PID %d se ha ejecutado\n", pid);

    return 0;
}

int ejecutarNuevoProc(char *programa, char *arg_list[])
{
    int pid;

    pid = fork();

    switch(pid)
    {
        case -1:
            fprintf(stderr, "No se pudo crear el proceso");
            exit(0);

        case 0:
            execvp(programa, arg_list);

            // No se ejecuta, si el execvp se ejecuta correctamente
            fprintf(stderr, "error al ejecutar exec");
            exit(0);

        default:
            return pid;
    }
}
