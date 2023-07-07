#include <stdio.h>
#include <windows.h>
#include <ctype.h>

enum Categoria {
    AGENTE = 'A',
    TEAM_LEADER = 'T',
    SUPERVISOR = 'S',
    CALIDAD = 'C'
};

enum Campania {
    VENTAS = 'V',
    ATENCION_AL_CLIENTE = 'A'
};

#define PORCENTAJE_TEAM_LEADER 5.0
#define PORCENTAJE_SUPERVISOR 10.0
#define PORCENTAJE_CALIDAD 12.0

#define PORCENTAJE_VENTAS 10.0
#define PORCENTAJE_ATENCION_AL_CLIENTE 2.0

int bienvenida()
{
    int numeroAgente;
    printf("\nPERSONAL DE LA EMPRESA YA-MAR (LIQUIDACION DE SUELDOS Y COMISIONES)\n");
    do
    {
        printf("\nIngrese NUMERO DE AGENTE (entre 1 y 100) - 0 para terminar - : ");
        scanf("%d", &numeroAgente);
    } while (numeroAgente < 0 || numeroAgente > 100);
    return numeroAgente;
}

char ingresarCategoriaValida()
{
    char categoria;
    do
    {
        printf("\nIngrese categoria ('A' - Agente, 'T' - Team Leader, 'S' - Supervisor, 'C' - Calidad): ");
        fflush(stdin);
        scanf("%c", &categoria);
        categoria = toupper(categoria);
    } while (categoria != AGENTE && categoria != TEAM_LEADER && categoria != SUPERVISOR && categoria != CALIDAD);
    return categoria;
}

int ingresarAntiguedadValida()
{
    int antiguedad;
    do
    {
        printf("\nIngrese antiguedad (entre 1 y 10 anios): ");
        scanf("%d", &antiguedad);
    } while (antiguedad < 1 || antiguedad > 10);
    return antiguedad;
}

char ingresarCampaniaValida()
{
    char campania;
    do
    {
        printf("\nIngrese campania ('V' - Ventas, 'A' - Atencion al cliente): ");
        fflush(stdin);
        scanf(" %c", &campania);
        campania = toupper(campania);
    } while (campania != VENTAS && campania != ATENCION_AL_CLIENTE);
    return campania;
}

float ingresarSueldoValido()
{
    float sueldo;
    do
    {
        printf("\nIngrese sueldo basico (entre 15000 y 45000): ");
        scanf("%f", &sueldo);
    } while (sueldo < 15000 || sueldo > 45000);
    return sueldo;
}

float asignarSueldoAdicionalPorCategoria(char categoria, float sueldo)
{
    float adicionalCategoria;
    // CONDICION 1)
    switch (categoria)
    {
    case AGENTE:
        adicionalCategoria = (float)sueldo * 0;
        break;
    case TEAM_LEADER:
        adicionalCategoria = (float)sueldo * PORCENTAJE_TEAM_LEADER / 100;
        break;
    case SUPERVISOR:
        adicionalCategoria = (float)sueldo * PORCENTAJE_SUPERVISOR / 100;
        break;
    case CALIDAD:
        adicionalCategoria = (float)sueldo * PORCENTAJE_CALIDAD / 100;
        break;
    }
    return adicionalCategoria;
}

float asignarAdicionalPorAntiguedad(char antiguedad, float sueldo, float adicionalCategoria)
{
    // CONDICION 2)
    float adicionalAntiguedad = antiguedad <= 5 ? (adicionalCategoria + sueldo) * ((float)antiguedad / 100) : antiguedad < 10 ? (adicionalCategoria + sueldo) * 0.08
                                                                                                                              : (adicionalCategoria + sueldo) * 0.11;
    return adicionalAntiguedad;
}

float asignarAdicionalPorCampania(char campania, float sueldo)
{
    // CONDICION 3)
    return campania == VENTAS ? sueldo * PORCENTAJE_VENTAS / 100 : sueldo * PORCENTAJE_ATENCION_AL_CLIENTE / 100;
}

void mostrarAgente(int numeroAgente, char categoria, float adicionalCategoria, int antiguedad, float adicionalAntiguedad, char campania, float adicionalCampania, float sueldoFinal)
{
    printf("\nAGENTE NUMERO %d\n", numeroAgente);
    printf("\nAdicional segun su categoria (%c): $ %2.f\n", categoria, adicionalCategoria);
    printf("\nAdicional segun su antiguedad (%d anios): $ %.2f\n", antiguedad, adicionalAntiguedad);
    printf("\nComisiones segun su campania (%c): $ %.2f\n", campania, adicionalCampania);
    printf("\nSu sueldo final es de $ %.2f\n", sueldoFinal);
}

void pausarYLimpiarConsola()
{
    printf("\n");
    system("pause");
    system("cls");
}

void mostrarResultados(float maximoSueldo, int maximoAgente, float minimoSueldo, int minimoAgente, float totalSueldos, float totalSueldoCategoriaTeamLeader, float totalAdicionalAntiguedadMenorA5, float totalComisionVentas, float totalAdicionalCampania, int cantidadAgentesAntiguedadCategoriaNoAgente, float totalAntiguedadCategoriaNoAgente)
{
    printf("\n1) El salario mas alto a pagar es $ %.2f y corresponde al agente numero %d\n", maximoSueldo, maximoAgente);
    printf("\n2) El salario minimo a pagar es $ %.2f y corresponde al agente numero %d\n", minimoSueldo, minimoAgente);
    printf("\n3) Total general de salarios a pagar : $ %.2f\n", totalSueldos);
    printf("\n4) Total de salarios a pagar de la categoria Team Leader: $ %.2f\n", totalSueldoCategoriaTeamLeader);
    printf("\n5) Importe total a pagar por antiguedad en los agentes de 1 a 5 anios: $ %.2f\n", totalAdicionalAntiguedadMenorA5);
    printf("\n6) Total de comisiones a pagar por campania de ventas: $ %.2f\n", totalComisionVentas);
    printf("\n7) Total general de comisiones a pagar: $ %.2f\n", totalAdicionalCampania);
    printf("\n8) %s\n", (cantidadAgentesAntiguedadCategoriaNoAgente > 0) ? "Promedio de antiguedad del personal que no sea Agente: %.2f\n" : "Los personales ingresados corresponden a la categoria Agente",
           (float)totalAntiguedadCategoriaNoAgente / cantidadAgentesAntiguedadCategoriaNoAgente);
    printf("\n9) Porcentaje respecto del total de salarios que cobran los agentes de categoria Team Leader: %.2f\n", (totalSueldoCategoriaTeamLeader / totalSueldos) * 100);
}

int main()
{
    char categoria, campania;
    int minimoAgente, maximoAgente, antiguedad;
    float sueldo, sueldoFinal, maximoSueldo, minimoSueldo, adicionalCategoria, adicionalAntiguedad, adicionalCampania;

    int cantidadDeAgentes = 0, totalAntiguedadCategoriaNoAgente = 0, cantidadAgentesAntiguedadCategoriaNoAgente = 0;
    float totalSueldos = 0, totalComisionVentas = 0, totalAdicionalCampania = 0, totalSueldoCategoriaTeamLeader = 0, totalAdicionalAntiguedadMenorA5 = 0;

    int numeroAgente = bienvenida();

    while (numeroAgente)
    {
        categoria = ingresarCategoriaValida();
        antiguedad = ingresarAntiguedadValida();
        campania = ingresarCampaniaValida();
        sueldo = ingresarSueldoValido();

        adicionalCategoria = asignarSueldoAdicionalPorCategoria(categoria, sueldo);
        adicionalAntiguedad = asignarAdicionalPorAntiguedad(antiguedad, sueldo, adicionalCategoria);
        adicionalCampania = asignarAdicionalPorCampania(campania, sueldo);

        if (antiguedad <= 5)
            totalAdicionalAntiguedadMenorA5 += adicionalAntiguedad; // PUNTO 5)

        if (campania == VENTAS)
            totalComisionVentas += adicionalCampania; // PUNTO 6)

        sueldoFinal = sueldo + adicionalCategoria + adicionalAntiguedad + adicionalCampania;

        totalSueldos += sueldoFinal; // PUNTO 3) y 9)

        totalAdicionalCampania += adicionalCampania; // PUNTO 7)

        if (categoria == TEAM_LEADER)
            totalSueldoCategoriaTeamLeader += sueldoFinal; // PUNTO 4) y 9)

        if (categoria != AGENTE) // PUNTO 8)
        {
            totalAntiguedadCategoriaNoAgente += antiguedad;
            cantidadAgentesAntiguedadCategoriaNoAgente++;
        }

        cantidadDeAgentes++; // VARIABLE TIPO BANDERA (TANTO PARA EL MAXIMO Y MINIMO COMO PARA SABER SI HAY AL MENOS 1 AGENTE INGRESADO)

        if (cantidadDeAgentes == 1) // SE USA LA PRIMERA VEZ QUE SE INGRESA EL PRIMER DATO PARA COMPARAR LAS VARIABLES
        {
            maximoSueldo = sueldoFinal;
            maximoAgente = numeroAgente;
            minimoSueldo = sueldoFinal;
            minimoAgente = numeroAgente;
        }

        if (sueldoFinal > maximoSueldo) // PUNTO 1)
        {
            maximoSueldo = sueldoFinal;
            maximoAgente = numeroAgente;
        }
        else if (sueldoFinal < minimoSueldo) // PUNTO 2)
        {
            minimoSueldo = sueldoFinal;
            minimoAgente = numeroAgente;
        }

        pausarYLimpiarConsola();
        mostrarAgente(numeroAgente, categoria, adicionalCategoria, antiguedad, adicionalAntiguedad, campania, adicionalCampania, sueldoFinal);
        pausarYLimpiarConsola();
        numeroAgente = bienvenida();
    }

    system("cls");

    if (cantidadDeAgentes)
        mostrarResultados(maximoSueldo, maximoAgente, minimoSueldo, minimoAgente, totalSueldos, totalSueldoCategoriaTeamLeader, totalAdicionalAntiguedadMenorA5, totalComisionVentas, totalAdicionalCampania, cantidadAgentesAntiguedadCategoriaNoAgente, totalAntiguedadCategoriaNoAgente);
    else
        printf("\nNo hay personal\n");

    pausarYLimpiarConsola();
    return 0;
}
