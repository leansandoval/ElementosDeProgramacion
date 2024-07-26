/* 9.1. Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:

• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).

Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”. Luego ingresan las ventas del mes:

    • Código de Producto (5 caracteres).
    • Cantidad pedida.

El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
    a. Actualizar la información de los productos con las ventas realizadas en el mes.
    b. Al finalizar, mostrar el listado de productos actualizado, informando:

                    DESCRIPCION     CANTIDAD UNIDADES VENDIDAS         IMPORTE TOTAL VENDIDO
                    XXXXXXX         XXXX                                $XXXXX,XX
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 50

typedef struct
{
    char codigo[6],descripcion[31];
    float precio,importeTotal;
    int cantidadUnidadesVendidas;
} T_Ventas;

int CargaStruct(T_Ventas[],int);
int Busqueda (T_Ventas[],char[],int);
int esDatoVal2(int,int);
int IngrDatoVal2(int);
void MostrarStruct(T_Ventas[],int);

int main()
{
    T_Ventas VProd[max];
    int cant,cantidadUnidadesPerdidas,pos;
    char codigo[6];
    printf("\n------------- VENTAS MES ANTERIOR -------------\n");
    cant=CargaStruct(VProd,max);
    printf("\n------------- VENTAS MES ACTUAL -------------\n");
    cantidadUnidadesPerdidas=IngrDatoVal2(0);
    while(cantidadUnidadesPerdidas!=0)
    {
        printf("\nIngrese un codigo de producto ya ingresado: ");
        fflush(stdin);
        gets(codigo);
        pos=Busqueda(VProd,codigo,cant);
        if(pos!=-1)
        {
            VProd[pos].cantidadUnidadesVendidas-=cantidadUnidadesPerdidas;
            //VProd[pos].importeTotal=0;
            VProd[pos].importeTotal=VProd[pos].cantidadUnidadesVendidas*VProd[pos].precio;
            cantidadUnidadesPerdidas=IngrDatoVal2(0);
        }
        else
        {
            printf("\nEl codigo de producto no existe\n");
            cantidadUnidadesPerdidas=IngrDatoVal2(0);
        }
    }
    MostrarStruct(VProd,cant);
    return 0;
}

int esDatoVal2(int x,int lim)
{
    if(x>=lim)
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
            printf("\nDato incorrecto, ingrese nuevamente\n");
        band=1;
        printf("\nIngrese cantidad de unidades perdidas (0 para terminar): ");
        scanf("%d",&dato);
    }
    while(esDatoVal2(dato,lim)==0);
    return dato;
}

int Busqueda(T_Ventas v[],char aux[],int ce)
{
    int i=0,pos=-1;
    while(pos==-1&&i<ce)
        if(strcmpi(v[i].codigo,aux)==0)
            pos=i;
        else
            i++;
    return pos;
}

int CargaStruct(T_Ventas v[],int ce)
{
    T_Ventas aux;
    int i=0,band=0;
    printf("\nIngrese DESCRIPCION del producto - 'FIN' para terminar: ");
    fflush(stdin);
    gets(aux.descripcion);
    while(strcmpi(aux.descripcion,"FIN")!=0 && i<ce)
    {
        do
        {
            printf("\nIngrese CODIGO del producto: ");
            fflush(stdin);
            gets(aux.codigo);
            if(band==1)
                printf("\nEl codigo ya fue ingresado en otro producto, ingrese otro\n");
            band=1;
        }
        while(!Busqueda(v,aux.codigo,i));
        do
        {
            printf("\nIngrese PRECIO del producto: ");
            scanf("%f",&aux.precio);
        }
        while(!(aux.precio>0));
        do
        {
            printf("\nCantidad de UNIDADES vendidas (DEL MES ANTERIOR): ");
            scanf("%d",&aux.cantidadUnidadesVendidas);
        }
        while(!(aux.cantidadUnidadesVendidas>0));

        aux.importeTotal=(float)(aux.precio*aux.cantidadUnidadesVendidas);

        v[i]=aux;
        i++;

        printf("\nIngrese DESCRIPCION del producto - 'FIN' para terminar: ");
        fflush(stdin);
        gets(aux.descripcion);
    }
    return i;
}

void MostrarStruct(T_Ventas v[],int ce)
{
    int i;
    printf("\nDESCRIPCION\t\tCANT. UNIDADES VENDIDAS\t\tIMP. TOTAL\n");
    for(i=0; i<=ce-1; i++)
        printf("\n%s\t\t\t%d\t\t\t\t$ %.2f\n",v[i].descripcion,v[i].cantidadUnidadesVendidas,v[i].importeTotal);
}
