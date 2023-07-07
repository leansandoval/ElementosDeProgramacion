#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int main()
{
    int cant;
    char Frase[500];
    printf("\nIngrese una frase de no mas de 500 caracteres: ");
    fgets(Frase,500,stdin);
    printf("\n\n%s",Frase);
    cant=strlen(Frase);
    printf("\nCantidad de palabras que contiene la frase: %d",cant);
    printf("\n\n");
    system("pause");
}

