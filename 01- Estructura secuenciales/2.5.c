/*2.5. Conociendo la cantidad de tarros de pintura que existe en un depósito de una pinturería y sabiendo que el
50% son tarros de 1Lt, el 30% tarros de 4Lts. y el resto tarros de 20Lts. Determinar la cantidad de tarros de
1Lt., 4Lts. Y 20 Lts.
----------------------------------------------------------------------------------------------------------------
Resolucion: Se ingresa la cantidad de tarros por teclado, defino una variable entera. Para saber el porcentaje de los
tarros que poseen X cantidad de litros es solo multiplicarlo por el porcentaje que dice el enunciado.
Como la mitad es de 1Lt y el 30% de 4Lts, el resto sera del 100%-50%-30%=20%.
*/

#include <stdio.h>
int main ()
{
    int tarros,t1,t4,t20;
    printf("\nIngrese la cantidad de tarros en total:");
    scanf("%d",&tarros);
    t1=tarros*0.5;
    t4=tarros*0.3;
    t20=tarros*0.2;
    printf("\nDe los %d tarros: %d son de 1L, %d son de 4L, y %d son de 20L",tarros,t1,t4,t20);
    return 0;
}
