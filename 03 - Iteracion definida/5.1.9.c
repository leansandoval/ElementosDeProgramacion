/*5.1.9 Confeccionar un programa que exhiba por pantalla una lista, a dos columnas, con los primeros 15 números
impares en la primera y los 15 primeros pares en la segunda, incluyendo los títulos.
---------------------------------------------------------------------------------------------------------------
Resolucion: pide los primeros 15 pares y los primeros 15 impares, por lo que seran los primeros 30 numeros
naturales. Dentro del ciclo for se va a imprimir el valor de i+1 y el valor de i por lo que se alinearan en dos
columnas.*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i;
    printf("\nIMPARES\tPARES\n");
    for(i=1;i<=30;i++)
    {
        printf("\n%d\t%d",i++,i);
    }
    return 0;
}
