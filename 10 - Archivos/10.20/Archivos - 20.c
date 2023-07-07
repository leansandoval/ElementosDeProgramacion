#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codLoc;
    int codProv;
    int codZona;
}T_Geogra;

typedef struct
{
    int codLoc;
    int encomienda;
}T_Encom;

int CargaVecGeo(T_Geogra[], char[]);
void mostrar(T_Geogra[], int);
int busqueda(int, T_Geogra[], int);
void contarKilos(T_Geogra[],int,int[]);
void ponerEnCero(int [], int);
void localidadesMenores(T_Geogra [], int, int[]);
void mostrarEncomiendas(int []);
void provinciaSinEncomiendas(T_Geogra[], int);

int main ()
{
    T_Geogra VGeo[200];
    T_Encom aux;
    int contador,vZonas[9],i;
    ponerEnCero(vZonas,9);
    contador = CargaVecGeo(VGeo,"GEOGRA.dat");
    //mostrar(VGeo,contador);
    contarKilos(VGeo,contador,vZonas);
    printf("\n---------------------------------------");
    mostrarEncomiendas(vZonas);
    printf("\n---------------------------------------");
    provinciaSinEncomiendas(VGeo,contador);
}

int CargaVecGeo(T_Geogra vec[],char s[100])
{
    FILE* pf;
    T_Geogra aux;
    int i,cont;
    cont=0;
    i=0;
    pf=fopen(s,"rb");
    if(pf==NULL)
    {
        printf("\nNo se abrio el archivo..");
        exit(1);
    }
    fread(&aux,sizeof(T_Geogra),1,pf);
    while(!feof(pf))
    {
        vec[i].codLoc = aux.codLoc;
        vec[i].codProv = aux.codProv;
        vec[i].codZona = aux.codZona;
        cont ++;
        i++;
        fread(&aux,sizeof(T_Geogra),1,pf);
    }
    fclose(pf);
    return cont;
}

void mostrar(T_Geogra v[], int ce)
{
    int i;
    for(i=0;i<ce;i++)
    {
        printf("\n Posicion :%d",i+1);
        printf("\n Codigo de Localidad: %d",v[i].codLoc);
        printf("\n Codigo de Provincia: %d",v[i].codProv);
        printf("\n Codigo de la Zona: %d",v[i].codZona);
        printf("\n---------------------------");
    }
}

int busqueda(int dato,T_Geogra vec[],int ce)
{
    int pos,i;
    i=0;
    pos=-1;
    while(i<ce && pos == -1)
    {
        if(vec[i].codLoc==dato)
            pos=i;
        i++;
    }
    return pos;
}

void contarKilos(T_Geogra vec[],int ce, int vZonas[])
{
    FILE* pf;
    FILE* ef;
    int i,pos;
    T_Encom aux;

    i=0;
    ef = fopen("ERROR.dat","wb");
    if(ef == NULL)
    {
        printf("El archivo no se pudo abrir...");
        exit(1);
    }
    pf = fopen("ENCOM.dat","rb");
    if(pf == NULL)
    {
        printf("El archivo no se pudo abrir...");
        exit(1);
    }
    fread(&aux,sizeof(T_Encom),1,pf);
    while(!feof(pf))
    {
        pos=busqueda(aux.codLoc,vec,ce);
        if(pos!=-1)
            vZonas[vec[pos].codZona-1]+=aux.encomienda;
        else
            fwrite(&aux,sizeof(T_Encom),1,ef);
        i++;
        fread(&aux,sizeof(T_Encom),1,pf);
    }
    localidadesMenores(vec,ce,vZonas);
    fclose(pf);
    fclose(ef);
}

void ponerEnCero(int v[], int ce)
{
    int i;
    for(i=0;i<=ce;i++)
        v[i]=0;
}

void localidadesMenores(T_Geogra v[], int ce, int vz[])
{
    int aux,i,j;
    aux= vz[0];
    for(i=0;i<=9;i++)
    {
        if(aux>=vz[i])
            aux=vz[i];
    }
    printf("\n%d",aux);
    printf("\nLas localidades con menor encomienda:");
    for(j=0;j<=ce;j++)
    {
        if(v[j].codZona == i)
        {
            printf("\n %d",v[j].codLoc);
        }

    }
}

void mostrarEncomiendas(int vZonas[])
{
    int i;
    printf("\nZona\t|\tTotal de Kilos ");
    for(i=0;i<9;i++)
        printf("\n%d\t|\t%d",i+1,vZonas[i]);
}

void provinciaSinEncomiendas(T_Geogra VGeo[], int contador)
{
    FILE *pf;
    T_Encom aux;
    int pos,Vprovincias[24],codaux,i;
    ponerEnCero(Vprovincias,24);
    pf=fopen("ENCOM.dat","rb");
    if(pf==NULL)
    {
        printf("El archivo no se pudo abrir..");
        exit(1);
    }
    fread(&aux,sizeof(T_Encom),1,pf);
    while(!feof(pf))
    {
        pos=busqueda(aux.codLoc,VGeo,contador);
        if(pos!=-1)
        {
            codaux = VGeo[pos].codProv;
            Vprovincias[codaux-1]++;
        }
        fread(&aux,sizeof(T_Encom),1,pf);
    }
    printf("\nProvincias sin Encomienda");
    for(i=0;i<24;i++)
    {
        printf("\nProvincia: %d\t%d",i+1,Vprovincias[i]);
    }
}
