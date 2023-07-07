/*5.1.12 Calcular el factorial de un número ingresado por teclado. El factorial se calcula como el producto de todos
los enteros positivos desde 1 hasta el número. En matemática el factorial se expresa con el símbolo !. Por
ejemplo, el factorial de 5 es 120 ya que 5! = 1 x 2 x 3 x 4 x 5 =120
----------------------------------------------------------------------------------------------------------------------
Resolucion: para realizar el factorial de un numero se realiza un ciclo for desde 1 hasta el numero que se debe
calcular su factorial. Dentro del for lo unico que hay que hacer es, utilizando una variable acumuladora, ir
multiplicando las iteraciones de uno en uno.
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,numero,factorial=1;
    printf("\nIngrese el numero: ");
    scanf("%d",&numero);
    for(i=1;i<=numero;i++)
        factorial*=i;                   // Equivalente a factorial=factorial*i
    printf("\nEl factorial de %d es: %d\n",numero,factorial);
    return 0;
}
