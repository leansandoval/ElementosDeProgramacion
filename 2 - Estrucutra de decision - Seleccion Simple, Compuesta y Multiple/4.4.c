/*4.4. Ingresar 3 valores reales y:
a. Si los dos primeros son mayores al tercero informar “MAYORES AL TERCERO”.
b. Si los tres son iguales informar “TRES IGUALES”.
c. Si alguno de los dos primeros es menor al tercero informar “ALGUNO ES MENOR”.
--------------------------------------------------------------------------------------------------
Resolucion: como son tres condiciones (a,b,c) solo hay que poner 3 if's encadenados. Al ingresar
3 valores reales, vamos a tener 3 variables float
a - Para esta condicion: num1 > num3 y num2 > num3
b - Para esta condicion: num1 = num2 y num1=num3 (en consecuencia no hace falta poner num2 = num3)
c - Para esta condicion: num1 < num3 o num 2 < num3
Fijarse que las primeras dos condiciones estan con Y (deben cumplise las dos preposiciones); y la
tercera esta con un O (ya que dice ALGUNO) por lo que basta con que se cumpla una sola condicion.
*/

#include <stdio.h>
int main ()
{
    float n1,n2,n3;
    printf("\nIngrese tres numeros uno despues del otro: ");
    scanf("%f%f%f",&n1,&n2,&n3);
    if(n1==n2 && n1==n3)
        printf("\nTRES IGUALES");
    else
        if(n1>n3&&n2>n3)
            printf("\nMAYORES AL TERCERO");
        else
            if(n1<n3||n2<n3)
                printf("\nALGUNO ES MENOR");
}
