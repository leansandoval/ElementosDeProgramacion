#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int esDatoVal(int,int,int);
int ControlDatos(int,int);
int IngrDatoVal3(int,int,int);
int esFechaValida(int,int,int);
int CantidadDiasDelMes(int,int);
int Bisiesto(int);

void PonerEnCero(int[],int);
void PonerEnCeroReal(float[],int);
void PonerMatEnCero(float[][15],int,int);

void CargaInicial(int[],int[],int);
void CargaGomero(int[],int);

int Busqueda(int[],int,int);
void Ordenamiento(float[],int[],int);

void SumarFilaMatEnV(float[][15],float[],int,int);
float SumaReal(float[],int);

float MenorRealPositivo(float[],int);
int Maximo(int[],int);

void MostrarIgualQueVParalelos(float[],int[],int,float);
void MostrarIgualQueVParalelos2(int[],int[],int,int);
void Listado(int[],float[],int);
void MostrarMayorQue(int[],int[],int);

int main()
{
    int VGomero[5],VUniStock[15],VStockMin[15],d,m,a,band=0,VCantVentasPorGomero[5],nrogomero,pos,nrocubierta,cant,cantmin=0,nrocubiertamin,stockactual,max;
    float MVentas[5][15],importe,venta,impVentasRechazadas=0,VVentasPorCubierta[15],VVentasPorGomero[5],min;
    PonerEnCero(VCantVentasPorGomero,5);
    PonerEnCeroReal(VVentasPorCubierta,15);
    PonerEnCeroReal(VVentasPorGomero,5);
    PonerMatEnCero(MVentas,5,15);
    do
    {
        if(band==1)
            printf("\nFecha no valida\n");
        band=1;
        printf("\n3) Ingrese fecha actual en formato DD-MM-AAAA\n");
        printf("\nIngrese dia: ");
        scanf("%d",&d);
        printf("\nIngrese mes: ");
        scanf("%d",&m);
        printf("\nIngrese anio: ");
        scanf("%d",&a);
    }while(esFechaValida(d,m,a)==0);
    system("cls");
    CargaInicial(VUniStock,VStockMin,15);
    system("cls");
    CargaGomero(VGomero,5);
    system("cls");
    printf("\n5) VENTAS DE LA EMPRESA CAUCHOS SA\n");
    do
    {
        printf("\nIngrese numero de gomero cargado anteriormente (0 para terminar): ");
        nrogomero=IngrDatoVal3(30,50,0);
        pos=Busqueda(VGomero,5,nrogomero);
        if(pos==-1&&nrogomero!=0)
            printf("\nEl numero ingresado no aparece en la lista\n");
    }while(pos==-1&&nrogomero!=0);
    while(nrogomero!=0)
    {
        printf("\nIngrese el numero de cubierta (entre 1 y 15): ");
        nrocubierta=ControlDatos(1,15);
        do
        {
            printf("\nIngrese importe: ");
            scanf("%f",&importe);
        }while(!(importe>0));
        do
        {
            printf("\nIngrese cantidad vendida: ");
            scanf("%d",&cant);
        }while(!(cant>0));
        venta=(float)importe*cant;
        if(VUniStock[nrocubierta-1]>=cant)
        {
            if(cantmin==0||cant<cantmin)
            {
                cantmin=cant;
                nrocubiertamin=nrocubierta;
            }
            MVentas[pos][nrocubierta-1]+=venta;
            VCantVentasPorGomero[pos]++;
            stockactual=VUniStock[nrocubierta-1]-cant;
            if(stockactual<VStockMin[nrocubierta-1])
            {
                printf("\n7) El stock quedo por debajo del minimo\n");
                VUniStock[nrocubierta-1]=stockactual;
            }
            else
                VUniStock[nrocubierta-1]=stockactual;
            do
            {
                printf("\nIngrese numero de gomero cargado anteriormente (0 para terminar): ");
                nrogomero=IngrDatoVal3(30,50,0);
                pos=Busqueda(VGomero,5,nrogomero);
                if(pos==-1&&nrogomero!=0)
                    printf("\nEl numero ingresado no aparece en la lista\n");
            }while(pos==-1&&nrogomero!=0);
        }
        else
        {
            printf("\n6) No se pudo realizar la venta (no hay stock suficiente)\n");
            impVentasRechazadas+=venta;
            do
            {
                printf("\nIngrese numero de gomero cargado anteriormente (0 para terminar): ");
                nrogomero=IngrDatoVal3(30,50,0);
                pos=Busqueda(VGomero,5,nrogomero);
                if(pos==-1&&nrogomero!=0)
                    printf("\nEl numero ingresado no aparece en la lista\n");
            }while(pos==-1&&nrogomero!=0);
        }
    }
    system("cls");
    printf("\n8) Numero de cubierta que vendio la menor cantidad en una venta durante el dia: %d\n",nrocubiertamin);
    SumarFilaMatEnV(MVentas,VVentasPorGomero,5,15);
    min=MenorRealPositivo(VVentasPorGomero,5);
    printf("\n9) Numero/numeros de gomero/gomeros que realizo/realizaron la menor recaudacion de ventas: \n");
    MostrarIgualQueVParalelos(VVentasPorGomero,VGomero,5,min);
    printf("\n10) Numeros/numeros de gomero/gomeros que no registraron ventas: \n");
    MostrarIgualQueVParalelos(VVentasPorGomero,VGomero,5,0);
    max=Maximo(VCantVentasPorGomero,5);
    printf("\n11) Gomeros con mas ventas\n");
    MostrarIgualQueVParalelos2(VCantVentasPorGomero,VGomero,5,max);
    Ordenamiento(VVentasPorGomero,VGomero,5);
    printf("\n12) VENTAS DE FECHA %d/%d/%d\n",d,m,a);
    Listado(VGomero,VVentasPorGomero,5);
    printf("\nTOTAL DE VENTAS: $ %.2f\n",SumaReal(VVentasPorGomero,5));
    printf("\n13) Cubiertas que no estan por debajo del stock minimo: \n");
    MostrarMayorQue(VUniStock,VStockMin,15);
    printf("\n14) Importe total perdido por ventas rechazadas: $ %.2f\n",impVentasRechazadas);
}

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int IngrDatoVal3(int lim1,int lim2,int lim3)
{
    int dato,band=0;
    do
    {
        if(band==1)
            printf("\nDato incorrecto, ingrese nuevamente: ");
        band=1;
        scanf("%d",&dato);
    }while(esDatoVal(dato,lim1,lim2)==0&&dato!=lim3);
    return dato;
}

int ControlDatos(int limi,int lims)
{
    int dato,band=0;
    do
    {
        if(band==1)
            printf("\nDato incorrecto, ingrese nuevamente: ");
        band=1;
        scanf("%d",&dato);
    }while(!(dato>=limi&&dato<=lims));
    return dato;
}

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

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void PonerEnCeroReal(float v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void PonerMatEnCero (float m[][15],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            m[i][j]=0;
}

void CargaInicial (int a[],int b[],int ce)
{
    int ustock,stockmin,i;
    char opcion;
    printf("\n1) CARGA LOTE 1\n");
    do
    {
        printf("\nPresione 'S' para cargar los datos manualmente o 'N' para cargar lote de prueba: ");
        fflush(stdin);
        scanf("%c",&opcion);
    }while(!(opcion=='N'||opcion=='n'||opcion=='S'||opcion=='s')); //CORRECCION

    if(opcion=='S'||opcion=='s')
    {
        for(i=0;i<=ce-1;i++)
        {
            printf("\nSTOCK DE LA CUBIERTA NUMERO %d\n",i+1);
            printf("\nIngrese unidades en stock (entre 1 a 5000): ");
            ustock=ControlDatos(1,5000);
            a[i]=ustock;
            do
            {
                printf("\nIngrese stock minimo: ");
                scanf("%d",&stockmin);
            }while(!(stockmin>0));
            b[i]=stockmin;
        }
    }
    else
    {
        a[0]=100;a[1]=5;a[2]=55;a[3]=5000;a[4]=450;a[5]=35;a[6]=11;a[7]=22;a[8]=1872;a[9]=10;a[10]=4800;a[11]=8;a[12]=88;a[13]=81;a[14]=893;
        b[0]=25;b[1]=2;b[2]=22;b[3]=2200;b[4]=150;b[5]=10;b[6]=2;b[7]=1;b[8]=600;b[9]=1;b[10]=1000;b[11]=2;b[12]=2;b[13]=22;b[14]=60;
    }
}

void CargaGomero(int v[],int ce)
{
    int i,nrogomero,pos;
    char opcion;
    printf("\n2) CARGA DEL LISTADO DE GOMEROS\n");
    do
    {
        printf("\nPresione 'S' para cargar los datos manualmente o 'N' para cargar lote de prueba: ");
        fflush(stdin);
        scanf("%c",&opcion);
    }while(!(opcion=='N'||opcion=='n'||opcion=='S'||opcion=='s'));
    if(opcion=='S'||opcion=='s')
        for(i=0;i<=ce-1;i++)
        {
            do
            {
                printf("\nIngrese el numero de gomero (empleado numero %d): ",i+1);
                nrogomero=ControlDatos(30,50);
                pos=Busqueda(v,i,nrogomero);
                if(pos!=-1)
                    printf("\nDato duplicado. Ingrese otro\n");
            }while(pos!=-1);
            v[i]=nrogomero;
        }
    else
    {
        v[0]=33;v[1]=35;v[2]=41;v[3]=44;v[4]=50;
    }
}

int Busqueda(int v[],int ce,int x)
{
    int i=0,p=-1;
    while(p==-1&&i<ce)
    {
        if(v[i]==x)
            p=i;
        else
            i++;
    }
    return p;
}

void SumarFilaMatEnV (float m[][15],float v[],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            v[i]+=m[i][j];
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

void MostrarIgualQueVParalelos (float v[],int a[],int ce,float x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(v[i]==x)
            printf("\n%d\n",a[i]);
}

int Maximo(int v[],int ce)    //CORRECCION
{
    int i,maximo;
    maximo=v[0];
    for(i=1;i<=ce-1;i++)
        if(v[i]>maximo)
            maximo=v[i];
    return maximo;
}

void MostrarIgualQueVParalelos2(int v[],int a[],int ce,int x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(v[i]==x)
            printf("\n%d\n",a[i]);
}

void Ordenamiento(float a[],int b[],int ce)
{
    int i=0,hubocambio,j,aux2;
    float aux;
    do
    {
        hubocambio=0;
        for(j=1;j<ce-i;j++)
            if(a[j-1]<a[j])
            {
                aux=a[j-1];
                a[j-1]=a[j];
                a[j]=aux;
                aux2=b[j-1];
                b[j-1]=b[j];
                b[j]=aux2;
                hubocambio=1;
            }
        i++;
    }while(hubocambio);
}

float SumaReal(float v[],int ce)
{
    int i;
    float s=0;
    for(i=0;i<=ce-1;i++)
        s+=v[i];
    return s;
}

void Listado(int a[],float b[],int ce)
{
    int i;
    printf("\nCUBIERTA\tIMPORTE\n");
    for(i=0;i<=ce-1;i++)
        if(b[i]>0)
            printf("\n%d\t\t$ %.2f\n",a[i],b[i]);
}

void MostrarMayorQue (int a[],int b[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(a[i]>b[i])
            printf("\n%d\n",i+1);
}
