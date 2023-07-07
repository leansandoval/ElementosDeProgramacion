#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char CodigoProvincia[4],NombreProvincia[31];
}T_Prov;

typedef struct
{
    char CodigoProvincia[4];
    int nacionalidad,canthabitantes;
}T_Cen;

typedef struct
{
    char CodigoMod,CodigoProvincia[4];
    int nacionalidad,cant;
}T_Mod;

void PonerEnCeroM(int[][50],int,int);
void PonerEnCeroV(int[],int);
void CargaArch(T_Prov[],int);
int Busqueda(T_Prov[],int,char[]);
void CargaMatArch(int[][50],T_Prov[],int);
void ActualizaArch(int[][50],T_Prov[],int);
void GrabarArchMat(int[][50],int,int,T_Prov[]);
void SumarFilaMatEnV(int[][50],int[],int,int);
void Ordenar(T_Prov[],int[],int);
void MostrarVectPar(T_Prov[],int[],int);

int main()
{
    T_Prov VProv[24];
    int Mat[24][50],VHab[24];
    PonerEnCeroM(Mat,24,50);
    PonerEnCeroV(VHab,24);
    CargaArch(VProv,24);
    CargaMatArch(Mat,VProv,24);
    ActualizaArch(Mat,VProv,24);
    GrabarArchMat(Mat,24,50,VProv);
    SumarFilaMatEnV(Mat,VHab,24,50);
    Ordenar(VProv,VHab,24);
    MostrarVectPar(VProv,VHab,24);
}

void PonerEnCeroV(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
}

void PonerEnCeroM (int m[][50],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
}

void CargaArch(T_Prov v[],int ce)
{
    FILE *pf;
    T_Prov aux;
    int i=0;
    pf=fopen("PROVINCIAS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Prov),1,pf);
    while(!feof(pf) && i<ce)
    {
        v[i]=aux;
        i++;
        fread(&aux,sizeof(T_Prov),1,pf);
    }
    fclose(pf);
}

void CargaMatArch (int m[][50],T_Prov v[],int f)
{
    FILE *pf;
    T_Cen aux;
    int pos;
    pf=fopen("CENSO.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Cen),1,pf);
    while(!feof(pf))
    {
        pos=Busqueda(v,f,aux.CodigoProvincia);
        if(pos!=-1)
            m[pos][aux.nacionalidad-1]=aux.canthabitantes;
        fread(&aux,sizeof(T_Cen),1,pf);
    }
    fclose(pf);
}

void AcutalizaArch(int m[][50],T_Prov v[],int f)
{
    FILE *pf;
    T_Mod aux;
    int pos;
    pf=fopen("MODIF_CENSO.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Mod),1,pf);
    while(!feof(pf))
    {
        pos=Busqueda(v,f,aux.CodigoProvincia);
        if(pos!=-1)
            if(aux.CodigoMod=='A')
                m[pos][aux.nacionalidad-1]+=aux.cant;
            else
                m[pos][aux.nacionalidad-1]=aux.cant;
        fread(&aux,sizeof(T_Mod),1,pf);
    }
    fclose(pf);
}

void GrabarArchMat(int m[][50],int f,int c,T_Prov v[])  //Grabar un archivo desde la matriz
{
    FILE *arch;
    T_Cen reg;
    int i,j;
    arch=fopen("Censo_Act","wb");
    if(arch==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            if(m[i][j]!=0)
                {
                    strcpy(reg.CodigoProvincia,v[i].CodigoProvincia);
                    reg.nacionalidad=j+1;
                    reg.canthabitantes=m[i][j];
                    fwrite(&reg,sizeof(T_Cen),1,arch);
                }
    fclose(arch);
}

int Busqueda(T_Prov v[],int ce,char x[])
{
    int i=0;
    while(strcmpi(v[i].CodigoProvincia,x)!=0&&i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return i;
}

void SumarFilaMatEnV(int m[][50],int v[],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            v[i]+=m[i][j];
}

void Ordenar(T_Prov b[],int a[],int ce)
{
    int i=0,j,hubocambio,aux;
    T_Prov aux2;
    do
    {
        hubocambio=0;
        for(j=1;j<ce-i;j++)
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
    }while(hubocambio);
}

void MostrarVectPar(T_Prov v[],int a[],int ce)
{
    int i;
    printf("\nProvincia\tTotal de habitantes\n");
    for(i=0;i<=ce-1;i++)
        printf("\n%-31s\t%d\n",v[i].NombreProvincia,a[i]);
}
