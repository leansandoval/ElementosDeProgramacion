/*5.1.6 Ingresar N y N Números naturales. Determinar e informar:
a. La sumatoria de los valores múltiplos de 3.
b. La cantidad de valores múltiplos de 5.
c. La sumatoria de los valores que se ingresan en orden par.
-------------------------------------------------------------------------------------------
Resolucion: el primer numero a ingresar es la cantidad de numeros que se pretende ingresar
dentro del ciclo for, la segunda variable va a tomar cualquier numero ingresado por teclado
hasta llegar al primer numero ingresado.
Se realizan 3 if's para lo pedido:
* Sumatoria para los valores multiplos de 3: si la variable numero al ser dividida por 3 da
como resto 0, quiere decir que es multiplo por lo tanto lo acumulo en su respectiva variable.
* Cantidad valores multiplos de 5: lo mismo que el punto anterior, solo que en vez de tener
una variable acumuladora voy a tener una variable contadora ya que pide cantidad.
* Sumatoria de los valores que se ingresan en orden par: la variable de iteracion es i, por
lo que si es divisible por 2, quiere decir que la iteracion es par y ese numero ingresado se
guarda en la variable acumuladora.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int numero,i,cantidadNumeros,cantidadMultiplos5=0,sumatoriaMultiplos3=0,sumatoriaPar=0;
    printf("\nIngrese un la cantidad de numeros a calcular: ");
    scanf("%d",&cantidadNumeros);
    for(i=1;i<=cantidadNumeros;i++)
    {
        printf("\nIngrese un numero hasta la cantidad que ingreso anteriormente: ");
        scanf("%d",&numero);
        if(numero%3==0)
            sumatoriaMultiplos3+=numero;
        if(numero%5==0)
            cantidadMultiplos5++;
        if(i%2==0)
            sumatoriaPar+=numero;
    }
    printf("\nLa sumatoria de de los valores multiplos de 3 es: %d\n",sumatoriaMultiplos3);
    printf("\nLa cantidad de valores multiplos de 5 es: %d\n",cantidadMultiplos5);
    printf("\nLa sumatoria de los valores que se ingresan en orden par es: %d\n",sumatoriaPar);
    return 0;
}
