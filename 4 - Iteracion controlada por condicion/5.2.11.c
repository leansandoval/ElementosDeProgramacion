/*5.2.11 Se ingresan números enteros, hasta que se ingrese el número cero. Determinar los 2 valores mayores
-----------------------------------------------------------------------------------------------------------
Resolucion: ingresamos el primer numero y antes del ciclo lo almacenamos como el mayor y el segundo mayor
ya que hasta ese momento es el unico numero que se ingreso. Para los proximos ingresos (dentro del ciclo)
si fuera mayor al que estaba anteriormente, el que estaba en mayor pasa a ser ahora el segundo mayor. Y el
numero ingresado seria el mayor de todos. Importante: es necesario declarar una bandera para saber si se
realizo el intercambio de mayor a segundo mayor ya que la otra condicion del if pisaria el dato.
Ejemplo:
Numero = 23 --> Mayor = 23, Segundo Mayor = 23
Numero = 32 --> Mayor = 32, Segundo Mayor = 23  (Primer if - Mayor pasa a ser Segundo Mayor)
Numero = 25 --> Mayor = 32, Segundo Mayor = 25  (Segundo if - Unicamente modifico al Segundo Mayor)
*/

#include <stdio.h>

int main()
{
    int numero,mayor,segundoMayor,bandera=0;
    printf("\nIngrese un numero entero (0 para terminar): ");
    scanf("%d",&numero);
    mayor=numero;
    segundoMayor=mayor;
    while(numero!=0)
    {
        if(numero>mayor)
        {
            segundoMayor=mayor;
            mayor=numero;
            bandera=1;
        }
        if(bandera==0 && numero>segundoMayor)
            segundoMayor=numero;
        bandera=0;
        printf("\nIngrese un numero entero (0 para terminar): ");
        scanf("%d",&numero);
    }
    printf("\nEl numero mayor es %d y el segundo mayor %d\n",mayor,segundoMayor);
    return 0;
}
