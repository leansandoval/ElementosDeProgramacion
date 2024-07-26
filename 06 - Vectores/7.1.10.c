#include<stdio.h>
#include<windows.h>
#include<math.h>

void PonerEnCero(float[],int);
void CargaVecA (float[],int);
void GeneraVecB(float[],float[],int);
void GeneraVecC(float[],float[],float[],int);
void CopiarInversoVecC(float[],float[],int);
void MayorValorYPosVecA(float[],int);
float MinimoValorRealVecB(float[],int);
void MostrarValorIgualA(float[],int,float);
int BusquedaSec(float[],int,float);
void Burbujeo(float[],int);
void GeneraVecE(float[],float[],int);
void ImprimirVecs(float[],float[],float[],float[],float[],int);

int main()
{
    float VA[10],VB[10],VC[10],VD[10],VE[10],min,valor;
    int pos;
    PonerEnCero(VB,10);
    PonerEnCero(VE,10);
    CargaVecA(VA,10);
    GeneraVecB(VA,VB,10);
    GeneraVecC(VA,VB,VC,10);
    CopiarInversoVecC(VC,VD,10);
    printf("\n");
    MayorValorYPosVecA(VA,10);
    min=MinimoValorRealVecB(VB,10);
    printf("\n");
    printf("\nValor minimo del vector B es %.2f en la posicion/posiciones: ",min);
    MostrarValorIgualA(VB,10,min);
    printf("\n");
    printf("\nIngrese un valor real: ");
    scanf("%f",&valor);
    pos=BusquedaSec(VC,10,valor);
    if(pos!=-1)
        printf("\nEl valor ingresado %.2f se encontro en la posicion %d del vector C",valor,pos);
    else
        printf("\nEl valor ingresado %.2f no se encontro en ninguna posicion del vector C",valor);
    Burbujeo(VD,10);
    GeneraVecE(VA,VE,10);
    printf("\n");
    ImprimirVecs(VA,VB,VC,VD,VE,10);
    printf("\n\n");
    system("pause");
    printf("\n");
}

void PonerEnCero (float v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void CargaVecA(float a[],int ce)
{
    int i;
    float dato;
    for(i=0;i<=ce-1;i++)
    {
        printf("\nIngrese un dato: ");
        scanf("%f",&dato);
        a[i]=dato;
    }
}

void GeneraVecB(float a[],float b[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(a[i]>0)
            b[i]=sqrt(a[i]);
}

void GeneraVecC(float a[],float b[],float c[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        c[i]=a[i]+b[i];
}

void CopiarInversoVecC(float c[],float d[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        d[i]=c[ce-1-i];
}

void MayorValorYPosVecA(float a[],int ce)
{
    float mayor=0;
    int i,pos;
    for(i=0;i<=ce-1;i++)
        if(mayor==0||a[i]>mayor)
            {
                mayor=a[i];
                pos=i;
            }
    printf("\nEl mayor valor del vector A es %.2f encontrado en la posicion %d",mayor,pos);
}

float MinimoValorRealVecB(float b[],int ce)
{
    int i;
    float menor=0;
    for(i=0;i<=ce-1;i++)
        if(menor==0||b[i]<menor)
            menor=b[i];
    return menor;
}

void MostrarValorIgualA(float v[],int ce,float x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(v[i]==x&&v[i]!=0)
            printf("\n%d",i);
}

int BusquedaSec(float c[],int ce,float x)
{
    int i=0,p=-1;
    while(p==-1&&i<ce)
    {
        if(c[i]==x)
            p=1;
        else
            i++;
    }
    return p;
}

void Burbujeo (float d[],int ce)
{
    int i=0,j,aux,hubocambio;
    do
    {
        hubocambio=0;
        for(j=1;j<ce-i;j++)
            if(d[j-1]<d[j])
                {
                    aux=d[j-1];
                    d[j-1]=d[j];
                    d[j]=aux;
                    hubocambio=1;
                }
        i++;
    }while(hubocambio);
}

void GeneraVecE(float a[],float e[],int ce)
{
    int i;
    float dato;
    for(i=0;i<=ce-1;i++)
        if(a[i]<0)
        {
            dato=a[i];
            e[i]=dato;
        }

}

void ImprimirVecs(float a[],float b[],float c[],float d[],float e[],int ce)
{
    int i;
    printf("\nVA\tVB\tVC\tVD\tVE");
    for(i=0;i<=ce-1;i++)
        printf("\n%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t",a[i],b[i],c[i],d[i],e[i]);
}

