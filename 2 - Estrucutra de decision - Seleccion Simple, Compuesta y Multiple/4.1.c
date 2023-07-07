/*4.1. Se ingresan 3 números distintos. Determinar el mayor.
------------------------------------------------------------------------------------------------------------
Resolucion: Para este ejercicio se puede ralizar con varios if's. Como el enunciado pide 3 numeros DISTINTOS,
esta sera la primera condicion, por lo que termino el programa si al menos 2 numeros ingresados son iguales.
En el caso que sean todos distintos, empiezo con el primer numero si es mayor a los tres. En el caso que no
lo sea, quiere decir que el mayor esta en el segundo y el tercer numero. Se realizar otro if nuevamente para
saber cual de los dos es el mayor.
*/

#include <stdio.h>
int main ()
{
    int n1,n2,n3;
    printf("\nIngrese 3 numeros distintos consecutivos: ");
    scanf("%d%d%d",&n1,&n2,&n3);
    if(n1!=n2 && n1!=n3 && n2!=n3)
        if(n1>n2&&n1>n3)
            printf("\nEl numero %d es el numero mayor",n1);
        else
            if(n2>n3)
                printf("\nEl numero %d es el numero mayor",n2);
            else
                printf("\nEl numero %d es el numero mayor",n3);
    else
        printf("\nTodos los numeros (o al menos 2) son iguales");
}
