/*1. Notas de alumnos
Se ingresa DNI, apellido y nombre y nota promedio de alumnos de un curso. Dicha información
termina con DNI igual a cero.
Se pide:
a) Grabar toda la información en el archivo alumno.dat
b) Leer la información grabada en el archivo.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char ayn[51];
    float np;
}T_Alum;

void Grabacion(void);
void Lectura(void);

int main()
{
    int opcion;
    do
    {
        printf("\n1 - GRABACION\n2 - LECTURA\n3 - FIN\n");
        do
        {
            printf("\nIngrese un opcion: ");
            scanf("%d",&opcion);
        }while(!(opcion>=1&&opcion<=3));
        switch(opcion)
        {
            case 1: Grabacion();break;
            case 2: Lectura();
        }
    }while(opcion!=3);
}

void Grabacion()
{
    FILE *pf;
    T_Alum al;
    pf=fopen("ALUMNO.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    printf("\nIngrese DNI: ");
    scanf("%d",&al.dni);
    while(al.dni)
    {
        fflush(stdin);
        printf("\nIngresar apellido y nombre: ");
        gets(al.ayn);
        printf("\nIngrese nota promedio: ");
        scanf("%f",&al.np);
        fwrite(&al,sizeof(T_Alum),1,pf);
        printf("\nIngrese DNI: ");
        scanf("%d",&al.dni);
    }
    fclose(pf);
}

void Lectura()
{
    FILE *pf;
    T_Alum al;
    pf=fopen("ALUMNO.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    printf("\nLos datos existentes del archivo son: ");
    printf("\n\nDNI\t\tAPELLIDO Y NOMBRE\t\tNOTA PROMEDIO\n");
    fread(&al,sizeof(T_Alum),1,pf);
    while(!feof(pf))
    {
        printf("\n%8d\t%-40s%5.2f\n",al.dni,al.ayn,al.np);
        fread(&al,sizeof(T_Alum),1,pf);
    }
    fclose(pf);
}
