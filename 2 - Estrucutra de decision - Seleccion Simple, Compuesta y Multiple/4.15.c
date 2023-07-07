/*4.15. Un negocio de artículos de computación vende DVDs según la siguiente escala de precios:
• sueltos, entre 1 y 9 a $15 c/u.
• la caja de 10 cuesta $120.
• la caja de 50 cuesta $500.
Si la compra excede las 100 unidades se efectúa un descuento del 10%.
NOTA: se aceptan compras entre 1 y 500 DVDs.
Se pide que se ingrese una cantidad de DVDs que se quiere comprar y calcule e informe el importe a pagar.
------------------------------------------------------------------------------------------------------------
Resolucion: se ingresan la cantidad de DVDs que se quiere comprar (variable tipo int). En primer lugar, la
nota dice que se aceptan compras entre 1 y 500 DVDs, por lo que esta sera nuestra primera condicion para
continuar con el programa o no.
Ademas declaramos las variables que contienen los distintos precios: sueltos (entre 1 y 9) a $15 c/u,
caja_de_10 a $120 c/u y caja_de_50 a $500 c/u.
Si la compra es mayor a 100 unidades, quiere decir que hay al menos 2 o mas cajas de 50. Asi que para saber
cuantas cajas son aplicamos dvd / 50 y a esa cantidad la multiplicamos por $500. Lo mismo para las cajas de
10.
Si la compra es mayor a 50 unidades, quiere decir que hay al menos una caja de 50; asi que aplicamos la
misma logica.

*/

#include<stdio.h>
#include<conio.h>

int main()
{
    int dvd;
    float caja_de_50,caja_de_10,sueltos,total_sin_descuento,total;
    printf("\nIngrese la cantidad de DVDs a comprar: ");
    scanf("%d",&dvd);
    if(dvd>=1 && dvd<=500)
        if(dvd>=100)
        {
            caja_de_50=(dvd/50)*500;
            caja_de_10=((dvd%50)/10)*120;
            sueltos=((dvd%50)%10)*15;
            total_sin_descuento=caja_de_50+caja_de_10+sueltos;
            total=total_sin_descuento-(total_sin_descuento*0.1);
            printf("\nEl importe es de %.2f\n",total);
        }
        else
            if(dvd>=50)
            {
                caja_de_50=(dvd/50)*500;
                caja_de_10=((dvd%50)/10)*120;
                sueltos=((dvd%50)%10)*15;
                total=caja_de_50+caja_de_10+sueltos;
                printf("\nEl importe es de %.2f\n",total);
            }
            else
                if(dvd>=10)
                {
                    total=(dvd/10)*120+(dvd%10)*15;
                    printf("\nEl importe es de %.2f\n",total);
                }
                else
                {
                    total=dvd*15;
                    printf("\nEl importe es de %.2f\n",total);
                }
    else
        printf("\nNo se puede realizar la compra\n");
    getch();
    return 0;
}
