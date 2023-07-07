/*4.3. Confeccionar un programa que pueda determinar de 3 números enteros que se ingresan si alguno de ellos
es igual a la suma de los otros dos.
------------------------------------------------------------------------------------------------------------
Resolucion: hace falta 3 if's para saber si uno de estos numeros es la suma de ambas. Fijarse que para
igualdades dentro de los if's es con necesario poner dos iguales ==.
*/

#include <stdio.h>
int main()
{
    int n1,n2,n3;
    printf("Ingrese 3 numeros enteros: ");
    scanf("%d%d%d",&n1,&n2,&n3);
    if(n3==n1+n2)
        printf("\nLa suma de %d y de %d da como resultado %d\n",n1,n2,n3);
    else
        if(n2==n1+n3)
            printf("\nLa suma de %d y de %d da como resultado %d\n",n1,n3,n2);
        else
            if(n1==n2+n3)
                printf("\nLa suma de %d y de %d da como resultado %d\n",n2,n3,n1);
            else
                printf("\nNinguno de los numeros es la suma de los demas\n");
    return 0;
}
