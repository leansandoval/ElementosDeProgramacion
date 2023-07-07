#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int dni,nota1,nota2;
    char nomyape[31];
    float prom;
}T_Alum;

void MostrarArch();

int main()
{
    MostrarArch();
    return 0;
}

void MostrarArch()
{
    T_Alum al;
    FILE * pf;
    pf=fopen("ALUMNOS.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    printf("\nDNI\t\tNOMBRE-APELLIDO\t\tNOTA 1\tNOTA 2\tPROMEDIO\n");
    fread(&al,sizeof(T_Alum),1,pf);
    while(!feof(pf))
    {
        printf("\n%d\t%s\t%d\t%d\t%.2f\n",al.dni,al.nomyape,al.nota1,al.nota2,al.prom);
        fread(&al,sizeof(T_Alum),1,pf);
    }
    fclose(pf);
}
