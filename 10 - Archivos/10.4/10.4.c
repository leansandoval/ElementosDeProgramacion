#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

typedef struct
{
    int codigo;
    float precio;
    char descripcion[51];
}T_Precio;

int CargaArch(T_Precio[],int);
void ActualizaArch(T_Precio[],int);
void MostrarArch();

int main()
{
    T_Precio VPrecios[100];
    int cant,codigo,pos,i;
    float incremento;
    cant=CargaArch(VPrecios,100);
    do
    {
        printf("\nIngrese el porcentaje de incremento de precios: ");
        scanf("%f",&incremento);
    }while(!(incremento>0));
    for(i=0;i<=cant-1;i++)
        VPrecios[i].precio=VPrecios[i].precio+(VPrecios[i].precio*incremento);
    ActualizaArch(VPrecios,cant);
    MostrarArch();
    printf("\n");
    system("pause");
}

int CargaArch(T_Precio v[],int ce)
{
    FILE *pf;
    T_Precio aux;
    int i=0;
    pf=fopen("PRECIOS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Precio),1,pf);
    while(!feof(pf)&&i<ce)
    {
        v[i]=aux;
        i++;
        fread(&aux,sizeof(T_Precio),1,pf);
    }
    fclose(pf);
    return i;
}

void ActualizaArch(T_Precio v[],int ce)
{
    int i;
    FILE *pf;
    pf=fopen("PRECIOS_ACTUALIZADOS.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<=ce-1;i++)
        fwrite(&v[i],sizeof(T_Precio),1,pf);
    fclose(pf);
}

void MostrarArch()
{
    FILE *pf;
    T_Precio aux;
    pf=fopen("PRECIOS_ACTUALIZADOS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    printf("\n\tLISTA DE PRECIOS ACTUALIZADOS\n");
    printf("\n\tCODIGO\tPRECIO\tDESCRIPCION\n");
    fread(&aux,sizeof(T_Precio),1,pf);
    while(!feof(pf))
    {
        printf("\n\t%d\t$%.2f\t%s\n",aux.codigo,aux.precio,aux.descripcion);
        fread(&aux,sizeof(T_Precio),1,pf);
    }
    fclose(pf);
}
