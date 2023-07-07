/*6.4. Se ingresa valores positivos entre 1 y 50, finalizando el ingreso con el valor -10, para ello generar una función
que valide dicho ingreso. Calcular:

    a. Cuántos números son primos.
    b. Cantidad de números pares.
    c. Promedio de los números impares.

Utilizar las siguientes funciones:

    • Resto: recibe por parámetro el Dividendo y el Divisor; Retorna el resto.
    • EsPar: recibe por parámetro un número; Retorna 1 si es Par, 0 si es Impar; Invoca a la función Resto.
    • EsPrimo: recibe por parámetro un número; Retorna 1 si es primo, 0 si no es primo; Invoca a la
    función Resto. (un número es primero si solo es divisible por 1 y por sí mismo).
    • Promedio: recibe por parámetro la suma y el contador; Retorna el promedio si contador > 0 sino retorna 0.

------------------------------------------------------------------------------------------------------------------------
Resolucion: para la validacion de datos entre el rango pedido utilizo la funcion esDatoVal e IngresaDatoValido.
Para la cantidad de numeros primos y pares, se declaran variables acumuladoras y para el promedio de numeros impares,
ademas de esto se declara una variable sumadora para estos ultimos.
NOTA:
* Para el promedio utilize un operador ternario para simplificar lineas
* En las funciones Resto y EsPar se realizo la asignacion en el return por lo mismo que lo de arriba.
*/

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define LIMITE_INFERIOR 1
#define LIMITE_SUPERIOR 50
#define CONDICION_DE_FIN -10

bool esDatoValido (int,int,int);
int IngresaDatoValido (int,int,int);
int Resto (int,int);
int EsPar (int);
int EsPrimo(int);
float Promedio (int,int);

int main()
{
    int numero,cantidadPares=0,cantidadPrimos=0,sumaNumerosImpares=0,cantidadImpares=0;
    numero=IngresaDatoValido(LIMITE_INFERIOR,LIMITE_SUPERIOR,CONDICION_DE_FIN);
    while(numero!=-10)
    {
        if(EsPar(numero)==1)
            cantidadPares++;
        else
        {
            cantidadImpares++;
            sumaNumerosImpares+=numero;
        }
        if(EsPrimo(numero)==1)
            cantidadPrimos++;
        numero=IngresaDatoValido(LIMITE_INFERIOR,LIMITE_SUPERIOR,CONDICION_DE_FIN);
    }
    printf("\nCantidad de numeros primos: %d\n",cantidadPrimos);
    printf("\nCantidad de numeros pares: %d\n",cantidadPares);
    printf("\nPromedio de numeros impares: %.2f\n",Promedio(sumaNumerosImpares,cantidadImpares));
    return 0;
}

bool esDatoValido (int numero,int limiteInferior,int limiteSuperior)
{
    if(numero>=limiteInferior && numero<=limiteSuperior)
        return true;
    else
        return false;
}

int IngresaDatoValido (int limiteInferior,int limiteSuperior,int condicionDeFin)
{
    int dato,bandera=0;
    do
    {
        if(bandera==1)
            printf("\nEl numero ingresado no se encuentra en el rango admitido\n");
        bandera=1;
        printf("\nIngrese un numero entre %d y %d (-10 para terminar): ",limiteInferior,limiteSuperior);
        scanf("%d",&dato);
    }
    while(!esDatoValido(dato,limiteInferior,limiteSuperior) && dato!=condicionDeFin);
    return dato;
}

int Resto (int dividendo,int divisor)
{
    int resto;
    return resto=dividendo%divisor;
}

int EsPar (int numero)
{
    return Resto(numero,2)==0 ? 1 : 0;
}

int EsPrimo (int numero)
{
    int i,posiblePrimo=0;
    for(i=2; i<=numero; i++)
        if(Resto(numero,i)==0 && Resto(numero,1)==0)
            posiblePrimo++;
    if(posiblePrimo==1)
        return 1;
    else
        return 0;
}

float Promedio (int suma,int cantidad)
{
    float promedio;
    return promedio = cantidad>0? (float)suma/cantidad : 0;
}
