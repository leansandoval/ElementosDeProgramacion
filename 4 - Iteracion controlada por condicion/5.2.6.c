/*5.2.6 Un negocio de perfumería efectúa descuentos en sus ventas según el importe de las mismas, con la
siguiente escala:

    • menor a 50 pesos el 3.5 %
    • entre 50 y 150 pesos el 10 %
    • entre 151 y 300 pesos el 20 %.
    • mayor a 300 pesos el 25 %

Confeccionar un programa que:

    a. Solicite un importe y calcule el descuento a efectuar y el importe neto a cobrar, con mensajes
    aclaratorios.
    b. Informe el importe promedio de todas las ventas realizadas.

Se debe contemplar que se puedan ingresar varios importes y para finalizar se ingresa un valor negativo o
cero.
-----------------------------------------------------------------------------------------------------------
Resolucion: se ingresa la variable de importes y dentro del ciclo while se encuentran las condiciones de
los descuentos dependiendo del importe que se ingreso, en ese mismo if se muestra por pantalla los mensajes
Antes de ingresar un nuevo importe de debe acumular las ventas e incrementar la cantidad de ventas que hubo.
*/

#include<stdio.h>

int main()
{
    int cantidadVentas=0;
    float importe,descuento,neto,totalImportes=0;
    printf("\nIngrese importe (Negativo o cero para terminar): ");
    scanf("%f",&importe);
    while(importe>0)
    {
        if(importe<=50)
        {
            descuento=importe*0.035;
            neto=importe-descuento;
            printf("\nImporte: $%.2f\tDescuento a efectuar: $%.2f\tImporte neto: $%.2f\n",importe,descuento,neto);
        }
        else if(importe<=150)
        {
            descuento=importe*0.1;
            neto=importe-descuento;
            printf("\nImporte: $%.2f\tDescuento a efectuar: $%.2f\tImporte neto: $%.2f\n",importe,descuento,neto);
        }
        else if(importe<=300)
        {
            descuento=importe*0.2;
            neto=importe-descuento;
            printf("\nImporte: $%.2f\tDescuento a efectuar: $%.2f\tImporte neto: $%.2f\n",importe,descuento,neto);
        }
        else
        {
            descuento=importe*0.25;
            neto=importe-descuento;
            printf("\nImporte: $%.2f\tDescuento a efectuar: $%.2f\tImporte neto: $%.2f\n",importe,descuento,neto);
        }
        totalImportes+=neto;
        cantidadVentas++;
        printf("\nIngrese importe (Negativo o cero para terminar): ");
        scanf("%f",&importe);
    }
    if(cantidadVentas!=0)
        printf("\nPromedio de ventas: %.2f\n",(float)totalImportes/cantidadVentas);
    else
        printf("\nNinguna venta ingresada\n");
    return 0;
}
