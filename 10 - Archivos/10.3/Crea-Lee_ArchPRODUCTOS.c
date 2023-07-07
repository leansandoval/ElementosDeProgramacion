#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct
{
    int codigo;
    float precio;
    char descrip[51];
}T_Precio;

int esDatoVal2(int,int);
int esDatoValReal(float,float);
int IngrDatoVal2(int);
float IngrDatoValReal(float);
void GeneraArch();
void MostrarArch();

int main()
{
    int opcion;
    printf("\n1 - GENERAR\n2 - LECTURA\n3 - FIN\n");
    do
    {
        do
        {
            printf("\nIngrese una opcion: ");
            scanf("%d",&opcion);
        }while(!(opcion>=1&&opcion<=3));
        switch(opcion)
        {
            case 1:GeneraArch();
            case 2:MostrarArch();
        }
    }while(opcion!=3);
    return 0;
}

int esDatoVal2(int x,int lim)
{
    if(x>=lim)
        return 1;
    else
        return 0;
}

int esDatoValReal(float x,float lim)
{
    if(x>lim)
        return 1;
    else
        return 0;
}

int IngrDatoVal2(int lim)
{
    int dato,band=0;
    do
    {
        if(band==1)
        {
            printf("\nDato incorrecto, ingrese nuevamente: ");
        }
        band=1;
        scanf("%d",&dato);
    }while(esDatoVal2(dato,lim)==0);
    return dato;
}

float IngrDatoValReal(float lim)
{
    float dato,band=0;
    do
    {
        if(band==1)
            printf("\nValor incorrecto\n");
        band=1;
        scanf("%f",&dato);
    }while(esDatoValReal(dato,lim)==0);
    return dato;
}

void GeneraArch()
{
    T_Precio al;
    FILE *pf;
    pf=fopen("PRODUCTOS.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    printf("\nIngrese codigo de producto (0 para terminar): ");
    al.codigo=IngrDatoVal2(0);
    while(al.codigo!=0)
    {
        printf("\nIngrese precio del producto: ");
        al.precio=IngrDatoValReal(0);
        printf("\nIngrese una descripcion: ");
        fflush(stdin);
        gets(al.descrip);
        fwrite(&al,sizeof(T_Precio),1,pf);
        printf("\nIngrese codigo de producto (0 para terminar): ");
        al.codigo=IngrDatoVal2(0);
    }
    fclose(pf);
}

void MostrarArch()
{
    FILE *pf;
    T_Precio aux;
    pf=fopen("PRODUCTOS.dat","rb");
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
        printf("\n%d\t%.2f\t%s\n",aux.codigo,aux.precio,aux.descrip);
        fread(&aux,sizeof(T_Precio),1,pf);
    }
    fclose(pf);
}
