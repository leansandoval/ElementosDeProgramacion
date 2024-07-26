/*2.4. Confeccionar un programa que ingrese una medida en 'pies' y la exhiba convertida a yardas, pulgadas, centimetros y metros.
NOTA: 1 pie=12 pulgadas, 1 yarda=3 pies, 1 pulgada=2,54cms.
---------------------------------------------------------------------------------------------------------------------------------
Resolucion: Asumo que todas las variables son de tipo float, por lo que solo hay que hacer regla de 3.
*/

#include <stdio.h>
int main()
{
    float pies,yar,pul,cm,mts;
    printf("Ingrese medida en 'pies': ");
    scanf("%f",&pies);
    pul=pies*12;
    yar=pies/3;
    cm=pul*2.54;
    mts=cm/100;
    printf("\nLas conversiones de la medida son:\n");
    printf("\nPulgadas: %.0f\n",pul);
    printf("\nYarda: %.1f\n",yar);
    printf("\nCentimetros: %.2f\n",cm);
    printf("\nMetros: %.4f\n",mts);
}
