/*5.2.3 Confeccionar un programa que pueda ingresar una secuencia de caracteres hasta que se digite un *. Se
desea obtener e informar cuantos caracteres ingresados son numéricos y cuantos alfabéticos. Estos últimos
tienen que mostrarse separados por mayúsculas y minúsculas. También informar la cantidad de otros
símbolos que no sean ni letras ni números.
------------------------------------------------------------------------------------------------------------
Resolucion: con un ciclo while y como condicion de fin el ingreso de un *, se utilizan variables contadoras
tanto para numeros, mayusculas, minusculas y otros caracteres. Esto se realiza con if's anidados. Recordar
tambien que para el ingreso de caracteres se debe limbiar el buffer del teclado, para ello utilizamos el
fflush.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    char caracter;
    int mayusculas=0,minusculas=0,numeros=0,otro=0;
    printf("\nIngrese un caracter (* para terminar): ");
    fflush(stdin);
    scanf("%c",&caracter);
    /*a) Limites de los if's con caracteres*/
    while(caracter!='*')
    {
        if(caracter>='0'&&caracter<='9')
            numeros++;
        else if(caracter>='A'&&caracter<='Z')
            mayusculas++;
        else if(caracter>='a'&&caracter<='z')
            minusculas++;
        else
            otro++;
        printf("\nIngrese otro caracter (* para terminar): ");
        fflush(stdin);
        scanf("%c",&caracter);
    }

    /*b) Limites de los if's segundo codigo ASCII
    while(caracter!='*')
    {
        if(caracter>=48&&caracter<=57)
            numeros++;
        else if(caracter>=65&&caracter<=90)
            mayusculas++;
        else if(caracter>=97&&caracter<=122)
            minusculas++;
        else
            otro++;
        printf("\nIngrese otro caracter (* para terminar): ");
        fflush(stdin);
        scanf("%c",&caracter);
    }
    */

    /*c) Limites de los if's segun funciones de la biblioteca stdlib.h
    while(caracter!='*')
    {
        if(isdigit(caracter))
            numeros++;
        else if(isupper(caracter))
            mayusculas++;
        else if(islower(caracter))
            minusculas++;
        else
            otro++;
        printf("\nIngrese otro caracter (* para terminar): ");
        fflush(stdin);
        scanf("%c",&caracter);
    }
    */

    printf("\nEl total de numeros es: %d\n",numeros);
    printf("\nEl total de letras mayusculas es: %d\n",mayusculas);
    printf("\nEl total de letras minusculas es: %d\n",minusculas);
    printf("\nEl total de otros caracteres es: %d\n",otro);
    return 0;
}
