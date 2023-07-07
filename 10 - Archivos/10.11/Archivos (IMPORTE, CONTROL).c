#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define max1 5
#define max2 10

typedef struct
{
    int anioImpuesto,bimestre;
    float importe;
}T_Importes;

typedef struct
{
    int nroContri,anioImpuesto,bimestre;
}T_Control;

void GeneraArchivoImportes();
void GeneraArchivoControl();
void LecturaArchivoImportes();
void LecturaArchivoControl();

int main()
{
    int opcion;
    printf("\nARCHIVO IMPORTES\n");
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
            case 1:GeneraArchivoImportes();break;
            case 2:LecturaArchivoImportes();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
    system("cls");
    printf("\nARCHIVO CONTROL\n");
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
            case 1:GeneraArchivoControl();break;
            case 2:LecturaArchivoControl();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
}

void GeneraArchivoImportes()
{
    T_Importes imp;
    FILE * pf;
    int i;
    pf=fopen("IMPORTES.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo se abrio el archivo..");
        exit(1);
    }
    printf("\n----IMPORTES----\n");
    for(i=0;i<=max1-1;i++)
    {
        do
        {
            printf("\nIngrese el anio de impuesto: ");
            scanf("%d",&imp.anioImpuesto);
        }while(!(imp.anioImpuesto>=2017&&imp.anioImpuesto<=2020));
        do
        {
            printf("\nIngrese el bimestre: ");
            scanf("%d",&imp.bimestre);
        }while(!(imp.bimestre>=1&&imp.bimestre<=6));
        do
        {
            printf("\nIngrese el importe: ");
            scanf("%f",&imp.importe);
        }while(!(imp.importe>0));
        fwrite(&imp,sizeof(T_Importes),1,pf);
        printf("\n---Datos Validados correctamente---\n");
    }
    fclose(pf);
}

void LecturaArchivoImportes()
{
    FILE *pf;
    T_Importes imp;
    pf=fopen("IMPORTES.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&imp,sizeof(T_Importes),1,pf);
    printf("\n\t------------IMPORTES------------\n");
    printf("\n\tANIO IMPUESTO\tBIMESTRE\tIMPORTE\n");
    while(!feof(pf))
    {
        printf("\n\t%d\t\t%d\t\t%.2f\n",imp.anioImpuesto,imp.bimestre,imp.importe);
        fread(&imp,sizeof(T_Importes),1,pf);
    }
    fclose(pf);
}

void GeneraArchivoControl()
{
    T_Control cont;
    FILE *pf;
    int i;
    pf=fopen("CONTROL.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo se abrio el archivo..");
        exit(1);
    }
    printf("\n------CONTROL------\n");
    for(i=0;i<=max2-1;i++)
    {
        printf("\nCONTRIBUYENTE NUMERO %d\n",i+1);
        cont.nroContri=i+1;
        do
        {
            printf("\nIngrese el anio de impuesto: ");
            scanf("%d",&cont.anioImpuesto);
        }while(!(cont.anioImpuesto>=2017&&cont.anioImpuesto<=2020));
        do
        {
            printf("\nIngrese el bimestre: ");
            scanf("%d",&cont.bimestre);
        }while(!(cont.bimestre>=1&&cont.bimestre<=6));
        fwrite(&cont,sizeof(T_Control),1,pf);
        printf("\n----Datos Validados correctamente----\n");
    }
    fclose(pf);
}

void LecturaArchivoControl()
{
    FILE *pf;
    T_Control cont;
    pf=fopen("CONTROL.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&cont,sizeof(T_Control),1,pf);
    printf("\n\t----------CONTROL----------\n");
    printf("\nNRO. CONTRIBUYENTE\tANIO IMPUESTO\tBIMESTRE\n");
    while(!feof(pf))
    {
        printf("\n\t%d\t\t%d\t\t%d\n",cont.nroContri,cont.anioImpuesto,cont.bimestre);
        fread(&cont,sizeof(T_Control),1,pf);
    }
    fclose(pf);
}
