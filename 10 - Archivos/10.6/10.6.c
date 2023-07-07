#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
    int codigoarticulo,cant;
}TFaltantes;

void MostrarArchPedidos();

int main()
{
    FILE *pf;
    FILE *pe;
    TFaltantes aux;
    int sumcant,codart;
    pf=fopen("FALTANTES.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    pe=fopen("PEDIDOS.dat","wb");
    if(pe==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(TFaltantes),1,pf);
    while(!feof(pf))
    {
        codart=aux.codigoarticulo;
        sumcant=0;
        while(codart==aux.codigoarticulo&&!feof(pf))
        {
            sumcant+=aux.cant;
            fwrite(&aux,sizeof(TFaltantes),1,pe);
            fread(&aux,sizeof(TFaltantes),1,pf);
        }
    }
    fclose(pf);
    fclose(pe);
    MostrarArchPedidos();
}

void MostrarArchPedidos()
{
    FILE *pf;
    TFaltantes aux;
    pf=fopen("PEDIDOS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(TFaltantes),1,pf);
    printf("\n\tPEDIDOS\n");
    printf("\nCODIGO DE ARTICULO\tCANTIDAD\n");
    while(!feof(pf))
    {
        printf("\n\t%d\t\t\t%d\n",aux.codigoarticulo,aux.cant);
        fread(&aux,sizeof(TFaltantes),1,pf);
    }
    fclose(pf);
}
