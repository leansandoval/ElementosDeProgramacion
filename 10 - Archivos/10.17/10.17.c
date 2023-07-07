#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

typedef struct
{
    char CodLoc[11];
    int Mes;
    float Temp;
}T_Temp;

typedef struct
{
    char CodLoc[11],DescLoc[51];
}T_Loca;

typedef struct
{
    char CodLoc[11];
    int mes;
    float promedio;
}T_Prom;

void PonerEnCeroFloat(float[],int);
void PonerMatEnCeroFloat(float[][12],int,int);
void PonerMatEnCeroInt(int[][12],int,int);
void CargaLocalidad(char[][11],int);
int Busqueda(char[][11],int,char[]);
void MostrarMatPorFilaFloat(float[][12],char[][11],float[],int,int);
void Promedio(float[][12],int[][12],int,int);
void GeneraArchivoPromedios(float[][12],char[][11],int,int);
void LecturaArchivoPromedios();

int main()
{
    FILE *pf;
    T_Temp aux;
    int MTempCon[5][12],pos;
    float MTempAc[5][12],VVar[5];
    char VLoc[5][11];
    PonerEnCeroFloat(VVar,5);
    PonerMatEnCeroFloat(MTempAc,5,12);
    PonerMatEnCeroInt(MTempCon,5,12);
    CargaLocalidad(VLoc,5);
    pf=fopen("TEMPERATURAS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Temp),1,pf);
    while(!feof(pf))
    {
        pos=Busqueda(VLoc,5,aux.CodLoc);
        MTempAc[pos][aux.Mes-1]+=aux.Temp;
        MTempCon[pos][aux.Mes-1]++;
        fread(&aux,sizeof(T_Temp),1,pf);
    }
    fclose(pf);
    Promedio(MTempAc,MTempCon,5,12);
    MostrarMatPorFilaFloat(MTempAc,VLoc,VVar,5,12);
    GeneraArchivoPromedios(MTempAc,VLoc,5,12);
    LecturaArchivoPromedios();
    printf("\n");
    system("pause");
}

void PonerEnCeroFloat(float v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void PonerMatEnCeroInt(int m[][12],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            m[i][j]=0;
}

void PonerMatEnCeroFloat(float m[][12],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            m[i][j]=0;
}

void CargaLocalidad(char c[][11],int ce)
{
    FILE *pf;
    T_Loca aux;
    int i;
    pf=fopen("LOCALIDADES.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Loca),1,pf);
    for(i=0;i<=ce-1;i++)
    {
        strcpy(c[i],aux.CodLoc);
        fread(&aux,sizeof(T_Loca),1,pf);
    }
    fclose(pf);
}

int Busqueda(char c[][11],int f,char aux[])
{
    int i=0,pos=-1;
    while(pos==-1&&i<f)
    {
        if(strcmpi(c[i],aux)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}

void MostrarMatPorFilaFloat(float m[][12],char a[][11],float b[],int f,int c)
{
    int i,j;
    printf("\nLocalidad\tEne\tFeb\tMar\tAbr\tMay\tJun\tJul\tAgo\tSep\tOct\tNov\t\tDic\tVARIACION TERMICA\n");
    for(i=0;i<=f-1;i++)
    {
        printf("\n%-11s\t",a[i]);
        for(j=0;j<=c-1;j++)
            if(m[i][j]!=0)
                printf("%.2f\t",m[i][j]);
            else
                printf("?\t");
        printf("\t%.2f\n",b[i]);
    }
}

void Promedio(float a[][12],int b[][12],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            if(b[i][j]>0)
                a[i][j]=(float)a[i][j]/b[i][j];
}

void GeneraArchivoPromedios(float m[][12],char a[][11],int f,int c)
{
    FILE *pf;
    T_Prom aux;
    int i,j;
    pf=fopen("PROMEDIOS.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<=f-1;i++)
    {
        for(j=0;j<=c-1;j++)
            if(m[i][j]!=0)
                {
                    strcpy(aux.CodLoc,a[i]);
                    aux.promedio=m[i][j];
                    aux.mes=j+1;
                }
        fwrite(&aux,sizeof(T_Prom),1,pf);
    }
    fclose(pf);
}

void LecturaArchivoPromedios()
{
    FILE *pf;
    T_Prom aux;
    pf=fopen("PROMEDIOS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Prom),1,pf);
    printf("\nCODIGO DE LOCALIDAD\tMES\tPROMEDIO\n");
    while(!feof(pf))
    {
        printf("\n\t%s\t\t%d\t%.2f\n",aux.CodLoc,aux.mes,aux.promedio);
        fread(&aux,sizeof(T_Prom),1,pf);
    }
    fclose(pf);
}
