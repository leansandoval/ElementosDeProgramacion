/*5.2.10 En un proceso de control se evalúan valores de temperatura, finalizando cuando de ingresa un valor
ficticio de temperatura -50.Determinar el valor máximo y mínimo medido y sus posiciones respecto al ingreso.
------------------------------------------------------------------------------------------------------------
Resolucion: parecido al maximo y minimo utlizando un ciclo for, la unica diferencia es que la variable de
iteracion sera la cantidad de temperatura ingresadas, que tambien deberan guardarse en otra variable en el
caso de ser maximo o minimo.*/

#include<stdio.h>

int main()
{
    int cantidadTemperaturas=0,posicionMayor,posicionMenor;
    float mayorTemperatura,temperatura,menorTemperatura;
    printf("\nIngrese una temperatura (-50 para terminar): ");
    scanf("%f",&temperatura);
    while(temperatura!=-50)
    {
        cantidadTemperaturas++;
        if(cantidadTemperaturas==1)
        {
            mayorTemperatura=temperatura;
            posicionMayor=cantidadTemperaturas;
            menorTemperatura=temperatura;
            posicionMenor=cantidadTemperaturas;
        }
        if(temperatura>mayorTemperatura)
        {
            mayorTemperatura=temperatura;
            posicionMayor=cantidadTemperaturas;
        }
        else if(menorTemperatura>temperatura)
        {
            menorTemperatura=temperatura;
            posicionMenor=cantidadTemperaturas;
        }
        printf("\nIngrese una temperatura (-50 para terminar): ");
        scanf("%f",&temperatura);
    }
    if(cantidadTemperaturas==0)
        printf("\nNo hay temperaturas ingresadas\n");
    else
    {
        printf("\nLa temperatura mayor es de %.2f ingresada en la posicion %d\n",mayorTemperatura,posicionMayor);
        printf("\nLa temperatura menor es de %.2f ingresada en la posicion %d\n",menorTemperatura,posicionMenor);
    }
    return 0;
}
