#include<stdio.h>
#include<windows.h>

int esDatoVal(int,int,int);
int IngrDatoVal(int,int,int);
void PonerEnCero(int[],int);
void PonerEnDisponibleMat(char[][9],int,int);
void CargaMat(char[][9],int[],int,int);
void MostrarVecButaca(int[],int);
void MostrarMatFila(char[][9],int,int);
int BusquedaSec(int[],int,int);
void CantAsientosDispYReser(char[][9],int,int);     //a
void CantEspectPorFila(char[][9],int[],int,int);    //b
void MostrarFilasVacias(int[],int);
int MaximoVec(int[],int);                           //c
void MostrarIgualQue(int[],int,int);
void CantEspectPorColumna(char[][9],int[],int,int); //d
void Burbujeo(int[],int[],int);
void MostrarCantButacas(int[],int[],int);

int main()
{
    int VButaca[9]={8,6,4,2,1,3,5,7,9},VCantEspecPorFila[12],max,VCantEspecPorColumna[9];
    char MReservas[12][9];
    PonerEnCero(VCantEspecPorFila,12);
    PonerEnCero(VCantEspecPorColumna,9);
    PonerEnDisponibleMat(MReservas,12,9);
    CargaMat(MReservas,VButaca,12,9);
    printf("\n");
    printf("\nFILAS/BUTACAS");
    printf("\n\n");
    MostrarVecButaca(VButaca,9);
    printf("\n");
    MostrarMatFila(MReservas,12,9);
    CantAsientosDispYReser(MReservas,12,9);
    printf("\n");
    CantEspectPorFila(MReservas,VCantEspecPorFila,12,9);
    MostrarFilasVacias(VCantEspecPorFila,12);
    max=MaximoVec(VCantEspecPorFila,12);
    printf("\n");
    MostrarIgualQue(VCantEspecPorFila,12,max);
    printf("\n");
    CantEspectPorColumna(MReservas,VCantEspecPorColumna,12,9);
    Burbujeo(VButaca,VCantEspecPorColumna,9);
    MostrarCantButacas(VButaca,VCantEspecPorColumna,9);
    printf("\n\n");
    system("pause");
}

////////////////////////////////////////////////////////////////////////////////////////////////

int esDatoVal (int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int IngrDatoVal (int lim1,int lim2,int lim3)
{
    int dato,band=0;
    do
    {
        if(band==-1)
            {
                printf("\nDato fuera de rango");
                printf("\n");
            }
        band=-1;
        printf("\nIngrese numero de fila (entre %d y %d) ... numero negativo para terminar : ",lim1,lim2);
        scanf("%d",&dato);
    }while(esDatoVal(dato,lim1,lim2)==0&&dato>=lim3);
    return dato;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

void PonerEnDisponibleMat(char m[][9],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            m[i][j]='D';
}

void CargaMat (char m[][9],int v[],int f,int c)
{
    int fila,butaca,pos;
    fila=IngrDatoVal(1,12,0);
    while(!(fila<0))
    {
        printf("\nIngrese numero de butaca (entre 1 y 9): ");
        scanf("%d",&butaca);
        pos=BusquedaSec(v,c,butaca);
        if(pos!=-1)
            {
                if(m[fila-1][pos]=='D')
                    {
                        m[fila-1][pos]='R';
                        fila=IngrDatoVal(1,12,0);
                    }

                else
                {
                    printf("\nYa se ha solicitado una reserva anteriormente, debe elegir otra");
                    printf("\n");
                    fila=IngrDatoVal(1,12,0);
                }
            }
        else
        {
            printf("\nNumero de butaca erronea");
            printf("\n");
            fila=IngrDatoVal(1,12,0);
        }
    }
}

int BusquedaSec (int v[],int ce,int x)
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

void MostrarMatFila(char m[][9],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
    {
        printf("\n%d",i+1);
        printf("\t");
        for(j=0;j<=c-1;j++)
            printf("%c\t",m[i][j]);
    }
    printf("\n");
}

void MostrarVecButaca (int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        printf("\t%d",v[i]);
}

////////////////////////////////////////////////////////////////////////////////////////////////

void CantAsientosDispYReser (char m[][9],int f,int c)
{
    int i,j,contdis=0,contres=0;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            if(m[i][j]=='D')
                contdis++;
            else
                contres++;
    printf("\nLa cantidad de asientos reservados es %d y disponibles %d",contres,contdis);
}

////////////////////////////////////////////////////////////////////////////////////////////////

void CantEspectPorFila (char m[][9],int v[],int f,int c)
{
    int i,j,cont;
    for(i=0;i<=f-1;i++)
    {
        cont=0;
        for(j=0;j<=c-1;j++)
        if(m[i][j]=='R')
            cont++;
        v[i]=cont;
    }
}

void MostrarFilasVacias (int v[],int ce)
{
    int i;
    printf("\nFilas vacias: ");
    printf("\n");
    for(i=0;i<=ce-1;i++)
        if(v[i]==0)
            printf("\n%d",i+1);
}

////////////////////////////////////////////////////////////////////////////////////////////////

int MaximoVec (int v[],int ce)
{
    int i,mayor=0;
    for(i=0;i<=ce-1;i++)
        if(mayor==0||v[i]>mayor)
            mayor=v[i];

    if(mayor!=0)
       {
            printf("\n");
            printf("\nFila/Filas con mayor cantidad de espectadores: ");
            return mayor;
       }

    else
        {
            printf("\n");
            printf("\nAl ser todas filas vacias, no hay maximo");
        }

}

void MostrarIgualQue (int v[],int ce,int x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(v[i]==x)
            printf("\n%d",i+1);
}

////////////////////////////////////////////////////////////////////////////////////////////////

void CantEspectPorColumna(char m[][9],int v[],int f,int c)
{
    int i,j,cont;
    for(j=0;j<=c-1;j++)
    {
        cont=0;
        for(i=0;i<=f-1;i++)
        if(m[i][j]=='R')
                cont++;
        v[j]=cont;
    }
}

void Burbujeo (int a[],int b[],int ce)
{
    int i=0,hubocambio,j,aux,aux2;
    do
    {
        hubocambio=0;
        for(j=0;j<ce-i;j++)
            if(a[j-1]>a[j])
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

void MostrarCantButacas(int a[],int b[],int ce)
{
    int i;
    printf("\nBUTACA\tCANTIDAD");
    printf("\n");
    for(i=0;i<=ce-1;i++)
        printf("\n%d\t%d",a[i],b[i]);
}
