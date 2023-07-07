/*2.11. Una pizzería vende empanadas por unidad o por docena, la docena cuesta $300 pero si se compra
individualmente se cobra $30 la unidad. Si se compran más empanadas que no se agrupen en docenas las
adicionales se cobran como por unidad. Indicar el precio total a abonar.
-----------------------------------------------------------------------------------------------------
Resolucion: Se ingresan por teclado la cantidad tanto de docenas vendidas como de unidades vendidas,
luego las docenas se las multiplica por $300 y la cantidad de unidades vendidas por $30. Para sacar
el precio total se suma ambos resultados.
*/

#include <stdio.h>
int main ()
{
    int docena,unidad,total_docena,total_unidad,total;
    printf("\nIngrese las docenas vendidas: ");
    scanf("%d",&docena);
    printf("\nIngrese las unidades vendidas: ");
    scanf("%d",&unidad);
    total_docena=docena*300;
    total_unidad=unidad*30;
    total=total_docena+total_unidad;
    printf("\nEl precio total es: %d\n",total);
    return 0;
}
