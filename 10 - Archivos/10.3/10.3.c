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
int Busqueda(T_Precio[],int,int);
void ActualizaArch(T_Precio[],int);
void MostrarArch();

int main()
{
    T_Precio VPrecios[100];
    int cant,codigo,pos;
    float nuevoprecio;
    cant=CargaArch(VPrecios,100);
    printf("\nIngrese el codigo de producto (0 para terminar): ");
    scanf("%d",&codigo);
    while(codigo!=0)
    {
        pos=Busqueda(VPrecios,cant,codigo);
        if(pos!=-1)
        {
            do
            {
                printf("\nIngrese el monto a modificar: ");
                scanf("%f",&nuevoprecio);
            }while(!(nuevoprecio>0));
            VPrecios[pos].precio=nuevoprecio;
        }
        else
            printf("\nEl codigo de producto es inexistente\n");
        printf("\nIngrese el codigo de producto (0 para terminar): ");
        scanf("%d",&codigo);
    }
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
    pf=fopen("PRODUCTOS.dat","rb");
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

int Busqueda(T_Precio v[],int ce,int x)
{
    int pos=-1,i=0;
    while(pos==-1&&i<ce)
        if(v[i].codigo==x)
            pos=i;
        else
            i++;
    return pos;
}

void ActualizaArch(T_Precio v[],int ce)
{
    int i;
    FILE *pf;
    pf=fopen("PRODUCTOSACT.dat","wb");
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
    pf=fopen("PRODUCTOSACT.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    printf("\nCODIGO\tPRECIO\tDESCRIPCION\n");
    fread(&aux,sizeof(T_Precio),1,pf);
    while(!feof(pf))
    {
        printf("\n%d\t%.2f\t%s\n",aux.codigo,aux.precio,aux.descripcion);
        fread(&aux,sizeof(T_Precio),1,pf);
    }
    fclose(pf);
}
