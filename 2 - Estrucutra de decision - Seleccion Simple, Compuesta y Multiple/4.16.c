/*4.16. Un negocio vende distintos artículos identificados por un código, según se muestra:
• código 1; 10; 100: 10 pesos la unidad.
• código 2; 22; 222: 7 pesos la unidad. La caja de 10 unidades vale 65 pesos.
• código 3; 33: 3 pesos la unidad. Si la compra es por más de 10 unidades se hace un descuento del
10% sobre el total de la compra.
• código 4; 44: 1 peso la unidad.
Confeccionar un programa que ingrese como dato el código de un artículo y la cantidad a comprar y se
informe el importe de la compra, con las siguientes leyendas:

                        ARTÍCULO xxxxx  CANTIDAD xxxx   IMPORTE A PAGAR $ xxxx.xx
-----------------------------------------------------------------------------------------------------
Resolucion: como se muestran distintas condiciones para distintos codigos, voy a realizar un switch
para este programa. Declaro una variable int llamada codigo y otra para ingresar la cantidad a
comprar (tambien int). En el switch voy a definir los case:
Si codigo = 1, 10 o 100 --> Cantidad * $10
Si codigo = 2, 22 o 222 --> Cantidad * $7
Si codigo = 3, 33       --> Cantidad * $3
Si codigo = 4, 44       --> Cantidad * $1
Ahora centremonos en las condiciones de los codigos 2,22,222 y 3,33:
Si se vende una caja (10 unidades) --> $65 la caja.
Ejemplo: compro una caja y 2 unidades, que es lo mismo decir que en total tendre 12 unidades pero el
precio sera $65 + $7*2 = $79.
Divido por las 10 unidades que trae la/s caja/s y lo que queda de resto son las unidades restantes.
Ahora, para el los otros codigos (3,33) es simplemente aplicar un descuento sobre el total de la compra
si cantidad > 10 unidades. Por lo que primero habra que multiplicarlo por lo que vale cada unidad y a ese
resultado aplicarle el descuento.
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

int main()
{
    int cantidad,codigo,band=0;
    float total;
    printf("\nIngrese la cantidad de articulos a comprar: ");
    scanf("%d",&cantidad);
    printf("\nIngrese el codigo correspondiente: ");
    scanf("%d",&codigo);
    switch(codigo)
    {
    case 1: case 10: case 100:
        total=cantidad*10;break;
    case 2: case 22: case 222:
        {if(cantidad>=10)
            total=(cantidad/10*65)+(cantidad%10*7);
        else
            total=cantidad*7;
        }break;
    case 3: case 33:
        {if(cantidad>10)
            total=cantidad*3-(cantidad*3*0.1);
        else
            total=cantidad*3;
        }break;
    case 4: case 44:
        total=cantidad*1;break;
    default:band=1;
    }
    if(band==0)
        printf("\nARTICULO  %d\tCANTIDAD    %d\tIMPORTE A PAGAR $%.2f\n",codigo,cantidad,total);
    else
        printf("\nEl codigo ingresado es erroneo\n");
    getch();
    return 0;
}
