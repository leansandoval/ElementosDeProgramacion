#include<stdio.h>
#include<windows.h>
#define tamanio 300

int esDatoVal(int,int,int);
int esClaseVal(char,char,char);
int IngrDatoVal(int,int);
char IngrClaseVal(char,char);

void PonerEnCero(int[],int);
void CargaVecArticulos (int[],char[],int[],int[],int[],int);

int Buscar(int[],int,int);
void MostarVec(int[],char[],int[],int[],int[],int);
void GeneraVB(int[],int[],int[],int);
void MostarVecEj(int[],int[],int[],int);


int main()
{
    int VCod[tamanio],VNumDeposito[tamanio],VStock[tamanio],VRepos[tamanio],VB[tamanio],VC[tamanio],VD[tamanio];
    char VClase[tamanio];
    PonerEnCero(VStock,tamanio);
    PonerEnCero(VB,tamanio);
    PonerEnCero(VC,tamanio);
    PonerEnCero(VD,tamanio);

    CargaVecArticulos(VCod,VClase,VNumDeposito,VStock,VRepos,tamanio);
    MostarVec(VCod,VClase,VNumDeposito,VStock,VRepos,tamanio);

    GeneraVB(VCod,VStock,VB,tamanio);
    GeneraVC(VCod,VStock,VRepos,VC,tamanio);
    GeneraVD(VCod,VNumDeposito,VD,tamanio);
    MostarVecEj(VB,VC,VD,tamanio);

    printf("\n\n");
    system("pause");
    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////

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
            printf("\nDato incorrecto");
            printf("\n");
        }
        band=1;
        printf("\nDato ingresado entre %d y %d: ",limi,lims);
        scanf("%d",&dato);
    }while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

int esClaseVal (char x,char limi,char lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

char IngrClaseVal(char limi,char lims)
{
    int band=0;
    char clase;
    do
    {
        if(band==1)
        {
            printf("\nClase incorrecta");
            printf("\n");
        }
        band=1;
        printf("\nIngrese codigo de articulo ('A' 'B' 'C' o 'D'): ");
        fflush(stdin);
        scanf("%c",&clase);
    }while(esClaseVal(clase,limi,lims)==0);
    return clase;
}

///////////////////////////////////////////////////////////////////////////////

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void CargaVecArticulos(int v[],char c[],int n[],int s[],int r[],int ce)
{
    int i,cod,numdeposito,stock,repos,pos,aux;
    char clase;
    for(i=0;i<=ce-1;i++)
    {
        printf("\nIngrese codigo del producto");
        printf("\n");
        cod=IngrDatoVal(1,500);
        aux=cod;
        pos=Buscar(v,aux,i);
        if(pos!=-1)
            {
                printf("\nDato duplicado. Ingrese otro");
                printf("\n");
                cod=IngrDatoVal(1,500);
            }
        clase=IngrClaseVal('A','D');
        printf("\nNUMERO DE DEPOSITO");
        printf("\n");
        numdeposito=IngrDatoVal(1,100);
        printf("\nSTOCK");
        printf("\n");
        stock=IngrDatoVal(0,2000);
        printf("\nPUNTO DE REPOSICION");
        printf("\n");
        repos=IngrDatoVal(500,1000);
        v[i]=cod;
        c[i]=clase;
        n[i]=numdeposito;
        s[i]=stock;
        r[i]=repos;
    }
}

///////////////////////////////////////////////////////////////////////////////

void MostarVec(int v[],char c[],int n[],int s[],int r[],int ce)
{
    int i;
    printf("\nCOD. DE ART.\tCLASE DE ART.\tNUM. DE DEPOSITO\tSTOCK\tPTO. DE REPOS.");
    for(i=0;i<=ce-1;i++)
        printf("\n\t%d\t\t%c\t\t%d\t\t%d\t\t%d\t\t",v[i],c[i],n[i],s[i],r[i]);
}

int Buscar (int v[],int dato,int ce)
{
    int i=0,pos=-1;
    while(pos==-1&&i<ce)
    {
        if(v[i]==dato)
            pos=1;
        i++;
    }
    return pos;
}

///////////////////////////////////////////////////////////////////////////////

void GeneraVB (int v[], int s[], int b[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
    {
        if(s[i]==0)
            b[i]=v[i];
    }
}

void GeneraVC (int v[],int s[],int r[],int c[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
    {
        if(s[i]<r[i])
            c[i]=v[i];
    }
}

void GeneraVD (int v[],int n[],int d[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(n[i]>=15&&n[i]<=50)
            d[i]=v[i];
}

void MostarVecEj(int b[],int c[],int d[],int ce)
{
    int i;
    printf("\nVB\tVC\tVD");
    for(i=0;i<=ce-1;i++)
        printf("\n%d\t%d\t%d",b[i],c[i],d[i]);
}

