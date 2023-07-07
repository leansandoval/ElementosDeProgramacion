#include <stdio.h>
#include <conio.h>
int main()
{
    int n1,n2;
    printf("\nIngrese el primer numero: ");
    scanf("%d",&n1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d",&n2);
    if(n1%n2==0)
        printf("\nEl numero %d es divisible por %d",n1,n2);
    else
        printf("\nEl numero %d NO es divisible por %d",n1,n2);
    printf("\n\n");
}
