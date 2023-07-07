/*
2. Control de Personal
La empresa GoogleMar dispone del archivo secuencial PERSONAL.dat con los siguientes datos de cada uno de sus 175 operarios activos.
• Nro. de Legajo (Nro. entero de 3 cifras NO correlativo)
• Apellido y Nombres (80 caracteres)
• Valor Hora ( xx.xx)
• Total de horas trabajadas (actualizar sumando)
• Total de sueldos a cobrar a la Fecha (actualizar sumando)
• Fecha del último proceso ( dia-mes-año) (actualizar cambiando)
Confeccionar el diagrama de lógica y la respectiva codificación para:
a) Generar un vector llamado ArrayPerso con los datos existentes en el archivo PERSONAL.dat, utilizando la función LECTURA_PERSONAL.
b) Ingresar desde el teclado la fecha del día de proceso: día (1 a 30), mes (1 a 12) y año (2011 a 2013 inclusive).
Solo permitir el ingreso de una fecha correcta, por error volver a solicitar toda la fecha. Confeccionar la función LEECONTROL para tal fin.
c) También se dispone del archivo HORAS.dat donde por cada día trabajado se registró.
• Nro. de Legajo (Nro. entero de 3 cifras NO correlativo)
• Cantidad de horas trabajadas
Estos datos se encuentran en el archivo ordenados por legajo.
Para el control de la existencia del Nro. de Legajo Confeccionar la función BUSQUEDA con los argumentos necesarios.
Si no existe, grabar la información ingresada (Nro. de legajo – cantidad de horas trabajadas) en el archivo ERROR.dat.
d) Actualizar ArrayPerso con las novedades ingresadas
El importe a cobrar se calcula como el producto entre las horas trabajadas y el valor que cobra por hora el operario.
La fecha de proceso es la ingresada por teclado.
e) Actualizar el archivo PERSONAL.dat Mediante función GRABAR.
f) Informar los datos de aquellos legajos que tienen un acumulado de sueldo mayor a $ 1.500 y las horas NO exceden a 140. Función LISTAR
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define TAM 175

typedef struct
{
    int dia,mes,anio;
}T_Fecha;

typedef struct
{
    int nrolegajo,totalhoras;
    char apeynom[21];
    float valorhora,totalsueldo;
    T_Fecha f;
}T_Personal;


typedef struct
{
    int nrolegajo,canthoras;
}T_Hora;

int LECTURA_PERSONAL(T_Personal[],int);
int CONTROL(int,int,int);
T_Fecha LEECONTROL();
int BUSQUEDA(T_Personal[],int,int);
void ACTUALIZA(T_Personal[],T_Fecha,int);
void GRABAR(T_Personal[],int);
void LISTAR(T_Personal[],int);

int main()
{
    T_Personal ArrayPerso[TAM];
    T_Fecha fecha;
    int cant=LECTURA_PERSONAL(ArrayPerso,TAM);
    fecha=LEECONTROL();
    ACTUALIZA(ArrayPerso,fecha,cant);
    GRABAR(ArrayPerso,cant);
    LISTAR(ArrayPerso,cant);
}

int LECTURA_PERSONAL(T_Personal v[],int ce)
{
    FILE*pf;
    T_Personal aux;
    int i=0;
    pf=fopen("PERSONAL.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Personal),1,pf);
    while(!feof(pf)&&i<ce)
    {
        v[i]=aux;
        i++;
        fread(&aux,sizeof(T_Personal),1,pf);
    }
    fclose(pf);
    return i;
}

int CONTROL(int x,int limi,int lims)
{
    if(x>=limi&&x<=lims)
        return 1;
    else
        return 0;
}

T_Fecha LEECONTROL()
{
    int band=0;
    T_Fecha f;
    do
    {
        if(band==1)
            printf("\nFecha incorrecta, ingrese nuevamente\n");
        band=1;
        printf("\nFECHA DEL DIA DE PROCESO\n");
        printf("\nIngrese dia (1 a 30): ");
        scanf("%d",&f.dia);
        printf("\nIngresem mes: ");
        scanf("%d",&f.mes);
        printf("\nIngrese anio (2011 a 2013): ");
        scanf("%d",&f.anio);
        system("cls");
    }while(CONTROL(f.dia,1,30)==0||CONTROL(f.mes,1,12)==0||CONTROL(f.anio,2011,2013)==0);
    return f;
}

int BUSQUEDA(T_Personal v[],int ce,int x)
{
    int pos=-1,i=0;
    while(pos==-1&&i<ce)
        if(v[i].nrolegajo==x)
            pos=i;
        else
            i++;
    return pos;
}

void ACTUALIZA(T_Personal v[],T_Fecha f,int ce)
{
    FILE *pf;
    FILE *pe;
    T_Hora aux;
    int pos,sumahora,nrolegajo;
    pf=fopen("HORAS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    pe=fopen("ERROR.dat","wb");
    if(pe==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Hora),1,pf);
    while(!feof(pf))
    {
        pos=BUSQUEDA(v,ce,aux.nrolegajo);
        if(pos!=-1)
        {
            nrolegajo=aux.nrolegajo;
            sumahora=0;
            while(nrolegajo==aux.nrolegajo&&!feof(pf))
            {
                sumahora+=aux.canthoras;
                fread(&aux,sizeof(T_Hora),1,pf);
            }
            v[pos].totalhoras+=(float)sumahora;
            v[pos].totalsueldo+=(float)sumahora*v[pos].valorhora;
            v[pos].f=f;
        }
        else
        {
            fwrite(&aux,sizeof(T_Hora),1,pe);
            fread(&aux,sizeof(T_Hora),1,pf);
        }
    }
    fclose(pe);
    fclose(pf);
}

void GRABAR(T_Personal v[],int ce)
{
    FILE*pf;
    int i;
    pf=fopen("PERSONALACT.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    for(i=0;i<=ce-1;i++)
        fwrite(&v[i],sizeof(T_Personal),1,pf);
    fclose(pf);
}

void LISTAR(T_Personal v[],int ce)
{
    int i;
    printf("\n\t\tLISTADO\n");
    printf("\nNRO. LEGAJO\tAPELLIDO Y NOMBRE\n");
    for(i=0;i<=ce-1;i++)
        if(v[i].totalsueldo>1500&&v[i].totalhoras<=140)
            printf("\n%d\t%-21s\n",v[i].nrolegajo,v[i].apeynom);

}
