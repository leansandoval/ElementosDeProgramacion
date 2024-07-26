/*4.6. Confeccionar un programa que permita ingresar 4 números enteros, de a uno por vez y determine el menor
valor y su número de orden. Informe los valores ingresados e identifique al menor con mensaje aclaratorio.
-------------------------------------------------------------------------------------------------------------
Se crean 4 variables int para ingresarlas por teclado. Luego con unos if's encadenados, se puede sacar el
menor rapidamente.
*/

#include<stdio.h>
#include<conio.h>

int main()
{
    int n1,n2,n3,n4;
    printf("\nIngrese cuatro numeros enteros\n");
    printf("\nPrimer numero: ");
    scanf("%d",&n1);
    printf("\nSegundo numero: ");
    scanf("%d",&n2);
    printf("\nTercer numero: ");
    scanf("%d",&n3);
    printf("\nCuarto numero: ");
    scanf("%d",&n4);
    if(n1<n2 && n1<n3 && n1<n4)
        printf("\n%d es el menor, es el primer numero ingresado\n",n1);
    else
        if(n2<n1 && n2<n4 && n2<n3)
            printf("\n%d es el menor, es el segundo numero ingresado\n",n2);
        else
            if(n3<n1 && n3<n2 && n3<n4)
                printf("\n%d es el menor, es el tercer numero ingresado\n",n3);
            else
                printf("\n%d es el menor, es el ultimo numero ingresado\n",n4);
}
