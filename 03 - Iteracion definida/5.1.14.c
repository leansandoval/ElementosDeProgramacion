/*5.1.14 Confeccionar un programa que determine e informe los números perfectos comprendidos entre 1 y 8000.
Un número es perfecto cuando es igual a la suma de sus divisores positivos menores que él.
------------------------------------------------------------------------------------------------------------
Resolucion: dos ciclos en los que el primero itera desde del 1 hasta el 8000, el segundo verifica la
condicion de numero perfecto. Como la condicion dice suma de divisores (i%j==0) positivos MENORES (j<i),
unicamente se deberan acumular dicha suma de estos. Si la suma de sus divisores es igual a este numero
quiere decir que es un numero perfecto, por lo tanto se muestra por pantalla. Para el siguiente numero
se debera 'limpiar' la variable sumadora, por lo tanto se inicializa antes de comenzar la siguiente
iteracion. La variable i representa el numero y j sus divisores*/

#include<stdio.h>

int main()
{
    int i,j,suma=0;
    printf("\nNumeros perfectos: ");
    for(i=1;i<=8000;i++)
    {
        for(j=1;j<=8000;j++)
            if(j<i && i%j==0)
                suma+=j;
                if(suma==i)
                    printf("\n%d",i);
        suma=0;
    }
    printf("\n");
    return 0;
}
