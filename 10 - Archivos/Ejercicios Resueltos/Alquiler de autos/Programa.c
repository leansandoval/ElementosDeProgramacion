/*
4. Alquiler de autos
Una empresa de alquiler de autos dispone como máximo de 50 coches, de cada uno de ellos se conoce.
• Nro. Patente
• Apellido y nombre del propietario
Esta información está grabada en un archivo AUTO.dat, que ya existe. Utilizar función Carga, para ingresarlo a memoria.
Además, cada vez que se alquila un auto, se tiene la siguiente información producida durante un mes, esta información se encuentra grabada en el archivo ALQUILER.DAT , secuencial, no ordenado.
• Nro. de Patente
• Día de alquiler (1 a 30)
• Importe del alquiler
Utilizar función Búsqueda para el Nro. de Patente
Se pide determinar:
a) Un listado ordenado en forma descendente por recaudación total de cada auto alquilado durante el mes, indicando:
                RECAUDACIÓN POR AUTOMÓVIL
PATENTE DEL AUTO                         RECAUDACIÓN
    xxxxxxx                                xxxx.xx
Utilizar la función Orden para ordenar los datos y la función Listado1 para mostrarlos
b) Un listado donde figure cada automóvil y los días en el mes que NO se alquiló.
Ingresar la fecha con la función Fecha, con el formato día, mes, año, validando día (1 a 30) , mes (1 a 12) , año (2011 o 2012)
                    LISTADO AL dd/mm/aa
Patente Auto/DIA 1 2 3 4 ..................... 28 29 30
    BSU123       x x x
    CJU236       x x x
    AHP888       x x x x x
Utilizar la función Listado2
c) Grabar el archivo CANTIDAD.DAT” con los siguientes datos:
• Nro. de Patente
• Apellido y nombre del propietario
• Cantidad de días que se alquiló cada auto en el mes.
Utilizar la función Grabar
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

typedef struct
{
    char nropatente[11],propietario[21];
}T_Auto;

typedef struct
{
    char nropatente[7];
    int dia;
    float importe;
}T_Alquiler;

typedef struct
{
    int dia,mes,anio;
}T_Fecha;

typedef struct
{
    char nropatente[11],propietario[21];
    int cant;
}T_Cant;

int Carga(T_Auto[],int);
int Busqueda(T_Auto[],int,char[]);
void Inicializar(char[][30],int,int);
void Orden(T_Auto[],float[],int);
void Listado1(T_Auto[],float[],int);
int esDatoVal(int,int,int);
T_Fecha IngrFechaVal();
void Listado2(T_Auto[],char[][30],T_Fecha,int,int);
void Grabar(T_Auto v[],char[][30],int,int);

int main()
{
    FILE *pf;
    T_Auto VProp[50];
    T_Alquiler aux;
    T_Fecha f;
    int cant=Carga(VProp,50),pos;
    float VRecau[50]={0};
    char MAlquiler[50][30];
    Inicializar(MAlquiler,50,30);
    pf=fopen("ALQUILER.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Alquiler),1,pf);
    while(!feof(pf))
    {
        pos=Busqueda(VProp,cant,aux.nropatente);
        if(pos!=-1)
        {
            MAlquiler[pos][aux.dia-1]=' ';
            VRecau[pos]+=aux.importe;
        }
        else
            printf("\nERROR PATENTE\n");
        fread(&aux,sizeof(T_Alquiler),1,pf);
    }
    fclose(pf);
    Orden(VProp,VRecau,cant);
    Listado1(VProp,VRecau,cant);
    Listado2(VProp,MAlquiler,f,cant,30);
    Grabar(VProp,MAlquiler,cant,30);
}

int Carga (T_Auto v[],int ce)
{
    FILE*pf;
    T_Auto aux;
    int i=0;
    pf=fopen("AUTO.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Auto),1,pf);
    while(!feof(pf)&&i<ce)
    {
        v[i]=aux;
        i++;
        fread(&aux,sizeof(T_Auto),1,pf);
    }
    fclose(pf);
    return i;
}

int Busqueda (T_Auto v[],int ce,char x[])
{
    int pos=-1,i=0;
    while(pos==-1&&i<ce)
        if(strcmpi(v[i].nropatente,x)==0)
            pos=i;
        else
            i++;
    return pos;
}

void Inicializar(char m[][30],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            m[i][j]='X';
}

void Orden(T_Auto v[],float b[],int ce)
{
    int i=0,j,hubocambio;
    float aux;
    T_Auto aux2;
    do
    {
        hubocambio=0;
        for(j=1;j<ce-i;j++)
            if(b[j-1]<b[j])
            {
                aux=b[j-1];
                b[j-1]=b[j];
                b[j]=aux;
                aux2=v[j-1];
                v[j-1]=v[j];
                v[j]=aux2;
                hubocambio=1;
            }
        i++;
    }while(hubocambio);
}

void Listado1(T_Auto v[],float b[],int ce)
{
    int i;
    printf("\n\t\tRECAUDACION POR AUTOMOVIL\n");
    printf("\nPATENTE DEL AUTO\t\t\tRECAUDACION\n");
    for(i=0;i<=ce-1;i++)
        if(b[i]>0)
            printf("\n%s\t\t\t\t\t$ %.2f\n",v[i].nropatente,b[i]);
}

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

T_Fecha IngrFechaVal()
{
    T_Fecha f;
    do
    {
        printf("\nIngrese fecha\n");
        printf("\nIngrese dia (del 1 al 30): ");
        scanf("%d",&f.dia);
        printf("\nIngrese mes: ");
        scanf("%d",&f.mes);
        printf("\nIngrese anio (2011 o 2012): ");
        scanf("%d",&f.anio);
    }while(esDatoVal(f.dia,1,30)==0||esDatoVal(f.mes,1,12)==0||esDatoVal(f.anio,2011,2012)==0);
    return f;
}

void Listado2(T_Auto v[],char m[][30],T_Fecha fecha,int f,int c)
{
    int i,j,k;
    fecha=IngrFechaVal();
    printf("\n\t\t\t\tLISTADO AL %d/%d/%d\n",fecha.dia,fecha.mes,fecha.anio);
    printf("\nPATENTE AUTO/DIA\n\n");
    for(k=0;k<=c-1;k++)
        printf(" %d",k+1);
    printf("\n");
    for(i=0;i<=f-1;i++)
    {
        printf("\n%s\t",v[i].nropatente);
        for(j=0;j<=c-1;j++)
            printf("%c  ",m[i][j]);
        printf("\n");
    }
}

void Grabar(T_Auto v[],char m[][30],int f,int c)
{
    FILE *pf;
    T_Cant aux;
    int i,j,s;
    pf=fopen("CANTIDAD.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<=f-1;i++)
    {
        s=0;
        for(j=0;j<=c-1;j++)
            if(m[i][j]==' ');
                s++;
        strcpy(aux.nropatente,v[i].nropatente);
        strcpy(aux.propietario,v[i].propietario);
        aux.cant=s;
        fwrite(&aux,sizeof(T_Cant),1,pf);
    }
    fclose(pf);
}


