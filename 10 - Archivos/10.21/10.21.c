#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TAM 20000

typedef struct
{
    int cajadeahorro;
    char apynom[31];
    float saldo;
}T_Saldos;

typedef struct
{
    int sucursal,cajadeahorro,mes,dia,codoperacion;
    float importe;
}T_Movi;

void PonerEnCero(int[],int);
int CargaArch(T_Saldos[],int);
int Busqueda(T_Saldos[],int,int);
void ProcesarArch(T_Saldos[],int[],int);
void GrabarArch(T_Saldos[],int);
void MostrarMayorQue(T_Saldos[],int[],int,int);

int main()
{
   int VExt[TAM],cant;  //Bloque declarativo
   T_Saldos VSal[TAM];
   PonerEnCero(VExt,TAM);
   cant=CargaArch(VSal,TAM);
   ProcesarArch(VSal,VExt,cant);
   GrabarArch(VSal,cant);
   printf("\nLas cuentas que en el mes realizaron mas de 5 extracciones son:");
   MostrarMayorQue(VSal,VExt,cant,5);
   return 0;
}

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
}

int CargaArch(T_Saldos v[],int ce)
{
   FILE*pf;
   T_Saldos aux;
   int i=0;
   pf=fopen("SALDOS.dat","rb");
   if(pf==NULL)
   {
      printf("\nNo abrio el archivo...");
      getch();
      exit(1);
   }
   fread(&aux,sizeof(T_Saldos),1,pf);
   while(!feof(pf)&&i<ce)
   {
      v[i]=aux;
      i++;
      fread(&aux,sizeof(T_Saldos),1,pf);
   }
   fclose(pf);
   return(i);
}

void GrabarArch(T_Saldos v[], int ce)
{
    int i;
    FILE *pf;
    pf=fopen("SALDOSACT.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        getch();
        exit(1);
    }
    for(i=0;i<=ce-1;i++)
        fwrite(&v[i],sizeof(T_Saldos),1,pf);
    fclose(pf);
}

void MostrarMayorQue(T_Saldos v[], int e[], int ce, int x)
{
    int i;
    for(i=0;i<=ce-1;i++)
        if(e[i]>x)
            printf("\n%d",v[i].cajadeahorro);
}

int Busqueda(T_Saldos v[], int ce, int x)
{
    int i=0;
    while(v[i].cajadeahorro!=x && i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return i;
}

void ProcesarArch (T_Saldos v[],int e[], int ce)
{
    FILE *pf, *ss;
    T_Movi aux;
    int pos;
    pf=fopen("MOVI.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo");
        getch();
        exit(1);
    }
    ss=fopen("SIN_SALDO.dat","wb");
    if(ss==NULL)
    {
        printf("\nNo abrio el archivo...");
        getch();
        exit (1);
    }
    fread(&aux,sizeof (T_Movi),1,pf);
    while(!feof(pf))
    {
        pos=Busqueda(v,ce,aux.cajadeahorro);
        if(pos!=-1)
            if(aux.codoperacion==1)
                v[pos].saldo+=aux.importe;
            else
                if(v[pos].saldo>=aux.importe)
                {
                    v[pos].saldo-=aux.importe;
                    e[pos]++;
                }
                else
                    fwrite(&aux,sizeof(T_Movi),1,ss);
        fread(&aux,sizeof(T_Movi),1,pf);
    }
    fclose(pf);
    fclose(ss);
}
