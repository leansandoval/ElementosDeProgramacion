/*5.1.5 Confeccionar un programa para calcular la suma de los primeros N números naturales.
El valor de N lo solicita por teclado el programa.
------------------------------------------------------------------------------------------
Resolucion: el numero ingresado es el tope del ciclo for y con una variable acumuladora ir
sumando desde el primer numero natural (0) hasta el numero ingresado. Este programa es
parecido a una sumatoria.*/

#include<stdio.h>
#include<conio.h>

int main ()
{
    int numero,i,suma=0;
    printf("\nIngrese un numero natural: ");
    scanf("%d",&numero);
    for(i=0;i<=numero;i++)
        suma+=i;
    printf("\nLa suma de los primeros %d numeros naturales es: %d\n",numero,suma);
    return 0;
    getch();
}
