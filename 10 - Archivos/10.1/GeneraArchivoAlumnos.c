#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct
{
    int dni,nota1,nota2;
    char nomyape[31];
    float prom;
}T_Alum;

int esDatoVal(int,int,int);
int IngrDatoVal(int,int,int);
int IngrDatoVal2(int,int);
void GeneraArch();

int main()
{
    GeneraArch();
    return 0;
}

int esDatoVal(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

int IngrDatoVal(int lim1,int lim2,int lim3)
{
    int dato,band=0;
    do
    {
        if(band==1)
            printf("\nDato invalido, ingrese otro: ");
        band=1;
        scanf("%d",&dato);
    }while(esDatoVal(dato,lim1,lim2)==0&&dato!=lim3);
    return dato;
}

int IngrDatoVal2(int limi,int lims)
{
    int dato,band=0;
    do
    {
        if(band==1)
            printf("\nDato invalido, ingrese otro dato: ");
        band=1;
        scanf("%d",&dato);
    }while(esDatoVal(dato,limi,lims)==0);
    return dato;
}

void GeneraArch()
{
    T_Alum al;
    FILE *pf;
    pf=fopen("ALUMNOS.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    printf("\nIngrese DNI - 0 para terminar - : ");
    al.dni=IngrDatoVal(10000000,99999999,0);
    while(al.dni!=0)
    {

        printf("\nIngrese Nombre y Apellido: ");
        fflush(stdin);
        gets(al.nomyape);
        printf("\nIngrese primera nota: ");
        al.nota1=IngrDatoVal2(1,10);
        printf("\nIngrese segunda nota: ");
        al.nota2=IngrDatoVal2(1,10);
        al.prom=(float)(al.nota1+al.nota2)/2;
        fwrite(&al,sizeof(T_Alum),1,pf);
        printf("\nIngrese DNI - 0 para terminar - : ");
        al.dni=IngrDatoVal(10000000,99999999,0);
    }
    fclose(pf);
}
