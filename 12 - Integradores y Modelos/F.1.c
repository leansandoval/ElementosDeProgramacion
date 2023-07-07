/*F.1 El Banco Cachi Sucursal San Justo dispone de un archivo llamada CUENTAS.dat, ordenado por Número de
cuenta, con el saldo de las cuentas de sus clientes hasta el día de ayer. Hay un registro por cuenta de cada
uno de sus casi 5000 clientes, con el siguiente diseño:
    • Número de cuenta (Nro. no correlativo entre 1000 y 35000)
    • Denominación (30 caracteres)
    • Total Sumas (float)
    • Total Restas(float)
    • Saldo (total sumas – total restas, con signo)

Se quiere confeccionar un programa para “actualizar” los 3 campos indicados de dicho archivo con los
movimientos producidos por los clientes en el día de la fecha. Por cada movimiento que se ingresa desde el
teclado, se informa:
    • Número de cuenta (entre 1000 y 35000)
    • Código de movimiento (‘E’: sumar ‘S ‘: restar)
    • Importe (float)

Estos movimientos NO se hallan ordenados y finalizan con un número de cuenta NEGATIVO.
Confeccionar un programa, diagrama más codificación, que realice lo siguiente:

    a. Ingrese la fecha del día del proceso (día, mes y año), para lo cual debe incluir en el programa y utilizar
    TRES veces la función CONTROL. NO se deben admitir valores erróneos, se deben volver a pedir. Los
    válidos son día 1/30, mes de 1/12 y año 2018.

    b. Debe generarse, en el main () un array de estructuras llamado ArrayCuentas con los datos del archivo
    Cuentas, mediante la confección de una función con parámetros, llamada GenArrayCuenta.

    c. Ingresar los movimientos que se informan y si alguna cuenta informada no se halla en el ArrayCuentas
    informarlo con un mensaje por pantalla, almacenar dicho número, código de movimiento e importe
    y continuar con otra. Si, la encuentra, efectuar actualización correspondiente. (no habrá más de 1000
    movimientos, no encontrados).

    d. Al finalizar el proceso listar todas las cuentas que han quedado con saldo cero o negativo. Si no hay
    cuentas en esta condición Imprimir “No hay cuentas con saldo 0 o negativo”.
                                        FECHA DE PROCESO: XX / XX / XXXX
                        Cuenta      Denominación    Total SUMAS     Total RESTAS    Saldo

    e. Listar las cuentas no encontradas, código de movimiento e importe, sin no hay imprimir mensaje
    aclaratorio.

    f. Con el ArrayCuentas actualizado generar un nuevo archivo llamado CUENTAS_DOS.*/

#include<stdio.h>
#include<windows.h>

typedef struct
{
    int nrocuenta;
    char denominacion[31];
    float suma,resta,saldo;
} T_Cuenta;

typedef struct
{
    int nrocuenta;
    char codmovimiento;
    float importe;
} T_Movi;

typedef struct
{
    int dia,mes,anio;
} T_Fecha;

T_Fecha CONTROL();
int GenArrayCuenta(T_Cuenta[],int);
int Busqueda(T_Cuenta[],int,int);
void MostrarCuentas(T_Cuenta[],int,T_Fecha);
void MostarCuentasNoEncontradas(T_Movi[],int);
void GenerarArch(T_Cuenta[],int);

int main()
{
    T_Cuenta ArrayCuentas[5000];
    T_Movi ArrayCuentasNoEncontradas[1000];
    T_Fecha fecha;
    int cant=GenArrayCuenta(ArrayCuentas,5000),nrocuenta,pos,i=0;
    char codmov;
    float importe;
    fecha=CONTROL();
    do
    {
        printf("\nIngrese numero de cuenta (Negativo para terminar): ");
        scanf("%d",&nrocuenta);
    }
    while(!(nrocuenta>=1000&&nrocuenta<=35000||nrocuenta<0));
    while(!(nrocuenta<0))
    {
        do
        {
            printf("\nIngrese codigo de movimiento: ");
            fflush(stdin);
            scanf("%c",&codmov);
        }
        while(!(codmov=='E'||codmov=='S'));
        do
        {
            printf("\nIngrese importe: ");
            scanf("%f",&importe);
        }
        while(importe<=0);
        pos=Busqueda(ArrayCuentas,cant,nrocuenta);
        if(pos!=-1)
        {
            if(codmov=='E')
            {
                ArrayCuentas[pos].saldo+=importe;
                ArrayCuentas[pos].suma+=importe;
            }
            else
            {
                ArrayCuentas[pos].saldo-=importe;
                ArrayCuentas[pos].resta-=importe;
            }
        }
        else
        {
            printf("\nEl numero de cuenta %d no fue encontrado\n",nrocuenta);
            if(i<1000-1)
            {
                ArrayCuentasNoEncontradas[i].nrocuenta=nrocuenta;
                ArrayCuentasNoEncontradas[i].codmovimiento=codmov;
                ArrayCuentasNoEncontradas[i].importe=importe;
                i++;
            }
        }
    }
    MostrarCuentas(ArrayCuentas,cant,fecha);
    if(i!=0)
        MostarCuentasNoEncontradas(ArrayCuentasNoEncontradas,i);
    else
        printf("\nTodas las cuentas ingresadas se han encontrado...\n");
    GenerarArch(ArrayCuentas,cant);
}

T_Fecha CONTROL()
{
    T_Fecha aux;
    int band;
    printf("\nIngrese fecha del dia del proceso\n");
    do
    {
        printf("\nIngrese dia: ");
        scanf("%d",&aux.dia);
        do
        {
            printf("\nIngrese mes: ");
            scanf("%d",&aux.mes);
            do
            {
                printf("\nIngrese anio: ");
                scanf("%d",&aux.anio);
            }
            while(aux.anio!=2018);
            if(band==1)
            {
                system("cls");
                printf("\nLa fecha ingresada no es valida. Por favor, ingrese nuevamente\n");
            }
            band=1;
        }
        while(!(aux.mes>=1&&aux.mes<=12));
    }
    while(!(aux.dia>=1&&aux.dia<=30));
    return aux;
}

int GenArrayCuenta(T_Cuenta v[],int ce)
{
    FILE *pf;
    T_Cuenta aux;
    int i=0;
    pf=fopen("CUENTAS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo... \n");
        system("pause");
        exit(1);
    }
    fread(&aux,sizeof(T_Cuenta),1,pf);
    while(!feof(pf))
    {
        v[i]=aux;
        i++;
        fread(&aux,sizeof(T_Cuenta),1,pf);
    }
    fclose(pf);
    return i;
}

int Busqueda(T_Cuenta v[],int ce,int x)
{
    int primero=0,ultimo=ce-1,central=0,pos=-1;
    while(primero<=ultimo&&pos==-1)
    {
        central=(primero+ultimo)/2;
        if(x==v[central].nrocuenta)
            pos=central;
        else if(x>v[central].nrocuenta)
            primero=central+1;
        else
            ultimo=central-1;
    }
    return pos;
}

void MostrarCuentas (T_Cuenta v[],int ce,T_Fecha fecha)
{
    int i,band=0;
    printf("\n\t\t\tFECHA DE PROCESO:\t%d/%d/%d\n",fecha.dia,fecha.mes,fecha.anio);
    printf("\nCuenta\tDenominacion\tTotal SUMAS\tTotal Restas\tSaldo\n");
    for(i=0; i<=ce-1; i++)
        if(v[i].saldo<=0)
        {
            printf("%d\t%c\t%.2f\t%.2f\t.2f\n",v[i].nrocuenta,v[i].denominacion,v[i].suma,v[i].resta,v[i].saldo);
            band=1;
        }
    if(band==0)
    {
        system("cls");
        printf("\nNo hay cuentas con saldo 0 o negativo\n");
    }
}

void MostarCuentasNoEncontradas(T_Movi v[],int ce)
{
    int i;
    printf("\n\tCUENTAS NO ENCONTRADAS\n");
    printf("\nCuenta\tCod. Movimiento\tImporte\n");
    for(i=0; i<=ce-1; i++)
        printf("\n%d\t%c\t%.2f\n",v[i].nrocuenta,v[i].codmovimiento,v[i].importe);
}

void GenerarArch(T_Cuenta v[],int ce)
{
    FILE *pf;
    int i;
    pf=fopen("CUENTAS_DOS.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        system("pause");
        exit(1);
    }
    for(i=0; i<=ce-1; i++)
        fwrite(&v[i],sizeof(T_Cuenta),1,pf);
    fclose(pf);
}
