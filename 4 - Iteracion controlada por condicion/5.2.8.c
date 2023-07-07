/*5.2.8 Confeccionar un programa que me permita calcular y mostrar una cantidad de números primos que se
solicita por la pantalla. Los números se calculan a partir del 2. Ejemplo: Si ingreso 6 genero los números: 5 - 7
- 11 - 13 - 17 – 19. El algoritmo para el cálculo de si un número es primo o no, debe estar optimizado para que
si encuentra un divisor no seguir buscando ya que se sabe que no es primo.
-----------------------------------------------------------------------------------------------------------------
Resolucion: en primer lugar, se ingresa la cantidad de numero primos que se van a mostrar por pantalla, luego
con una variable contadora llamada cantidadPrimos verifica que llegue al tope que se ingreso en un primer momento.
Como los primos se calculan a partir del 2 los posibles divisores su respectiva variable empezara inicializada en
este numero. El while anidado indica el tope de numeros divisibles por el posiblePrimo. Por lo tanto si es mayor,
ya no seguira buscando (algoritmo optimizado). Si como resto da 0, no es primo ya que tendra muchos mas divisores,
caso contrario se debera incrementar los posibles divisores para seguir dividiendo en la siguiente pasada. Para
este caso esPrimo seguira en verdadero, y por lo tanto quiere decir que unicamente si divisible consigo mismo y
entra en el if del primer while para imprimirlo.*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int cantidadPrimos=0,posibleDivisor,aVisualizar,posiblePrimo=2;
    bool esPrimo;
    printf("\nIngrese la cantidad de numeros primos a visualizar: ");
    scanf("%d",&aVisualizar);
    printf("\n");
    while(cantidadPrimos<aVisualizar)
    {
        esPrimo=true;
        posibleDivisor=2;
        while(esPrimo && posibleDivisor<posiblePrimo)
        {
            if(posiblePrimo%posibleDivisor==0)
                esPrimo=false;
            else
                posibleDivisor++;
        }
        if(esPrimo)                         // Entra en este if si el numero es primo
        {
            printf("\t%d",posiblePrimo);    // Lo imprime
            cantidadPrimos++;               // Y ademas incrementa el contador de primos
        }
        posiblePrimo++;                     // Terminado el ciclo while posible primo debe incrementarse, inicialmente en 2
    }
    printf("\n");
    return 0;
}
