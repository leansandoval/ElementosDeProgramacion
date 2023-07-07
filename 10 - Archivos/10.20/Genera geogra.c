#include <stdio.h>
#include <stdlib.h>

typedef struct{int cloc,cprov,czg;}T_Geo;

int esDatoVal (int,int,int);
void GeneraArch ();

int main()
{
    GeneraArch();
    return 0;
}

void GeneraArch ()
{
    T_Geo mov;
    FILE *pf;
    pf=fopen("GEOGRA.dat","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit (1);
    }
    printf("\nIngrese numero de localidad:");
    scanf("%d",&mov.cloc);
    while(mov.cloc != 0)
    {
        printf("\nIngrese codigo de provincia:");
        scanf("%d",&mov.cprov);
        printf("\nIngrese codigo de zona geografica:");
        scanf("%d",&mov.czg);
        if(mov.cloc>=0 &&  esDatoVal(mov.cprov,1,24) && esDatoVal(mov.czg,1,9))
            fwrite(&mov,sizeof(T_Geo),1,pf);
        printf("\nIngrese numero de localidad:");
        scanf("%d",&mov.cloc);
    }
    fclose(pf);
}

int esDatoVal (int x, int li, int ls)
{
    if(x>li && x<ls)
        return 1;
    else
        return 0;
}
