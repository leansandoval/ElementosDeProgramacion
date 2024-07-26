/*5.1.3 Se ingresan 50 números enteros. Determinar el promedio de los números pares.
-------------------------------------------------------------------------------------
Resolucion: se realiza un scanf dentro del for para el ingreso de los 50 numeros.
Luego se lo divide por 2 para saber si es un numero par. Si lo es, se incrementa una
variable contadora (previamente inicializada) para saber la cantidad de numero pares
que se ingresaron; y ademas una variable sumadora que acumule la suma de los numeros
pares. Luego de terminar el ciclo se realiza el promedio utilizando la variable
sumadora dividiendola por la cantidad de numeros pares que hubo en total.
Como la los numeros son enteros y la cantidad tambien, se debera castear el resultado
a flotante.
*/

#include<stdio.h>
#include<conio.h>
int main ()
{
    int numero,par,i,cantidadPar=0,suma=0;
    float promedio;
    printf("\nIngrese 50 numeros enteros: ");
    for(i=1;i<=50;i++)
    {
        scanf("%d",&numero);
        par=numero%2;
        if(par==0)
            {
                cantidadPar++;
                suma+=numero;
            }
    }
    promedio=(float)suma/cantidadPar;
    printf("\nEl promedio de los numeros pares es: %.2f\n",promedio);
    return 0;
    getch();
}
