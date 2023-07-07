/*5.2.1 Confeccionar un programa que calcule e informe los valores de las potencias de 2 cuyo resultado sean
menores que 600. (1 2 4 8 16 …)
-------------------------------------------------------------------------------------------------------------
Resolucion: la condicion del ciclo while debera se la del enunciado, hasta que las potencias de 2 sean
menores a 600. Dentro del ciclo se imprime el numero y ademas para el siguiente se debera multiplicar por 2
el numero impreso.
*/

#include<stdio.h>

int main()
{
    int potenciaDe2=1;
    printf("\nValores de las potencias de 2 menores a 600\n");
    while(potenciaDe2<600)
    {
        printf("\n%d",potenciaDe2);
        potenciaDe2=potenciaDe2*2;
    }
    printf("\n");
    return 0;
}
