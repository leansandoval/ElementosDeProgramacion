/*9.4. Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:

    • Número de cliente (entero de 4 dígitos no correlativos).
    • Importe (mayor a cero).
    • Número de vendedor (entero de 1 a 10).

El ingreso de datos finaliza con un número de cliente 999.

Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la
función CARGA_CLIENTE () y para cada uno se ingresa:

    • Código de cliente (entero de 4 dígitos no correlativos).
    • Nombre y Apellido (50 caracteres máximo).

Se solicita:

    a. Determinar la cantidad de ventas realizadas por cliente.
    b. La cantidad de ventas realizadas por vendedor.
    c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada
    cliente, informando:
                        CODIGO DE CLIENTE       NOMBRE Y APELLIDO       TOTAL FACTURADO
                                X               XXXXX XXXXXXXX          $ XXXXXXXXX,XX
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define TOPE 5

typedef struct
{
    int nroCliente,nroVendedor;
    float importe;
} T_Venta;

typedef struct
{
    int nroCliente;
    char nombreYApellido[51];
} T_Cliente;

int Carga_Cliente(T_Cliente[],int);
int Carga_Venta (T_Cliente[],int,T_Venta[]);
int BusquedaCliente(T_Cliente[],int,int);

void CantidadVentasPorCliente (T_Venta[],int);
void MostrarEstructuraCliente (T_Cliente[],int);
void MostrarEstructuraVenta (T_Venta[],int);

int main()
{
    int cantidadClientes,cantidadVentas=0,aux,pos,i=0;
    T_Cliente VCliente[TOPE];
    T_Venta VVenta[cantidadVentas];
    cantidadClientes=Carga_Cliente(VCliente,TOPE);
    if(cantidadClientes>0)
    {
        MostrarEstructuraCliente(VCliente,cantidadClientes);
        cantidadVentas=Carga_Venta(VCliente,cantidadClientes,VVenta);
        CantidadVentasPorCliente(VVenta,cantidadVentas);
        /*printf("\nIngrese un codigo de cliente ya ingresado: ");
        scanf("%d",&aux);
        pos=Busqueda(VVenta,cantidadClientes,aux);
        if(pos!=-1)
            printf("\nEl cliente realizo las ventas con un importe de: $ %.2f\n",VVenta[pos].importe);
        else
            printf("\nEl codigo de cliente ingresado no existe\n");*/
    }
    else
        printf("\nNo hay clientes\n");
    return 0;
}

int Carga_Cliente(T_Cliente v[],int ce)     //Falta validar si se ingresa el mismo numero de cliente
{
    T_Cliente aux;
    int i=0,pos;
    printf("\n------- Carga Clientes -------\n");
    do
    {
        printf("\nIngrese numero de cliente - 4 cifras (999 para terminar): ");
        scanf("%d",&aux.nroCliente);
    }
    while((aux.nroCliente<1000 || aux.nroCliente>9999) && aux.nroCliente!=999);

    while(aux.nroCliente!=999 && i<ce)
    {
        int band=0;
        printf("\nIngrese nombre y apellido del cliente: ");
        fflush(stdin);
        gets(aux.nombreYApellido);
        v[i]=aux;
        i++;
        if(i<ce)
        {
            do
            {
                printf("\nIngrese numero de cliente - 4 cifras (999 para terminar): ");
                scanf("%d",&aux.nroCliente);
            }
            while((aux.nroCliente<1000 || aux.nroCliente>9999) && aux.nroCliente!=999);
        }
    }
    return i;
}

int Carga_Venta (T_Cliente vCliente[],int ce,T_Venta vVenta[])
{
    T_Venta aux;
    int i=0,band=0,pos;
    printf("\n------- Carga Ventas -------\n");
    do
    {
        printf("\nIngrese numero de cliente - 4 cifras (999 para terminar): ");
        scanf("%d",&aux.nroCliente);
    }
    while(BusquedaCliente(vCliente,ce,aux.nroCliente) && aux.nroCliente!=999);
    while(aux.nroCliente!=999)
    {
        do
        {
            printf("\nIngrese un importe: ");
            scanf("%f",&aux.importe);
        }
        while(aux.importe<0);
        do
        {
            printf("\nIngrese numero de vendedor (numeros del 1 al 10): ");
            scanf("%d",&aux.nroVendedor);
        }
        while(aux.nroVendedor<1||aux.nroVendedor>10);
        vVenta[i]=aux;
        i++;
        do
        {
            printf("\nIngrese numero de cliente - 4 cifras (999 para terminar): ");
            scanf("%d",&aux.nroCliente);
        }
        while(BusquedaCliente(vCliente,ce,aux.nroCliente) && aux.nroCliente!=999);
    }
    return i;
}

int BusquedaCliente(T_Cliente v[],int ce,int x)
{
    int i=0,pos=-1;
    while(pos==-1&&i<ce)
        if(v[i].nroCliente==x)
            pos=i;
        else
            i++;
    return pos;
}

void CantidadVentasPorCliente (T_Venta v[],int ce)
{
    int i=0,j,aux,cantVentas=0;
    for(i=0; i<ce; i++)
    {
        aux=v[i].nroCliente;
        for(j=0; j<ce; j++)
            if(aux=v[j].nroCliente)
                cantVentas++;
        printf("\nEl cliente numero %d realizo %d venta/s\n",aux,cantVentas);
        cantVentas=0;
    }
}

void MostrarEstructuraCliente (T_Cliente v[],int ce)
{
    int i;
    printf("\nNro. Cliente\tNombre y Apellido\n");
    for(i=0; i<ce; i++)
        printf("\n%d\t\t%s",v[i].nroCliente,v[i].nombreYApellido);
}

void MostrarEstructuraVenta (T_Venta v[],int ce)
{
    int i;
    printf("\nNro. Cliente\tNro Vendedor\tImporte\n");
    for(i=0; i<ce; i++)
        printf("\n%d\t%d\t%2.f\n",v[i].nroCliente,v[i].nroVendedor,v[i].importe);
}
