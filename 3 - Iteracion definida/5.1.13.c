/*5.1.13 Realizar un programa que:
a. Muestre todos los números primos entre 1 y 100. (Un nro. es primo cuando es divisible solamente
por 1 y por sí mismo)
b. Contar y mostrar la cantidad de primos encontrados.
------------------------------------------------------------------------------------------------------
Resolucion: se deberan realizar 2 ciclos for, el primero es para contar desde el 1 hasta el 100 (por
convencion se lo pone a partir del 2, ya que el uno no es primo) y el segundo for anidado es para
saber por que numero es divisible. Dentro de este for hay una condicion if, que indica la condiciones
de un numero primo. Si es unicamente divisible por 1 y por si mismo, se incrementara una variable
bandera. Si posee como valor 1 quiere decir que ese numero es primo, por lo tanto se lo imprime y se
incrementa la variable contadora de la cantidad de primos.*/

#include<stdio.h>

int main()
{
    int i,j,posiblePrimo=0,cantidadPrimos=0;
    printf("\nNumeros primos: ");
    for(i=2; i<=100; i++)
    {
        for(j=2; j<=i; j++)
            if(i%j==0 && i%1==0)
                posiblePrimo++;
        if(posiblePrimo==1)
        {
            printf("\n%d",i);
            cantidadPrimos++;
        }
        posiblePrimo=0;
    }
    printf("\n\nCantidad de numeros primos: %d\n",cantidadPrimos);
    return 0;
}
