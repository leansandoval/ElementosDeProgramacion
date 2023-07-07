#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
    int nrocliente;
    char razonsocial[26],codestado;
    float imptotal,tpe,saldodeudor;
}T_Sal;

typedef struct
{
    int nrocliente,zona;
    char codoperacion;
    float imp;
}T_Op;

int Lectura_Cliente(T_Sal[],int);
int Control(T_Op);
int Entrada(T_Sal[],int,int);
void Lectura_Error();
void Grabar(T_Sal[],int);
void Listar(T_Sal[],int);

int main()
{
    FILE *pe;
    T_Op info;
    T_Sal VActivos[1200];
    int cant,pos;
    cant=Lectura_Cliente(VActivos,1200);
    pe=fopen("ERROR.dat","wb");
    printf("\nIngrese numero de cliente (0 para teminar): ");
    scanf("%d",&info.nrocliente);
    while(info.nrocliente!=0)
    {
        printf("\nIngrese zona: ");
        scanf("%d",&info.zona);
        printf("\nIngrese codigo de operacion: ");
        fflush(stdin);
        scanf("%c",&info.codoperacion);
        printf("\nIngrese importe: ");
        scanf("%f",&info.imp);
        if(Control(info)==1)
        {
            pos=Entrada(VActivos,cant,info.nrocliente);
            if(pos!=-1)
            {
                if(info.codoperacion=='V')
                    VActivos[pos].imptotal+=info.imp;
                else
                    VActivos[pos].tpe+=info.imp;
                VActivos[pos].saldodeudor=VActivos[pos].imptotal-VActivos[pos].tpe;
            }
            else
                printf("\nCliente inexistente\n");
        }
        else
            fwrite(&info,sizeof(T_Op),1,pe);
        printf("\nIngrese numero de cliente (0 para teminar): ");
        scanf("%d",&info.nrocliente);
    }
    fclose(pe);
    Lectura_Error();
    Grabar(VActivos,cant);
    Listar(VActivos,cant);
    getch();
}

int Lectura_Cliente (T_Sal v[],int ce)
{
    FILE *pf;
    T_Sal sal;
    int i=0;
    pf=fopen("SALDOS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&sal,sizeof(T_Sal),1,pf);
    while(!feof(pf)&&i<ce)
    {
        if(sal.codestado=='A')
        {
            v[i]=sal;
            i++;
        }
        fread(&sal,sizeof(T_Sal),1,pf);
    }
    fclose(pf);
    return (i);
}

int Control (T_Op info)
{
    if(info.nrocliente>=0&&info.nrocliente<=11900)
        if(info.zona>=1&&info.zona<=100)
            if(info.codoperacion=='V'||info.codoperacion=='P')
                if(info.imp>0&&info.imp<20000)
                    return 1;
                else
                    return 0;
            else
                return 0;
        else
            return 0;
    else
        return 0;
}

int Entrada(T_Sal v[],int ce,int aux)
{
    int pos=-1,i=0;
    while(pos==-1&&i<ce)
        if(v[i].nrocliente==aux)
            pos=i;
        else
            i++;
    return (pos);
}

void Lectura_Error()
{
    FILE *pe;
    T_Op er;
    printf("\nINFORMACION DEL ARCHIVO ERROR\n");
    printf("\nNRO. CLIENTE\tZONA\tCOD. OPERACION\tIMPORTE\n");
    pe=fopen("ERROR.dat","rb");
    if(pe==NULL)
    {
        printf("\nNo abrio el archivo...");
        getch();
        exit(1);
    }
    fread(&er,sizeof(T_Op),1,pe);
    while(!feof(pe))
    {
        printf("\n\t%d\t%d\t\t%c\t%.2f\n",er.nrocliente,er.zona,er.codoperacion,er.imp);
        fread(&er,sizeof(T_Op),1,pe);
    }
    fclose(pe);
}

void Grabar(T_Sal v[],int ce)
{
    FILE *pf;
    int i;
    pf=fopen("SALDOSACT.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        getch();
        exit(1);
    }
    for(i=0;i<=ce-1;i++)
        fwrite(&v[i],sizeof(T_Sal),1,pf);
    fclose(pf);
}

void Listar(T_Sal v[],int ce)
{
    int i;
    printf("\n\tSALDOS DEUDORES MAYORES DE $1500\n");
    printf("\nNRO.CLIENTE\tRAZON SOCIAL\tSALDO DEUDOR\n");
    for(i=0;i<=ce-1;i++)
        printf("\n%d\t\t%s\t%.2f\n",v[i].nrocliente,v[i].razonsocial,v[i].saldodeudor);
}
