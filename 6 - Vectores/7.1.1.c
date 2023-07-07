#include<stdio.h>
#include<windows.h>
float CARGA (float[],int);
float INVERTIR (float [],float [],int);
void MOSTRAR (float [],int);
int main()
{
    int VA[10],VB[10];
    CARGA(VA,10);
    INVERTIR(VA,VB,10);
    MOSTRAR(VB,10);
    printf("\n\n");
    system("pause");
    printf("\n");
}

float CARGA (float a[],int ce)
{
    int i;
    float num;
    for(i=0;i<=ce-1;i++)
    {
        printf("\nIngrese un valor real: ");
        scanf("%f",&num);
        a[i]=num;
    }
}

float INVERTIR (float a[],float b[],int ce)
{
    int i,y=9;
    for(i=0;i<ce;i++)
    {
        b[i]=a[y];
        y--;
    }
}

void MOSTRAR (float b[],int ce)
{
    int i;
    printf("\nValores invertidos: ");
    printf("\n")
    for(i=0;i<=ce-1;i++)
    {
        printf("\n%.2f",b[i]);
    }
}
