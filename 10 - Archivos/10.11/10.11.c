/*10.11.La municipalidad de Marina del Mar desea efectuar un control de la cobranza del impuesto Municipal en
los 6 bimestres del año. Existen 50 contribuyentes, numerados de 1 a 50.
• El primer dato para ingresar es el número del año a procesar (xxxx)
Se suministra el archivo “IMPORTES.dat”, ordenado por año-bimestre, con 18 ítems, que contienen los
importes de los impuestos de los últimos 3 años, cada ítem contiene:
• Año del impuesto (entero)
• Bimestre (entero)
• Importe (real)
Se dispone además de un segundo archivo, llamado “CONTROL.dat”, ordenado por número de
contribuyente, con un registro por cada cobro efectuado, con los siguientes datos (solo considerar los del
año en estudio).
• Número de contribuyente (entero)
• Año del impuesto (entero)
• Bimestre (entero)
Se solicita confeccionar un programa para determinar e informar:
a. El importe total recaudado en el año.
b. Las deudas de cada contribuyente según el siguiente formato de impresión:
                                        DEUDAS REGISTRADAS EN EL AÑO XXX
            CONTRIBUYENTE         BIMESTRES 1 2 3 4 5 6           IMPORTE           ADEUDADO
                XXXXX                       X         X             $               XXXXXX,XX
------------------------------------------------------------------------------------------------------------------------
Resolucion: Para empezar, como indica que el primero dato a ingresar es el año a procesar, se declara una variable de
tipo int. Previamente se debera tener un archivo llamado IMPORTES.dat (la estructura esta en el enunciado) y ademas otro
archivo llamando CONTROL.dat

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define fila 10

typedef struct
{
    int anioImpuesto,bimestre;
    float importe;
}T_Importes;

typedef struct
{
    int nroContri,anioImpuesto,bimestre;
}T_Control;

void PonerEnCeroMat(int[][6],int,int);
void CargaArchivoImportes(float[],int,int);
float SumaVec(float[],int);
void Inicializar(float[],int,float);
void Mostrar(int[][6],int,int,float[]);

int main()
{
    FILE *pf;
    T_Control aux;
    float VImp[6],VPag[fila],sum,tot=0;
    int MBimestre[fila][6],anio;
    PonerEnCeroMat(MBimestre,fila,6);
    do
    {
        printf("\nIngrese numero de anio a procesar: ");
        scanf("%d",&anio);
    }while(!(anio>=2017&&anio<=2020));
    CargaArchivoImportes(VImp,6,anio);
    sum=SumaVec(VImp,6);
    Inicializar(VPag,fila,sum); /*Suma importe adeudado por cada contribuyente*/
    pf=fopen("CONTROL.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    fread(&aux,sizeof(T_Control),1,pf);
    while(!feof(pf))
    {
        if(aux.anioImpuesto==anio)
        {
            tot+=VImp[aux.bimestre-1];
            MBimestre[aux.nroContri-1][aux.bimestre-1]=1;
            VPag[aux.nroContri-1]-=VImp[aux.bimestre-1];
        }
        fread(&aux,sizeof(T_Control),1,pf);
    }
    fclose(pf);
    printf("\nTOTAL RECAUDADO EN EL ANIO %d: %d\n",anio,tot); //pt.a
    printf("\n\t\t\tDEUDAS REGISTRADAS EN EL ANIO %d",anio);
    printf("\nCONTRIBUYENTE\tBIMESTRES  1  2  3  4  5  6 \tIMPORTE ADEUDADO");
    Mostrar(MBimestre,fila,6,VPag);
    printf("\n\n");
    system("pause");
}

void PonerEnCeroMat (int m[][6],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
       for(j=0;j<c;j++)
            m[i][j]=0;
}

void CargarArchivoControl(T_Control v[],int ce)
{
    int i;
    FILE *pf;
    T_Control aux;
    pf=fopen("CONTROL.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...\n");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(T_Control),1,pf);
    while(!feof(pf)&&i<ce)
    {
        v[i]=aux;
        i++;
        fread(&aux,sizeof(T_Control),1,pf);
    }
    fclose(pf);
}

/*Funcion para cargar un archivo. En este caso, el archivo IMPORTES.dat contiene un vector de estructuras.
Declaro FILE *pf para utilizarlo como puntero y para abrir el archivo --> pf=fopen("IMPORTES.dat","rb")
rb ya que voy a leer dicho archivo (read binary). Para leerlo utilizo --> fread(&imp,sizeof(T_Importes),1,pf)
*/

void CargaArchivoImportes (float v[],int ce,int anio)
{
    FILE *pf;
    T_Importes imp;
    pf=fopen("IMPORTES.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        getch();
        exit(1);
    }
    fread(&imp,sizeof(T_Importes),1,pf);
    while(!feof(pf))
    {
        if(imp.anioImpuesto==anio)
            v[imp.bimestre-1]+=imp.importe;
        fread(&imp,sizeof(T_Importes),1,pf);
    }
    fclose (pf);
}

void Mostrar(int m[][6],int f,int c,float v[])
{
    int i,j;
    for(i=0;i<f;i++)
        if(v[i]>0)
        {
            printf("\n%d",i+1);
            for(j=0;j<c;j++)
                if(m[i][j]==0)
                    printf("\t\t\t%c",'x');
            printf("\t$ %f",v[i]);
        }
}

float SumaVec(float v[],int ce)
{
    int i;
    float suma=0;
    for(i=0;i<ce;i++)
        suma+=v[i];
    return suma;
}

void Inicializar(float v[],int ce,float x)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=x;
}
