#include<stdio.h>
#include<windows.h>

int esDatoVal(int,int,int);
int esDatoValReal(float,float);
int IngrDatoVal(int,int);
float IngrDatoValReal(float);

void PonerEnCero(float[],int);
void PonerMatEnCero(float[][12],int,int);

void CargaMat(float[][12],int,int);
void MostrarMatFila(float[][12],int,int);

void SumarFilaMatEnV(float[][12],float[],int,int);
int ProductoMaxRecaudacion(float[],int);

void SumarColumnaMatEnV(float[][12],float[],int,int);
void SumarPorTrimestre(float[][12],float[],int,int,int);
void MostrarVec(float[],int);

int main()
{
    float MPrecios[20][12],VRecaudacionProd[20],VRecaudacionMes[12];
    PonerMatEnCero(MPrecios,20,12);
    PonerEnCero(VRecaudacionProd,20);
    PonerEnCero(VRecaudacionMes,12);
    CargaMat(MPrecios,20,12);
    MostrarMatFila(MPrecios,20,12);

    SumarFilaMatEnV(MPrecios,VRecaudacionProd,20,12);
    printf("\nProducto con mayor recudacion: %d",ProductoMaxRecaudacion(VRecaudacionProd,20)+1);

    SumarColumnaMatEnV(MPrecios,VRecaudacionMes,20,12);
    MostrarVec(VRecaudacionMes,12);

    printf("\n\n");
    system("pause");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int esDatoValReal(float x,float lim)
{
    if(x>lim)
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
            printf("\nDato incorrecto");
            printf("\n");
        }
        band=1;
        printf("\nIngrese precio unitario del producto: ");
        scanf("%f",&dato);
    }while(esDatoValReal(dato,lim)==0);
    return dato;
}

int IngrDatoVal(int limi,int lims)
{
    int dato,band=0;
    do
    {
        if(band==1)
        {
            printf("\nDato incorrecto, ingrese nuevamente: ");
        }
        band=1;
        scanf("%d",&dato);
    }while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void PonerEnCero(float v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void PonerMatEnCero (float m[][12],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            m[i][j]=0;
}

void CargaMat (float m[][12],int f,int c)
{
    int codigo,mes;
    float precio;
    printf("\nIngrese codigo de producto (entre 1 y 20)... 0 para terminar: ");
    codigo=IngrDatoVal(0,f);
    while(codigo!=0)
    {
        printf("\nIngrese mes correspondiente: ");
        mes=IngrDatoVal(1,c);
        precio=IngrDatoValReal(0);
        m[codigo-1][mes-1]+=precio;
        printf("\nIngrese codigo de producto (entre 1 y 20)... 0 para terminar: ");
        codigo=IngrDatoVal(0,f);
    }
}

void MostrarMatFila(float m[][12],int f,int c)
{
    int i,j;
    printf("\nPRODUCTO/MES");
    printf("\n");
    printf("\n");
    printf("\t  1     2     3     4     5     6     7     8     9    10    11    12");
    printf("\n");
    for(i=0;i<=f-1;i++)
    {
        printf("\n%d\t",i+1);
        for(j=0;j<=c-1;j++)
            printf("%.2f  ",m[i][j]);
    }
    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void SumarFilaMatEnV(float m[][12],float v[],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            v[i]+=m[i][j];
}

int ProductoMaxRecaudacion(float v[],int ce)
{
    int i,pos;
    float mayor=0;
    for(i=0;i<=ce-1;i++)
        if(mayor==0||v[i]>mayor)
            {
                mayor=v[i];
                pos=i;
            }
    return pos;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void SumarColumnaMatEnV(float m[][12],float v[],int f,int c)
{
    int i,j;
    float s;
    for(j=0;j<=c-1;j++)
    {
        s=0;
        for(i=0;i<=f-1;i++)
            s+=m[i][j];
        v[j]=s;
    }
}

void MostrarVec (float v[],int ce)
{
    int i;
    printf("\n");
    for(i=0;i<=ce-1;i++)
        printf("%.2f\t",v[i]);
}
