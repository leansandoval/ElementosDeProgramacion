/*5.1.1 Mostrar por pantalla los números pares comprendidos entre 100 y 500.
----------------------------------------------------------------------------
Resolucion: Realizo un ciclo for desde el 100 hasta el 500. Dentro del ciclo
divido ese numero por 2, si su resto da 0, quiere decir que ese numero es un
numero par. Es por eso que dentro de la condicion del if se lo imprime.
*/

#include<stdio.h>
int main()
{
    int i,par;
    printf("\nLos numeros pares comprendidos entre 100 y 500 son: ");
    for(i=100;i<=500;i++)
    {
        par=i%2;
        if(par==0)
            printf("\n%d",i);
    }
    return 0;
}
