/*9.3. Se sabe que como maximo en una comision de Elementos de Programacion hay 80 alumnos. De cada
alumno se conoce:

    * Numero de DNI (entero).
    * Apellido y Nombre (80 caracteres).
    * Nota1, Nota2 (entero).
    * Nota Promedio (real, calculado segun Nota1 y Nota2).

Se solicita:

    a. Declarar un tipo de dato que contenga la informacion del alumno.
    b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
    c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comision, esta
    informacion termina con DNI igual al 0. Funcion ingreso.
    d. Indicar cuantos alumnos aprobaron (ambos parciales con nota >= 4 y cuantos reprobaron la
    materia. Funcion resultado.
    e. Informar los datos de los alumnos de (DNI - Apellido y Nombre - Nota Promedio) de los alumnos.
    PROMOCIONADOS (ambas notas >= 7). Funcion informePromo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define CANT_ALUMNOS 80

typedef struct
{
    int dni, nota1, nota2;
    char apellidoYNombre[81];
    float promedio;
} Alumno;

int esDatoValido(int dato, int limiteInferior, int limiteSuperior);
int ingresarDatoValido(int, int, int);
int ingresarDatoValido2(int, int);
int ingreso(Alumno[], int);
void resultado(Alumno[], int);
void informePromo(Alumno[], int);

int main()
{
    Alumno alumnos[CANT_ALUMNOS];
    int cantAlumnos = ingreso(alumnos, CANT_ALUMNOS);
    if (cantAlumnos)
    {
        cantAlumnos++;
        resultado(alumnos, cantAlumnos);
        informePromo(alumnos, cantAlumnos);
    }
    else
        printf("\nNo hay alumnos.\n");
    printf("\n");
    system("pause");
    return 0;
}

int esDatoValido(int dato, int limiteInferior, int limiteSuperior)
{
    return dato >= limiteInferior && dato <= limiteSuperior ? 1 : 0;
}

int ingresarDatoValido(int primerLimite, int segundoLimite, int tercerLimite)
{
    int dato, control = 0;
    do
    {
        if (control == 1)
            printf("\nDato invalido, ingrese otro: ");
        control = 1;
        scanf("%d", &dato);
    } while (!esDatoValido(dato, primerLimite, segundoLimite) && dato != tercerLimite);
    return dato;
}

int ingresarDatoValido2(int limiteInferior, int limiteSuperior)
{
    int dato, control = 0;
    do
    {
        if (control == 1)
            printf("\nDato invalido, ingrese otro dato: ");
        control = 1;
        scanf("%d", &dato);
    } while (!esDatoValido(dato, limiteInferior, limiteSuperior));
    return dato;
}

int ingreso(Alumno alumnos[], int cantElem)
{
    Alumno alumno;
    int cantAlumnos = 0;
    printf("\nIngrese DNI del alumno (0 para terminar): ");
    alumno.dni = ingresarDatoValido(10000000, 99999999, 0);
    while (alumno.dni && cantAlumnos < cantElem)
    {
        printf("\nIngrese apellido y nombre del alumno: ");
        fflush(stdin);
        fgets(alumno.apellidoYNombre, sizeof(alumno.apellidoYNombre), stdin);
        
        printf("\nIngrese la primera nota: ");
        alumno.nota1 = ingresarDatoValido2(1, 10);
        
        printf("\nIngrese la segunda nota: ");
        alumno.nota2 = ingresarDatoValido2(1, 10);
        
        alumno.promedio = (float)(alumno.nota1 + alumno.nota2) / 2;
        
        alumnos[cantAlumnos++] = alumno;

        printf("\nIngrese DNI del alumno (0 para terminar): ");
        alumno.dni = ingresarDatoValido(10000000, 99999999, 0);
    }
    return cantAlumnos;
}

void resultado(Alumno alumnos[], int cantElem)
{
    int aprobados = 0, desaprobados = 0;
    for (int i = 0; i < cantElem; i++) {
        if (alumnos[i].nota1 >= 4 && alumnos[i].nota2 >= 4)
            aprobados++;
        else
            desaprobados++;
    }
    printf("\nLa cantidad de alumnos que aprobaron son %d y los que desaprobaron son %d\n", aprobados, desaprobados);
}

void informePromo(Alumno alumnos[], int cantElem)
{
    printf("\nDNI\t\tApellido y Nombre\tNota Promedio\n");
    for (int i = 0; i < cantElem; i++) {
        if (alumnos[i].nota1 >= 7 && alumnos[i].nota2 >= 7)
            printf("\n%d\t%s\t\t%.2f\n", alumnos[i].dni, alumnos[i].apellidoYNombre, alumnos[i].promedio);
    }
}
