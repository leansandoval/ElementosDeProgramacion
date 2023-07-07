#include<stdio.h>
#include<conio.h>
#define pi 3.141592654
int main()
{
    int cod;
    float valor,rad,grad;
    printf("\nIngrese un valor y a continuacion ingrese el codigo: ");
    scanf("%f%d",&valor,&cod);
    rad=pi/180;
    grad=180/pi;
    switch(cod)
    {
        case 1:printf("\nEl valor ingresado en grados a radianes es: %.2f",valor*rad);break;
        case 2:printf("\nEl valor ingresado en radianes a grados es: %.2f",valor*grad);break;
        default:printf("\nCodigo fuera de rango");
    }
    printf("\n\n");
    return 0;
    getch();
}
