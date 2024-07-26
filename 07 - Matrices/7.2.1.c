#include<stdio.h>
#include<windows.h>

void CargaMat(int[][3],int,int);
void MostrarMatFila(int[][3],int,int);
void PonerEnCero(int[],int);
void SumaFilaMatEnV(int[][3],int[],int,int);
int SumaVec(int[],int);

int main()
{
    int MNumeros[3][3],VSumaFila[3],sum,num;
    PonerEnCero(VSumaFila,3);
    CargaMat(MNumeros,3,3);
    MostrarMatFila(MNumeros,3,3);
    SumaFilaMatEnV(MNumeros,VSumaFila,3,3);
    sum=SumaVec(VSumaFila,3);
    printf("\nIngrese un numero entero: ");
    scanf("%d",&num);
    printf("\nEl producto al realizar las suma de todos los elementos de la matriz con el numero %d es: %d",num,sum*num);
    printf("\n\n");
    system("pause");
}

void CargaMat (int m[][3],int f,int c)
{
    int i,j,dato,suma=0;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
        {
            printf("\nIngrese un numero entero (dato ingresado en la posicion (%d,%d): ",i,j);
            scanf("%d",&dato);
            m[i][j]=dato;
        }
}

void MostrarMatFila(int m[][3],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
    {
        printf("\n");
        for(j=0;j<=c-1;j++)
            printf("%d\t",m[i][j]);
    }
    printf("\n");
}

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void SumaFilaMatEnV (int m[][3],int v[],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            v[i]+=m[i][j];
}

int SumaVec(int v[],int ce)
{
    int i,s=0;
    for(i=0;i<=ce-1;i++)
        s+=v[i];
    return s;
}
