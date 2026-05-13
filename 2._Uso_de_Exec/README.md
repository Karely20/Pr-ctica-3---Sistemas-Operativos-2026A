# Ejercicio 3.2.1
## Detalles de la Implementación

El programa fue desarrollado para demostrar la creación y ejecución de procesos en sistemas Unix/Linux utilizando las funciones `fork()` y `execvp()`.

### Cambios y funcionamiento

- **Creación de procesos:**  
  Se utilizó `fork()` para crear un proceso hijo a partir del proceso principal.

- **Ejecución de comandos:**  
  El proceso hijo ejecuta el comando `ls -l` mediante `execvp()`, mostrando los archivos y carpetas del directorio actual.

- **Sincronización de procesos:**  
  La función `wait()` permite que el proceso padre espere la finalización del hijo antes de continuar su ejecución.

- **Control de errores:**  
  Se implementaron mensajes de error para detectar fallos en la creación del proceso o en la ejecución del comando.

  ## Resultado de ejecución
  <img width="369" height="264" alt="image" src="https://github.com/user-attachments/assets/edb4c362-760f-44fc-9089-7b48943541e2" />

















