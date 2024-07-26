/*2.3. Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con mensajes aclaratorios la suma, el producto, el cociente y el resto.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
Resolucion: Se ingresan dos variables int llamadas n1 y n2. Declaramos las demas variables correspondientes para la suma, producto, cociente y resto (tambien int).
Para el segundo valor entero, se pide que sea distinto de 0 ya que de lo contrario, estare dividiendo un entero por 0.
*/

#include <stdio.h>
int main ()
{
    int numero1,numero2,suma,producto,cociente,resto;
    printf("\nIngrese un numero entero: ");
    scanf("%d",&numero1);
    printf("\nIngrese un numero entero (distinto de 0): ");
    scanf("%d",&numero2);
    suma=numero1+numero2;
    producto=numero1*numero2;
    cociente=numero1/numero2;
    resto=numero1%numero2;
    printf("\nEl resultado de operar %d y %d es: ",numero1,numero2);
    printf("\n\nSuma: %d",suma);
    printf("\nProducto: %d",producto);
    printf("\nCociente: %d",cociente);
    printf("\nResto:%d",resto);
    return 0;
}
