#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int esDatoVal2(int,int);
int esDatoValReal(float,float);
int IngrDatoVal2(int);
float IngrDatoValReal(float);

void PonerEnCero(int[],int);
int Minimo(int[],int);
float SumaVecReal(float[],int);
void GeneraVReacaudacion(float[],float[],int[],int);

int CargaCod(char[][4],float[],int);
void CargaVentas(char[][4],float[],int[],int);
int BusquedaSecChar(char[][4],char[],int);
void BurbujeoChar(char[][4],float[],int[],int);
void MostrarVCharParalelo(char[][4],float[],int[],int);
void MostrarIgualQueVParalelos(char[][4],int[],int,int);


int main()
{
    int VVentas[50],cant,min;
    float VPrecio[50],VRecaudacion[50],sum;
    char VCodigos[50][4];
    PonerEnCero(VVentas,50);
    cant=CargaCod(VCodigos,VPrecio,50);
    if(cant>0)
    {
        CargaVentas(VCodigos,VPrecio,VVentas,cant);
        MostrarVCharParalelo(VCodigos,VPrecio,VVentas,cant);
        GeneraVReacaudacion(VRecaudacion,VPrecio,VVentas,cant);
        sum=SumaVecReal(VRecaudacion,cant);
        printf("\n\nRecaudacion total del dia: %.2f",sum);
        min=Minimo(VVentas,cant);
        MostrarIgualQueVParalelos(VCodigos,VVentas,cant,min);
        BurbujeoChar(VCodigos,VPrecio,VVentas,cant);
        printf("\n\nListado ordenado en forma alfabetica por codigo de producto: \n");
        MostrarVCharParalelo(VCodigos,VPrecio,VVentas,cant);
    }
    else
        printf("\nNo hubo ventas");
    printf("\n\n");
    system("pause");
}

int esDatoVal2(int x,int lim)
{
    if(x>=lim)
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
    float precio,band=0;
    do
    {
        if(band==1)
        {
            printf("\nPrecio incorrecto");
            printf("\n");
        }
        band=1;
        printf("\nIngrese precio unitario correspondiente: ");
        scanf("%f",&precio);
    }while(esDatoValReal(precio,lim)==0);
    return precio;
}

int IngrDatoVal2(int lim)
{
    int dato,band=0;
    do
    {
        if(band==1)
        {
            printf("\nDato incorrecto, ingrese nuevamente");
            printf("\n");
        }
        band=1;
        printf("\nIngrese la cantidad de ventas (0 para terminar): ");
        scanf("%d",&dato);
    }while(esDatoVal2(dato,lim)==0);
    return dato;
}

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

int CargaCod (char c[][4],float v[],int f)
{
    int i=0,pos;
    float precio;
    char cod[4];
    printf("\nIngrese codigo de producto alfanumerico (3 caracteres) FIN para terminar: ");
    fflush(stdin);
    gets(cod);
    while(strcmpi(cod,"FIN")!=0&&i<f)
    {
        pos=BusquedaSecChar(c,cod,i);
        if(pos==-1)
        {
           strcpy(c[i],cod);
            precio=IngrDatoValReal(0);
            v[i]=precio;
            i++;
            printf("\nIngrese codigo de producto alfanumerico (3 caracteres) FIN para terminar: ");
            fflush(stdin);
            gets(cod);
        }
        else
        {
            printf("\nEl codigo ya fue ingresado anteriormente");
            printf("\nIngrese codigo de producto alfanumerico (3 caracteres) FIN para terminar: ");
            fflush(stdin);
            gets(cod);
        }
    }
    return i;
}

void CargaVentas (char c[][4],float a[],int b[],int f)
{
    int cant,pos;
    char aux[4];
    cant=IngrDatoVal2(0);
    while(cant!=0)
    {
        do
        {
            printf("\nIngrese el codigo de producto correspondiente a las ventas: ");
            fflush(stdin);
            gets(aux);
            pos=BusquedaSecChar(c,aux,f);
            if(pos==-1)
                printf("\nEl codigo ingresado no aparece en la lista\n");
        }while(pos==-1);
        b[pos]+=cant;
        cant=IngrDatoVal2(0);
    }
}

int BusquedaSecChar(char c[][4],char aux[],int f)
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

void MostrarVCharParalelo(char c[][4],float a[],int b[],int f)
{
    int i;
    printf("\nCODIGO\tPRECIO\tVENTAS");
    printf("\n");
    for (i=0;i<f;i++)
        printf("\n%s\t%.2f\t%d",c[i],a[i],b[i]);
}

void GeneraVReacaudacion (float a[],float b[],int c[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        a[i]=(float)b[i]*c[i];
}

float SumaVecReal (float v[],int ce)
{
    int i;
    float s=0;
    for(i=0;i<=ce-1;i++)
        s+=v[i];
    return s;
}

int Minimo (int v[],int ce)
{
    int i,menor=0;
    for(i=0;i<=ce-1;i++)
        if(v[i]>0&&(menor==0||v[i]<menor))
            menor=v[i];
    return menor;
}

void MostrarIgualQueVParalelos(char c[][4],int v[],int f,int x)
{
    int i;
    printf("\n\nProducto/productos que vendieron la menor cantidad de unidades:");
    printf("\n");
    for(i=0;i<=f-1;i++)
        if(v[i]==x)
            printf("%s",c[i]);
}

void BurbujeoChar(char c[][4],float a[],int b[],int f)
{
    int i,j,aux3;
    char aux[4];
    float aux2;
    for (i=0;i<f-1;i++)
    {
        for (j=0;j<f-1-i;j++)
        {
            if (strcmpi(c[j],c[j+1])>0)
                {
                    strcpy(aux,c[j]);
                    strcpy(c[j],c[j+1]);
                    strcpy(c[j+1],aux);
                    aux2=a[j];
                    a[j]=a[j+1];
                    a[j+1]=aux2;
                    aux3=b[j];
                    b[j]=b[j+1];
                    b[j+1]=aux3;
                }
        }
    }
}
