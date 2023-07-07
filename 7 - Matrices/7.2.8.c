#include<stdio.h>
#include<windows.h>

int esDatoVal(int,int,int);
int IngrDatoVal(int,int);
int IngrDatoVal3(int,int,int);

void PonerMatEnVacio(char[][15],int,int);
int CargaMat(char[][15],int,int);
int BusquedaSec(int[],int,int);
void MostrarMatFila(char[][15],int,int,int);

int main()
{
    int total;
    char MExpensas[5][15];
    PonerMatEnVacio(MExpensas,5,15);
    total=CargaMat(MExpensas,5,15);
    MostrarMatFila(MExpensas,5,15,total);
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

int IngrDatoVal(int limi,int lims)
{
    int dato,band=0;
    do
    {
        if(band==1)
        {
            printf("\nDato incorrecto, ingrese nuevamente: ");
            printf("\n");
        }
        band=1;
        scanf("%d",&dato);
    }while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

int IngrDatoVal3(int lim1,int lim2,int lim3)
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
    }while(esDatoVal(dato,lim1,lim2)==0&&dato!=lim3);
    return dato;
}

void PonerMatEnVacio (char m[][15],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            m[i][j]=' ';
}

int CargaMat(char m[][15],int f,int c)
{
    int piso,dpto,expensas=0;
    printf("\nIngrese numero de piso del 1 al %d (99 para terminar): ",f);
    piso=IngrDatoVal3(1,5,99);
    while(piso!=99)
    {
        printf("\nIngrese numero de departamento (entre 1 y %d): ",c);
        dpto=IngrDatoVal(1,15);
        if( m[piso-1][dpto-1]==' ')
        {
            m[piso-1][dpto-1]='X';
            expensas=expensas+1000;
        }
        m[piso-1][dpto-1]='X';
        printf("\nIngrese numero de piso del 1 al %d (99 para terminar): ",f);
        piso=IngrDatoVal3(1,5,99);
    }
    return expensas;
}

int BusquedaSec (int v[],int ce,int x)
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


void MostrarMatFila(char m[][15],int f,int c,int x)
{
    int i,j;
    printf("\n\t\t\t\t\t\t\tTOTAL RECAUDADO: %d",x);
    printf("\n\t\t\t\t\t\t      DEPARTAMENTOS DEUDORES");
    printf("\n\n");
    printf("PISO   DTPO 1  DTPO 2  DTPO 3  DTPO 4  DTPO 5  DTPO 6  DTPO 7  DTPO 8  DTPO 9  DTPO 10  DTPO 11  DTPO 12  DTPO 13  DTPO 14  DTPO 15");
    printf("\n");
    for(i=0;i<=f-1;i++)
    {
        printf("\n%d\t",i+1);
        for(j=0;j<=c-1;j++)
            printf("%c\t",m[i][j]);
    }
    printf("\n");
}
