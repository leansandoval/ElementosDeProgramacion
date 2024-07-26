/*6.9. Realizar una funcion que reciba 3 numeros enteros correspondientes al dia, mes y año de una fecha y valide
si la misma es correcta. En caso de que la fecha es correcta debe retornar un 1 y si es incorrecta debe
retornar un 0. Para la validacion usar la funcion del punto 8 que retorna la cantidad de dias de un mes.*/

#include <stdio.h>
#include <stdbool.h>

bool esFechaValida(int, int, int);
int cantidadDiasDelMes(int, int);
bool bisiesto(int);

int main()
{
    int bandera = 0, dia, mes, anio;
    do
    {
        if (bandera)
            printf("\nLa fecha ingresada es invalida, ingrese nuevamente.\n");
        bandera = 1;
        printf("\nIngrese anio: ");
        scanf("%d", &anio);
        printf("\nIngrese mes: ");
        scanf("%d", &mes);
        printf("\nIngrese dia: ");
        scanf("%d", &dia);
    } while (!esFechaValida(dia, mes, anio));
    printf("\nFecha valida: %d/%d/%d\n", dia, mes, anio);
    return 0;
}

bool esFechaValida(int dia, int mes, int anio)
{
    if (anio >= 1950 && anio <= 2100)
        if (mes >= 1 && mes <= 12)
            return dia >= 1 && dia <= cantidadDiasDelMes(mes, anio);
}

int cantidadDiasDelMes(int mes, int anio)
{
    return (mes == 4 || mes == 6 || mes == 9 || mes == 11) ? 30 : (mes == 2) ? (bisiesto(anio) ? 29 : 28)
                                                                             : 31;
}

bool bisiesto(int anio)
{
    return anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0;
}

void mostrarFechaValida(int dia, int mes, int anio)
{
    esFechaValida(dia, mes, anio) ? printf("%02d/%02d/%04d", dia, mes, anio) : printf("La fecha no es válida.");
}

/*6.10. Realizar una función que permita sumar 1 día a una fecha válida mostrando la fecha resultante. Si la fecha
recibida no es válida informarlo con un mensaje (validar utilizando la función del punto 9)*/

void sumarUnDia(int dia, int mes, int anio)
{
    if (esFechaValida(dia, mes, anio))
    {
        dia++;
        if (dia > cantidadDiasDelMes(mes, anio))
        {
            dia = 1;
            mes++;
            if (mes > 12)
            {
                mes = 1;
                anio++;
            }
        }
        printf("Fecha resultante: ");
        mostrarFechaValida(dia, mes, anio);
    }
    else
        printf("La fecha no es válida.");
}

/*6.11. Realizar una función que permita sumar n días a una fecha válida mostrando la fecha resultante. Si la fecha
recibida no es válida informarlo con un mensaje (validar utilizando la función del punto 9).*/

void sumarNDias(int dia, int mes, int anio, int diasASumar) 
{
    if (esFechaValida(dia, mes, anio))
    {
        while (diasASumar)
        {
            int cantidadDias = cantidadDiasDelMes(mes, anio);
            dia++;
            if (dia > cantidadDias)
            {
                dia = 1;
                mes++;
                if (mes > 12)
                {
                    mes = 1;
                    anio++;
                }
            }
            diasASumar--;
        }

        printf("Fecha resultante: ");
        mostrarFechaValida(dia, mes, anio);
    }
    else
        printf("La fecha no es válida.");
}