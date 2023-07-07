#include<stdio.h>
#include<string.h>

int main()
{
    char Nombre[11],Apellido[11],NomYApe[21];
    printf("\nIngrese su nombre: ");
    fflush(stdin);
    gets(Nombre);
    printf("\nIngrese su apellido: ");
    fflush(stdin);
    gets(Apellido);
    strcpy(NomYApe,Nombre);
    strcat(strcat(strcat(NomYApe,",")," "),Apellido);
    printf("\nNombre: %s",Nombre);
    printf("\n\nApellido: %s",Apellido);
    printf("\n\nNombre y apellido en formato NOMBRE, APELLIDO: %s",NomYApe);
    printf("\n\n");
    system("pause");
}
