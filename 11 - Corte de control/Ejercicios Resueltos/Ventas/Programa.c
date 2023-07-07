/*
1. Ventas
Se dispone de un archivo llamado ventas.dat que contiene la información de las ventas realizadas
por la empresa a lo largo del mes. El archivo se encuentra ORDENADO POR NUMERO DE VENDEDOR y
tiene la siguiente estructura:
• Número de factura (entero)
• Número de Vendedor (entero)
• Importe de la factura (real)
Se desea realizar un programa que leyendo el archivo calcule la cantidad de ventas y el importe
total facturado por cada vendedor. Al finalizar mostrar además el importe total facturado por la
empresa.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
    int numfactura,numvendedor;
    float importe;
}T_Ventas;

void Corte();

int main()
{
    Corte();
}

void Corte()
{
    FILE *pf;
    T_Ventas aux;
    float totalfacturado=0,facvendedor;
    int contfacvendedor,numvendedor;
    pf=fopen("VENTAS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Ventas),1,pf);
    while(!feof(pf))
    {
        numvendedor=aux.numvendedor;
        facvendedor=0;
        contfacvendedor=0;
        while(numvendedor==aux.numvendedor&&!feof(pf))
        {
            facvendedor+=aux.importe;
            contfacvendedor++;
            totalfacturado+=aux.importe;
            fread(&aux,sizeof(T_Ventas),1,pf);
        }
        printf("\nVENDEDOR: %d\n",numvendedor);
        printf("\nFACTURACION: $ %.2f\n",facvendedor);
        printf("\nCANTIDAD DE FACTURAS: %d\n",contfacvendedor);
        printf("\n--------------------------\n");
    }
    printf("\nFACTURACION TOTAL: $ %.2f\n",totalfacturado);
    fclose(pf);
}
