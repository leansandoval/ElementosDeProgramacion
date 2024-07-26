/*2.1. Se ingresan la cantidad de horas trabajadas y el valor por hora de un empleado. Determinar el sueldo.
------------------------------------------------------------------------------------------------------------
Resolucion: como pide el ingreso de horas de trabajadas estamos hablando de una variable int.
Para el caso de el valor de hora por empleado, se puede decir que es una variable float.
Para determinar el sueldo simplemente se multiplica, las horas trabajadas y el valor por hora del empleado.
*/

#include <stdio.h>

int main()
{
    float valor,sueldo;
    int horas;
    printf("\nIngrese la cantidad de horas trabajadas del empleado: ");
    scanf("%d",&horas);
    printf("\nIngrese el valor por hora del empleado: ");
    scanf("%f",&valor);
    sueldo=horas*valor;
    printf("\nEl sueldo del empleado es de: %.2f",sueldo);
    return 0;
}
