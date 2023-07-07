#include <stdio.h>
#include <stdlib.h>

typedef struct{int codloc;
                int codprov;
                int codzona;
                }T_Mov;

int esDatoVal (int,int,int);
void GeneraArch ();

int main()
{
    GeneraArch();
    return 0;
}

void GeneraArch ()
{
    T_Mov mov;
    FILE *pf;
    pf=fopen("GEOGRA","wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit (1);
    }
    printf("\nIngrese numero de localidad:");
    scanf("%d",&mov.codloc);
    while(mov.codloc != 0)
    {
        printf("\nIngrese codigo de provincia:");
        scanf("%d",&mov.codprov);
        printf("\nIngrese codigo de zona geografica:");
        scanf("%d",&mov.codzona);
        if(mov.codloc>=0 &&  esDatoVal(mov.codprov,1,24) && esDatoVal(mov.codzona,1,9))
            fwrite(&mov,sizeof(T_Mov),1,pf);
        printf("\nIngrese numero de localidad:");
        scanf("%d",&mov.codloc);
    }
    fclose(pf);
}

int esDatoVal (int x, int ls, int li)
{
    if(x>=li && x<=ls)
        return 1;
    else
        return 0;
}

