#include<stdio.h>
#include<windows.h>

void CargaMat(int[][4],int,int);
void MostrarMatFila(int[][4],int,int);
void PonerEnCero(int[],int);
void SumaColumnaMatEnV(int[][4],int[],int,int);
void MostrarVec(int[],int);

int main()
{
     int MNumeros[5][4],VSumaColum[4];
     PonerEnCero(VSumaColum,4);
     CargaMat(MNumeros,5,4);
     printf("\nMatriz ingresada: ");
     printf("\n");
     MostrarMatFila(MNumeros,5,4);
     SumaColumnaMatEnV(MNumeros,VSumaColum,5,4);
     printf("\nVector que posee la suma por columna de la matriz: ");
     printf("\n");
     MostrarVec(VSumaColum,4);
     printf("\n\n");
     system("pause");
}

void CargaMat (int m[][4],int f,int c)
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

void MostrarMatFila(int m[][4],int f,int c)
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

void SumaColumnaMatEnV (int m[][4],int v[],int f,int c)
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

void MostrarVec(int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        printf("\t%d",v[i]);
}
