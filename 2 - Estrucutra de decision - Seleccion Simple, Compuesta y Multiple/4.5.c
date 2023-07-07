/*4.5. Se ingresan 3 números enteros. Informarlos en orden creciente.
-----------------------------------------------------------------------------------
Resolucion: Declaramos tres variables int. Como debemos ordenarlos de menor a mayor
primero me fijo si el primer numero es el menor de ambos: num1 < num2 Y num1 < num3
si es verdadero, solo queda saber cual es el menor entre los otros dos, por lo que
declaro la condicion num2 < num3; si es verdadero. Quiere decir que el orden
creciente es num1 - num2 - num3. Si la ultima condicion es falsa, quiere decir que
el orden creciente es num1 - num3 - num3.
Realizo el mismo razonamiento para las demas combinaciones (6 combinaciones en
total).
*/

#include <stdio.h>
#include <conio.h>
int main()
{
    int n1,n2,n3;
    printf("\nIngrese el primer numero: ");
    scanf("%d",&n1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d",&n2);
    printf("\nIngrese el tercer numero: ");
    scanf("%d",&n3);
    if(n1<n2 && n1<n3)
        if(n2<n3)
            printf("\nOrdenados en orden creciente: %d  %d  %d",n1,n2,n3);
        else
            printf("\nOrdenados en orden creciente: %d  %d  %d",n1,n3,n2);
    else
        if(n2<n3 && n2<n1)
            if(n1<n3)
                printf("\nOrdenados en orden creciente: %d  %d  %d",n2,n1,n3);
            else
                printf("\nOrdenados en orden creciente: %d  %d  %d",n2,n3,n1);
    if(n3<n2&&n3<n1)
        if(n2<n1)
            printf("\nOrdenados en orden creciente: %d  %d  %d",n3,n2,n1);
    else
        printf("\nOrdenados en orden creciente: %d  %d  %d",n3,n1,n2);
    printf("\n\n");
    return 0;
    getch();
}
