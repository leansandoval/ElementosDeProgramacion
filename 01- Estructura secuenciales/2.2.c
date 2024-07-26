/*2.2. Se ingresan las notas de dos evaluaciones de un alumno. Determinar la nota promedio.
------------------------------------------------------------------------------------------------------------------------------------------
Resolucion: al tratarse de dos notas, considero dos variables int y asumo que las notas estan 'redondeadas' (no acepto 9,50 ... 7,25 etc.)
Al ser dos notas, el promedio es la suma de las notas dividida la cantidad de notas, en este caso dos.
Fijarse que la variable flotante llamada prom esta declarada de la forma --> prom=(float)(nota1+nota2)/2.
Este float entre parentesis es necesario para la conversion de una division de variables enteras a un resultado flotante.
*/

#include <stdio.h>
int main ()
{
    int nota1,nota2;
    float prom;
    printf("\nIngrese la nota de la primera evaluacion:");
    scanf("%d",&nota1);
    printf("\nIngrese la nota de la segunda evaluacion:");
    scanf("%d",&nota2);
    prom=(float)(nota1+nota2)/2;
    printf("\nLa nota promedio del alumno es de: %.2f",prom);
    return 0;
}



