#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int main()
{
    int cat;
    printf("Ingrese el numero de catalogo: ");
    scanf("%d",&cat);
    if(cat>=1200 && cat<=90000)
        if(cat>=12121&&cat<=18081)
            printf("\nArticulo defectuoso");
        else
            if(cat>=30012&&cat<=45565)
                printf("\nArticulo defectuoso");
            else
                if(cat>=67000&&cat<=68000)
                    printf("\nArticulo defectuoso");
                else
                     printf("\nArticulo NO defectuoso");
    else
        printf("\nFUERA DE RANGO");
    printf("\n\n");

}
