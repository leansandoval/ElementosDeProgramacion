#include<stdio.h>
#include<windows.h>
#define tamanio 15

void PonerEnCero(int[],int);
int esDatoVal (int,int,int);
int esCantVal(int,int);
int IngrDatoVal(int,int);
int IngrCodVendedorVal(int,int,int);
int IngrCantVal(int);

void CargaVecCod(int[],int);
void CargaVent(int[],int[],int,int[],int);

void Burbujeo(int[],int);
int BusquedaSec(int[],int,int);
void Arrastre(int[],int[],int);

void ListaVec(int[],int[],int);
void ListaCantVentasxVendedor(int[],int);

int MenorIntPositivo(int[],int);
void MostrarIgualQue(int[],int,int);

int main()
{
    int VProd[tamanio],VCant[tamanio],VCod[5],min;
    PonerEnCero(VCant,tamanio);
    PonerEnCero(VCod,5);

    CargaVecCod(VProd,tamanio);
    Burbujeo(VProd,tamanio);

    CargaVent(VProd,VCant,tamanio,VCod,5);
    Arrastre(VProd,VCant,tamanio);

    ListaVec(VProd,VCant,tamanio);
    ListaCantVentasxVendedor(VCod,5);

    min=MenorIntPositivo(VCod,5);
    printf("\nVendedor/vendedores que realizacion menor cantidad de unidades: ");
    MostrarIgualQue(VCod,5,min);

    printf("\n\n");
    system("pause");
    printf("\n");
}

/////////////////////////////////////////////////////////////
int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int esCantVal(int x,int lim)
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
                printf("\nDato fuera de rango, ingrese nuevamente: ");
        band=1;
        scanf("%d",&dato);
    }while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

int IngrCantVal (int lim)
{
    int dato,band=0;
    do
    {
        if(band==1)
            {
                printf("\nDato fuera de rango");
                printf("\n");
            }
        band=1;
        printf("\nIngrese CANTIDAD de VENTAS realizadas durante el dia: ");
        scanf("%d",&dato);
    }while(esCantVal(dato,lim)==0);
    return dato;
}

int IngrCodVendedorVal(int lim1,int lim2,int lim3)
{
    int dato,band=0;
    do
    {
        if(band==1)
            {
                printf("\nDato fuera de rango");
                printf("\n");
            }
        band=1;
        printf("\nIngrese CODIGO de VENDEDOR entre %d y %d (%d para terminar): ",lim1,lim2,lim3);
        scanf("%d",&dato);
    }while(esDatoVal(dato,lim1,lim2)==0&&dato!=lim3);
    return dato;
}

/////////////////////////////////////////////////////////////
void PonerEnCero (int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void CargaVecCod(int p[],int ce)
{
    int i,codprod;
    for(i=0;i<=ce-1;i++)
    {
        printf("\nIngrese CODIGO de PRODUCTO (3 digitos) Producto numero %d: ",i+1);
        codprod=IngrDatoVal(100,999);
        p[i]=codprod;
    }
}

void CargaVent(int prod[],int vent[],int ce,int cod[],int ce1)
{
    int codprod,codvendedor,cant,pos;
    codvendedor=IngrCodVendedorVal(1001,1005,0);
    while(codvendedor!=0)
    {
        do
        {
            printf("\nIngrese un CODIGO de PRODUCTO (YA CARGADO): ");
            codprod=IngrDatoVal(100,999);
            pos=BusquedaSec(prod,ce,codprod);
            if(pos==-1)
                {
                    printf("\nEl codigo ingresado no aparece en la lista");
                    printf("\n");
                }
        }while(!(pos!=-1));
        cant=IngrCantVal(0);
        vent[pos]+=cant;
        cod[codvendedor-1001]++;
        codvendedor=IngrCodVendedorVal(1001,1005,0);
    }
}

/////////////////////////////////////////////////////////////

void Burbujeo (int a[],int ce)
{
    int i=0,j,aux,hubocambio;
    do
    {
        hubocambio=0;
        for(j=1;j<ce-i;j++)
            if(a[j-1]<a[j])
                {
                    aux=a[j-1];
                    a[j-1]=a[j];
                    a[j]=aux;
                    hubocambio=1;
                }
        i++;
    }while(hubocambio);
}

int BusquedaSec(int v[],int ce,int x)
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

void ListaVec(int p[], int v[],int ce)
{
    int i;
    printf("\nCODIGO DE PRODUCTO\tCANT UNIDADES");
    printf("\n");
    for(i=0;i<=ce-1;i++)
        printf("\n\t%d\t\t%d",p[i],v[i]);
}

void ListaCantVentasxVendedor(int c[],int ce)
{
    int i;
    printf("\nCOD. VENDEDOR\tCANT. VENTAS");
    for(i=0;i<=ce-1;i++)
        printf("\n\t%d\t\t%d",i+1001,c[i]);
}

void Arrastre(int a[],int b[],int ce)
{
    int hubocambio,i=0,j,aux,aux2;
    do
    {
        hubocambio=0;
        for(j=1;j<ce-i;j++)
            if(b[j-1]>b[j])
            {
                aux=b[j-1];
                b[j-1]=b[j];
                b[j]=aux;
                aux2=a[j-1];
                a[j-1]=a[j];
                a[j]=aux2;
                hubocambio=1;
            }
    i++;
    }while(hubocambio);
}

/////////////////////////////////////////////////////////////

int MenorIntPositivo (int v[],int ce)
{
    int i,menor=0;
    for(i=0;i<=ce-1;i++)
    {
        if(v[i]>0&&(menor==0||menor>v[i]))
            menor=v[i];
    }
    return menor;
}

void MostrarIgualQue(int a[],int ce,int x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(a[i]==x)
            printf("\n%d",i+1001);
}
