#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

typedef struct
{
    int cajadeahorro;
    char apynom[31];
    float saldo;
}T_Saldos;

typedef struct
{
    int sucursal,cajadeahorro,mes,dia,codoperacion;
    float importe;
}T_Movi;

void GenerarArchivoSaldos();
void LecturaArchivoSaldos();
void GenerarArchivoMovi();
void LecturaArchivoMovi();

int main()
{
    int opcion;
    printf("\nARCHIVO SALDOS\n");
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
            case 1:GenerarArchivoSaldos();break;
            case 2:LecturaArchivoSaldos();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
    system("cls");
    printf("\nARCHIVO MOVI\n");
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
            case 1:GenerarArchivoMovi();break;
            case 2:LecturaArchivoMovi();break;
        }
    }while(opcion!=3);
    printf("\n");
    system("pause");
    return 0;
}

void GenerarArchivoSaldos()
{
    FILE *pf;
    T_Saldos aux;
    char opcion='S';
    pf=fopen("SALDOS.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    while(opcion!='N')
    {
        do
        {
            printf("\nIngrese numero de cara de ahorro (6 cifras): ");
            scanf("%d",&aux.cajadeahorro);
        }while(!(aux.cajadeahorro>=100000&&aux.cajadeahorro<=999999));
        printf("\nIngrese apellido y nombre: ");
        fflush(stdin);
        gets(aux.apynom);
        do
        {
            printf("\nIngrese saldo: ");
            scanf("%f",&aux.saldo);
        }while(!(aux.saldo>0));
        printf("\n------DATOS VALIDADOS CORRECTAMENTE------\n");
        fwrite(&aux,sizeof(T_Saldos),1,pf);
        do
        {
            printf("\nDesea agregar otro cliente mas? ('S' - Si, 'N' - No): ");
            fflush(stdin);
            scanf("%c",&opcion);
        }while(!(opcion=='S'||opcion=='N'));
    }
    fclose(pf);
}

void LecturaArchivoSaldos()
{
    FILE *pf;
    T_Saldos aux;
    pf=fopen("SALDOS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Saldos),1,pf);
    printf("\nNUM. CAJA DE AHORRO\tAPELLIDO Y NOMBRE\t\t\tSALDO\n");
    while(!feof(pf))
    {
        printf("\n\t%d\t\t%-31s\t\t%.2f\n",aux.cajadeahorro,aux.apynom,aux.saldo);
        fread(&aux,sizeof(T_Saldos),1,pf);
    }
    fclose(pf);
}

void GenerarArchivoMovi()
{
    FILE *pf;
    T_Movi aux;
    char opcion='S';
    pf=fopen("MOVI.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    while(opcion!='N')
    {
        do
        {
            printf("\nIngrese sucursal del banco (4 cifras): ");
            scanf("%d",&aux.sucursal);
        }while(!(aux.sucursal>=1000&&aux.sucursal<=9999));
        do
        {
            printf("\nIngrese numero de cara de ahorro (6 cifras): ");
            scanf("%d",&aux.cajadeahorro);
        }while(!(aux.cajadeahorro>=100000&&aux.cajadeahorro<=999999));
        do
        {
            printf("\nIngrese mes: ");
            scanf("%d",&aux.mes);
            if(aux.mes==4||aux.mes==6||aux.mes==9||aux.mes==11)
                do
                {
                    printf("\nIngrese dia: ");
                    scanf("%d",&aux.dia);
                }while(!(aux.dia>=1&&aux.dia<=30));
            else
                if(aux.mes==2)
                    do
                    {
                        printf("\nIngrese dia: ");
                        scanf("%d",&aux.dia);
                    }while(!(aux.dia>=1&&aux.dia<=28)); //Se considera NO BISIESTO
                else
                    do
                    {
                        printf("\nIngrese dia: ");
                        scanf("%d",&aux.dia);
                    }while(!(aux.dia>=1&&aux.dia<=31));
        }while(!(aux.mes>=1&&aux.mes<=12));
        do
        {
            printf("\nIngrese codigo de operacion (1 - Deposito, 2 - Extraccion): ");
            scanf("%d",&aux.codoperacion);
        }while(!(aux.codoperacion==1||aux.codoperacion==2));
        do
        {
            printf("\nIngrese importe: ");
            scanf("%f",&aux.importe);
        }while(!(aux.importe>0));
        fwrite(&aux,sizeof(T_Movi),1,pf);
        printf("\n----------DATOS VALIDADOS CORRECTAMENTE----------\n");
        do
        {
            printf("\nDesea agregar mas datos? ('S' - Si, 'N' - No): ");
            fflush(stdin);
            scanf("%c",&opcion);
        }while(!(opcion=='S'||opcion=='N'));
    }
    fclose(pf);
}

void LecturaArchivoMovi()
{
    FILE *pf;
    T_Movi aux;
    pf=fopen("MOVI.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Movi),1,pf);
    printf("\nSUCURSAL\tNRO. CAJA DE AHORRO\tMES\tDIA\tCOD. DE OPERACION\tIMPORTE\n");
    while(!feof(pf))
    {
        printf("\n%d\t\t\t%d\t\t%d\t%d\t\t%d\t\t%.2f\n",aux.sucursal,aux.cajadeahorro,aux.mes,aux.dia,aux.codoperacion,aux.importe);
        fread(&aux,sizeof(T_Movi),1,pf);
    }
    fclose(pf);
}
