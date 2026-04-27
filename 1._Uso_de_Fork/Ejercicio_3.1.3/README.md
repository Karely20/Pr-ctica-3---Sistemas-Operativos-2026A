# Ejercicio 3.1.3
Creación de un proceso hijo sin espera ( Ejecutar código de la Figura 3)

*Ejecución del código de la Figura 3*

<img width="493" height="86" alt="Captura de pantalla 2026-05-08 205818" src="https://github.com/user-attachments/assets/3bbb0e73-a812-4017-92af-36728b063bea" />

1. **¿Cuál es el PID del proceso padre del proceso hijo creado?**
   
   El PPID del proceso hijo creado es **1670**, por lo tanto ese el PID del proceso padre.
     
2. **Verifique a qué proceso corresponde el PPID encontrado.**
   
   El PPID encontrado (1670) corresponde al proceso padre ya que en la ejecución del padre muestra el mismo valor en su PID.
   
3. **¿Cómo se denomina al tipo de proceso hijo?**
   
   El proceso hijo no es huérfano en el momento en que imprime su PPID, porque todavía muestra el PID del padre; sin embargo, se vuelve huérfano cuando el padre termina su ejecución.
   
4. **Modifique el código de la Figura 3 para que el proceso hijo no quede huérfano. Demostrar el resultado con el PPID del proceso hijo.**

   A pesar de que en la ejecución no se aprecia claramente como el proceso queda huérfano ya que imprime el PID del padre, para evitar este problema el proceso padre debe esperar al hijo antes de terminar de ejecutarse.
   Esto se cumple añadiendo `wait(0)` en el padre.

   *Ejecución del código de la Figura 3 añadiendo `wait(0)`*
   
   <img width="456" height="73" alt="Captura de pantalla 2026-05-08 211119" src="https://github.com/user-attachments/assets/749736f8-9c4c-480c-8640-f14a765bfde1" />
