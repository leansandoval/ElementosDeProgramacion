/*5.1.16 Se ingresan DNI y la nota promedio de 10 alumnos. Determinar el DNI del alumno de mayor nota
promedio (considerar único).
------------------------------------------------------------------------------------------------------
Resolucion: este ejercicio pide un maximo, se puede realizar de 3 formas (estan explicadas abajo)
*/

#include<stdio.h>

int main()
{
    int i,dni,documento,bandera=0;
    float notaPromedio,maximaNota;
    /* a) Leer el primero afuera de ciclo y lo almacenamos en la variable mayor.
    printf("\nIngrese DNI del alumno: ");
    scanf("%d",&dni);
    printf("\nIngrese nota promedio del alumno correspondiente: ");
    scanf("%f",&notaPromedio);
    maximaNota=notaPromedio;
    for(i=1; i<=9; i++)
    {
        printf("\nIngrese DNI del alumno: ");
        scanf("%d",&dni);
        printf("\nIngrese nota promedio del alumno correspondiente: ");
        scanf("%f",&notaPromedio);
        if(maximaNota<notaPromedio)
        {
            maximaNota=notaPromedio;
            documento=dni;
        }
    }*/

    /*b) Una pregunta para separar el primero del resto, para darle valor inicial a la variable mayor.
    for(i=1; i<=10; i++)
    {
        printf("\nIngrese DNI del alumno: ");
        scanf("%d",&dni);
        printf("\nIngrese nota promedio del alumno correspondiente: ");
        scanf("%f",&notaPromedio);
        if(i==1 || notaPromedio>maximaNota)
        {
            maximaNota=notaPromedio;
            documento=dni;
        }
    }
    En este ejemplo se realiza un solo if con dos condiciones, se pregunta si es la primera vez que
    se ingresa al ciclo, condición que se da cuando i vale 1. Luego esa condición será siempre falsa
    y por lo tanto se evalúa si el número recién ingresado es más grande que el guardado en la
    variable mayor. Sin embargo, la primera vez que se ingresa la variable mayor aún no tiene valor
    asignado, pero como el lenguaje C no necesita evaluar todas las condiciones, la primera vez que
    se ingresa al ciclo la primera condición es verdadera y al ser un or con una condición que sea
    verdadera es suficiente y por lo tanto no se evalúa la segunda condición.
    */

    /*c) Una pregunta para separar el primero del resto, para darle valor inicial a la variable mayor,
    utilizando una señal.

    Una bandera o señal cumple con la función de tener el conocimiento de que un evento haya
    sucedido o no, es una variable a la cual se le asigna solo dos valores, uno se le asigna al inicio del
    proceso y el otro, al suceder el evento buscado.
    */
    for(i=1; i<=10; i++)
    {
        printf("\nIngrese DNI del alumno: ");
        scanf("%d",&dni);
        printf("\nIngrese nota promedio del alumno correspondiente: ");
        scanf("%f",&notaPromedio);
        if(bandera==0 || notaPromedio>maximaNota)
        {
            maximaNota=notaPromedio;
            documento=dni;
            bandera=1;
        }
    }
    printf("\nEl alumno con DNI %d obtuvo la mayor nota promedio de %.2f\n",documento,maximaNota);
    return 0;
}
