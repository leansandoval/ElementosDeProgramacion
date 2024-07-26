#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>

#define VIDAS 5

void generarPalabraOculta(const char palabra[], char palabraOculta[]);
bool seEncuentraLetraEnCadena(const char palabra[], char letra);
void completarLetraEnPalabraOculta(const char palabra[], char palabraOculta[], char letra);
void mostrarPalabraOculta(const char palabraOculta[]);
void dibujarAhorcado(int vidas);

int main()
{
    char palabra[11];
    char palabraOculta[11];
    int vidas = VIDAS;
    char letra;

    printf("Ingrese la palabra de 10 caracteres como maximo: ");
    fgets(palabra, sizeof(palabra), stdin);
    palabra[strcspn(palabra, "\n")] = '\0';

    generarPalabraOculta(palabra, palabraOculta);

    while (vidas && strcmp(palabra, palabraOculta))
    {
        printf("Vidas restantes: %d\n", vidas);

        do
        {
            printf("Ingrese una letra: ");
            fflush(stdin);
            scanf("%c", &letra);
        } while (!isalpha(letra));

        if (seEncuentraLetraEnCadena(palabra, letra))
        {
            completarLetraEnPalabraOculta(palabra, palabraOculta, letra);
            printf("\n");
            mostrarPalabraOculta(palabraOculta);
            printf("\n\n");
        }
        else
        {
            printf("La letra no se encuentra en la palabra. Perdiste una vida.\n");
            vidas--;
            dibujarAhorcado(VIDAS - vidas);
        }
    }

    !strcmp(palabra, palabraOculta) ? printf("¡Felicitaciones! Adivinaste la palabra.\n") : printf("Se agotaron las vidas. La palabra era: %s\n", palabra);

    system("pause");
    return 0;
}

void generarPalabraOculta(const char palabra[], char palabraOculta[])
{
    size_t i;
    for (i = 0; i < strlen(palabra); i++)
        palabraOculta[i] = '_';
    palabraOculta[i] = '\0';
}

bool seEncuentraLetraEnCadena(const char palabra[], char letra)
{
    bool seEncontro = false;

    for (size_t i = 0; i < strlen(palabra) && !seEncontro; i++)
        if (toupper(palabra[i]) == toupper(letra))
            seEncontro = true;

    return seEncontro;
}

void completarLetraEnPalabraOculta(const char palabra[], char palabraOculta[], char letra)
{
    for (size_t i = 0; i < strlen(palabra); i++)
    {
        if (toupper(palabra[i]) == toupper(letra))
            palabraOculta[i] = palabra[i];
    }
}

void mostrarPalabraOculta(const char palabraOculta[])
{
    for (size_t i = 0; i < strlen(palabraOculta); i++)
        printf("%c ", palabraOculta[i]);
}

void dibujarAhorcado(int vidasPerdidas)
{
    printf(" +---+\n");
    printf(" |   |\n");
    printf(" |   %s\n", vidasPerdidas >= 2 ? "O" : " ");
    printf(" |  %s%s%s\n", vidasPerdidas >= 4 ? "/" : " ", vidasPerdidas >= 3 ? "|" : " ", vidasPerdidas >= 4 ? "\\" : " ");
    printf(" |  %s %s\n", vidasPerdidas >= 5 ? "/" : " ", vidasPerdidas >= 5 ? "\\" : " ");
    printf(" |\n");
    printf(" =========\n");
}