#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define fila 10
#define columna 15

int esDatoVal(int,int,int);
int IngrDatoVal(int,int);
void PonerEnCero(int[],int);
void PonerMatEnCero(int[][columna],int,int);
void CargaMat(int[][columna],int,int);
void SumarFilaMatEnV(int[][columna],int[],int,int);
void SumColMatAVec(int[][columna],int[],int,int);
int Maximo(int[],int);
void MostrarIgualQue(int[],int,int);
void MostrarVec(int[],int);

int main()
{
    int MTour[fila][columna],VCantTour[fila],VCantAgencia[columna],max;
    PonerMatEnCero(MTour,fila,columna);
    PonerEnCero(VCantTour,fila);
    PonerEnCero(VCantAgencia,columna);
    CargaMat(MTour,fila,columna);
    SumarFilaMatEnV(MTour,VCantTour,fila,columna);
    SumColMatAVec(MTour,VCantAgencia,fila,columna);
    printf("\na) Total de pasajes vendidos por tour: \n");
    MostrarVec(VCantTour,fila);
    max=Maximo(VCantAgencia,columna);
    printf("\nb) El numero de agencia/agencias que obtuvo/obtuvieron la maxima cantidad de pasajes vendidos es: \n");
    MostrarIgualQue(VCantAgencia,columna,max);
    printf("\n");
    system("pause");
}

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
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
            printf("\nDato incorrecto, ingrese nuevamente: ");
        }
        band=1;
        scanf("%d",&dato);
    }while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void PonerMatEnCero (int m[][columna],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            m[i][j]=0;
}

void CargaMat(int m[][columna],int f,int c)
{
    int codagencia,codtour,cant;
    printf("\nIngrese codigo de agencia entre 1 y 15 (0 para terminar): ");
    codagencia=IngrDatoVal(0,15);
    while(codagencia!=0)
    {
        printf("\nIngrese codigo de tour (entre 1 y 10): ");
        codtour=IngrDatoVal(1,10);
        printf("\nIngrese cantidad de pasajes (entre 0 y 20): ");
        cant=IngrDatoVal(1,20);
        m[codtour-1][codagencia-1]=cant;
        printf("\nIngrese codigo de agencia entre 1 y 15 (0 para terminar): ");
        codagencia=IngrDatoVal(0,15);
    }
}

void SumarFilaMatEnV (int m[][columna],int v[],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            v[i]+=m[i][j];
}

void SumColMatAVec(int m[][columna],int v[],int f,int c)
{
    int i,j,s;
    for(j=0;j<=c-1;j++)
    {
        s=0;
        for(i=0;i<=f-1;i++)
            s+=m[i][j];
        v[j]=s;
    }
}

int Maximo(int v[],int ce)
{
    int i,mayor=0;
    for(i=0;i<=ce-1;i++)
        if(mayor==0||v[i]>mayor)
            mayor=v[i];
    return mayor;
}

void MostrarIgualQue (int v[],int ce,int x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(v[i]==x)
            printf("\n%d\n",i+1);
}

void MostrarVec(int v[],int ce)
{
    int i;
    printf("\nTOUR\tCANTIDAD\n");
    for(i=0;i<=ce-1;i++)
        printf("\n%d\t%d\n",i+1,v[i]);
}
