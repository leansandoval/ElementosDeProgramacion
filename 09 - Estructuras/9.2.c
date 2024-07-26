/*9.2. Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:

    • Código del medicamento (entero, de 3 cifras).
    • Precio (real).
    • Stock (entero).

Se solicita:

    a. Declarar un tipo de dato que contenga la información del medicamento.
    b. Declarar un vector de estructura de tipo de datos creado en a.
    c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
    d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
    e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.*/

#include<stdio.h>
#include<stdlib.h>
#define tope 50

typedef struct
{
    int codigo,stock;
    float precio;
} T_Medi;

int esDatoVal(int,int,int);
int esDatoVal2(int,int);
int esDatoValReal(float,float);
int IngrDatoVal(int,int);
int IngrDatoVal2(int);
float IngrDatoValReal(float);
void Ingreso(T_Medi[],int);
int Busqueda_Medi(T_Medi[],int,int);
void Informe(T_Medi[],int);

int main()
{
    T_Medi VMedi[tope];
    int aux,pos;
    Ingreso(VMedi,tope);
    printf("\nIngrese un codigo de medicamento YA INGRESADO (0 para terminar): ");
    scanf("%d",&aux);
    while(aux!=0)
    {
        pos=Busqueda_Medi(VMedi,tope,aux);
        if(pos!=-1)
        {
            printf("\nEl precio del medicamento es $%.2f\n",VMedi[pos].precio);
            printf("\nIngrese un codigo de medicamento YA INGRESADO (0 para terminar): ");
            scanf("%d",&aux);
        }
        else
        {
            printf("\nEl codigo de medicamente no existe\n");
            printf("\nIngrese un codigo de medicamento YA INGRESADO (0 para terminar): ");
            scanf("%d",&aux);
        }
    }
    Informe(VMedi,tope);
}

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int esDatoVal2(int x,int lim)
{
    if(x>lim)
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

int IngrDatoVal(int limi,int lims)
{
    int dato,band=0;
    do
    {
        if(band==1)
            printf("\nDato incorrecto, ingrese nuevamente: ");
        band=1;
        scanf("%d",&dato);
    }
    while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

int IngrDatoVal2(int lim)
{
    int dato,band=0;
    do
    {
        if(band==1)
            printf("\nDato incorrecto, ingrese nuevamente: ");
        band=1;
        scanf("%d",&dato);
    }
    while(esDatoVal2(dato,lim)==0);
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
    }
    while(esDatoValReal(dato,lim)==0);
    return dato;
}

void Ingreso(T_Medi v[],int ce)
{
    T_Medi aux;
    int i,pos;
    for(i=0; i<=ce-1; i++)
    {
        do
        {
            printf("\nIngrese codigo de producto: ");
            aux.codigo=IngrDatoVal(100,999);
            pos=Busqueda_Medi(v,i,aux.codigo);
            if(pos!=-1)
                printf("\nEl codigo ya fue ingresado anteriormente, ingrese otro\n");
        }
        while(!(pos==-1));
        printf("\nIngrese precio: ");
        aux.precio=IngrDatoValReal(0);
        printf("\nIngrese stock: ");
        aux.stock=IngrDatoVal2(0);
        v[i]=aux;
    }
}

int Busqueda_Medi (T_Medi v[],int ce,int x)
{
    int i=0,pos=-1;
    while(pos==-1&&i<ce)
    {
        if(v[i].codigo==x)
            pos=i;
        else
            i++;
    }
    return pos;
}

void Informe(T_Medi v[],int ce)
{
    T_Medi aux;
    int i;
    printf("\nCODIGO\tPRECIO\tSTOCK\n");
    for(i=0; i<=ce-1; i++)
        if(v[i].stock<10)
            printf("\n%d\t$%.2f\t%d\n",v[i].codigo,v[i].precio,v[i].stock);
}
