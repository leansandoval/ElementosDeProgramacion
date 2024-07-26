/*5.1.10 Confeccionar un programa que solicite el ingreso de un valor entero N < 12 y luego una lista de N números
reales sobre la cual debe calcular:
a. el promedio de los positivos.
b. el promedio de los negativos.
c. la cantidad de ceros.
Si el valor ingresado N es mayor que 12 informar 'VALOR EXCEDIDO” y si es menor o igual a 0 informar
“CANTIDAD INVALIDA”.
------------------------------------------------------------------------------------------------------------------
Resolucion: en primer lugar se colocan las condiciones del valor entero ingresado N, las demas condiciones
comenzaran unicamente cuando el  valor ingresado este entre 1 y 12. Si es menor o igual a 0 mostrar por pantalla
el mensaje y si es mayor a 12 su respectivo mensaje. Para los valores dentro de 1 y 12 empezara el ciclo for en
donde se ingresaran los numeros hasta la cantidad ingresada anteriormente. Si el numero es 0, incrementar la
variable contadora (else del primer if) si el numero es menor a 0, acumular y contar los que se ingresen, idem
para valores positivos.
Una vez terminado el ciclo for se muetra el promedio (casteado) y la cantidad de ceros.*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int valor,i,cantidadPositivos=0,cantidadNegativos=0,cantidadCeros=0;
    float numero,sumaNegativos=0,sumaPositivos=0;
    printf("\nIngrese un valor entero: ");
    scanf("%d",&valor);
    if(valor>0 && valor<=12)
    {
        for(i=1; i<=valor; i++)
        {
            printf("\nIngrese un numero: ");
            scanf("%f",&numero);
            if(numero!=0)
            {
                if(numero<0)
                {
                    sumaNegativos+=numero;
                    cantidadNegativos++;
                }
                else
                {
                    sumaPositivos+=numero;
                    cantidadPositivos++;
                }
            }
            else
                cantidadCeros++;
        }
        printf("\nPromedio de numeros positivos: %.2f\n",(float)sumaPositivos/cantidadPositivos);
        printf("\nPromedio de numeros negativos: %.2f\n",(float)sumaNegativos/cantidadNegativos);
        printf("\nCantidad de ceros: %d\n",cantidadCeros);
    }
    else if(valor>12)
        printf("\nVALOR EXCEDIDO\n");
    else
        printf("\nCANTIDAD INVALIDA\n");
    return 0;
}
