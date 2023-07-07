#include<stdio.h>
#include<windows.h>
void PonerEnCero(int[],int);
int esDatoVal(int,int,int);
int esDatoVal2(int,int);
int IngrDatoVal(int,int,int);
int IngrDatoVal2(int);
int CargaVecParalelo(int [],int [],int);
void ListadoVectores(int [],int [],int);
int MaximoVec(int [],int);
int MinimoVec(int[],int);
void MostrarIgualQue(int[],int[],int,int);
int BusquedaSec(int[],int,int);

int main()
{
    int VCod[10],VUni[10],cant=0,max,min;
    PonerEnCero(VUni,10);
    cant=CargaVecParalelo(VCod,VUni,10);
    printf("\nCodigo de producto    \tUnidad");
    ListadoVectores(VCod,VUni,cant);
    max=MaximoVec(VUni,cant);
    printf("\nCodigos de productos del cual se solicitaron mayor cantidad de unidades");
    MostrarIgualQue(VUni,VCod,cant,max);
    min=MinimoVec(VUni,cant);
    printf("\nCodigos de productos del cual se solicitaron menor cantidad de unidades");
    MostrarIgualQue(VUni,VCod,cant,min);
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

int IngrDatoVal (int lim1,int lim2,int lim3)
{
    int dato;
    do
    {
        printf("\nIngrese codigo del producto (entre %d y %d,%d para terminar): ",lim1,lim2,lim3);
        scanf("%d",&dato);
    }while(esDatoVal(dato,lim1,lim2)==0&&dato!=lim3);
    return dato;
}

int IngrDatoVal2 (int lim)
{
    int dato;
    do
    {
        printf("\nIngrese la cantidad de unidades solicitadas: ");
        scanf("%d",&dato);
    }while(esDatoVal2(dato,lim)==0);
    return dato;
}

int CargaVecParalelo(int c[],int u[],int ce)
{
    int i=0,codigo,aux,unidades,pos;
    codigo=IngrDatoVal(1000,9999,0);
    while(codigo!=0&&i<ce)
    {
        unidades=IngrDatoVal2(0);
        pos=BusquedaSec(c,ce,codigo);
        if(pos!=-1)
        {
            c[pos]=codigo;
            u[pos]+=unidades;
            codigo=IngrDatoVal(1000,9999,0);
        }
        else
        {
            c[i]=codigo;
            u[i]=unidades;
            i++;
            codigo=IngrDatoVal(1000,9999,0);
        }
    }
    return i;
}

void ListadoVectores (int a[],int b[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        printf("\n\t%d\t\t%d",a[i],b[i]);
}

int MaximoVec (int v[],int ce)
{
    int i,mayor=0;
    for(i=0;i<=ce-1;i++)
        if(i==0||v[i]>mayor)
            mayor=v[i];
    return mayor;
}

int MinimoVec (int a[],int ce)
{
    int i,menor=0;
    for(i=0;i<=ce-1;i++)
        if(i==0||a[i]<menor)
                menor=a[i];
    return menor;
}

void MostrarIgualQue(int a[],int b[],int ce,int x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(a[i]==x)
            printf("\n%d",b[i]);
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
