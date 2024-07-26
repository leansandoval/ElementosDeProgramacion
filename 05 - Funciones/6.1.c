/*6.1. Realizar un programa que al ingresar solicite el ingreso de dos números enteros y luego muestre por
pantalla el siguiente menú (las xx de los números deben ser reemplazadas con los valores
correspondientes):

                                        Menú de Opciones
                                        ---- -- --------
                                        Numero 1: xx Numero 2: xx
                                        1) Sumar
                                        2) Restar
                                        3) Multiplicar
                                        4) Dividir
                                        5) Ingresar Nuevos Números
                                        6) Salir

Ingrese su opción:
Al ingresar el número de la opción del 1 al 4, se realiza la operación y muestra el resultado hasta que se
presione una tecla. Luego vuelve a mostrar el menú para poder realizar otra operación con los mismos
números. La opción 5 pide el ingreso de dos nuevos números de trabajo mientras que la opción 6 sale y
cierra el programa.
El ingreso de la opción debe estar validado y en caso de ingresarse un número no válido debe solicitarlo
nuevamente.
Usar una función para mostrar el menú y retornar el valor elegido.
------------------------------------------------------------------------------------------------------------
Resolucion: Como pide unicamente una funcion para mostrar el menu y que nos retorne el valor, creamos una
funcion en la que ingresemos dichos numeros enteros y luego nos aparezca las opciones del menu.
* MostrarMenu: funcion que unicamente muestra el menu, basicamente es un printf para ingresar los numeros
pedidos.*/

#include<stdio.h>
#include<windows.h>

void MostrarMenu(int,int);

int main()
{
    int bandera=0,numero1,numero2,opcion;
    printf("\nIngrese el primer numero: ");
    scanf("%d",&numero1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d",&numero2);
    MostrarMenu(numero1,numero2);
    do
    {
        if(bandera==1)
            printf("\nEl numero ingresado no se encuentra dentro de rango de opciones.\n");
        bandera=1;
        printf("\nIngresar una opcion del 1 al 6: ");
        scanf("%d",&opcion);
    }
    while(opcion<1 || opcion>6);
    while(opcion!=6)
    {
        switch(opcion)
        {
        case 1:
            printf("\nLa suma de %d y %d es: %d\n",numero1,numero2,numero1+numero2);
            break;
        case 2:
            printf("\nLa resta de %d y %d es: %d\n",numero1,numero2,numero1-numero2);
            break;
        case 3:
            printf("\nLa multiplicacion de %d y %d es: %d\n",numero1,numero2,numero1*numero2);
            break;
        case 4:
            if(numero2!=0)
                printf("\nLa division de %d y %d es: %.2f\n",numero1,numero2,(float)numero1/numero2);
            else
                printf("\nError, el divisor es 0...\n");
            break;
        case 5:
            system("cls");
            printf("\nIngrese el primer numero: ");
            scanf("%d",&numero1);
            printf("\nIngrese el segundo numero: ");
            scanf("%d",&numero2);
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
        MostrarMenu(numero1,numero2);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl numero ingresado no se encuentra dentro de rango de opciones.\n");
            bandera=1;
            printf("\nIngresar una opcion del 1 al 6: ");
            scanf("%d",&opcion);
        }
        while(opcion<1 || opcion>6);
    }
    return 0;
}

void MostrarMenu(int numero1,int numero2)
{
    printf("\n---------------------------------\n");
    printf("\tMenu de opciones");
    printf("\n---------------------------------\n");
    printf("\nNumero 1: %d\tNumero 2: %d\n",numero1,numero2);
    printf("\n1) Sumar\n");
    printf("\n2) Restar\n");
    printf("\n3) Multiplicar\n");
    printf("\n4) Dividir\n");
    printf("\n5) Ingresar nuevos numeros\n");
    printf("\n6) Salir\n");
}
