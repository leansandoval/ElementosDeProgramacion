/*5.2.9 Se desea realizar un programa para calcular el sueldo final a pagar a cada empleado de una empresa. De
cada uno se tiene, sueldo básico, antigüedad, cantidad de hijos y estudios superiores (‘S’ o ‘N’). Además, se
conocen los porcentajes de aumento del sueldo que dependen de los siguientes factores:

    • Si el empleado tiene más de 10 años de antigüedad: aumento del 10%
    • Si el empleado tiene más de 2 hijos: aumento del 10%, si solo tiene uno 5%
    • Si el empleado posee estudios superiores: aumento del 5%

Luego de ingresar los datos de un empleado se debe preguntar si se desea ingresar otro empleado o no. Se
termina la carga cuando no se deseen ingresar más empleados.
Determinar:

    a. Por cada empleado: número de empleado, el sueldo básico y el nuevo sueldo.
    b. Sueldo nuevo promedio de la empresa.
---------------------------------------------------------------------------------------------------------------
Resolucion: validacion para el ingreso datos con do while's y condiciones de if para saber que aumento posee.
Despues del ingreso de datos para el nuevo empleado, se debera guardar el numero sueldo en una variable sumadora
junto con un contador para luego sacar el sueldo promedio de la empresa.*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int numeroEmpleado,antiguedad,cantidadHijos,cantidadSueldos=0,bandera=0;
    float sueldo,nuevoSueldo,sumaSueldo=0;
    char pregunta;
    do
    {
        if(bandera==1)
            printf("\nDato invalido\n");
        bandera=1;
        printf("\nDesea agregar un empleado? (S en caso afirmativo N en caso negativo): ");
        fflush(stdin);
        scanf("%c",&pregunta);
        pregunta=toupper(pregunta);
    }
    while(pregunta!='S' && pregunta!='N');
    while(pregunta!='N')
    {
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl numero de empleado es invalido, ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese el numero de empleado: ");
            scanf("%d",&numeroEmpleado);
        }
        while(numeroEmpleado<=0);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nLa cantidad ingresada es invalida, ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese sueldo basico correspondiente: ");
            scanf("%f",&sueldo);
        }
        while(sueldo<=0);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nLa antiguedad ingresada es invalida, ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese antiguedad del empleado (en anios): ");
            scanf("%d",&antiguedad);
        }
        while(antiguedad<=0);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nLa cantidad ingresada es invalida, ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese cantidad de hijos: ");
            scanf("%d",&cantidadHijos);
        }
        while(cantidadHijos<=0);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nDato invalido\n");
            bandera=1;
            printf("\nPosee estudios superiores? (S en caso afirmativo N en caso negativo): ");
            fflush(stdin);
            scanf("%c",&pregunta);
            pregunta=toupper(pregunta);
        }
        while(pregunta!='S' && pregunta!='N');
        bandera=0;
        if(antiguedad>10 || cantidadHijos>2)
            nuevoSueldo=sueldo+(sueldo*0.1);
        else if(cantidadHijos==1 || pregunta=='S')
            nuevoSueldo=sueldo+(sueldo*0.05);
        else
            nuevoSueldo=sueldo;
        printf("\n---------------------------------------------------------------------------------------\n");
        printf("\nNumero de empleado: %d\t\tSueldo basico: $%.2f\t\tNuevo sueldo: $%.2f\n",numeroEmpleado,sueldo,nuevoSueldo);
        sumaSueldo+=nuevoSueldo;
        cantidadSueldos++;
        printf("\n---------------------------------------------------------------------------------------\n");
        do
        {
            if(bandera==1)
                printf("\nDato invalido\n");
            bandera=1;
            printf("\nDesea agregar otro empleado? (S en caso afirmativo N en caso negativo): ");
            fflush(stdin);
            scanf("%c",&pregunta);
            pregunta=toupper(pregunta);
        }
        while(pregunta!='S' && pregunta!='N');
    }
    if(cantidadSueldos!=0)
        printf("\nEl sueldo nuevo promedio de la empresa es de: $%.2f\n",(float)sumaSueldo/cantidadSueldos);
    else
        printf("\nNo hubo empleados\n");
    return 0;
}
