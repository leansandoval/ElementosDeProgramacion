/*2.7. Se ingresa un número entero de 3 cifras. Descomponerlo en unidad, decena y centena.
------------------------------------------------------------------------------------------
Resolucion: para descomponer el numero en unidad, decena y centena vamos a tener que
dividir dicho numero por 100, el cociente nos dara la centena por lo que usamos el
operandor /
Para la decena debemos sacar el resto de la division, usamos el operador % y luego
dividimos por 10.
Idem para la unidad, pero en vez de dividir, vamos a utilizar nuevamente % para conocer el
resto.
*/

#include <stdio.h>
int main()
{
    int numero,centena,decena,unidad;
    printf("\nIngrese un numero de tres cifras: ");
    scanf("%d",&numero);
    centena=numero/100;
    decena=(numero%100)/10;
    unidad=(numero%100)%10;
    printf("\nCentena:%d\n",centena);
    printf("\nDecena:%d\n",decena);
    printf("\nUnidad:%d\n",unidad);
    return 0;
}
