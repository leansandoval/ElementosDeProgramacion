/*5.1.7 Dadas 20 notas y legajos de alumnos de un curso. Determinar:
a. Cantidad de alumnos aplazados.
b. Cuando la nota sea mayor a 7, mostrar el mensaje: “El alumno con legajo xxx ha Promocionado”.
-------------------------------------------------------------------------------------------------
Resolucion: como son 20 notas el ciclo for ira desde la primera nota hasta la numero 20. Dentro
del ciclo se ingresa la nota y el legajo. Obviamente la nota debera estar entre 1 y 10 por lo
tanto ese sera el primer if, luego para los alumnos aplazados sera para los notas menores a 4.
Cuando se encuentre una nota dentro de ese rango se ingrementara la variable que cuenta la
cantidad de aplazados. En el else se anida un if para cuando la nota sea mayor a 7 y muestre
por pantalla el legajo del alumno.
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int nota,i,cantidadAplazados=0,legajo;
    for(i=1;i<=20;i++)
    {
        printf("\nIngrese la nota de cada alumno: ");
        scanf("%d",&nota);
        printf("\nIngrese el legajo correspondiente para cada uno: ");
        scanf("%d",&legajo);
        if(nota>=1 && nota<=10)
            if(nota<4)
                cantidadAplazados++;
            else
                if(nota>=7)
                    printf("\nEl alumno con legajo %d ha promocionado\n",legajo);
    }

    printf("\nLa cantidad de alumnos aplazados es: %d\n",cantidadAplazados);
    return 0;
}
