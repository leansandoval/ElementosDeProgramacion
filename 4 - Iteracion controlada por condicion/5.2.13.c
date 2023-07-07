/*5.2.13 Realizar un programa que le solicite al usuario el ingreso de una vocal (este dato de ingreso se debe
validar). Luego el programa debe dibujar en pantalla la vocal ingresada en cinco filas y cuatro columnas. La
vocal debe estar formada en cada carácter por la misma letra en mayúscula.
El programa finaliza al ingresar la letra f.
Restricciones: Por cada printf se debe exhibir un solo carácter o salto de línea o espacio.
Ejemplos:

Ingreso del carácter a:
    AAAA
    A  A
    AAAA
    A  A
    A  A

Ingreso del carácter e:
    EEEE
    E
    EEEE
    E
    EEEE

Extender el programa para que la vocal se exhiba más grande ingresando un factor de multiplicación.
Por ejemplo si se ingresa un 2 debe dibujarse el doble de grande la letra en pantalla.*/

#include <stdio.h>
#include <ctype.h>
#define FILA 5
#define COLUMNA 4

int main()
{
    int i,j,bandera=0,tamanio;
    char letra;
    do
    {
        if(bandera==1)
            printf("\nEl caracter ingresado no es una vocal, ingrese nuevamente.\n");
        bandera=1;
        printf("\nIngrese una vocal (f para teminar): ");
        fflush(stdin);
        scanf("%c",&letra);
        letra=tolower(letra);
    }
    while(letra!='a' && letra!='e' && letra!='i' && letra!='o' && letra!='u' && letra!='f');
    if(letra!='f')
    {
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nDato invalido, ingrese nuevamente.\n");
            bandera=1;
            printf("\nInicialmente la letra se mostrara en 5 filas y 4 columnas (tamanio=1), si desea multiplicar su tamanio, ingrese un valor mayor: ");
            scanf("%d",&tamanio);
        }
        while(tamanio<=0);
    }
    while(letra!='f')
    {
        switch(letra)
        {
        case 'a':
            printf("\n");
            for(i=0; i<FILA*tamanio; i++)
            {
                for(j=0; j<COLUMNA*tamanio; j++)
                    if((i==0 || i==(FILA*tamanio/2)) || j==0 || (j==COLUMNA*tamanio-1))
                        printf("%c",toupper(letra));
                    else
                        printf(" ");
                printf("\n");

            }
            break;
        case 'e':
            printf("\n");
            for(i=0; i<FILA*tamanio; i++)
            {
                for(j=0; j<COLUMNA*tamanio; j++)
                    if((i==0 || i==(FILA*tamanio/2) || i==(FILA*tamanio-1)) || j==0)
                        printf("%c",toupper(letra));
                    else
                        printf(" ");
                printf("\n");
            }
            break;
        case 'i':
            printf("\n");
            for(i=0; i<FILA*tamanio; i++)
            {
                for(j=0; j<COLUMNA*tamanio; j++)
                    if((j==COLUMNA*tamanio/2) ||
                       (i==0 && (j==(COLUMNA*tamanio/2)-1 || j==(COLUMNA*tamanio/2)+1)) ||
                       (i==FILA*tamanio-1 && (j==(COLUMNA*tamanio/2)-1 || j==(COLUMNA*tamanio/2)+1)))
                        printf("%c",toupper(letra));
                    else
                        printf(" ");
                printf("\n");
            }
            break;
        case 'o':
            printf("\n");
            for(i=0; i<FILA*tamanio; i++)
            {
                for(j=0; j<COLUMNA*tamanio; j++)
                    if((j==0 || j==COLUMNA*tamanio-1) || (i==0 || i==FILA*tamanio-1))
                        printf("%c",toupper(letra));
                    else
                        printf(" ");
                printf("\n");
            }
            break;
        case 'u':
            printf("\n");
            for(i=0; i<FILA*tamanio; i++)
            {
                for(j=0; j<COLUMNA*tamanio; j++)
                    if((j==0 || j==COLUMNA*tamanio-1) || i==FILA*tamanio-1)
                        printf("%c",toupper(letra));
                    else
                        printf(" ");
                printf("\n");
            }
            break;
        }
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl caracter ingresado no es una vocal, ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese una vocal (f para teminar): ");
            fflush(stdin);
            scanf("%c",&letra);
            letra=tolower(letra);
        }
        while(letra!='a' && letra!='e' && letra!='i' && letra!='o' && letra!='u' && letra!='f');
        if(letra!='f')
        {
            bandera=0;
            do
            {
                if(bandera==1)
                    printf("\nDato invalido, ingrese nuevamente.\n");
                bandera=1;
                printf("\nInicialmente la letra se mostrara en 5 filas y 4 columnas (tamanio=1), si desea multiplicar su tamanio, ingrese un valor mayor: ");
                scanf("%d",&tamanio);
            }
            while(tamanio<=0);
        }
    }
    return 0;
}
