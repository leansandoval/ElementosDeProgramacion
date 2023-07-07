/*5.1.20 Ingresar un numero entero mayor a 0. Debe dibujar una piramide con * con tantas filas como el numero
indicado. En cada fila se va incrementando la cantidad de asteriscos de 2 en 2.
Por ejemplo, si se ingresa el numero 5 debe mostrar en pantalla:
                                                        *
                                                       ***
                                                      *****
                                                     *******
                                                    *********
*/

#include<stdio.h>

int main()
{
    int numero,i,j,k;
    printf("\nIngrese un numero entero mayor a 0: ");
    scanf("%d",&numero);
    if(numero)
        for(i=1; i<=numero; i++)        // POSICION DE LAS FILAS
        {
            for(j=numero; j>=i; j--)    // ESPACIOS EN BLANCO
                printf(" ");
            for(k=1; k<=i*2-1; k++)     // CANTIDAD DE COLUMNAS (i*2-1 condicion de relacion entre la posicion de la fila)
                printf("*");
            printf("\n");
        }
    else
        printf("\nNumero incorrecto\n");
    return 0;
}
