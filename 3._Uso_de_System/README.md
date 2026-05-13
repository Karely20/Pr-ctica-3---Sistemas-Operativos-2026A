

# Ejercicio 3.1.5

Ejecute el programa donde el proceso hijo termina antes que el padre, provocando la creación de un proceso Zombie.

Ejecución del código de verificación de proceso Zombie:
https://github.com/8Patrick88/Sistemas_Evidencia_Linux/blob/main/Ejecucion.png?raw=true


Al ejecutar el programa se generaron dos procesos: el proceso padre y el proceso hijo. El proceso hijo terminó inmediatamente utilizando `exit(0)`, mientras que el proceso padre permaneció dormido durante 20 segundos utilizando `sleep(20)` sin ejecutar `wait()`. Debido a esto, el hijo quedó temporalmente en estado Zombie.

1. **Proceso Padre**

   * **PID:** 20541 - Corresponde al proceso principal que ejecuta el programa.
   * El padre entra en estado de espera con `sleep(20)` para permitir observar el proceso Zombie desde otra terminal.

2. **Proceso Hijo**

   * **PID:** 20542 - Es el proceso creado mediante `fork()`.
   * **PPID:** 20541 - Indica que el proceso padre fue quien creó el proceso hijo.
   * El hijo finaliza inmediatamente con `exit(0)` y queda en estado Zombie porque el padre todavía no ejecuta `wait()` para recoger su estado de terminación.

*Verificación del proceso Zombie utilizando `ps -l | grep Z`:*

Terminal 2: Verificación del Zombie mientras el padre duerme
https://raw.githubusercontent.com/8Patrick88/Sistemas_Evidencia_Linux/7e3325cc84375e19eb8f2609adb49904353b5c32/zombie.png


En la salida del comando `ps -l | grep Z` se puede observar que el proceso `ejercicio_3.1.5` aparece con el estado `Z`, que significa **Zombie**. Además, el texto `<defunct>` indica que el proceso hijo ya terminó su ejecución, pero aún conserva su entrada en la tabla de procesos porque el padre no ha leído su estado de salida mediante `wait()`.
