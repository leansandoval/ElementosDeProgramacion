/*4.7. Confeccionar un programa que solicite e ingrese 3 valores reales positivos, mayores que cero y determine
e informe si forman o no triángulo. Para ello utilizar el teorema de la desigualdad del triángulo que establece
que la suma de las longitudes de cualesquiera de dos lados de un triángulo es mayor que la longitud del
tercer lado
---------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<conio.h>

int main()
{
    float lado1,lado2,lado3;
    printf("\nIngrese tres valores reales positivos\n");
    printf("\nPrimera longitud: ");
    scanf("%f",&lado1);
    printf("\nSegunda longitud: ");
    scanf("%f",&lado2);
    printf("\nTercera longitud: ");
    scanf("%f",&lado3);
    if(lado1>0 && lado2>0 && lado3>0)
        if(lado1+lado2>lado3)
            printf("\nLos tres numeros ingresados pueden forman un triangulo\n");
        else
            if(lado1+lado3>lado2)
                printf("\nLos tres numeros ingresados pueden forman un triangulo\n");
            else
                if(lado2+lado3>lado1)
                    printf("\nLos tres numeros ingresados pueden forman un triangulo\n");
                else
                    printf("\nLos datos ingresados NO PUEDEN formar un triangulo\n");
    else
        printf("\nLos datos ingresados NO PUEDEN formar un triangulo\n");
}
