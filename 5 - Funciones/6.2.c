/*6.2. Se ingresan números enteros comprendidos entre 100 y 2000 (usar función LeerYValidar). Determinar
usando la función EstaDentroDelRango:

    a. Cantidad de números ingresados entre 100 y 500
    b. Cantidad de números pares ingresados entre 500 y 1200
    c. Promedio de números ingresados entre 1200 y 2000

El ingreso de datos finaliza cuando se ingresa un número igual a 99.
Para realizar este programa se deben realizar las siguientes funciones:

• EstaDentroDelRango: que reciba 3 enteros correspondientes a un número a validar y los límites
superior e inferior del rango. La función debe retornar un 1 si el número a validar se encuentra
dentro del rango indicado o un 0 si no lo está.

• LeerYValidar: que reciba los límites superior e inferior de un rango y retorne un número que se
encuentre dentro del mismo. (El ingreso de datos se realiza dentro de la función). Para validar el
rango utilizar la función EstaDentroDelRango realizada en el punto anterior.
------------------------------------------------------------------------------------------------------------
Resolucion: para el item a, podemos utilizar la funcion EstaDentroDelRango, ya que nuestros limites inferior
y superior seran 100 y 500 respectivamente. Para conocer la cantidad, declaramos una variable contadora
(previamente inicializada) y luego poner un condicion if para saber si esta dentro del rango y empezar a
contar.
Para el item b, sera casi lo mismo que el item a; la unica diferencia sera una condicion mas dentro del if
para saber si el numero es par (resto 0).
Para el item c, ademas de una variable contadora, se declara otra variable sumadora (tambien inicializada),
para luego tener ambas variables y realizar el promedio.
NOTA: Siempre las variables acumuladoras deben inicializarse. No explico las funciones ya que estan bien
explicadas en el enunciado.
*/

#include <stdio.h>
#include <windows.h>

int EstaDentroDelRango (int,int,int);
int LeerYValidar (int,int);

int main()
{
    int numero,cantidadNumerosRangoA=0,cantidadNumerosParesRangoB=0,cantidadNumerosRangoC=0,sumaCantidadNumerosRangoC=0;
    numero=LeerYValidar(99,2000);
    while(numero!=99)
    {
        if(EstaDentroDelRango(numero,100,500)==1)
            cantidadNumerosRangoA++;
        if(numero%2==0&&EstaDentroDelRango(numero,500,1200)==1)
            cantidadNumerosParesRangoB++;
        if(EstaDentroDelRango(numero,1200,2000)==1)
            {
                cantidadNumerosRangoC++;
                sumaCantidadNumerosRangoC+=numero;
            }
        numero=LeerYValidar(99,2000);
    }
    printf("\nCantidad de numeros ingresados entre 100 y 500: %d\n",cantidadNumerosRangoA);
    printf("\nCantidad numeros pares ingresados entre 500 y 1200: %d\n",cantidadNumerosParesRangoB);
    if(cantidadNumerosRangoC>0)
            printf("\nPromedio de los numeros ingresados: %.2f\n",(float)sumaCantidadNumerosRangoC/cantidadNumerosRangoC);
    else
        printf("\nNo hay numeros ingresados en el intervalo 1200 y 2000\n");
    return 0;
}

int EstaDentroDelRango(int numero,int limiteInferior,int limiteSuperior)
{
    if(numero>=limiteInferior && numero<=limiteSuperior)
        return 1;
    else
        return 0;
}

int LeerYValidar(int limiteInferior,int limiteSuperior)
{
    int dato,bandera=0;     //Declaro una variable tipo bandera para el ingreso de un dato correcto o incorrecto
    do
    {
        if(bandera==1)      //Si el numero ingresado no se encuentra en ese rango, se muestra el siguiente mensaje
            printf("\nDato incorrecto, ingrese nuevamente\n");
        bandera=1;
        printf("\nIngrese un dato entero comprendido entre %d y %d (99 para terminar): ",limiteInferior+1,limiteSuperior);
        scanf("%d",&dato);
    }
    while(!EstaDentroDelRango(dato,limiteInferior,limiteSuperior));
    return dato;
}
