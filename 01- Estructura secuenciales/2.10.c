/*2.10. Confeccionar un programa que solicite el ingreso del valor del radio (r) de un círculo y con dicho valor calcule
la superficie del círculo, la longitud de la circunferencia (perímetro) y el volumen de la esfera.
Superficie = π(r^2)
Perimetro = 2πr
Volumen =(4/3)π(r^3)
-------------------------------------------------------------------------------------------------------------------------
Resolucion: Definimos la variable flotante r y aplicamos las formulas. Para el valor de π utilizo #define.
Observar el lugar de la division para la formula de volumen.
*/

#include <stdio.h>
#define pi 3.141592654

int main()
{
    float r,superficie,perimetro,volumen;
    printf("\nIngrese el valor del radio: ");
    scanf("%f",&r);
    superficie=pi*r*r;
    perimetro=2*pi*r;
    volumen=4*pi*r*r*r/3;
    printf("\nSuperficie: %.2f\n",superficie);
    printf("\nPerimetro: %.2f\n",perimetro);
    printf("\nVolumen: %.2f\n",volumen);
}

