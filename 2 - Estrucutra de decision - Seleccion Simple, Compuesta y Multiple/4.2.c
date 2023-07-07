/*4.2. Dados tres números determinar e informar con un mensaje si el primer número ingresado es menor que
los otros dos.
----------------------------------------------------------------------------------------------------------
Resolucion: Asumo que los numero ingresados son de tipo int. Luego, la primera condicion sera que el primer
numero sea distinto a los otros dos. Con un simple if puedo saber si es menor a ambos.
*/

#include <stdio.h>
int main()
{
    int n1,n2,n3;
    printf("\nIngresar 3 numeros enteros consecutivos:\n");
    scanf("%d%d%d",&n1,&n2,&n3);
    if (n1!=n2 && n1!=n3)
        if(n1<n2 && n1<n3)
            printf("\nEl primer numero ingresado (%d) es menor a %d y a %d\n",n1,n2,n3);
        else
            printf("\nEl primero numero ingresado (%d) NO ES el numero menor\n",n1);
    else
        printf("\nEl primer numero ingresado se repitio al menos 2 veces\n");
    return 0;
}
