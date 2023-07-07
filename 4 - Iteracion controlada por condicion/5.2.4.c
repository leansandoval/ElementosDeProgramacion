/*5.2.4 Un negocio de venta de granos desea controlar las ventas realizadas. De cada una ingresa el importe total
y un código que indica la forma de pago. El código puede ser:

    • C: cheque, 20% de recargo.
    • E: efectivo, 10% de descuento.
    • T: con tarjeta, 12% de recargo.

Se debe ingresar una F para finalizar el día de venta y arrojar los siguientes totales.

                                Efectivo en Caja:               $ xxxx.xx
                                Ventas con Tarjeta de Crédito:  $ xxxx.xx
                                Ventas con cheque:              $ xxxx.xx
                                Total de Venta:                 $ xxxx.xx
                                Importe del IVA:                $ xxxx.xx

Nota: El IVA corresponde al 21% del total de ventas.
------------------------------------------------------------------------------------------------------------------------
Resolucion: se valida el ingresa unicamente los ingresos de char que sea 'C', 'E', 'T' y 'F' con un do while, fijarse
que dentro de la condicion del while hay una funcion llamada toupper: lo que hace es tranformar la letra de minuscula,
a mayuscula, esto es por si el usuario ingresa 'c', 'e', 't' o 'f'. Dentro del ciclo while, se pide el importe del
articulo y luego dependiendo el codigo que se haya ingresado anteriormente, este tendra un recargo o un descuente. Para
ello, se utiliza un switch y entra a los casos sea cual sea el codigo. Con variables acumuladoras/sumadoras, se guardan
los resultados de las ventas y al finalizar el ciclo se muestran por pantalla.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    float importe,importeTotalCheque=0,importeTotalEfectivo=0,importeTotalTarjeta=0,recargoCheque,descuentoEfectivo,recargoTarjeta;
    char codigo;
    int bandera=0;
    do
    {
        if(bandera==1)
            printf("\nEl codigo ingresado no es correcto, ingrese nuevamente\n");
        bandera=1;
        printf("\nIngrese codigo correspondiente (C: cheque - E: efectivo - T: tarjeta - F: finalizar): ");
        fflush(stdin);
        scanf("%c",&codigo);
        codigo=toupper(codigo);     // Por si se ingresa algun caracter en minuscula
    }
    while(!(codigo=='C' || codigo=='E' || codigo=='T' || codigo=='F'));
    while(codigo!='F')
    {
        printf("\nIngrese importe del articulo: ");
        scanf("%f",&importe);
        switch(codigo)
        {
        case 'C':
            recargoCheque=importe+(importe*0.2);
            break;
        case 'E':
            descuentoEfectivo=importe-(importe*0.1);
            break;
        case 'T':
            recargoTarjeta=importe+(importe*0.12);
            break;
        }
        importeTotalCheque+=recargoCheque;
        importeTotalEfectivo+=descuentoEfectivo;
        importeTotalTarjeta+=recargoTarjeta;
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl codigo ingresado no es correcto, ingrese nuevamente\n");
            bandera=1;
            printf("\nIngrese codigo correspondiente (C: cheque - E: efectivo - T: tarjeta - F: finalizar): ");
            fflush(stdin);
            scanf("%c",&codigo);
            codigo=toupper(codigo);
        }
        while(!(codigo=='C' || codigo=='E' || codigo=='T' || codigo=='F'));
    }
    printf("\nEfectivo en Caja:                 $%.2f\n",importeTotalEfectivo);
    printf("\nVentas con Tarjeta de Credito:    $%.2f\n",importeTotalTarjeta);
    printf("\nVentas con Cheque:                $%.2f\n",importeTotalCheque);
    printf("\nTotal de Venta:                   $%.2f\n",importeTotalCheque+importeTotalEfectivo+importeTotalTarjeta);
    printf("\nImporte de IVA:                   $%.2f\n",(importeTotalCheque+importeTotalEfectivo+importeTotalTarjeta)*0.21);
    return 0;
}
