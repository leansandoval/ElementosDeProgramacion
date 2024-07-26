/*2.8. Se ingresa un número entero que representa una fecha con formato (ddmmaa). Se pide transformarlo a un
número con formato (aammdd).
-------------------------------------------------------------------------------------------------------------
Resolucion: La fecha ingresada, se tendra que descompone de la siguiente forma: utilizo 3 variables int,
una para el dia (dd), mes (mm) y año (aa).
Para descomponerla sera muy identico a la resolucion del 2.7: utilizando operadores de division / y resto %.
Ahora, para componer la nueva fecha sera utilizando el operando de multiplicacion *, ya que el año paso de
ser el de menor valor al de mayor peso. Idem con el mes.
*/

#include <stdio.h>
int main ()
{
    int fecha,dd,mm,aa,nuevo_aa,nuevo_mm,nueva_fecha;
    printf("\nIngrese fecha en formato ddmmaa: ");
    scanf("%d",&fecha);
    dd=fecha/10000;
    mm=(fecha%10000)/100;
    aa=(fecha%10000)%100;
    nuevo_aa=aa*10000;
    nuevo_mm=mm*100;
    nueva_fecha=nuevo_aa+nuevo_mm+dd;
    printf("\nLa nueva fecha en formato aammdd es: %d",nueva_fecha);
    return 0;
}
