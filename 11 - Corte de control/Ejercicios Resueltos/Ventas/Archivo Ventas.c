#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

typedef struct
{
    int numfactura,numvendedor;
    float importe;
}T_Ventas;

void GeneraArchivoVentas();
void LecturaArchivoVentas();

int main()
{
    int opcion;
    printf("\nARCHIVO VENTAS\n");
    printf("\n1 - GENERA\t2 - LECTURA\t3 - FIN\n");
    do
    {
        do
        {
            printf("\nIngrese una opcion: ");
            scanf("%d",&opcion);
        }while(!(opcion>=1&&opcion<=3));
        switch(opcion)
        {
            case 1:GeneraArchivoVentas();break;
            case 2:LecturaArchivoVentas();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
}

void GeneraArchivoVentas()
{
    FILE *pf;
    T_Ventas aux;
    char opcion='S';
    pf=fopen("VENTAS.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    while(opcion!='N'&&opcion!='n')
    {
        do
        {
            printf("\nIngrese numero de factura: ");
            scanf("%d",&aux.numfactura);
        }while(!(aux.numfactura>0));
        do
        {
            printf("\nNumero de vendedor: ");
            scanf("%d",&aux.numvendedor);
        }while(!(aux.numvendedor>0));
        do
        {
            printf("\nIngrese importe: ");
            scanf("%f",&aux.importe);
        }while(!(aux.importe>0));
        fwrite(&aux,sizeof(T_Ventas),1,pf);
        printf("\n-----DATOS VALIDADOS CORRECTAMENTE-----\n");
        do
        {
            printf("\n¿Desea agregar mas datos? ('S' - Si, 'N' - No): ");
            fflush(stdin);
            scanf("%c",&opcion);
        }while(!(opcion=='N'||opcion=='n'||opcion=='S'||opcion=='s'));
    }
    fclose(pf);
}

void LecturaArchivoVentas()
{
    FILE *pf;
    T_Ventas aux;
    pf=fopen("VENTAS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Ventas),1,pf);
    printf("\nFACTURA\t\tVENDEDOR\tIMPORTE\n");
    while(!feof(pf))
    {
        printf("\n%d\t\t%d\t\t$ %.2f\n",aux.numfactura,aux.numvendedor,aux.importe);
        fread(&aux,sizeof(T_Ventas),1,pf);
    }
    fclose(pf);
}
