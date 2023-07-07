#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

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

int Leer(TVenta[],int);
int Busqueda(TVenta[],int,int);
void Grabar(TVenta[],int);
void Orden(TVenta[],int[],int);
void SinPago(TVenta[],int[],int);

int main()
{
    TVenta VEdificio[200];
    TFecha fec;
    int nrodpto,VNoPago[200]={0},cant,pos;
    cant=Leer(VEdificio,200);
    do
    {
        printf("\nIngrese numero de departamento (0 para terminar): ");
        scanf("%d",&nrodpto);
    }while(!(nrodpto>=100&&nrodpto<=999||nrodpto==0));
    while(nrodpto!=0)
    {
        pos=Busqueda(VEdificio,cant,nrodpto);
        if(pos!=-1)
        {
            printf("\nIngrese fecha de pago (Dia, Mes, Anio): ");
            scanf("%d%d%d",&fec.dia,&fec.mes,&fec.anio);
            VEdificio[pos].FPago=fec;
            VNoPago[pos]=1;
        }
        else
            printf("\nEl numero de departamento no se encuentra\n");
        do
        {
            printf("\nIngrese numero de departamento (0 para terminar): ");
            scanf("%d",&nrodpto);
        }while(!(nrodpto>=100&&nrodpto<=999||nrodpto==0));
    }
    Grabar(VEdificio,cant);
    Orden(VEdificio,VNoPago,cant);
    SinPago(VEdificio,VNoPago,cant);
    system("pause");
}

int Leer(TVenta v[],int ce)
{
    FILE *pf;
    TVenta aux;
    int i=0;
    pf=fopen("EDIFICIO.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(TVenta),1,pf);
    while(!feof(pf)&&i<ce)
    {
        v[i]=aux;
        i++;
        fread(&aux,sizeof(TVenta),1,pf);
    }
    fclose(pf);
    return(i);
}

int Busqueda(TVenta v[],int ce,int x)
{
    int pos=-1,i=0;
    while(pos==-1&&i<ce)
        if(v[i].nrodpto==x)
            pos=i;
        else
            i++;
    return(pos);
}

void Grabar (TVenta v[],int ce)
{
    FILE *pf;
    int i;
    pf=fopen("DEPARTA.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<=ce-1;i++)
        fwrite(&v[i],sizeof(TVenta),1,pf);
    fclose(pf);
}

void Orden (TVenta a[],int b[],int ce)
{
    TVenta aux;
    int cota,k,i,j,aux1;
    cota=ce;
    k=1;
    while(k!=0)
    {
        k=0;
        for(j=1;j<cota;j++)
            if(a[j-1].valor<a[j].valor)
            {
                aux=a[j-1];
                a[j-1]=a[j];
                a[j]=aux;
                aux1=b[j-1];
                b[j-1]=b[j];
                b[j]=aux1;
                k=j;
            }
        cota=k;
    }
}

void SinPago(TVenta a[],int b[],int ce)
{
    int i;
    printf("\n\t\tEXPENSAS IMPAGAS\n");
    printf("\nDEPARTAMENTO\tPROPIETARIO\tVALOR EXPENSA\n");
    for(i=0;i<=ce-1;i++)
        if(b[i]==0)
            printf("\n%d\t\t%s\t%.2f\n",a[i].nrodpto,a[i].nprop,a[i].valor);
    printf("\n");
}
