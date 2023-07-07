#include <stdio.h>
#include <stdlib.h>

typedef struct{int cloc,cprov,czg;}T_Geo;

void MostrarArch();

int main()
{
    T_Geo mov;
    FILE *pf;
    pf=fopen("GEOGRA.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    printf("\nCodigo de localidad \t Codigo de provincia \tCodigo de zona geografica");
    fread(&mov,sizeof(T_Geo),1,pf);
    while(!feof(pf))
    {
        printf("\n %d \t%d\t%d",mov.cloc,mov.cprov,mov.czg);
         fread(&mov,sizeof(T_Geo),1,pf);
    }
    fclose(pf);
}
