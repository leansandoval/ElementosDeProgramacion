/*9.5. De una persona se conoce los siguientes datos:

    • Número de Legajo (int, entre 1 y 10.000)
    • Apellido (string, 15 caracteres)
    • Nombre (string, 15 caracteres)
    • Altura (float, mayor de 0)
    • Sexo (char, F o M)
    • Día de Nacimiento (int, entre 1 y 31
    • Mes de Nacimiento (int, ente 1 y 12)
    • Año de Nacimiento (int, ente 1950 y 2019)

Se solicita realizar los siguientes procesos:

    a. Con datos ingresados por teclado: Crear una Estructura de Datos con los datos enunciados
    anteriormente y llamarla PERSONA.

    b. Mostrar los datos de la Estructura de Datos del punto a.

    c. Con datos ingresados por teclado: Modificar la Estructura de Datos del punto a, crear una Estructura
    de Datos que contenga Nombre y Apellido y otra Estructura de Datos que contenga Día/Mes/Año
    utilizarla en una nueva Estructura de Datos llamada PERSONA2.

    d. Mostrar los datos de la Estructura de Datos del punto c.

    e. Crear una FUNCION que cargue los datos de la Estructura de Datos del punto c y que retorne los datos
    al programa principal (main).

    f. Con datos ingresados por teclado: Modificar la Estructurad de Datos llamada PERSONA2 del punto c.
    y agregarle un campo/miembro que contenga los códigos de las Materias Aprobadas (pueden llegar a
    ser hasta 36 materias) y llamarla PERSONA3.

    g. Crear una FUNCION que realice el punto f.

    h. Mostrar los datos de la Lista creada en el punto f.

    i. Crear una FUNCION que realice el punto h.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>

#define CANTIDAD_MAXIMA_CODIGOS 36

//Estan todos los puntos en uno solo

typedef struct
{
    int dia, mes, anio;
} Fecha;

typedef struct
{
    int numeroDeLegajo;
    char apellido[16];
    char nombre[16];
    float altura;
    char sexo;
    Fecha fechaDeNacimiento;
    int codigoDeMateriasAprobadas[CANTIDAD_MAXIMA_CODIGOS];
    int cantidadMateriasAprobadas;
} Persona;

bool esBisiesto(int anio);
int cantidadDiasDelMes(int mes, int anio);
bool esFechaValida(Fecha fecha);
Fecha ingresarFechaValida();
void mostrarFechaValida(Fecha fecha);

Persona cargarDatosPersona();
void mostrarPersona(Persona persona);

int main()
{
    Persona persona = cargarDatosPersona();
    printf("\n");
    mostrarPersona(persona);
    printf("\n");
    system("pause");
    return 0;
}

bool esBisiesto(int anio)
{
    return anio % 4 == 0 && anio % 100 != 0 && anio % 400 == 0;
}

int cantidadDiasDelMes(int mes, int anio)
{
    return mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 10 || mes == 12 ? 31 : mes == 2 ? esBisiesto(anio) ? 29 : 28
                                                                                                  : 30;
}

bool esFechaValida(Fecha fecha)
{
    if (fecha.anio >= 1950 && fecha.anio <= 2023)
        if (fecha.mes >= 1 && fecha.mes <= 12)
            return fecha.dia >= 1 && fecha.dia <= cantidadDiasDelMes(fecha.mes, fecha.anio);
    return false;
}

Fecha ingresarFechaValida()
{
    Fecha fecha;

    do
    {
        printf("Ingrese dia: ");
        scanf("%d", &fecha.dia);

        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes);

        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio);

    } while (!esFechaValida(fecha));

    return fecha;
}

void mostrarFechaValida(Fecha fecha)
{
    esFechaValida(fecha) ? printf("%02d/%02d/%04d", fecha.dia, fecha.mes, fecha.anio) : printf("La fecha es invalida");
}

Persona cargarDatosPersona()
{
    Persona persona;

    do
    {
        printf("Ingrese un numero de legajo (Entre 1 y 10000): ");
        scanf("%d", &persona.numeroDeLegajo);
    } while (persona.numeroDeLegajo < 1 && persona.numeroDeLegajo > 10000);

    printf("Ingrese apellido de la persona: ");
    fflush(stdin);
    fgets(persona.apellido, sizeof(persona.apellido), stdin);
    persona.apellido[strcspn(persona.apellido, "\n")] = '\0';

    printf("Ingrese nombre de la persona: ");
    fflush(stdin);
    fgets(persona.nombre, sizeof(persona.nombre), stdin);
    persona.nombre[strcspn(persona.nombre, "\n")] = '\0';

    do
    {
        printf("Ingrese altura: ");
        scanf("%f", &persona.altura);
    } while (persona.altura <= 0);

    do
    {
        printf("Ingrese sexo (M o F): ");
        fflush(stdin);
        scanf("%c", &persona.sexo);
        persona.sexo = toupper(persona.sexo);
    } while (persona.sexo != 'F' && persona.sexo != 'M');

    printf("Ingrese fecha de nacimiento\n");
    persona.fechaDeNacimiento = ingresarFechaValida();

    int codigo, i = 0;

    do
    {
        printf("Ingrese algun codigo de materia (Codigo 0 para terminar): ");
        scanf("%d", &codigo);
    } while (codigo < 0);

    while (codigo && i < CANTIDAD_MAXIMA_CODIGOS)
    {
        persona.codigoDeMateriasAprobadas[i++] = codigo;
        do
        {
            printf("Ingrese algun codigo de materia (Codigo 0 para terminar): ");
            scanf("%d", &codigo);
        } while (codigo < 0);
    }

    persona.cantidadMateriasAprobadas = i + 1;

    return persona;
}

void mostrarPersona(Persona persona)
{
    printf("Numero de legajo: %d\n", persona.numeroDeLegajo);
    printf("Apellido: %s\n", persona.apellido);
    printf("Nombre: %s\n", persona.nombre);
    printf("Altura: %.2f\n", persona.altura);
    printf("Sexo: %c\n", persona.sexo);
    printf("Fecha de nacimiento: ");
    mostrarFechaValida(persona.fechaDeNacimiento);
    printf("\n");
    printf("Codigos de materias aprobadas:\n");
    for(int i = 0; i < persona.cantidadMateriasAprobadas - 1; i++)
        printf("%d\n", persona.codigoDeMateriasAprobadas[i]);
}