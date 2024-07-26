#include<stdio.h>
int main()
{
    int da,ma,aa,dn,mn,an,anio;
    printf("\nIngrese fecha actual en formado dd/mm/aaaa: ");
    scanf("%d%d%d",&da,&ma,&aa);
    printf("\nIngrese fecha nacimiento en formato dd/mm/aaaa: ");
    scanf("%d%d%d",&dn,&mn,&an);
    if(an<aa)
        if(da<dn || ma<mn)
        {
            anio=(aa-an)-1;
            printf("\nSu edad es de: %d",anio);
        }
        else
        {
            anio=(aa-an);
            printf("\nSu edad es de: %d",anio);
        }
    else
        printf("\nLa fecha de nacimiento es mayor a la actual");
}
