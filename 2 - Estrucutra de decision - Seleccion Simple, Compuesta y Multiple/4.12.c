/*4.12. Ingresar el valor de la hora y la cantidad de horas trabajadas por un empleado. Calcular su sueldo tomando
en cuenta que recibe un premio de $500 si trabajo más de 50 horas y, además, si trabajó más de 150 horas
se le otorgan $1000 adicionales.
------------------------------------------------------------------------------------------------------------------
Resolucion: Variable tipo float para el valor por hora e int para la cantidad de horas trabajadas. Por lo que el
sueldo se determina como la multiplicacion de ambos valores, pero hay que tener en cuenta la cantidad de horas
trabajadas.
Si la cantidad > 50 horas --> sueldo (cantidad de horas * valor de la hora) + $500
Si la cantidad > 150 horas --> sueldo (cantidad de horas * valor de la hora) + $500 + $1000. Asumo que se conservan
los $500 ya que en el enunciado dice ademas.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    int horas;
    float valor;
    printf("\nIngrese el valor de cada hora trabajada: ");
    scanf("%f",&valor);
    printf("\nIngrese la cantidad de horas trabajadas: ");
    scanf("%d",&horas);
    if(horas>50 && horas<=150)
        printf("\nEl sueldo del empleado es de: $%.2f\n",(valor*horas)+500);
    else
        if(horas>horas)
           printf("\nEl sueldo del empleado es de: $%.2f\n",(valor*horas)+1500);
        else
           printf("\nEl sueldo del empleado es de: $%.2f\n",valor*horas);
    return 0;
}
