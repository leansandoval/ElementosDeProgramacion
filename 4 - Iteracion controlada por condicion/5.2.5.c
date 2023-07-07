/*5.2.5 De cada uno de los alumnos de un curso se ingresa su número de DNI y las notas de los dos exámenes
parciales confeccionar, un programa que muestre por cada alumno su condición final con el siguiente
mensaje:
                “El alumno con DNI: xxxxxxx, obtuvo las notas: xx y xx [condición final]”

La condición final se establece según las siguientes reglas:

    • PROMOCIONA: ambas notas > = 7
    • RINDE EXAMEN FINAL: ambas notas > = 4
    • REPROBO LA MATERIA: alguna nota no cumple lo anterior

El programa finaliza cuando se ingresa un valor negativo como número de DNI. Al finalizar mostrar la nota
promedio de alumnos promocionados.
---------------------------------------------------------------------------------------------------------------
Resolucion: tanto el dni como las notas deberan ser validadas con un do while son sus respectivas restricciones
Para indicar si promociono, aprobo o recurso unicamente se resuelve con un par de if's y mostrando por pantalla
su condicion final. Para el caso de la promocion, se deberan acumular las notas con su respectivo contador para
luego realizar el promedio de las notas promocionadas.
*/

#include<stdio.h>

int main()
{
    int dni,bandera=0,cantidadNotasPromocionadas=0,notaPrimerParcial,notaSegundoParcial,sumaNota=0;
    do
    {
        if(bandera==1)
            printf("\nEl DNI ingresado es incorrecto\n");
        bandera=1;
        printf("\nIngrese DNI del alumno (Negativo para terminar): ");
        scanf("%d",&dni);
    }
    while(dni>=0 && (dni<=10000000 || dni>99999999));
    while(dni>0)
    {
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nLa nota que se ingreso no es valida\n");
            bandera=1;
            printf("\nIngrese nota del primer parcial: ");
            scanf("%d",&notaPrimerParcial);
        }
        while(notaPrimerParcial<=0 || notaPrimerParcial>=11);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nLa nota que se ingreso no es valida\n");
            bandera=1;
            printf("\nIngrese nota del segundo parcial: ");
            scanf("%d",&notaSegundoParcial);
        }
        while(notaSegundoParcial<=0 || notaSegundoParcial>=11);
        if(notaPrimerParcial>=7 && notaSegundoParcial>=7)
        {
            printf("\nEl alumno con DNI %d, obtuvo las notas: %d y %d (PROMOCIONA)\n",dni,notaPrimerParcial,notaSegundoParcial);
            sumaNota+=(notaPrimerParcial+notaSegundoParcial);
            cantidadNotasPromocionadas+=2;
        }
        else if(notaPrimerParcial>=4 && notaSegundoParcial>=4)
            printf("\nEl alumno con DNI %d, obtuvo las notas: %d y %d (RINDE EXAMEN FINAL)\n",dni,notaPrimerParcial,notaSegundoParcial);
        else
            printf("\nEl alumno con DNI %d, obtuvo las notas: %d y %d (REPROBO LA MATERIA)\n",dni,notaPrimerParcial,notaSegundoParcial);
        bandera=0;
        printf("\n-------------------------------------------------------------------\n");
        do
        {
            if(bandera==1)
                printf("\nEl DNI ingresado es incorrecto\n");
            bandera=1;
            printf("\nIngrese DNI del alumno (Negativo para terminar): ");
            scanf("%d",&dni);
        }
        while(dni>=0 && (dni<=10000000 || dni>99999999));
    }
    printf("\n-------------------------------------------------------------------\n");
    if(cantidadNotasPromocionadas!=0)
        printf("\nLa nota promedio de alumnos promocionados es: %.2f\n",(float)sumaNota/cantidadNotasPromocionadas);
    else
        printf("\nNo hay ningun alumno promocionado\n");
    return 0;
}
