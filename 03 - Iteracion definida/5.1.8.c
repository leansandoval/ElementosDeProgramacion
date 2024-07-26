/*5.1.8 Dadas las edades y estaturas de 45 alumnos de un curso. Determinar:
a. Edad promedio.
b. Estatura promedio.
c. Cantidad de alumnos mayores de 10 años.
d. Cantidad de alumnos que miden menos de 1.40 cm.
-------------------------------------------------------------------------------------------------
Resolucion: Declaro una macro para cantidad de alumnos (en este caso 45). Dentro del ciclo for,
ingreso edad y estatura y a su vez ya voy acumulando el ingreso de datos. Dos if para las
condiciones del ejercicio con sus respectivas variables contadoras. Para el promedio unicamente
hay que castear ya que se mezclan variables enteras con flotantes.
*/

#include<stdio.h>
#include<stdlib.h>
#define ALUMNOS 45
int main()
{
    int i,edad,sumaEdad=0,cantidadEdadMayorA10=0,cantidadEstaturaMenorA140m=0;
    float estatura,sumaEstatura=0;
    for(i=1;i<=ALUMNOS;i++)
    {
        printf("\nIngrese edad: ");
        scanf("%d",&edad);
        printf("\nIngrese estatura: ");
        scanf("%f",&estatura);
        sumaEdad+=edad;
        sumaEstatura+=estatura;
        if(edad>10)
            cantidadEdadMayorA10++;
        if(estatura<1.40)
            cantidadEstaturaMenorA140m++;
    }
    printf("\nEdad promedio: %.2f\n",(float)sumaEdad/ALUMNOS);
    printf("\nEstatura promedio: %.3f\n",(float)sumaEstatura/ALUMNOS);
    printf("\nCantidad de alumnos mayores de 10 anios: %d\n",cantidadEdadMayorA10);
    printf("\nCantidad de alumnos que miden menos de 1.40 cm: %d\n",cantidadEstaturaMenorA140m);
    return 0;
}
