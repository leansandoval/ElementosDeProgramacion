#include<stdio.h>
#include<string.h>
#include<windows.h>
int esDatoVal(int,int,int);
int IngrDatoVal(int,int);
int CargaAlumnosParalelo(char[][11],int[],int);
void MostrarVCharParalelo(char[][11],int[],int);
int BusquedaSecChar(char[][11],char[],int);
void BuscarAlumno(char[][11],int[],int);
void BurbujeoChar(char[][11],int[],int);
int main()
{
    int cant,VDni[50];
    char VAlumnos[50][11];
    cant=CargaAlumnosParalelo(VAlumnos,VDni,50);
    if(cant!=0)
    {
        MostrarVCharParalelo(VAlumnos,VDni,cant);
        BuscarAlumno(VAlumnos,VDni,cant);
        BurbujeoChar(VAlumnos,VDni,cant);
        printf("\nListado de alumnos ordenado alfabeticamente de menor a mayor\n");
        MostrarVCharParalelo(VAlumnos,VDni,cant);
    }
    else
        printf("\nNo hay alumnos");
    printf("\n\n");
    system("pause");
}

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
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
        {
            printf("\nDato incorrecto, ingrese nuevamente: ");
        }
        band=1;
        scanf("%d",&dato);
    }while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

int CargaAlumnosParalelo(char c[][11],int v[],int f)
{
    int i=0,dni,largo;
    char Nombre[11];
    printf("\nIngrese nombre del alumno (FIN para terminar): ");
    fflush(stdin);
    gets(Nombre);
    while(strcmpi(Nombre,"FIN")!=0&&i<f)
    {
        strcpy(c[i],Nombre);
        printf("\nIngrese DNI correspondiente: ");
        dni=IngrDatoVal(10000000,99999999);
        v[i]=dni;
        i++;
        printf("\nIngrese nombre del alumno (FIN para terminar): ");
        fflush(stdin);
        gets(Nombre);
    }
    return i;
}

void MostrarVCharParalelo(char c[][11],int v[],int f)
{
    int i;
    printf("\nNOMBRE\tDNI");
    printf("\n");
    for (i=0;i<f;i++)
        printf("\n%s\t%d",c[i],v[i]);
}

int BusquedaSecChar(char c[][11],char aux[],int f)
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

void BuscarAlumno (char c[][11],int v[],int f)
{
    int i=0,pos;
    char Aux[11];
    printf("\n");
    printf("\nIngrese nombre del alumno a buscar (NOBUSCARMAS para terminar): ");
    fflush(stdin);
    gets(Aux);
    while(strcmpi(Aux,"NOBUSCARMAS")!=0&&i<f)
    {
        pos=BusquedaSecChar(c,Aux,f);
        if(pos!=-1)
            {
                printf("\nEl alumno posee el DNI numero: %d",v[pos]);
                printf("\n");
            }

        else
            {
                printf("\nEl alumno que ingreso no se encuentra en la lista");
                printf("\n");
            }
        printf("\nIngrese nombre del alumno a buscar (NOBUSCARMAS para terminar): ");
        fflush(stdin);
        gets(Aux);
    }
}

void BurbujeoChar(char c[][11],int v[],int f)
{
    int i,j,aux2;
    char aux[11];
    for (i=0;i<f-1;i++)
    {
        for (j=0;j<f-1-i;j++)
        {
            if (strcmpi(c[j],c[j+1])>0)
            {
                strcpy(aux,c[j]);
                strcpy(c[j],c[j+1]);
                strcpy(c[j+1],aux);
                aux2=v[j];
                v[j]=v[j+1];
                v[j+1]=aux2;
            }
        }
    }
}
