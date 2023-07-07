#include <stdio.h>
#include <stdlib.h>

typedef struct{int cl;
                float peso;
                }T_Enc;

void MostrarArch();

int main()
{
    MostrarArch();
    return 0;
}

void MostrarArch()
{
    T_Enc enc;
    FILE *pf;
    pf=fopen("ENCOM.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    printf("\n Codigo de localidad \t Peso de encomienda");
    fread(&enc,sizeof(T_Enc),1,pf);
    while(!feof(pf))
    {
        printf("\n%d \t\t\t%.2f",enc.cl,enc.peso);
        fread(&enc,sizeof(T_Enc),1,pf);
    }
    fclose(pf);
}
