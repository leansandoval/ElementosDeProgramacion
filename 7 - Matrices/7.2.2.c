#include<stdio.h>
#include<windows.h>

void CargaMat(int[][3],int,int);
void MostrarMatFila(int[][3],int,int);
void MostrarMatTraspuesta(int[][3],int,int);

int main()
{
    int MNumeros[2][3];
    CargaMat(MNumeros,2,3);
    printf("\nMatriz original: ");
    printf("\n");
    MostrarMatFila(MNumeros,2,3);
    printf("\nMatriz transpuesta: ");
    printf("\n");
    MostrarMatTraspuesta(MNumeros,2,3);
    printf("\n\n");
    system("pause");
}

void CargaMat (int m[][3],int f,int c)
{
    int i,j,dato,suma=0;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
        {
            printf("\nIngrese un numero entero (dato ingresado en la posicion (%d,%d): ",i+1,j+1);
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

void MostrarMatTraspuesta(int m[][3],int f,int c)
{
    int i,j;
    for(j=0;j<=c-1;j++)
    {
        printf("\n");
        for(i=0;i<=f-1;i++)
            printf("%d\t",m[i][j]);
    }
    printf("\n");
}
