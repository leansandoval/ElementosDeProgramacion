/*2.13. Confeccionar un programa que solicite el ingreso de un número entero positivo de 4 cifras y
pueda calcular e informar la suma de sus dígitos hasta llegar a una sola cifra.
Ej:2561 --> 5
2+5+6+1 = 14 --> 1+4 = 5
----------------------------------------------------------------------------------------------------
Resolucion: Se descompone el numero tanto en unidades de mil, centena, decena y unidad. Luego, esos
numeros descompuestos se suman. Suponiento que el numero maximo que se puede formar sea 9999
9+9+9+9 = 36 --> 3+6 = 9. La primera suma dara un resultado (como mucho) de dos cifras.
Por lo que tendra unicamente unidad y decena. Se descompone nuevamente y se los vuelve a sumar a ambas.
*/

#include <stdio.h>
int main ()
{
    int numero,unidad_de_mil,centena,decena,unidad,primera_suma,decena2,unidad2,segunda_suma;
    printf("\nIngrese un numero entero de 4 cifras: ");
    scanf("%d",&numero);
    unidad_de_mil=numero/1000;
    centena=(numero%1000)/100;
    decena=((numero%1000)%100)/10;
    unidad=((numero%1000)%100)%10;
    primera_suma=unidad_de_mil+centena+decena+unidad;
    decena2=primera_suma/10;
    unidad2=primera_suma%10;
    segunda_suma=decena2+unidad2;
    printf("\nLa suma de los digitos del numero %d hasta llegar a una sola cifra es: %d",numero,segunda_suma);
}
