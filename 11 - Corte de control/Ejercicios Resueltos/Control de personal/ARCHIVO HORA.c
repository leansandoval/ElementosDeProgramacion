#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

typedef struct
{
    int dia,mes,anio;
}T_Fecha;

typedef struct
{
    int nrolegajo,totalhoras;
    char apeynom[21];
    float valorhora,totalsueldo;
    T_Fecha f;
}T_Personal;

typedef struct
{
    int nrolegajo,canthoras;
}T_Hora;

void GenerarArchivoPersonal();
void LecturaArchivoPersonal();
void GenerarArchivoHoras();
void LecturaArchivoHoras();

int main()
{
    int opcion;
    printf("\nARCHIVO PERSONAL\n");
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
            case 1:GenerarArchivoPersonal();break;
            case 2:LecturaArchivoPersonal();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
    system("cls");
    printf("\nARCHIVO HORAS\n");
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
            case 1:GenerarArchivoHoras();break;
            case 2:LecturaArchivoHoras();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
    return 0;
}

void GenerarArchivoPersonal()
{
    FILE *pf;
    T_Personal aux;
    char opcion='S';
    pf=fopen("PERSONAL.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        system("pause");
        exit(1);
    }
    while(opcion!='N'&&opcion!='n')
    {
        do
        {
            printf("\nIngrese numero de legajo: ");
            scanf("%d",&aux.nrolegajo);
        }while(!(aux.nrolegajo>=100&&aux.nrolegajo<=999));
        printf("\nIngrese apellido y nombre del operario: ");
        fflush(stdin);
        gets(aux.apeynom);
        do
        {
            printf("\nIngrese valor de la hora: ");
            scanf("%f",&aux.valorhora);
        }while(!(aux.valorhora>0));
        do
        {
            printf("\nTotal de horas trabajadas: ");
            scanf("%d",&aux.totalhoras);
        }while(!(aux.totalhoras));
        do
        {
            printf("\nTotal de sueldos a cobrar a la fecha: ");
            scanf("%f",&aux.totalsueldo);
        }while(!(aux.totalsueldo>0));
        do
        {
            printf("\nFECHA DEL ULTIMO PROCESO\n");
            printf("\nIngrese dia: ");
            scanf("%d",aux.f.dia);
            printf("\nIngrese mes: ");
            scanf("%d",aux.f.mes);
            printf("\nIngrese anio: ");
            scanf("%d",aux.f.anio);
        }while(!( (aux.f.dia>=1&&aux.f.dia<=30) && (aux.f.mes>=1&&aux.f.mes<=12) && (aux.f.anio>=1900&&aux.f.anio<=2020) ));
        fwrite(&aux,sizeof(T_Personal),1,pf);
        printf("\n-----DATOS VALIDADOS CORRECTAMENTE-----\n");
        do
        {
            printf("\nDesea agregar mas datos? ('S' - Aceptar, 'N' - Cancelar): ");
            fflush(stdin);
            scanf("%c",&opcion);
        }while(!(opcion=='N'||opcion=='n'||opcion=='s'||opcion=='S'));
    }
    fclose(pf);
}

void LecturaArchivoPersonal()
{
    FILE*pf;
    T_Personal aux;
    pf=fopen("PERSONAL.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        system("pause");
        exit(1);
    }
    fread(&aux,sizeof(T_Personal),1,pf);
    printf("\nNUM. LEGAJO\tAPELLIDO Y NOMBRE\tVALOR HORA\tTOTAL HORAS TRABAJADAS\tTOTAL SUELDOS A COBRAR\tULTIMO PROCESO\n");
    while(!feof(pf))
    {
        printf("\n%d\t%s\t%.2f\t%d\t.2f\t%d/%d/%d\n",aux.nrolegajo,aux.apeynom,aux.valorhora,aux.totalhoras,aux.totalsueldo,aux.f.dia,aux.f.mes,aux.f.anio);
        fread(&aux,sizeof(T_Personal),1,pf);
    }
    fclose(pf);
}

void GenerarArchivoHoras()
{
    FILE*pf;
    T_Hora aux;
    char opcion='S';
    pf=fopen("HORAS.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        system("pause");
        exit(1);
    }
    while(opcion!='N'&&opcion!='n')
    {
        do
        {
            printf("\nIngrese numero de legajo: ");
            scanf("%d",&aux.nrolegajo);
        }while(!(aux.nrolegajo>=100&&aux.nrolegajo<=999));
        do
        {
            printf("\nIngrese cantidad de horas trabajadas durante el dia: ");
            scanf("%d",&aux.canthoras);
        }while(!(aux.canthoras>0));
        fwrite(&aux,sizeof(T_Hora),1,pf);
        printf("\n-----DATOS VALIDADOS CORRECTAMENTE-----\n");
        do
        {
            printf("\nDesea agregar mas datos? ('S' - Aceptar, 'N' - Cancelar): ");
            fflush(stdin);
            scanf("%c",&opcion);
        }while(!(opcion=='N'||opcion=='n'||opcion=='s'||opcion=='S'));
    }
    fclose(pf);
}

void LecturaArchivoHoras()
{
    FILE *pf;
    T_Hora aux;
    pf=fopen("HORAS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        system("pause");
        exit(1);
    }
    fread(&aux,sizeof(T_Hora),1,pf);
    printf("\nNRO. LEGAJO\tCANTIDAD HORAS\n");
    while(!feof(pf))
    {
        printf("\n%d\t\t\t%d\n",aux.nrolegajo,aux.canthoras);
        fread(&aux,sizeof(T_Hora),1,pf);
    }
    fclose(pf);
}
