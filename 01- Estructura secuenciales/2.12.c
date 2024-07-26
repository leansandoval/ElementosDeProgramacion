/*2.12. Una farmacia vende algunos artículos sin descuento y a otros con descuento del 20%. Confeccionar un
programa que recibiendo el precio original y un código que indica si es o no con descuento, informe el
precio final (0 no aplica el descuento y 1 aplica el descuento).
------------------------------------------------------------------------------------------------------------
Resolucion: Se ingrega por teclado un precio (tipo float) y luego ingreso el codigo (como los unicos
posibles valores son 1 y 0) el codigo sera de tipo int.
Para el precio total se debera restar el descuento, en el caso que sera 0, estaria haciendo precio - 0
por lo que queda el precio como viene. Para el caso en el que el codigo sea 1, lo multiplico por el 20%;
quedando asi precio - 1*20%.
*/

#include <stdio.h>
#include <conio.h>
int main()
{
    float precio,precio_total;
    int codigo;
    printf("\nIngrese el precio del articulo: ");
    scanf("%f",&precio);
    printf("\nIngrese el codigo (0 para NO aplicar descuento o 1 para aplicar descuento): ");
    scanf("%d",&codigo);
    precio_total=precio-(codigo*(precio*0.2));
    printf("\nEl precio total es: %.2f\n",precio_total);
    return 0;
    getch();
}
