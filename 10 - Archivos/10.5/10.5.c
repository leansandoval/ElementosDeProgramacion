#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
    int codigoarticulo,stock;
    char descripcion[51];
}TInfo;

typedef struct
{
    int codigoarticulo,cant;
}TFal;


void CargaArch(TInfo[],int);
int Busqueda(TInfo[],int,int);
void ActualizaArch(TInfo[],int);
void MostrarArchStock();
void MostrarArchFaltantes();

int main()
{
    FILE *arch;
    TFal aux;
    TInfo VStock[10];
    CargaArch(VStock,10);
    int pos,cantnovend;
    arch=fopen("FALTANTES.dat","wb");
    if(arch==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    do
    {
        printf("\nIngrese codigo de articulo (0 para terminar): ");
        scanf("%d",&aux.codigoarticulo);
        pos=Busqueda(VStock,10,aux.codigoarticulo);
        if(pos==-1&&aux.codigoarticulo!=0)
            printf("\nCodigo de articulo inexistente\n");
    }while(pos==-1&&aux.codigoarticulo!=0);
    while(aux.codigoarticulo!=0)
    {
        do
        {
            printf("\nIngrese la cantidad de ventas que se realizo: ");
            scanf("%d",&aux.cant);
        }while(!(aux.cant>0));
        if(VStock[pos].stock>=aux.cant)
            VStock[pos].stock-=aux.cant;
        else
        {
            cantnovend=aux.cant-VStock[pos].stock;
            VStock[pos].stock=0;
            aux.cant=cantnovend;
            fwrite(&aux,sizeof(TFal),1,arch);
        }
        do
        {
            printf("\nIngrese codigo de articulo (0 para terminar): ");
            scanf("%d",&aux.codigoarticulo);
            pos=Busqueda(VStock,10,aux.codigoarticulo);
            if(pos==-1&&aux.codigoarticulo!=0)
                printf("\nCodigo de articulo inexistente\n");
        }while(pos==-1&&aux.codigoarticulo!=0);
    }
    fclose(arch);
    ActualizaArch(VStock,10);
    MostrarArchStock();
    MostrarArchFaltantes();
}

void CargaArch(TInfo v[],int ce)
{
    FILE *pf;
    TInfo aux;
    int i=0;
    pf=fopen("STOCK.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(TInfo),1,pf);
    while(!feof(pf)&&i<ce)
    {
        v[i]=aux;
        i++;
        fread(&aux,sizeof(TInfo),1,pf);
    }
    fclose(pf);
}

int Busqueda(TInfo v[],int ce,int x)
{
    int pos=-1,i=0;
    while(pos==-1&&i<ce)
        if(v[i].codigoarticulo==x)
            pos=i;
        else
            i++;
    return pos;
}

void ActualizaArch(TInfo v[],int ce)
{
    FILE *pf;
    int i;
    pf=fopen("STOCKACT.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<=ce-1;i++)
            fwrite(&v[i],sizeof(TInfo),1,pf);
    fclose(pf);
}

void MostrarArchStock()
{
    FILE *pf;
    TInfo aux;
    pf=fopen("STOCKACT.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(TInfo),1,pf);
    printf("\n\tSTOCK ACTUALIZADOS\n");
    printf("\nCODIGO DE ARTICULO\tDESCRIPCION\tSTOCK\n");
    while(!feof(pf))
    {
        printf("\n\t%d\t\t%s\t%d\n",aux.codigoarticulo,aux.descripcion,aux.stock);
        fread(&aux,sizeof(TInfo),1,pf);
    }
    fclose(pf);
}

void MostrarArchFaltantes()
{
    FILE *pf;
    TFal aux;
    pf=fopen("FALTANTES.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(TFal),1,pf);
    printf("\n\tVENTAS NO CONCRETADAS\n");
    printf("\nCODIGO DE ARTICULO\tCANTIDAD NO VENDIDA\n");
    while(!feof(pf))
    {
        printf("\n\t%d\t\t\t%d\n",aux.codigoarticulo,aux.cant);
        fread(&aux,sizeof(TFal),1,pf);
    }
    fclose(pf);
}
