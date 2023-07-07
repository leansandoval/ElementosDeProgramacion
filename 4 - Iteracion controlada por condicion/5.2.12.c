/*5.2.12 Confeccionar un programa que permita el ingreso de 6 ternas de valores enteros.
    a. De cada terna informar el mayor valor y su orden en la terna.
    b. De cada terna informar cuantos valores son múltiplos de 7.
    c. De las 6 ternas determinar e informar el promedio de los primeros valores de cada una.
----------------------------------------------------------------------------------------------
Resolucion: un ciclo while para la cantidad de ternas (en este caso 6) y un ciclo for para los
3 datos de la terna. Dentro del ciclo for guardo el primer valor de la terna para asumiendo
que el primer valor de cada terna es el maximo, otra condicion por si es multiplo de 7 y otra
para sumar el primer valor de cada terna. Despues de cada for muestro por pantalla e inicializo
las variables sumadoras y contadoras para la siguiente terna.*/

#include<stdio.h>
#define TOPE 6

int main()
{
    int i,posicionMayor,valor,mayor=0,cantidadTernas=0,multiplosDe7=0,sumaPrimerValor=0;
    while(cantidadTernas!=TOPE)
    {
        cantidadTernas++;
        for(i=1; i<=3; i++)
        {
            printf("\nIngrese valor correspondiente de la terna: ");
            scanf("%d",&valor);
            if(i==1 || valor>mayor)
            {
                mayor=valor;
                posicionMayor=i;
            }
            if(valor%7==0)
                multiplosDe7++;
            if(i==1)
                sumaPrimerValor+=valor;
        }
        printf("\nMayor valor de la terna es el %d en la posicion %d\n",mayor,posicionMayor);
        printf("\nCantidad de valores multiplos de 7: %d\n",multiplosDe7);
        mayor=0;
        multiplosDe7=0;
    }
    printf("\nPromedio de los primeros valores de cada terna: %.2f\n",(float)sumaPrimerValor/TOPE);
    return 0;
}
