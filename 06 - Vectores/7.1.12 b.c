#include<stdio.h>
#include<windows.h>
int esDatoVal(int,int,int);
int IngrDatoVal(int,int,int);
int BusquedaSec(int[],int,int);
int CargaVecParalelo(int[],float[],int);
void MostrarVecs(int[],float[],int);
int Maximo(float[],int);
void MostrarIgualQueVecParalelo(int[],float[],int,float);


int main()
{
    int VLegajo[100],cant;
    float VSueldo[100],max;
    cant=CargaVecParalelo(VLegajo,VSueldo,100);
    if(cant!=0)
        {
            MostrarVecs(VLegajo,VSueldo,cant);
            max=Maximo(VSueldo,cant);
            printf("\n");
            printf("\nEl/Los empleado/empleados con sueldo maximo (%.2f) son: ",max);
            printf("\n");
            MostrarIgualQueVecParalelo(VLegajo,VSueldo,cant,max);
        }
    else
        printf("\nNo hay empleados");
    printf("\n\n");
    system("pause");
}

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int IngrDatoVal(int lim1,int lim2,int lim3)
{
    int dato,band=0;
    do
    {
        if(band==1)
            {
                printf("\nDato fuera del rango");
                printf("\n");
            }
        band=1;
        printf("\nIngrese numero de legajo entre %d y %d (%d para terminar): ",lim1,lim2,lim3);
        scanf("%d",&dato);
    }while(esDatoVal(dato,lim1,lim2)==0&&dato!=lim3);
    return dato;
}

int CargaVecParalelo (int l[],float s[],int ce)
{
    int legajo,pos,i=0;
    float sueldo;
    legajo=IngrDatoVal(1000,9999,0);
    while(legajo!=0&&i<ce)
    {
        pos=BusquedaSec(l,ce,legajo);
        if(pos==-1)
        {
            l[i]=legajo;
            do
                {
                    printf("\nIngrese sueldo: ");
                    scanf("%f",&sueldo);
                }while(!(sueldo>0));
            s[i]=sueldo;
            i++;
            legajo=IngrDatoVal(1000,9999,0);
        }
        else
        {
            printf("\nEL LEGAJO YA FUE INGRESADO ANTERIORMENTE");
            printf("\n");
            legajo=IngrDatoVal(1000,9999,0);
        }
    }
    return i;
}

int BusquedaSec(int v[],int ce,int x)
{
    int i=0,p=-1;
    while(p==-1&&i<ce)
    {
        if(v[i]==x)
            p=i;
        else
            i++;
    }
    return p;
}

void MostrarVecs(int l[],float s[],int ce)
{
    int i;
    printf("\nLEGAJO\tSUELDO");
    for(i=0;i<=ce-1;i++)
        printf("\n%d\t%.2f",l[i],s[i]);
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

void MostrarIgualQueVecParalelo(int a[],float b[],int ce,float x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(b[i]==x)
            printf("\n%d",a[i]);
}
