/*5.2.7 Ingresar diversos quintetos de números positivos de 1 cifra c/u, finalizando cuando las cinco cifras leídas
sean iguales a cero. Determinar e informar cuantos de los quintetos ingresados han formado números
capicúas 'triples' y cuantos 'quíntuples'.
-------------------------------------------------------------------------------------------------------------------
Resolucion: validar que las variables que se ingresen del quinteto sean de una cifra cada una (do while).

Para la condicion de capicuas triples:
* El primer numero debe ser igual al tercero
* El tercer numero debe ser igual al quinto
Ejemplo:
16102 ---> 1 capicua triple
02454 ---> 1 capicua triple
32303 ---> 2 capicuas triples

Para la condicion de capicuas quintuples:
* El primer numero debe ser igual al tercero Y el segundo numero, igual al cuarto.
Ejemplo:
40204 --> 1 capicua quintuple

Caso especial:
32323 --> 1 capicua quintuple, 2 capicuas triples
*/

#include <stdio.h>

int main()
{
    int bandera=0,primero,segundo,tercero,cuarto,quinto,capicuaTriple=0,capicuaQuintuple=0;
    printf("\nIngrese quintetos de numeros positivos de 1 cifra cada uno (quinteto de '0' para terminar)\n");
    do
    {
        if(bandera==1)
            printf("\nEl numero ingresado es incorrecto\n");
        bandera=1;
        printf("\nPrimer numero: ");
        scanf("%d",&primero);
    }
    while(primero<0 || primero>9);
    bandera=0;
    do
    {
        if(bandera==1)
            printf("\nEl numero ingresado es incorrecto\n");
        bandera=1;
        printf("\nSegundo numero: ");
        scanf("%d",&segundo);
    }
    while(segundo<0 || segundo>9);
    bandera=0;
    do
    {
        if(bandera==1)
            printf("\nEl numero ingresado es incorrecto\n");
        bandera=1;
        printf("\nTercer numero: ");
        scanf("%d",&tercero);
    }
    while(tercero<0 || tercero>9);
    bandera=0;
    do
    {
        if(bandera==1)
            printf("\nEl numero ingresado es incorrecto\n");
        bandera=1;
        printf("\nCuarto numero: ");
        scanf("%d",&cuarto);
    }
    while(cuarto<0 || cuarto>9);
    bandera=0;
    do
    {
        if(bandera==1)
            printf("\nEl numero ingresado es incorrecto\n");
        bandera=1;
        printf("\nQuinto numero: ");
        scanf("%d",&quinto);
    }
    while(quinto<0 || quinto>9);
    bandera=0;
    while(primero!=0 || segundo!=0 || tercero!=0 || cuarto!=0 ||quinto!=0)
    {

        if(primero==tercero)
            capicuaTriple++;
        if(tercero==quinto)
            capicuaTriple++;
        if(primero==quinto && segundo==cuarto)
            capicuaQuintuple++;
        printf("\nIngrese quintetos de numeros positivos de 1 cifra cada uno (quinteto de '0' para terminar)\n");
        do
        {
            if(bandera==1)
                printf("\nEl numero ingresado es incorrecto\n");
            bandera=1;
            printf("\nPrimer numero: ");
            scanf("%d",&primero);
        }
        while(primero<0 || primero>9);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl numero ingresado es incorrecto\n");
            bandera=1;
            printf("\nSegundo numero: ");
            scanf("%d",&segundo);
        }
        while(segundo<0 || segundo>9);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl numero ingresado es incorrecto\n");
            bandera=1;
            printf("\nTercer numero: ");
            scanf("%d",&tercero);
        }
        while(tercero<0 || tercero>9);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl numero ingresado es incorrecto\n");
            bandera=1;
            printf("\nCuarto numero: ");
            scanf("%d",&cuarto);
        }
        while(cuarto<0 || cuarto>9);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl numero ingresado es incorrecto\n");
            bandera=1;
            printf("\nQuinto numero: ");
            scanf("%d",&quinto);
        }
        while(quinto<0 || quinto>9);
    }
    printf("\nCantidad de capicuas triples: %d\n",capicuaTriple);
    printf("\nCantidad de capicuas quintiples: %d\n",capicuaQuintuple);
    return 0;
}
