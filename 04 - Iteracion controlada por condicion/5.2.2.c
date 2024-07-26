/*5.2.2 Escribir las sentencias que permitan el ingreso correcto del valor numérico de un día y un mes
determinado. Por algún error volver a solicitar.
------------------------------------------------------------------------------------------------------
Resolucion: se valida el ingreso del mes con un do while, dentro de este se declara una variable
bandera en el caso de que el valor que se ingrese del mes sea incorrecto.
Luego, dependiendo del mes que se haya ingresado, van a depender los dias. Si es un mes impar, el mes
posee 31 dias; si es par (menos febrero), 30 dias; y si es febrero, 28 dias (asumiendo un año no
bisiesto)*/

#include<stdio.h>

int main()
{
    int dia,mes,bandera=0;
    do
    {
        if(bandera==1)
            printf("\nEl valor numero del mes que se ingreso es incorrecto\n");
        bandera=1;
        printf("\nIngrese valor numerico del mes: ");
        scanf("%d",&mes);
    }
    while(mes<=0 || mes>=13);
    bandera=0;
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
    {
        do
        {
            if(bandera==1)
                printf("\nEl valor numero del dia que se ingreso es incorrecto\n");
            bandera=1;
            printf("\nIngrese valor numerico del dia: ");
            scanf("%d",&dia);
        }
        while(dia<=0 || dia>=32);
        printf("\nFecha valida\n");
    }
    else if(mes==2)
    {
        do
        {
            if(bandera==1)
                printf("\nEl valor numero del dia que se ingreso es incorrecto\n");
            bandera=1;
            printf("\nIngrese valor numerico del dia: ");
            scanf("%d",&dia);
        }
        while(dia<=0 || dia>=29);
        printf("\nFecha valida\n");
    }
    else
    {
        do
        {
            if(bandera==1)
                printf("\nEl valor numero del dia que se ingreso es incorrecto\n");
            bandera=1;
            printf("\nIngrese valor numerico del dia: ");
            scanf("%d",&dia);
        }
        while(dia<=0 || dia>=31);
        printf("\nFecha valida\n");
    }
    return 0;
}
