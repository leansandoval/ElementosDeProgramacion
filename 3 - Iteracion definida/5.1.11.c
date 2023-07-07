/*5.1.11 Ingresar 18 valores de temperatura distintos de cero. Se pide determinar e informar cuantas ternas (tres
valores seguidos) de valores positivos y cuantas de negativos hay.
-----------------------------------------------------------------------------------------------------------------
Resolucion: dentro del ciclo for, si la temperatura ingresada es 0 (y 0 es un valor invalido) tengo que decrementar
la variable de iteracion (i--). Luego, si el valor ingresado es positivo incremento la cantidad de temperaturas
positivas. Idem si la temperatura ingresada es negativa. Declaro una variable auxiliar que contendra la temperatura
ingresada anteriormente (inicialmente aux esta en 0 para evitar problemas con el primer ingreso de temperatura). Si
la temperatura anterior (osea aux) es de signo contrario a la que actualmente se esta ingresando, la otra variable
contadora debera ponerse nuevamente en cero ya que en el enunciado indica que se cuenta como ternaria si los valores
son CONSECUTIVOS. Cuando se ingresen 3 temperaturas consecutivas y del mismo signo, se incrementara la variable que
contendra la cantidad de ternarias ya sea positiva o negativa; y ademas se debera inicializar el contador.*/

#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int i,temperaturaPositiva=0,temperaturaNegativa=0,ternasPositivas=0,ternasNegativas=0;
    float aux=0,temperatura;
    for(i=1; i<=18; i++)
    {
        printf("\nIngrese una temperatura: ");
        scanf("%f",&temperatura);
        if(temperatura!=0)
        {
            if(temperatura>0)
            {
                temperaturaPositiva++;
                if(aux<0)
                    temperaturaNegativa=0;
                if(temperaturaPositiva==3)
                {
                    ternasPositivas++;
                    temperaturaPositiva=0;
                }
            }
            else
            {
                temperaturaNegativa++;
                if(aux>0)
                    temperaturaPositiva=0;
                if(temperaturaNegativa==3)
                {
                    ternasNegativas++;
                    temperaturaNegativa=0;
                }
            }
            aux=temperatura;
        }
        else
        {
            printf("\nTemperatura no valida\n");
            i--;
        }
    }
    printf("\nTernas positivas: %d\n",ternasPositivas);
    printf("\nTernas negativas: %d\n",ternasNegativas);
    return 0;
}
