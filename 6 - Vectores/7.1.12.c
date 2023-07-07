#include<stdio.h>
#include<windows.h>
int esDatoValReal(float,float);
float IngrDatoValReal(float);
void PonerEnCero(float [],int);
int CargaEmpleados(float[],int);
void ImprimeReal(float [],int);
int Maximo(float[],int);
void MostrarIgualQue(float[],int,float);

int main()
{
    int cant;
    float VSueldo[100],max;
    PonerEnCero(VSueldo,100);
    cant=CargaEmpleados(VSueldo,100);
    ImprimeReal(VSueldo,cant);
    max=Maximo(VSueldo,cant);
    printf("\n");
    printf("\nEmpleado/empleados que poseen el maximo sueldo (%.2f): ",max);
    printf("\n");
    MostrarIgualQue(VSueldo,cant,max);
    printf("\n\n");
    system("pause");
    printf("\n");
}

void PonerEnCero(float v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

int esDatoValReal(float x,float lim)
{
    if(x>=lim)
        return 1;
    else
        return 0;
}

float IngrDatoValReal(float lim)
{
    float dato,band=0;
    do
    {
        if(band==1)
        {
            printf("\nSueldo incorrecto");
            printf("\n");
        }
        band=1;
        printf("\nIngrese sueldo correspondiente: ");
        scanf("%f",&dato);
    }while(esDatoValReal(dato,lim)==0);
    return dato;
}

int CargaEmpleados (float v[],int ce)
{
    int i=0;
    float sueldo;
    sueldo=IngrDatoValReal(0);
    while(sueldo!=0&&i<ce)
    {
        v[i]=sueldo;
        i++;
        sueldo=IngrDatoValReal(0);
    }
    return i;
}

void ImprimeReal(float v[],int ce)
{
    int i;
    printf("\nNUMERO DE LEGAJO\tSUELDO");
    printf("\n");
    for(i=0;i<=ce-1;i++)
    {
        printf("\n%d\t\t\t%.2f",i+1,v[i]);
    }
}

int Maximo (float v[],int ce)
{
    int i;
    float mayor=0;
    for(i=0;i<=ce-1;i++)
        if(i==0||v[i]>mayor)
            mayor=v[i];
    return mayor;
}

void MostrarIgualQue(float a[],int ce,float x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(a[i]==x)
            printf("\n%d",i+1);
}
