#include <stdio.h>
int main ()
{
    int num1,num2,num3;
    printf("\nIngrese 3 numeros naturales\n");
    printf("\nPrimer numero: ");
    scanf("%d",&num1);
    printf("\nSegundo numero: ");
    scanf("%d",&num2);
    printf("\nTercer numero: ");
    scanf("%d",&num3);
    if(num1<num2 && num1<num3)
    {
        if(num2<num3)
            {
                printf("\nOrdenados en orden creciente:\n");
                printf("\n%d\n",num1);
                printf("\n%d\n",num2);
                printf("\n%d\n",num3);
            }
        else
        {
            printf("\nOrdenados en orden creciente:\n");
            printf("\n%d\n",num1);
            printf("\n%d\n",num3);
            printf("\n%d\n",num2);
        }
   }
    if(num2<num1 && num2<num3)
    {
        if(num1<num3)
        {
            printf("\nOrdenados en orden creciente:\n");
            printf("\n%d\n",num2);
            printf("\n%d\n",num1);
            printf("\n%d\n",num3);
        }
        else
        {
            printf("\nOrdenados en orden creciente:\n");
            printf("\n%d\n",num2);
            printf("\n%d\n",num3);
            printf("\n%d\n",num1);
        }
    }
    if(num3<num1 && num3<num2)
    {
        if(num1<num2)
        {
            printf("\nOrdenados en orden creciente:\n");
            printf("\n%d\n",num3);
            printf("\n%d\n",num1);
            printf("\n%d\n",num2);
        }
        else
        {
            printf("\nOrdenados en orden creciente:\n");
            printf("\n%d\n",num3);
            printf("\n%d\n",num2);
            printf("\n%d\n",num1);
        }
    }
}
