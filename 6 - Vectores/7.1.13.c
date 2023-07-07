#include<stdio.h>
#include<windows.h>

int esDatoVal(int,int,int);
int esDatoValReal(float,float);
int IngrDatoVal(int,int,int);
float IngrDatoValReal(float);

void PonerEnCero(float [],int);
int CargaVec(float[],int);
void ImprimeReal(float [],int);

float SumaReal(float[],int);
float PromedioReal(float[],int,int);
int ContarMayorA(float[],int,int);

float MayorRealPositivo(float[],int);
float MenorRealPositivo(float[],int);
void MostrarIgualQue(float[],int,float);

void NoParticipa(float[],int);

int main()
{
    int cant;
    float VTiempo[60],prom,max,min;
    PonerEnCero(VTiempo,60);
    cant=CargaVec(VTiempo,60);
    ImprimeReal(VTiempo,60);
    prom=(float)PromedioReal(VTiempo,60,cant);
    max=MayorRealPositivo(VTiempo,60);
    min=MenorRealPositivo(VTiempo,60);
    printf("\n\nNumero de auto que clasifico en primer lugar:\n");
    MostrarIgualQue(VTiempo,60,min);
    printf("\n\nNumero de auto que obtuvo el peor tiempo de clasificacion:\n");
    MostrarIgualQue(VTiempo,60,max);
    printf("\n\nCantidad de autos que superaron el promedio de tiempo de clasificacion: %d",ContarMayorA(VTiempo,60,prom));
    printf("\n");
    NoParticipa(VTiempo,60);
    printf("\n\n");
    system("pause");
    printf("\n");
}

/////////////////////////////////////////////////////////////////////////////////

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int IngrDatoVal(int lim1,int lim2,int lim3)
{
    int num,band=0;
    do
    {
        if(band==1)
        {
            printf("\nNumero incorrecto");
            printf("\n");
        }
        band=1;
        printf("\nIngrese numero del auto (numero negativo para terminar): ");
        scanf("%d",&num);
    }while(esDatoVal(num,lim1,lim2)==0&&num>=lim3);
    return num;
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
    float tiempo,band=0;
    do
    {
        if(band==1)
        {
            printf("\nTiempo incorrecto");
            printf("\n");
        }
        band=1;
        printf("\nIngrese tiempo correspondiente: ");
        scanf("%f",&tiempo);
    }while(esDatoValReal(tiempo,lim)==0);
    return tiempo;
}

/////////////////////////////////////////////////////////////////////////////////

void PonerEnCero(float v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

int CargaVec(float v[],int ce)
{
    int i,cant=0;
    float tiempo,sum=0,prom;
    i=IngrDatoVal(1,60,0);
    while(!(i<0))
    {
        tiempo=IngrDatoValReal(0);
        cant++;
        v[i-1]=tiempo;
        i=IngrDatoVal(1,60,0);
    }
    return cant;
}

void ImprimeReal(float v[],int ce)
{
    int i;
    printf("\nNUMERO DE AUTO\t\tTIEMPO DE LLEGADA");
    printf("\n");
    for(i=0;i<=ce-1;i++)
        if(v[i]>0   )
    {
        printf("\n%d\t\t\t%.2f",i+1,v[i]);
    }
}

/////////////////////////////////////////////////////////////////////////////////

float MayorRealPositivo (float v[],int ce)
{
    int i;
    float mayor=0;
    for(i=0;i<=ce-1;i++)
        if(mayor==0||v[i]>mayor)
            mayor=v[i];
    return mayor;
}

float MenorRealPositivo (float v[],int  ce)
{
    float menor=0;
    int i;
    for(i=0;i<=ce-1;i++)
        if(v[i]>0&&(menor==0||menor>v[i]))
            menor=v[i];
    return menor;
}

void MostrarIgualQue(float a[],int ce,float x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(a[i]==x)
            printf("\n%d",i+1);
}

/////////////////////////////////////////////////////////////////////////////////

void NoParticipa(float v[],int ce)
{
    int i,cont=0;
    for(i=0;i<=ce-1;i++)
        if(v[i]==0)
            cont++;
    printf("\nCantidad de autos que no participan: %d",cont);
}

/////////////////////////////////////////////////////////////////////////////////

float SumaReal(float v[],int ce)
{
    int i;
    float s=0;
    for(i=0;i<=ce-1;i++)
        s+=v[i];
    return s;
}

float PromedioReal(float a[],int ce,int cant)
{
    return (float)SumaReal(a,ce)/cant;
}

int ContarMayorA(float v[],int ce,int x)
{
    int c=0,i;
    for(i=0;i<=ce-1;i++)
        if(v[i]>x)
            c++;
    return c;
}
