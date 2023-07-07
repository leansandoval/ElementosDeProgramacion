/*4.14. La farmacia Sindical efectúa descuentos a sus afiliados según el importe de la compra con la siguiente
escala:
a. menor de $55 el descuento es del 4.5%
b. entre $55 y $100 el descuento es del 8%
c. más de $100 el descuento es del 10.5%
Confeccionar un programa que reciba un importe e informe: el descuento y el precio neto a cobrar, con
mensajes aclaratorios.
-------------------------------------------------------------------------------------------------------------------------
Resolucion: Se ingresar el importe de la compra (tipo float) y luego dependiendo del precio, se realizar cierto descuento.
Si        precio < $55  --> Descuento del 4.5%
Si  $55 < precio < $100 --> Descuento del 8%
Si        precio > $100 --> Descuento del 10.5%
Por lo que se procede a encadenar (en este caso) 2 if's para aplicar las 3 condiciones. Luego con un simple printf se
muestra por pantalla el descuento y el precio neto (que serie el precion aplicado ya el descuento).
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    float precio;
    printf("\nIngrese precio del articulo: ");
    scanf("%f",&precio);
    if(precio>=55 && precio<=100)
        printf("\nSe hizo un descuento del 8 porciento por lo que el precio neto es de %.2f\n",precio-(0.08*precio));
    else
        if(precio>100)
            printf("\nSe hizo un descuento del 10.5 porciento por lo que el precio neto es de %.2f\n",precio-(0.105*precio));
        else
            printf("\nSe hizo un descuento del 4.5 porciento por lo que el precio neto es de %.2f\n",precio-(0.045*precio));
    getch();
    return 0;
}
