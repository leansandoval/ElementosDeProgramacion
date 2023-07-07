/*7.2.9 Se desea contabilizar los votos recibidos en las elecciones de un club de fútbol. Existen 10 candidatos cada
uno representado por un número de lista diferente (número de 3 cifras no correlativo). La votación se realiza
en 15 sedes distintas codificadas del 1 al 15. Se ingresan los votos registrados en cada una de las sedes
registrando:

    • Número de lista
    • Número de sede
    • Cantidad de votos

(Solo se informan candidatos que recibieron votos).
La carga de votos finaliza con un número de lista igual a 0
Mostrar:

a. Cantidad de votos recibidos por cada candidato en cada sede.
                                    LISTA   SEDE1   SEDE2   SEDE3   …   SEDE15
                                    873     36      78      99      …   XX
                                    735     XX      XX      XXX     …   XX

b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato:
                                        TOTAL DE VOTOS  PORCENTAJE  LISTA
                                            800             80%     873
                                            200             20%     735

c. Candidatos que NO recibieron votos en la sede 5.*/

#include<stdio.h>
#include<windows.h>

int esDatoVal(int,int,int);
int esDatoVal2(int,int);
int IngrDatoVal(int,int);
int IngrDatoVal2(int);
void CargaVec(int[],int);
void PonerEnCero(int[],int);
void MostrarVec (int[],int);
void PonerMatEnCero(int[][15],int,int);
int BusquedaSec(int[],int,int);
void MostrarMatFila(int[][15],int,int,int[],int);
void CargaMat(int[][15],int,int,int[],int);
void SumarFilaMatEnV(int[][15],int[],int,int);
void MostrarVotosTotales(int[],int[],int);
void Burbujeo(int[],int[],int);
void MostrarListaNoVotSec5(int[][15],int,int,int[],int);

int main()
{
    int VCandidatos[10],MElecciones[10][15],VSumaCandidatos[10];
    CargaVec(VCandidatos,10);
    PonerEnCero(VSumaCandidatos,10);
    PonerMatEnCero(MElecciones,10,15);
    CargaMat(MElecciones,10,15,VCandidatos,10);
    MostrarMatFila(MElecciones,10,15,VCandidatos,10);
    SumarFilaMatEnV(MElecciones,VSumaCandidatos,10,15);
    MostrarListaNoVotSec5(MElecciones,10,15,VCandidatos,10);
    Burbujeo(VSumaCandidatos,VCandidatos,10);
    MostrarVotosTotales(VSumaCandidatos,VCandidatos,10);
    return 0;
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
    if(x>=lim)
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
            printf("\nDato incorrecto, ingrese nuevamente.\n");
        band=1;
        scanf("%d",&dato);
    }
    while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

int IngrDatoVal2(int lim)
{
    int dato,band=0;
    do
    {
        if(band==1)
            printf("\nDato incorrecto, ingrese nuevamente.\n");
        band=1;
        printf("\nIngrese la cantidad de VOTOS registrados (%d para terminar): ",lim);
        scanf("%d",&dato);
    }
    while(esDatoVal2(dato,lim)==0);
    return dato;
}

void CargaVec(int v[],int ce)
{
    int i,candidato,pos;
    for(i=0; i<=ce-1; i++)
    {
        do
        {
            printf("\nIngrese NUMERO DE CANDIDATO (3 digitos) candidato numero %d: ",i+1);
            candidato=IngrDatoVal(100,999);
            pos=BusquedaSec(v,i,candidato);
            if(pos!=-1)
                printf("\nEl numero de candidato fue ingresado anteriormente, ingrese otro\n");
        }
        while(pos!=-1);
        v[i]=candidato;
    }
}

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0; i<=ce-1; i++)
        v[i]=0;
}

void MostrarVec(int v[],int ce)
{
    int i;
    for(i=0; i<=ce-1; i++)
        printf("\n%d",v[i]);
}

void PonerMatEnCero (int m[][15],int f,int c)
{
    int i,j;
    for(i=0; i<=f-1; i++)
        for(j=0; j<=c-1; j++)
            m[i][j]=0;
}

int BusquedaSec (int v[],int ce,int x)
{
    int i=0,p=-1;
    while(p==-1&&i<ce)
        if(v[i]==x)
            p=i;
        else
            i++;
    return p;
}

void MostrarMatFila(int m[][15],int f,int c,int v[],int ce)
{
    int i,j;
    printf("\nLISTA\tSEDE 1\tSEDE 2\tSEDE 3\tSEDE 4\tSEDE 5\tSEDE 6\tSEDE 7\tSEDE 8\tSEDE 9\tSEDE 10\tSEDE 11\tSEDE 12\tSEDE 13\tSEDE 14\tSEDE 15\n");
    for(i=0; i<=f-1; i++)
    {
        printf("\n%d\t",v[i]);
        for(j=0; j<=c-1; j++)
            printf("%d\t",m[i][j]);
    }
    printf("\n");
}

void CargaMat (int m[][15],int f,int c,int v[],int ce)
{
    int voto,candidato,sede,pos;
    voto=IngrDatoVal2(0);
    while(voto!=0)
    {
        printf("\nNUMERO DE CANDIDATO de la lista a la que le corresponde los votos ingresados: ");
        candidato=IngrDatoVal(100,999);
        pos=BusquedaSec(v,ce,candidato);
        if(pos!=-1)
        {
            printf("\nIngrese a la SEDE a la que se le asignara los votos: ");
            sede=IngrDatoVal(1,15);
            if(m[pos][sede-1]==0)
                m[pos][sede-1]=voto;
            else
                printf("\nYa fue ingresado anteriormente votos en esta sede\n");
            voto=IngrDatoVal2(0);
        }
        else
        {
            printf("\nEl numero de candidato ingresado no aparece en la lista, ingrese nuevamente\n");
            voto=IngrDatoVal2(0);
        }
    }
}

void SumarFilaMatEnV (int m[][15],int v[],int f,int c)
{
    int i,j;
    for(i=0; i<=f-1; i++)
        for(j=0; j<=c-1; j++)
            v[i]+=m[i][j];
}

void MostrarVotosTotales(int a[],int b[],int ce)
{
    int i;
    printf("\nTOTAL DE VOTOS\tPORCENTAJE\tLISTA\n");
    for(i=0; i<=ce-1; i++)
        printf("\n\t%d\t%.2f\t\t%d",a[i],(float)a[i]/100,b[i]);
}

void Burbujeo (int a[],int b[],int ce)
{
    int i=0,hubocambio,j,aux,aux2;
    do
    {
        hubocambio=0;
        for(j=0; j<ce-i; j++)
            if(a[j-1]<a[j])
            {
                aux=a[j-1];
                a[j-1]=a[j];
                a[j]=aux;
                aux2=b[j-1];
                b[j-1]=b[j];
                b[j]=aux2;
                hubocambio=1;
            }
        i++;
    }
    while(hubocambio);
}

void MostrarListaNoVotSec5(int m[][15],int f,int c,int v[],int ce)
{
    int i;
    printf("\nCandidatos que no recibieron votos en la sede 5\n");
    for(i=0; i<=f-1; i++)
        if(m[i][4]==0)
            printf("\n%d",v[i]);
}
