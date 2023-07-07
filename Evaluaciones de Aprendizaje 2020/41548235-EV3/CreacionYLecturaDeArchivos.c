#include <stdio.h>
#include <windows.h>
#include <string.h>

#define ERROR_ARCHIVO -1
#define TODO_OK 0
#define PATH_ARCHIVO_COMPRAS "Compras.dat"
#define PATH_ARCHIVO_STOCK "Stock.dat"

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

int validarDatoEnteroMayorALimite(const char mensaje[], int limite);
int validarDatoEnteroEntreLimites(const char mensaje[], int limiteInferior, int limiteSuperior);
char aceptarOCancelar(const char mensaje[]);

Producto crearRegistroStock();
int crearArchivoStock(const char nombreArchivo[]);
int leerArchivoStock(const char nombreArchivo[]);

Compra crearRegistroCompra();
int crearArchivoCompras(const char nombreArchivo[]);
int leerArchivoCompras(const char nombreArchivo[]);

int main()
{
    int opcion, resultado;

    printf("\nARCHIVO STOCK\n");
    printf("\n1 - GENERAR\n2 - LECTURA\n3 - FIN\n");

    do
    {
        opcion = validarDatoEnteroEntreLimites("\nIngrese una opcion: ", 1, 3);
        switch (opcion)
        {
        case 1:
            resultado = crearArchivoStock(PATH_ARCHIVO_STOCK);
            if (resultado != TODO_OK)
                return resultado;
            break;
        case 2:
            resultado = leerArchivoStock(PATH_ARCHIVO_STOCK);
            if (resultado != TODO_OK) {
                printf("\nOcurrio un error al abrir el archivo.\n\n");
                system("pause");
                return resultado;
            }
            break;
        }
    } while (opcion != 3);

    printf("\n");
    system("pause");
    system("cls");

    printf("\nARCHIVO COMPRAS\n");
    printf("\n1 - GENERAR\n2 - LECTURA\n3 - FIN\n");
    do
    {
        opcion = validarDatoEnteroEntreLimites("\nIngrese una opcion: ", 1, 3);
        switch (opcion)
        {
        case 1:
            resultado = crearArchivoCompras(PATH_ARCHIVO_COMPRAS);
            if (resultado != TODO_OK)
                return resultado;
            break;
        case 2:
            resultado = leerArchivoCompras(PATH_ARCHIVO_COMPRAS);
            if (resultado != TODO_OK)
                return resultado;
            break;
        }
    } while (opcion != 3);

    printf("\n");
    system("pause");

    return TODO_OK;
}

int validarDatoEnteroMayorALimite(const char mensaje[], int limite)
{
    int dato;
    do
    {
        printf("%s", mensaje);
        scanf("%d", &dato);
    } while (dato <= limite);
    return dato;
}

int validarDatoEnteroEntreLimites(const char mensaje[], int limiteInferior, int limiteSuperior)
{
    int dato;
    do
    {
        printf("%s", mensaje);
        scanf("%d", &dato);
    } while (dato < limiteInferior || dato > limiteSuperior);
    return dato;
}

char aceptarOCancelar(const char mensaje[])
{
    char opcion;
    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = toupper(opcion);
    } while (opcion != 'S' && opcion != 'N');
    return opcion;
}

Producto crearRegistroStock()
{
    Producto producto;

    printf("\nIngrese codigo de articulo: ");
    fflush(stdin);
    fgets(producto.codigoArticulo, sizeof(producto.codigoArticulo), stdin);
    // gets(producto.codigoArticulo);

    printf("\nIngreses descripcion: ");
    fflush(stdin);
    fgets(producto.descripcion, sizeof(producto.descripcion), stdin);
    // gets(producto.descripcion);

    do
    {
        printf("\nIngrese precio unitario: ");
        scanf("%f", &producto.precioUnitario);
    } while (!(producto.precioUnitario > 0));

    producto.stock = validarDatoEnteroMayorALimite("\nIngrese stock: ", 0);

    return producto;
}

int crearArchivoStock(const char nombreArchivo[])
{
    FILE *archProd = fopen(nombreArchivo, "wb");
    if (!archProd)
        return ERROR_ARCHIVO;
    char opcion = 'S';
    while (opcion != 'N')
    {
        Producto producto = crearRegistroStock();
        fwrite(&producto, sizeof(Producto), 1, archProd);
        printf("\n----- DATOS VALIDADOS CORRECTAMENTE -----\n");
        opcion = aceptarOCancelar("\nDesea agregar mas datos? ('S' - Aceptar, 'N' - Cancelar): ");
    }
    fclose(archProd);
    return TODO_OK;
}

int leerArchivoStock(const char nombreArchivo[])
{
    FILE *archProd = fopen(nombreArchivo, "rb");
    if (!archProd)
        return ERROR_ARCHIVO;

    Producto producto;
    fread(&producto, sizeof(Producto), 1, archProd);

    printf("\nCOD. DE ARTICULO\tDESCRIPCION\t\tPRECIO UNITARIO\t\tSTOCK\n");

    while (!feof(archProd))
    {
        printf("\n\t%-5s\t\t%-21s\t$ %-12.2f\t\t%d\n", producto.codigoArticulo, producto.descripcion, producto.precioUnitario, producto.stock);
        fread(&producto, sizeof(Producto), 1, archProd);
    }

    fclose(archProd);
    return TODO_OK;
}

Compra crearRegistroCompra()
{
    Compra compra;

    compra.numeroOrdenDeCompra = validarDatoEnteroMayorALimite("\nIngrese numero de orden de compra: ", 0);
    compra.numeroProveedor = validarDatoEnteroEntreLimites("\nIngrese numero de proveedor: ", 1, 50);

    printf("\nIngrese codigo de articulo: ");
    fflush(stdin);
    fgets(compra.codigoArticulo, sizeof(compra.codigoArticulo), stdin);
    //gets(compra.codigoArticulo);

    printf("\nIngreses descripcion: ");
    fflush(stdin);
    fgets(compra.descripcion, sizeof(compra.descripcion), stdin);
    //gets(compra.descripcion);

    compra.dia = validarDatoEnteroEntreLimites("\nIngrese dia: ", 1, 30);
    compra.mes = validarDatoEnteroEntreLimites("\nIngrese mes: ", 1, 12);
    compra.cantidadPedida = validarDatoEnteroMayorALimite("\nIngrese cantidad pedida: ", 0);

    return compra;
}

int crearArchivoCompras(const char nombreArchivo[])
{
    FILE *archCompras = fopen(nombreArchivo, "wb");
    char opcion = 'S';
    if (!archCompras)
        return ERROR_ARCHIVO;
    while (opcion != 'N')
    {
        Compra compra = crearRegistroCompra();
        fwrite(&compra, sizeof(Compra), 1, archCompras);
        printf("\n----- DATOS VALIDADOS CORRECTAMENTE -----\n");
        opcion = aceptarOCancelar("\nDesea agregar mas datos? ('S' - Aceptar, 'N' - Cancelar): ");
    }
    fclose(archCompras);
    return TODO_OK;
}

int leerArchivoCompras(const char nombreArchivo[])
{
    FILE *archCompra = fopen(nombreArchivo, "rb");
    if (!archCompra)
        return ERROR_ARCHIVO;
    Compra compra;
    fread(&compra, sizeof(Compra), 1, archCompra);
    printf("\nORDEN DE COMPRA\t\tPROVEEDOR\tCODIGO DE ARTICULO\tDESCRIPCION\tDIA\tMES\t\tCANTIDAD PEDIDA\n");
    while (!feof(archCompra))
    {
        printf("\n\t%d\t\t\t%d\t\t\t%s\t\t%-11s\t%d\t%d\t\t%d\n", compra.numeroOrdenDeCompra, compra.numeroProveedor, compra.codigoArticulo, compra.descripcion, compra.dia, compra.mes, compra.cantidadPedida);
        fread(&compra, sizeof(Compra), 1, archCompra);
    }
    fclose(archCompra);
    return TODO_OK;
}