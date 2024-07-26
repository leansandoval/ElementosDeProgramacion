#include<stdio.h>
#include<windows.h>
int esDatoVal(int,int,int);
int IngrDNIVal(int,int,int);
float IngrNotaVal(int,int);
int CargaAlumnos(int[],float[],int);
void ListadoVectores(int [],float [],int);
float MaximoVec(float [],int);
void MostrarIgualQue(float[],int[],int,float);
int main()
{
    int VDni[60],cant=0;
    float VNota[60],max;
    cant=CargaAlumnos(VDni,VNota,100);
    if(cant>0)
    {
        printf("\n\tDNI\t\t\tNOTA");
        printf("\n");
        ListadoVectores(VDni,VNota,cant);
        printf("\n");
        max=MaximoVec(VNota,cant);
        printf("\nDNI de los alumnos que obtuvieron la nota maxima (%.2f): ",max);
        MostrarIgualQue(VNota,VDni,cant,max);
    }
    else
        printf("\nNo hay alumnos");
    printf("\n\n");
    system("pause");
    printf("\n");
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
        printf("\nIngrese DNI del alumno (numero negativo para terminar): ");
        scanf("%d",&dato);
    }while(!(esDatoVal(dato,lim1,lim2)==1||dato<lim3));
    return dato;
}

float IngrNotaVal(int lim1,int lim2)
{
    float dato;
    do
    {
        printf("\nIngrese nota correspondiente: ");
        scanf("%f",&dato);
    }while(esDatoVal(dato,lim1,lim2)==0);
    return dato;
}

int CargaAlumnos(int a[],float b[],int ce)
{
    int i=0,dni;
    float nota;
    dni=IngrDNIVal(10000000,99999999,0);
    while(dni>0&&i<ce)
    {
        nota=IngrNotaVal(0,10);
        a[i]=dni;
        b[i]=nota;
        i++;
        dni=IngrDNIVal(10000000,99999999,0);
    }
    return i;
}

void ListadoVectores (int a[],float b[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        printf("\n\t%d\t\t%.2f",a[i],b[i]);
}

float MaximoVec (float v[],int ce)
{
    int i;
    float mayor=0;
    for(i=0;i<=ce-1;i++)
        if(i==0||v[i]>mayor)
            mayor=v[i];
    return mayor;
}

void MostrarIgualQue(float a[],int b[],int ce,float x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(a[i]==x)
            printf("\n%d",b[i]);
}
