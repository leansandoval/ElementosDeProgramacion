#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct
{
    int codart,stock;
    char descrip[51];
}TInfo;

void GeneraArch();
void MostrarArch();

int main()
{
    char opcion;
    printf("\n1 - GENERAR\n2 - LECTRURA\n3 - FIN\n");
    do
    {
        do
        {
            printf("\nIngrese la opcion elegida: ");
            scanf("%d",&opcion);
        }while(!(opcion>=1&&opcion<=3));
        switch(opcion)
        {
            case 1:GeneraArch();break;
            case 2:MostrarArch();break;
        }
    }while(opcion!=3);
}

void GeneraArch()
{
    FILE *pf;
    TInfo aux;
    int codart,i;
    pf=fopen("STOCK.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<10;i++)
    {
        printf("\nPRODUCTO NUMERO %d\n",i+1);
        do
        {
            printf("\nIngrese codigo de articulo: ");
            scanf("%d",&aux.codart);
        }while(!(aux.codart>0));
        printf("\nIngrese descripcion: ");
        fflush(stdin);
        gets(aux.descrip);
        do
        {
            printf("\nIngrese stock: ");
            scanf("%d",&aux.stock);
        }while(!(aux.stock>0));
        fwrite(&aux,sizeof(TInfo),1,pf);
    }
    fclose(pf);
}

void MostrarArch()
{
    FILE *pf;
    TInfo aux;
    pf=fopen("STOCK.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(TInfo),1,pf);
    printf("\nCODIGO DE ARTICULO\tDESCRIPCION\t\tSTOCK\n");
    while(!feof(pf))
    {
        printf("\n\t%d\t\t%-21s\t%d\n",aux.codart,aux.descrip,aux.stock);
        fread(&aux,sizeof(TInfo),1,pf);
    }
    fclose(pf);
}
