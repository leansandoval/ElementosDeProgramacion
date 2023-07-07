#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
    int dia,mes,anio;
}TFecha;

typedef struct
{
    int nrodpto;
    char nprop[31];
    float sup,valor;
    TFecha FPago;
}TVenta;

int esBisiesto(int);
int CantDiasMes(int,int);
int esFechaVal(int,int,int);
void Lectura();
void Grabacion();

int main()
{
    int opcion;
    do
    {
        printf("\n1 - Grabacion\n2 - Lectura\n3 - Fin\n");
        do
        {
            printf("\nIngrese una opcion: ");
            scanf("%d",&opcion);
        }while(!(opcion>=1&&opcion<=3));
        switch(opcion)
        {
            case 1:Grabacion();break;
            case 2:Lectura();break;
        }
    }while(opcion!=3);
}

int esFechaVal(int d,int m,int a)
{
    int dv=0;
    if(a>1900)
        if(m>=1&&m<=12)
            if(d>=1&&d<=CantDiasMes(m,a))
                dv=1;
    return dv;
}

int CantDiasMes(int m,int a)
{
    int cd=31;
    if(m==4||m==6||m==9||m==11)
        cd=30;
    else
        if(m==2)
            cd=28+esBisiesto(a);
    return cd;
}

int esBisiesto(int a)
{
    if((a%4==0&&a%100!=0)||a%400==0)
        return 1;
    else
        return 0;
}

void Grabacion(int ce)
{
    FILE *pf;
    TVenta aux;
    pf=fopen("EDIFICIO.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    do
    {
        printf("\nIngrese numero de departamento (0 para terminar): ");
        scanf("%d",&aux.nrodpto);
    }while(!(aux.nrodpto>=100&&aux.nrodpto<=999||aux.nrodpto==0));
    while(aux.nrodpto!=0)
    {

        printf("\nIngrese nombre del propietario: ");
        fflush(stdin);
        gets(aux.nprop);
        do
        {
            printf("\nIngrese superficie en metros cuadrados: ");
            scanf("%f",&aux.sup);
        }while(!(aux.sup>0));
        do
        {
            printf("\nIngrese valor de las expensas: ");
            scanf("%f",&aux.valor);
        }while(!(aux.valor>0));
        do
        {
            printf("\nIngrese fecha del ultimo pago (en formato DD-MM-AAAA): ");
            scanf("%d%d%d",&aux.FPago.dia,&aux.FPago.mes,&aux.FPago.anio);
        }while(esFechaVal(aux.FPago.dia,aux.FPago.mes,aux.FPago.anio)==0);
        fwrite(&aux,sizeof(TVenta),1,pf);
        do
        {
            printf("\nIngrese numero de departamento (0 para terminar): ");
            scanf("%d",&aux.nrodpto);
        }while(!(aux.nrodpto>=100&&aux.nrodpto<=999||aux.nrodpto==0));
    }
    fclose(pf);
}

void Lectura()
{
    FILE *pf;
    TVenta aux;
    pf=fopen("EDIFICIO.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    printf("\nNRO. DEPTO.\tNOMBRE DEL PROP.\tSUPERFICIE\tVALOR EXPENSAS\tFECHA ULTIMO PAGO\n");
    fread(&aux,sizeof(TVenta),1,pf);
    while(!feof(pf))
    {
        printf("\n%d\t\t%s\t%.2f\t\t%.2f\t\t%d/%d/%d\n",aux.nrodpto,aux.nprop,aux.sup,aux.valor,aux.FPago.dia,aux.FPago.mes,aux.FPago.anio);
        fread(&aux,sizeof(TVenta),1,pf);
    }
    fclose(pf);
}
