#include <stdio.h>
#include <windows.h>
#include <string.h>

#define ERROR_ARCHIVO -1
#define TODO_OK 0

#define CANT_PRODUCTOS 10
#define CANT_PROVEEDORES 50
#define CANT_DIAS 30
#define JUNIO 6

#define PATH_STOCK "Stock.dat"
#define PATH_STOCK_ACT "Stock_Act.dat"
#define PATH_COMPRAS "Compras.dat"
#define PATH_SIN_ESPACIO "SinEspacio.dat"

typedef struct
{
    char codigoArticulo[5];
    char descripcion[31];
    float precioUnitario;
    int stock;
} Producto;

typedef struct
{
    int numeroOrdenDeCompra;
    int numeroProveedor;
    char codigoArticulo[5];
    char descripcion[31];
    int dia;
    int mes;
    int cantidadPedida;
} Compra;

typedef struct
{
    int numeroOrdenDeCompra;
    int dia;
    int mes;
} SinEspacio;

typedef struct
{
    int numeroProveedor;
    int cantArticulosPedidos;
    float importeTotalPedido;
} Proveedor;

void cargarProveedores(Proveedor proveedores[], int cantElem);
int buscarProveedor(Proveedor proveedores[], int cantElem, int numeroDeProveedorABuscar);

int cargarProductos(Producto productos[], int cantElemMaximo);
int buscarProducto(Producto productos[], int cantElem, char codigoArticuloABuscar[]);

int grabarArchivoStock(Producto productos[], int cantElem);
void informe(Proveedor proveedores[], int cantElem);
void listado(int matrizProveedorDia[][CANT_DIAS], int filas, int columnas);

int main()
{
    FILE *archCompra;     // Compras.dat
    FILE *archSinEspacio; // SinEspacio.dat

    archCompra = fopen(PATH_COMPRAS, "rb");
    archSinEspacio = fopen(PATH_SIN_ESPACIO, "wb");

    if (!archCompra || !archSinEspacio)
    {
        printf("\nNo abrio el archivo.\n");
        return ERROR_ARCHIVO;
    }

    Producto productos[CANT_PRODUCTOS];
    Proveedor proveedores[CANT_PROVEEDORES] = {0};
    int matrizProveedorDia[CANT_PROVEEDORES][CANT_DIAS] = {0};
    int cantElemProductos = cargarProductos(productos, CANT_PRODUCTOS);

    cargarProveedores(proveedores, CANT_PROVEEDORES);

    Compra compra;
    SinEspacio sinEspacio;

    fread(&compra, sizeof(Compra), 1, archCompra);

    while (!feof(archCompra))
    {
        if (compra.mes == JUNIO)
        {
            int posicionProducto = buscarProducto(productos, cantElemProductos, compra.codigoArticulo);
            int posicionProveedor = buscarProveedor(proveedores, CANT_PROVEEDORES, compra.numeroProveedor);

            matrizProveedorDia[posicionProveedor][compra.dia - 1] += compra.cantidadPedida;

            if (posicionProducto != -1)
            {
                productos[posicionProducto].stock += compra.cantidadPedida;
                proveedores[posicionProveedor].cantArticulosPedidos += compra.cantidadPedida;
                proveedores[posicionProveedor].importeTotalPedido += (float)productos[posicionProducto].precioUnitario * compra.cantidadPedida;
            }
            else
            {
                if (cantElemProductos < CANT_PRODUCTOS)
                {
                    strcpy(productos[cantElemProductos].codigoArticulo, compra.codigoArticulo);
                    strcpy(productos[cantElemProductos].descripcion, compra.descripcion);
                    printf("\nSe encontro un codigo que no estaba en el stock con descripcion %s, indique que precio debe poseer: ", compra.descripcion);
                    scanf("%f", &productos[cantElemProductos].precioUnitario);
                    productos[cantElemProductos].stock = compra.cantidadPedida;
                    cantElemProductos++;
                }
                else
                {
                    printf("\nBuscar deposito del codigo %s con descripcion %s\n", compra.codigoArticulo, compra.descripcion);
                    sinEspacio.numeroOrdenDeCompra = compra.numeroOrdenDeCompra;
                    sinEspacio.dia = compra.dia;
                    sinEspacio.mes = compra.mes;
                    fwrite(&sinEspacio, sizeof(SinEspacio), 1, archSinEspacio);
                }
            }
        }
        fread(&compra, sizeof(Compra), 1, archCompra);
    }

    fclose(archCompra);
    fclose(archSinEspacio);

    informe(proveedores, CANT_PROVEEDORES);
    listado(matrizProveedorDia, CANT_PROVEEDORES, CANT_DIAS);
    grabarArchivoStock(productos, cantElemProductos);

    return TODO_OK;
}

void cargarProveedores(Proveedor proveedores[], int cantElem)
{
    for (int i = 0; i < cantElem; i++)
        proveedores[i].numeroProveedor = i + 1;
}

int buscarProveedor(Proveedor proveedores[], int cantElem, int numeroDeProveedorABuscar)
{
    int posicion = -1;

    for (int i = 0; i < cantElem && posicion == -1; i++)
    {
        if (proveedores[i].numeroProveedor == numeroDeProveedorABuscar)
            posicion = i;
    }

    return posicion;
}

int cargarProductos(Producto productos[], int cantElemMaximo)
{
    FILE *archStock = fopen(PATH_STOCK, "rb");

    if (!archStock)
    {
        printf("\nNo abrio el archivo.\n");
        return ERROR_ARCHIVO;
    }

    Producto stock;
    fread(&stock, sizeof(Producto), 1, archStock);

    int cantElemReales = 0;

    while (!feof(archStock) && cantElemReales < cantElemMaximo)
    {
        productos[cantElemReales] = stock;
        cantElemReales++;
        fread(&stock, sizeof(Producto), 1, archStock);
    }

    fclose(archStock);
    return cantElemReales;
}

int buscarProducto(Producto productos[], int cantElem, char codigoArticuloABuscar[])
{
    int posicion = -1;

    for (int i = 0; i < cantElem && posicion == -1; i++)
    {
        if (!strcmpi(productos[i].codigoArticulo, codigoArticuloABuscar))
            posicion = i;
    }

    return posicion;
}

void informe(Proveedor proveedores[], int cantElem)
{
    printf("\nNumero de proveedor\tCantidad pedida\t\t\tImporte total\n");
    for (int i = 0; i < cantElem; i++)
        if (proveedores[i].cantArticulosPedidos)
            printf("\n\t%d\t\t\t%d\t\t\t$ %.2f\n", proveedores[i].numeroProveedor, proveedores[i].cantArticulosPedidos, proveedores[i].importeTotalPedido);
}

void listado(int matrizProveedorDia[][CANT_DIAS], int filas, int columnas)
{
    printf("\nProveedor/Dia ");
    for (int dia = 1; dia <= columnas; dia++)
        printf("%4d", dia);

    for (int i = 0; i < filas; i++)
    {
        printf("\n%-14d", i + 1);
        for (int j = 0; j < columnas; j++)
            printf("%4d", matrizProveedorDia[i][j]);
    }
    printf("\n");
}

int grabarArchivoStock(Producto productos[], int cantElem)
{
    FILE *archProd;
    archProd = fopen(PATH_STOCK_ACT, "wb");

    if (!archProd)
    {
        printf("\nNo abrio el archivo.\n");
        return ERROR_ARCHIVO;
    }

    fwrite(&productos, sizeof(Producto), cantElem, archProd);

    fclose(archProd);
    return TODO_OK;
}
