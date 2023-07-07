/*5.1.4 Se ingresan 100 letras. Determinar la cantidad de vocales ingresadas.
------------------------------------------------------------------------------------------
Resolucion: un scanf dentro de un ciclo for desde 1 hasta 100. Si la letra es una vocal
(ya sea minuscula y mayuscula) se incrementara la variable contadora de las letras
vocales.
*/

#include<stdio.h>
#include<conio.h>
int main()
{
    char letra;
    int i,cantidadVocales=0;
    printf("\nIngrese 100 letras: ");
    for(i=1;i<=100;i++)
    {
        scanf("%c",&letra);
        fflush(stdin);
        if(letra=='a'||letra=='A'||letra=='e'||letra=='E'||letra=='i'||letra=='I'||letra=='o'||letra=='O'||letra=='u'||letra=='U')
            cantidadVocales++;
    }
    printf("\nLa cantidad de vocales ingresadas: %d\n",cantidadVocales);
    return 0;
    getch();
}
