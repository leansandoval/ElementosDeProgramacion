#include<stdio.h>
#include<string.h>
#include<windows.h>
#define autosgama 15

int esDatoValReal(float,float);
int esDatoValInt(int,int);
float IngrDatoValReal(float);
int IngrDatoValInt(int);
void CargaPatentes(char[][7],int);
int BusquedaSecChar(char[][7],char[],int);
int esFechaValida(int,int,int);
int CantidadDiasDelMes(int,int);
int Bisiesto(int);
int CargaAutos(char[][7],char[][7],int[],float[],int);
void GeneraVPPesos(float[],float[],int,int);
void MostrarAlquiler(char[][7],int[],float[],int,int[],int[],int[]);
float SumaVecFloat(float[],int);
int main()
{
    int d,m,a,band=0,VDiasAlquiler[autosgama],cant,VDia[autosgama],VMes[autosgama],VAnio[autosgama];
    float cotiz,VPrecioDolar[autosgama],VPrecioPesos[autosgama],porcent;
    char VPatentes[autosgama][7],VAutos[autosgama][7];
    CargaPatentes(VPatentes,autosgama);
    do
    {
        if(band==1)
            printf("\nFecha no valida, ingrese nuevamente");
        band=1;
        printf("\n\nIngrese fecha actual en formato DDMMAAAA:\n");
        printf("\n");
        scanf("%d%d%d",&d,&m,&a);
    }while(esFechaValida(d,m,a)==0);
    printf("\nCotiazion del dolar a la fecha: ");
    cotiz=IngrDatoValReal(0);
    cant=CargaAutos(VPatentes,VAutos,VDiasAlquiler,VPrecioDolar,autosgama);
    if(cant>0)
    {
        GeneraVPPesos(VPrecioPesos,VPrecioDolar,cant,cotiz);
        SumarNFechas(d,m,a,VDia,VMes,VAnio,VDiasAlquiler,cant);
        printf("\n\t\t\t\t   ALQUILER DE AUTOS DEL DIA: %d--%d--%d\n",d,m,a);
        printf("\n\t\t\t\t\tCOTIZACION DEL DOLAR: $ %.2f\n",cotiz);
        MostrarAlquiler(VAutos,VDiasAlquiler,VPrecioPesos,cant,VDia,VMes,VAnio);
        printf("\nTOTAL RECAUDADO POR ALQUILER (EN PESOS): $ %.2f\n",SumaVecFloat(VPrecioPesos,cant));
        printf("\nTOTAL RECAUDADO POR ALQUILER (EN DOLARES): U$S %.2f\n",SumaVecFloat(VPrecioDolar,cant));
        porcent=(float)(cant*100)/30;
        printf("\nPORCENTAJE DE AUTOS ALQUILADOS DURANTE EL DIA: %.2f",porcent);
    }
    else
        printf("\nNo hubo alquileres");
    printf("\n\n");
    system("pause");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int esDatoValInt(int x,int lim)
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

int IngrDatoValInt(int lim)
{
    int dato,band=0;
    do
    {
        if(band==1)
            printf("\nDato incorrecto, ingrese nuevamente: ");
        band=1;
        scanf("%d",&dato);
    }while(esDatoValInt(dato,lim)==0);
    return dato;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CargaPatentes(char c[][7],int f)
{
    int i,pos;
    char patente[7];
    for(i=0;i<=f-1;i++)
        {
            do
            {
                printf("\nIngrese numero de patente del auto %d: ",i+1);
                fflush(stdin);
                gets(patente);
                pos=BusquedaSecChar(c,patente,i);
                if(pos!=-1)
                    printf("\nLa patente ya fue ingresada, por favor ingrese otra\n");
            }while(pos!=-1);
            strcpy(c[i],patente);
        }
}

int BusquedaSecChar(char c[][7],char aux[],int f)
{
    int i=0,pos=-1;
    while(pos==-1&&i<f)
    {
        if(strcmpi(c[i],aux)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int esFechaValida(int d,int m,int a)
{
    int r=0;
    if(a>=1950&&a<=2020)
        if(m>=1&&m<=12)
            if(d>=1&&d<=CantidadDiasDelMes(m,a))
                r=1;
    return r;
}

int CantidadDiasDelMes(int m,int a)
{
    int cdm=0;
    if(m==4||m==6||m==9||m==11)
        cdm=30;
    else
        if(m==2)
            cdm=28+Bisiesto(a);
        else
            cdm=31;
    return cdm;
}

int Bisiesto(int a)
{
    if(a%4==0&&a%100!=0||a%400==0)
        return 1;
    else
        return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CargaAutos (char c[][7],char d[][7],int a[],float b[],int f)
{
    int i=0,pos,dias;
    float precio;
    char patente[7];
    printf("\nIngrese patente del auto a buscar (FINDIA para terminar): ");
    fflush(stdin);
    gets(patente);
    while(strcmpi(patente,"FINDIA")!=0&&i<f)
    {
        pos=BusquedaSecChar(c,patente,autosgama);
        if(pos!=-1)
        {
            strcpy(d[i],patente);
            printf("\nCantidad de dias de alquiler: ");
            dias=IngrDatoValInt(0);
            a[i]=dias;
            printf("\nPrecio diario del alquier en dolares: ");
            precio=IngrDatoValReal(0);
            b[i]=precio;
            i++;
            printf("\nIngrese patente del auto a buscar (FINDIA para terminar): ");
            fflush(stdin);
            gets(patente);
        }
        else
        {
            printf("\nLa patente ingresada no se encuentra en la lista\n");
            printf("\nIngrese patente del auto a buscar (FINDIA para terminar): ");
            fflush(stdin);
            gets(patente);
        }
    }
    return i;
}

void GeneraVPPesos (float a[],float b[],int ce,int x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        a[i]=(float)b[i]*x;
}

void MostrarAlquiler(char c[][7],int a[],float b[],int f,int vd[],int vm[],int va[])
{
    int i;
    printf("\n\tNRO. DE AUTO\tDIAS DE ALQUILER\tPRECIO DEL ALQUILER EN PESOS\tFECHA DE DEVOLUCION DEL AUTO\n");
    for(i=0;i<=f-1;i++)
        printf("\n\t%s\t\t\t%d\t\t\t$ %.2f\t\t\t%d/%d/%d",c[i],a[i],b[i],vd[i],vm[i],va[i]);
    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float SumaVecFloat (float v[],int ce)
{
    int i;
    float s=0;
    for(i=0;i<=ce-1;i++)
        s+=v[i];
    return s;
}

void SumarNFechas (int d,int m,int a,int vd[],int vm[],int va[], int da[],int f)
{
    int i;
    for(i=0;i<=f-1;i++)
    {
        vd[i]=d+da[i];
        vm[i]=m;
        va[i]=a;
        while(vd[i]>CantidadDiasDelMes(m,a))
        {
            vd[i]-=CantidadDiasDelMes(m,a);
            vm[i]++;
            if(m>12)
            {
                vm[i]=1;
                va[i]++;
            }
        }
    }
}
