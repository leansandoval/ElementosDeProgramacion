#include<stdio.h>
#include<windows.h>
#define columna 120
#define fila 40

int esDatoVal(int,int,int);
int esDatoVal2(int,int);
int IngrDatoVal(int,int);
int IngrDatoVal2(int);
void PonerMatEnCero(int[][columna],int,int);
void MostrarMatFila(int[][columna],int,int);
void PonerEnCero(int[],int);
void SumarFilaMatEnV(int[][columna],int[],int,int);
int Minimo(int[],int);
void MostrarIgualQue(int[],int,int);

int main()
{
    int MMercaderias[fila][columna],VTotalPorSucursal[fila],min;
    PonerMatEnCero(MMercaderias,fila,columna);
    PonerEnCero(VTotalPorSucursal,fila);
    CargaMat(MMercaderias,fila,columna);
    MostrarMatFila(MMercaderias,fila,columna);
    SumarFilaMatEnV(MMercaderias,VTotalPorSucursal,fila,columna);
    min=Minimo(VTotalPorSucursal,fila);
    MostrarIgualQue(VTotalPorSucursal,fila,min);
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

int esDatoVal2(int x,int lim)
{
    if(x>lim)
        return 1;
    else
        return 0;
}

int IngrDatoVal2(int lim)
{
    int dato,band=0;
    do
    {
        if(band==1)
        {
            printf("\nDato incorrecto, ingrese nuevamente\n");
        }
        band=1;
        printf("\nIngrese cantidad de unidades pedidas: ");
        scanf("%d",&dato);
    }while(esDatoVal2(dato,lim)==0);
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

void PonerMatEnCero (int m[][columna],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            m[i][j]=0;
}

void CargaMat (int m[][columna],int f,int c)
{
    int sucursal,rubro,cant;
    printf("\nIngrese numero de sucursal entre 1 y %d (0 para terminar): ",f);
    sucursal=IngrDatoVal(0,f);
    while(sucursal!=0)
    {
        printf("\nCodigo de rubro (entre 1 y %d): ",c);
        rubro=IngrDatoVal(1,c);
        cant=IngrDatoVal2(0);
        m[sucursal-1][rubro-1]+=cant;
        printf("\nIngrese numero de sucursal entre 1 y %d (0 para terminar): ",f);
        sucursal=IngrDatoVal(0,f);
    }
}

void MostrarMatFila(int m[][columna],int f,int c)
{
    int i,j,k;
    printf("\n");
    printf("\nSUCURSAL/RUBRO");
    printf("\n");
    for(k=0;k<=c-1;k++)
        printf("\t%d",k+1);
    for(i=0;i<=f-1;i++)
    {
        printf("\n%d\t",i+1);
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

void SumarFilaMatEnV (int m[][columna],int v[],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            v[i]+=m[i][j];
}

int Minimo(int v[],int ce)
{
    int i,menor=0;
    for(i=0;i<=ce-1;i++)
        if(v[i]>0&&menor==0||v[i]<menor)
            menor=v[i];
    return menor;
}

void MostrarIgualQue (int v[],int ce,int x)
{
    int i;
    printf("\nSucursal/sucursales que pidio/pidieron la menor cantidad en total: ");
    printf("\n");
    for(i=0;i<=ce-1;i++)
        if(v[i]==x)
            printf("\n%d",i+1);
}
