/*5.1.18 Realizar un programa que muestre por pantalla las tablas de multiplicar del 1 al 9 de la siguiente forma:
                                            1   2   3   4   5   6   7   8   9
                                            2   4   6   8   10  12  14  16  18
                                            3   6   9   12  15  18  21  24  27
                                            4   8   12  16  20  24  28  32  36
                                            5   10  15  20  25  30  35  40  45
                                            6   12  18  24  30  36  42  48  54
                                            7   14  21  28  35  42  49  56  63
                                            8   16  24  32  40  48  56  64  72
                                            9   18  27  36  45  54  63  72  81
--------------------------------------------------------------------------------------------------------------------
Resolucion: para cada tabla se debera realizar un ciclo for y dentro de ese ir imprimiento por pantalla cada numero.
Observar los \t y los \n para que quede esteticamente de la forma.*/

#include<stdio.h>

int main()
{
    int i,numero;
    printf("\n\t\t\tTablas de multiplicar del 1 al 9\n\n");
    for(i=1; i<=9; i++)
    {
        numero=1*i;
        printf("\t%d",numero);
    }
    printf("\n");
    for(i=1; i<=9; i++)
    {
        numero=2*i;
        printf("\t%d",numero);
    }
    printf("\n");

    for(i=1; i<=9; i++)
    {
        numero=3*i;
        printf("\t%d",numero);
    }
    printf("\n");
    for(i=1; i<=9; i++)
    {
        numero=4*i;
        printf("\t%d",numero);
    }
    printf("\n");
    for(i=1; i<=9; i++)
    {
        numero=5*i;
        printf("\t%d",numero);
    }
    printf("\n");
    for(i=1; i<=9; i++)
    {
        numero=6*i;
        printf("\t%d",numero);
    }
    printf("\n");
    for(i=1; i<=9; i++)
    {
        numero=7*i;
        printf("\t%d",numero);
    }
    printf("\n");
    for(i=1; i<=9; i++)
    {
        numero=8*i;
        printf("\t%d",numero);
    }
    printf("\n");
    for(i=1; i<=9; i++)
    {
        numero=9*i;
        printf("\t%d",numero);
    }
    printf("\n");
    return 0;
}
