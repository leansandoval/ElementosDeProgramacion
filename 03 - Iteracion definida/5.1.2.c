/*5.1.2 Confeccionar un programa para calcular el valor de la siguiente suma:
100 + 95 + 90 + ... + 50.
-----------------------------------------------------------------------------
Resolucion: Declaro una variable sumadora/acumuladora para almacenar la suma
total. Realizo ciclo for desde 50 hasta 100 y que vaya iterando de 5 en 5
para realizar la suma.
Dentro del for voy acumulando las sumas intermedias dentro de la misma
variable.
*/

#include<stdio.h>
#include<conio.h>
int main()
{
    int sum=0,i;
    printf("\nLa suma de los valores 100 + 95 + 90 + ... + 50 es: ");
    for(i=50;i<=100;i=i+5)
        sum=sum+i;
    printf("%d\n",sum);
    return 0;
    getch();
}
