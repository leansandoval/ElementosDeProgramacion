#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
    char nropatente[11],propietario[21];
}T_Auto;

typedef struct
{
    char nropatente[7];
    int dia;
    float importe;
}T_Alquiler;

void GeneraArchivoAuto();
void LecturaArchivoAuto();
void GeneraArchivoAlquiler();
void LecturaArchivoAlquiler();

int main()
{
    int opcion;
    printf("\nARCHIVO AUTO\n");
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
            case 1:GeneraArchivoAuto();break;
            case 2:LecturaArchivoAuto();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
    system("cls");
    printf("\nARCHIVO ALQUILER\n");
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
            case 1:GeneraArchivoAlquiler();break;
            case 2:LecturaArchivoAlquiler();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
    return 0;
}

void GeneraArchivoAuto()
{
    FILE *pf;
    T_Auto aux;
    int i;
    pf=fopen("AUTO.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<49;i++)
    {
        printf("\nIngrese numero de patente: ");
        fflush(stdin);
        gets(aux.nropatente);
        printf("\nIngrese apellido y nombre del propietario: ");
        fflush(stdin);
        gets(aux.propietario);
        fwrite(&aux,sizeof(T_Auto),1,pf);
    }
    fclose(pf);
}

void LecturaArchivoAuto()
{
    FILE *pf;
    T_Auto aux;
    pf=fopen("AUTO.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Auto),1,pf);
    printf("\nNRO. PATENTE\tAPELLIDO Y NOMBRE DEL PROPIETARIO\n");
    while(!feof(pf))
    {
        printf("\n%12s\t%-21s\n",aux.nropatente,aux.propietario);
        fread(&aux,sizeof(T_Auto),1,pf);
    }
    fclose(pf);
}

void GeneraArchivoAlquiler()
{
    FILE *pf;
    T_Alquiler aux;
    char opcion='S';
    pf=fopen("ALQUILER.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    while(opcion!='N')
    {
        printf("\nIngrese numero de patente: ");
        fflush(stdin);
        gets(aux.nropatente);
        do
        {
            printf("\nIngrese dia de alquiler: ");
            scanf("%d",&aux.dia);
        }while(!(aux.dia>=1&&aux.dia<=30));
        do
        {
            printf("\nIngrese importe de alquiler: ");
            scanf("%f",&aux.importe);
        }while(!(aux.importe>0));
        fwrite(&aux,sizeof(T_Alquiler),1,pf);
        printf("\n-------DATOS VALIDADOS CORRECTAMENTE-------\n");
        do
        {
            printf("\nDesea agregar mas datos? ('S' - Si, 'N' - No): ");
            fflush(stdin);
            scanf("%c",&opcion);
        }while(!(opcion=='N'||opcion=='S'));
    }
    fclose(pf);
}

void LecturaArchivoAlquiler()
{
    FILE *pf;
    T_Alquiler aux;
    pf=fopen("ALQUILER.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Alquiler),1,pf);
    printf("\nNRO. DE PATENTE\tDIA DE ALQUILER\tIMPORTE\n");
    while(!feof(pf))
    {
        printf("\n\t%s\t\t%d\t $ %.2f\n",aux.nropatente,aux.dia,aux.importe);
        fread(&aux,sizeof(T_Alquiler),1,pf);
    }
    fclose(pf);
}
