#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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

void GeneraArchivoTemperaturas();
void LecturaArchivoTemperaturas();
void GeneraArchivoLocalidades(int);
void LecturaArchivoLocalidades(int);

int main()
{
    int opcion;
    printf("\nARCHIVO TEMPERATURAS\n");
    printf("\n1 - GENERAR\t2 - LECTURA\t3 - FIN\n");
    do
    {
        do
        {
            printf("\nIngrese una opcion: ");
            scanf("%d",&opcion);
        }while(!(opcion>=1&&opcion<=3));
        switch(opcion)
        {
            case 1:GeneraArchivoTemperaturas();break;
            case 2:LecturaArchivoTemperaturas();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
    system("cls");
    printf("\nARCHIVO LOCALIDADES\n");
    printf("\n1 - GENERAR\t2 - LECTURA\t3 - FIN\n");
    do
    {
        do
        {
            printf("\nIngrese una opcion: ");
            scanf("%d",&opcion);
        }while(!(opcion>=1&&opcion<=3));
        switch(opcion)
        {
            case 1:GeneraArchivoLocalidades(5);break;
            case 2:LecturaArchivoLocalidades(5);break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
    return 0;
}

void GeneraArchivoTemperaturas()
{
    FILE*pf;
    T_Temp aux;
    char opcion='S';
    pf=fopen("TEMPERATURAS.dat","wb");
    if(pf==NULL)
    {1
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    while(opcion!='N')
    {
        printf("\nIngrese codigo de localidad: ");
        fflush(stdin);
        gets(aux.CodLoc);
        do
        {
            printf("\nIngrese mes: ");
            scanf("%d",&aux.Mes);
        }while(!(aux.Mes>=1&&aux.Mes<=12));
        printf("\nIngrese temperatura: ");
        scanf("%f",&aux.Temp);
        printf("\n---DATOS VALIDADOS CORRECTAMENTE---\n");
        fwrite(&aux,sizeof(T_Temp),1,pf);
        do
        {
            printf("\nDesea cargar mas datos? 'S' Si - 'N' No : ");
            fflush(stdin);
            scanf("%c",&opcion);
        }while(!(opcion=='S'||opcion=='N'));
    }
    fclose(pf);
}

void LecturaArchivoTemperaturas()
{
    FILE *pf;
    T_Temp aux;
    pf=fopen("TEMPERATURAS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Temp),1,pf);
    printf("\nCODIGO LOCALIDAD\tMES\tTEMPERATURA\n");
    while(!feof(pf))
    {
        printf("\n\t%s\t\t%d\t%.2f\n",aux.CodLoc,aux.Mes,aux.Temp);
        fread(&aux,sizeof(T_Temp),1,pf);
    }
    fclose(pf);
}

void GeneraArchivoLocalidades(int ce)
{
    FILE *pf;
    T_Loca aux;
    int i;
    pf=fopen("LOCALIDADES.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<=ce-1;i++)
    {
        printf("\nIngrese codigo de localidad: ");
        fflush(stdin);
        gets(aux.CodLoc);
        printf("\nIngrese descripcion: ");
        fflush(stdin);
        gets(aux.DescLoc);
        printf("\n---DATOS VALIDADOS CORRECTAMENTE---\n");
        fwrite(&aux,sizeof(T_Loca),1,pf);
    }
    fclose(pf);
}

void LecturaArchivoLocalidades(int ce)
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
    printf("\nCODIGO DE LOCALIDAD\tDESCRIPCION\n");
    for(i=0;i<=ce-1;i++)
    {
        printf("\n%11s\t\t%-51s\n",aux.CodLoc,aux.DescLoc);
        fread(&aux,sizeof(T_Loca),1,pf);
    }
    fclose(pf);
}
