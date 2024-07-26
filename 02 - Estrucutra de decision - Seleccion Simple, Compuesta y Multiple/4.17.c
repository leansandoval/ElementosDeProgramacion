/*4.17. Confeccionar un programa que pueda determinar el importe a pagar por una prestación médica según su
código. Los importes se cobran según la siguiente tabla:

  Codigo | Importe
--------------------
    A    |   20
    D    |   40
    F    |   60
    M    |   150
    T    |   150

Se debe ingresar el número de historia del paciente y el código de la prestación. Se debe emitir un ticket
con el número de la historia, el código y el importe a pagar.
------------------------------------------------------------------------------------------------------------
Resolucion: Como primer lugar, se pide ingresar numero de historia del paciente (int). Luego el codigo de
prestacion (char); para este ejercicio tenemos 5 codigos (A,D,F,M,F) los cuales tienen distintos importes.
Para mejor resolucion, en vez de muchos if's se utiliza un switch: dependiendo el codigo que tendra el
paciente, va a tener un importe correspondiente.
Declaramos una variable tipo bandera, en la que si el codigo esta bien ingresado (bandera=1) se muestra por
pantalla el numero de historia del paciente, el codigo de prestacion y el importe a pagar. En el codigo esta
implicito, si 'entra' al switch. Si bandera esta en cero, quiere decir que el codigo ingresado es incorrecto,
por lo que termina el programa.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    int numero_paciente,importe,bandera=0;
    char codigo;
    printf("\nIngrese el numero de historia del paciente: ");
    scanf("%d",&numero_paciente);
    printf("\nIngrese el codigo de la prestacion: ");
    fflush(stdin);
    scanf("%c",&codigo);
    switch(codigo)
    {
        case 'A': case 'a':
            importe=20;
            break;
        case 'D': case 'd':
            importe=40;
            break;
        case 'F': case 'f':
            importe=60;
            break;
        case 'M': case 'm': case 'T': case 't':
            importe=150;
            break;
        default:
            bandera=1;
    }
    if(bandera==0)
        printf("\nNUMERO DE HISTORIA    %d\tCODIGO  %c\t    IMPORTE A PAGAR $%d\n",numero_paciente,codigo,importe);
    else
        printf("\nEl codigo ingresado no es valido\n");
    getch();
    return 0;
}
