/*5.1.21 Tomando como base el ejercicio anterior ingresar un número entero mayor a 0 y dibujar un rombo con
*. Por ejemplo, si se ingresa el número 5 dibuja la pirámide de 5 filas y luego completa el rombo al ir
decrementando la cantidad de asteriscos.
                                                    *
                                                    ***
                                                    *****
                                                    *******
                                                    *********
                                                    *******
                                                    *****
                                                    ***
                                                    *
*/

#include<stdio.h>

int main()
{
    int numero,i,j,k;
    printf("\nIngrese un numero entero mayor a 0: ");   // n = NUMERO DE FILAS TOTALES
    scanf("%d",&numero);
    if(numero>0)
    {
        for(i=1; i<=numero-1; i++)                      // POSICION DE LAS FILAS (n-1 porque en el otro for se va a incluir la fila que comparte los 2 triangulos)
        {
            for(j=numero; j>=i; j--)                    // ESPACIOS EN BLANCO
                printf(" ");
            for(k=1; k<=i*2-1; k++)                     // CANTIDAD DE ASTERISCOS (i*2-1 condicion de relacion entre la posicion de la fila)
                printf("*");
            printf("\n");
        }
        for(i=1; i<=numero; i++)
        {
            for(j=1; j<=i; j++)
                printf(" ");
            for(k=numero*2-1; k>=i*2-1; k--)            // n*2-1 TOTAL DE FILAS QUE COMPONE EL TRIANGULO
                printf("*");
            printf("\n");
        }
    }
    else
        printf("\nNumero incorrecto\n");
    return 0;
}
