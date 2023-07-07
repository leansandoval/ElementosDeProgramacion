#include<stdio.h>
#include<windows.h>
void PonerEnCero(int[],int);
int esDatoVal(int,int,int);
int esDatoVal2(int,int);
int IngrDatoVal(int,int);
int IngrDatoVal2(int);
void CargaVec(int[],int);
void ImprimeVec(int[],int);
int main()
{
    int VUnidades[10],codigo,cant;
    PonerEnCero(VUnidades,10);
    CargaVec(VUnidades,10);
    ImprimeVec(VUnidades,10);
    printf("\n\n");
    system("pause");
    printf("\n");
}

void PonerEnCero (int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int esDatoVal2(int x,int lim)
{
    if(x>lim)
        return 1;
    else
        return 0;
}

int IngrDatoVal(int limi,int lims)
{
    int dato,band=0;
    do
    {
        if(band==1)
            {
                printf("\nDato incorrecto");
                printf("\n");
            }
        band=1;
        printf("\nIngrese codigo del producto (del %d al %d): ",limi+1,lims);
        scanf("%d",&dato);
    }while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

int IngrDatoVal2 (int lim)
{
    int dato,band=0;
    do
    {
        if(band==1)
            {
                printf("\nDato incorrecto");
                printf("\n");
            }
        band=1;
        printf("\nIngrese la cantidad de unidades solicitadas: ");
        scanf("%d",&dato);
    }while(esDatoVal2(dato,lim)==0);
    return dato;
}

void CargaVec(int v[],int ce)
{
    int codigo,cant;
    codigo=IngrDatoVal(0,10);
    while(codigo!=0)
    {
        cant=IngrDatoVal2(0);
        v[codigo-1]+=cant;   //Acceso directo
        codigo=IngrDatoVal(0,10);
    }
}

void ImprimeVec(int a[],int ce)
{
    int i;
    printf("\nCODIGO DE PRODUCTO\tUNIDADES");
    for(i=0;i<=ce-1;i++)
        printf("\n\t%d\t\t%d",i+1,a[i]);
}
