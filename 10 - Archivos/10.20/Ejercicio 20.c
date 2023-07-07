#include <stdio.h>
#include <stdlib.h>

typedef struct{int cloc,cprov,czg;}T_Geo;

typedef struct{int cl;
                float peso;
                }T_Enc;

void PonerEnCeroInt (int [],int);
void PonerEnCeroFloat (float [],int);
int CargarArch (T_Geo [],int);
int Busqueda (T_Geo [],int,int);
void ProcesarArch (T_Geo [],int,int[],float[],int[]);
int MinimaEncom(int [],int);
void MostrarLocMin(T_Geo [],int,int);
void Mostrar(int[],float [],int);
void MostrarProv(int [],int,int);

int main()
{
    T_Geo VGeo[200];
    int VCant[9],VProv[24],cant,min;
    float VKilos[9];
    PonerEnCeroFloat(VKilos,9);
    PonerEnCeroInt(VProv,24);
    PonerEnCeroInt(VCant,9);
    cant=CargarArch(VGeo,200);
    ProcesarArch(VGeo,cant,VCant,VKilos,VProv);
    min=MinimaEncom(VCant,9);
    MostrarLocMin(VGeo,cant,min);
    printf("\n ZONA\t\t\t\t TOTAL DE KILOS");
    Mostrar(VCant,VKilos,9);
    printf("\n Provincias que no recibieron encomiendas: ");
    MostrarProv(VProv,24,0);
}
void PonerEnCeroFloat(float V[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        V[i]=0;
}
void PonerEnCeroInt(int V[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        V[i]=0;
}

int CargarArch (T_Geo V[],int ce)
{
    FILE *pf;
    T_Geo aux;
    int i=0;
    pf=fopen("GEOGRA.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    fread(&aux,sizeof(T_Geo),1,pf);
    while(!feof(pf) && i<ce)
    {
        V[i]=aux;
        i++;
        fread(&aux,sizeof(T_Geo),1,pf);
    }

    fclose(pf);
    return(i);
}
int Busqueda(T_Geo V[],int ce,int x)
{
    int i=0;
    while(V[i].cloc!=x && i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return i;
}
void ProcesarArch(T_Geo V[], int cant, int VC[], float VK[], int VP[])
{
    FILE *pf,*ss;
    T_Enc aux;
    int pos;
    pf=fopen("ENCOM.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit (1);
    }

    ss=fopen("ERROR.dat","wb");
    if(ss==NULL)
     {
        printf("\nNo abrio el archivo...");
        exit (1);
    }
    fread(&aux,sizeof(T_Enc),1,pf);
    while(!feof(pf))
    {
        pos=Busqueda(V,cant,aux.cl);
        if(pos!=-1)
            {VC[V[pos].czg-1]++;
            VK[V[pos].czg-1]+=aux.peso;
            VP[V[pos].cprov-1]=1;
            }
        else
            fwrite(&aux,sizeof(T_Enc),1,ss);
        fread(&aux,sizeof(T_Enc),1,pf);
    }
    fclose(pf);
    fclose(ss);
}
int MinimaEncom(int V[],int ce)
{
    int m,i;
    m=V[0];
    for(i=0;i<ce;i++)
    {
        if(V[i]<m)
            m=V[i];
    }
    return m;

}

void MostrarLocMin(T_Geo V[], int ce,int x)
{
    int i;
    for(i=0;i<ce;i++)
        {if(V[i].czg==x)
            printf("\n%d",V[i].cloc);
        }
}
void Mostrar(int VC[],float VK[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        printf("\n %d \t\t\t\t %f",VC[i],VK[i]);
}
void MostrarProv(int V[],int ce,int x)
{
    int i;
    for(i=0;i<ce;i++)
        {if(V[i]==x)
            printf("\n%d",i+1);
        }
}
