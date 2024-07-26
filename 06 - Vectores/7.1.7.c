#include<stdio.h>
#include<windows.h>
void PonerEnCero(int[],int);
int esDatoVal(int,int,int);
int esDatoVal2(int,int);
int IngrDNIVal(int,int,int);
int IngrCodigoVal(int,int);
float IngrSueldoVal(int);
int CargaEmpleados(int[],int[],float[],int);
void CuentaPorSector(int[],int[],int);
void MostrarCantSector(int[],int[]);
float TotalAPagar(float[],int);
void OrdenarCantSector(int[],int []);

int main()
{
    int VDni[100],VCod[100],cant=0,VSector[5]={1,2,3,4,5},VCantSector[5];
    float VSuel[100],suma=0;
    PonerEnCero(VCantSector,5);
    cant=CargaEmpleados(VDni,VCod,VSuel,100);
    if(cant>0)
    {
        suma=TotalAPagar(VSuel,cant);
        CuentaPorSector(VCantSector,VCod,cant);
        MostrarCantSector(VSector,VCantSector);
        printf("\nImporte total de sueldos: %.2f",suma);
        OrdenarCantSector(VSector,VCantSector);
        printf("\n");
        printf("\nCantidades ordenadas");
        printf("\n");
        MostrarCantSector(VSector,VCantSector);
    }
    else
        printf("\nNo hay empleados");
    printf("\n\n");
    system("pause");
    printf("\n");
}

void PonerEnCero (int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}
int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int IngrDNIVal(int lim1,int lim2,int lim3)
{
    int dato;
    do
    {
        printf("\nIngrese DNI del alumno (99 para terminar): ");
        scanf("%d",&dato);
    }while(esDatoVal(dato,lim1,lim2)==0&&dato!=lim3);
    return dato;
}

int esDatoVal2(int x,int lim)
{
    if(x>lim)
        return 1;
    else
        return 0;
}

float IngrSueldoVal (int lim)
{
    float dato;
    do
    {
        printf("\nIngrese sueldo correspondiente: ");
        scanf("%f",&dato);
    }while(esDatoVal2(dato,lim)==0);
    return dato;
}

int IngrCodigoVal(int lim1,int lim2)
{
    int dato;
    do
    {
        printf("\nIngrese codigo del sector (del %d al %d): ",lim1,lim2);
        scanf("%d",&dato);
    }while(esDatoVal(dato,lim1,lim2)==0);
    return dato;
}

int CargaEmpleados(int a[],int b[], float c[],int ce)
{
    int i=0,dni,codigo;
    float sueldo;
    dni=IngrDNIVal(10000000,99999999,99);
    while(dni!=99&&i<ce)
    {
        codigo=IngrCodigoVal(1,5);
        sueldo=IngrSueldoVal(0);
        a[i]=dni;
        b[i]=codigo;
        c[i]=sueldo;
        i++;
        dni=IngrDNIVal(10000000,99999999,99);
    }
    return i;
}

float TotalAPagar(float v[],int ce)
{
    int i,suma=0;
    for(i=0;i<=ce-1;i++)
        suma+=v[i];
    return suma;
}

void CuentaPorSector(int d[],int b[],int ce)
{
    int i,indiceSector,sector;
    for(i=0;i<=ce-1;i++)
        {
            sector=b[i];
            indiceSector=sector-1;
            d[indiceSector]+=1;
        }
}

void MostrarCantSector(int e[],int d[])
{
    int i;
    printf("\n || SECTOR || CANTIDAD || \n");
    for(i=0; i < 5; i++)
        printf(" ||   %d    ||    %d     || \n",e[i],d[i]);
}

void OrdenarCantSector(int e[], int d[])
{
    int i,desordenado=1,cota=4,auxSector,auxCantidad;
    while(desordenado)
    {
        desordenado = 0;
        for(i = 0; i < cota; i++)
            if(d[i] > d[i+1])
                {
                    auxSector = e[i+1];
                    auxCantidad = d[i+1];
                    e[i+1] = e[i];
                    d[i+1] = d[i];
                    e[i] = auxSector;
                    d[i] = auxCantidad;
                    desordenado = i;
                }
        cota = desordenado;
    }
}
