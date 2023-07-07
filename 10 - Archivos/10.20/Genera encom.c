#include <stdio.h>
#include <stdlib.h>

typedef struct{int cl;
                float peso;
                }T_Enc;

void GeneraArch ();

int main()
{
    GeneraArch();
    return 0;
}

void GeneraArch ()
{
    T_Enc enc;
    FILE *pf;
    pf=fopen("ENCOM.dat","wb");
     if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit (1);
    }
    printf("\nIngrese codigo de localidad:");
    scanf("%d",&enc.cl);
    while(enc.cl!=0)
    {
        printf("\nIngrese peso de la encomienda:");
        scanf("%f",&enc.peso);
        if(enc.cl>=0 && enc.peso>=0)
            fwrite(&enc,sizeof(T_Enc),1,pf);
        printf("\nIngrese codigo de localidad:");
        scanf("%d",&enc.cl);
    }
    fclose(pf);
}
