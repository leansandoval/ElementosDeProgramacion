/*6.5. Confeccionar un programa que permita ingresar varias ternas de valores a punto flotante, que finalice al
ingresar una terna con los valores ORDENADOS en forma creciente. Para cada terna exhibir la siguiente
pantalla:

                                            ** OPCIONES POSIBLES **
                                            1 – Mayor valor
                                            2 – Promedio
                                            3 – Suma
                                            4 - Finalizar
                                            ** Digite su opción:

Según la opción deseada debe aparecer en pantalla el resultado, sin borrar el menú. No admitir otros
valores de opción. Confeccionar y utilizar una función PARA CADA UNA de las opciones y otra para detectar
la condición final.*/

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

int Menu (float,float,float);
float MayorValorTerna (float,float,float);
float PromedioTerna(float,float,float);
float SumaTerna(float,float,float);
bool Creciente(float,float,float);

int main()
{
    int i,opcion;
    float valor,primerValor,segundoValor,tercerValor;
    printf("\nEl programa finaliza con ternas ingresadas en orden creciente\n");
    for(i=1; i<=3; i++)
    {
        printf("\nIngrese valor de la terna numero %d: ",i);
        scanf("%f",&valor);
        if(i==1)
            primerValor=valor;
        else if(i==2)
            segundoValor=valor;
        else
            tercerValor=valor;
    }
    while(!Creciente(primerValor,segundoValor,tercerValor))
    {
        system("cls");
        opcion=Menu(primerValor,segundoValor,tercerValor);
        while(opcion!=4)
        {
            switch(opcion)
            {
            case 1:
                printf("\nMayor valor de la terna: %.2f\n",MayorValorTerna(primerValor,segundoValor,tercerValor));
                break;
            case 2:
                printf("\nPromedio de los valores de la terna: %.2f\n",PromedioTerna(primerValor,segundoValor,tercerValor));
                break;
            case 3:
                printf("\nSuma de los valores de la terna: %.2f\n",SumaTerna(primerValor,segundoValor,tercerValor));
                break;
            }
            printf("\n");
            system("pause");
            system("cls");
            opcion=Menu(primerValor,segundoValor,tercerValor);
        }
        printf("\nEl programa finaliza con ternas ingresadas en orden creciente\n");
        for(i=1; i<=3; i++)
        {
            printf("\nIngrese valor de la terna numero %d: ",i);
            scanf("%f",&valor);
            if(i==1)
                primerValor=valor;
            else if(i==2)
                segundoValor=valor;
            else
                tercerValor=valor;
        }
        Creciente(primerValor,segundoValor,tercerValor);
    }
    return 0;
}

bool Creciente (float primerValor,float segundoValor,float tercerValor)
{
    if(primerValor<segundoValor && segundoValor<tercerValor)
        return true;
    else
        return false;
}

int Menu (float primerValor,float segundoValor,float tercerValor)
{
    int opcion;
    printf("\n--------------------------------------");
    printf("\n\tValores de la terna\n");
    printf("\n\t%.2f    %.2f    %.2f\n",primerValor,segundoValor,tercerValor);
    printf("--------------------------------------\n");
    printf("\n**OPCIONES POSIBLES**\n");
    printf("\n1 - Mayor valor\n");
    printf("\n2 - Promedio\n");
    printf("\n3 - Suma\n");
    printf("\n4 - Finalizar\n");
    do
    {
        printf("\n** Digite su opcion: ");
        scanf("%d",&opcion);
    }
    while(opcion<1 || opcion>4);
    return opcion;
}

float MayorValorTerna (float primerValor,float segundoValor,float tercerValor)
{
    float mayor;
    return mayor=(primerValor>segundoValor && primerValor>tercerValor)? primerValor : (segundoValor>primerValor && segundoValor>tercerValor)? segundoValor : tercerValor;
}

float PromedioTerna (float primerValor, float segundoValor, float tercerValor)
{
    float promedio;
    return promedio=(primerValor+segundoValor+tercerValor)/3;
}

float SumaTerna(float primerValor,float segundoValor,float tercerValor)
{
    float suma;
    return suma=primerValor+segundoValor+tercerValor;
}
