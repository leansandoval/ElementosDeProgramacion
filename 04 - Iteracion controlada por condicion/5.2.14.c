/*5.2.14 Se ingresan datos de los empleados de una empresa. Por cada empleado se ingresa:

    • Legajo (entero entre 1000 y 5000)
    • Sueldo básico (float mayor a 1000)
    • Antigüedad en años (mayor o igual a 0)
    • Sexo (‘M' o 'F')
    • Categoría (entero entre 1 a 5)

Por cada empleado ingresado se debe calcular el sueldo final a abonar sabiendo que:

    • Las Categorías 2 y 3 tienen $500 de bonificación.
    • La Categoría 4 tiene 10% de bonificación.
    • La Categoría 5 tiene 30% de bonificación.
    • Si la antigüedad es mayor a 10 años recibe una bonificación del 10% ADICIONAL.

Todos los datos ingresados deben ser validados. El ingreso finaliza con un legajo igual a cero.
Informar:

    • El sueldo a abonar a cada empleado.
    • Cantidad de empleados de más de 10 años de antigüedad.
    • El mayor sueldo y el legajo del empleado que cobra dicho sueldo.
    • Cantidad de hombres y de mujeres.
---------------------------------------------------------------------------------------------------
Resolucion: para el ingreso de datos es necesario validarlos con do while's y para la bonificacion
de categorias y antiguedad son necesarios algunos if's para las condiciones. El sueldo de cada
empleado se lo muestra por pantalla dentro del ciclo (justo antes de que empieze el ingreso del
siguiente legajo) y la cantidad de empleados y mayor son variables acumuladoras/sumadoras que se
muestran una vez terminado el ciclo while o bien cuando se ingrese el legajo igual a cero.
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int legajo,anio,categoria,legajoMayor;
    int bandera=0,banderaMayor=0,cantidadEmpleadosAntigudadMayorA10=0,cantidadHombres=0,cantidadMujeres=0;
    float sueldo,sueldoFinal,bonificacionCategoria,bonificacionAntiguedad,sueldoMayor;
    char sexo;
    do
    {
        if(bandera==1)
            printf("\nEl numero de legajo ingresado es invalido.\n");
        bandera=1;
        printf("\nIngrese numero de legajo (entre 1000 y 5000 - 0 para terminar): ");
        scanf("%d",&legajo);
    }
    while((legajo<1000 || legajo>5000) && legajo!=0);
    while(legajo!=0)
    {
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl sueldo ingresado es invalido.\n");
            bandera=1;
            printf("\nIngrese sueldo basico (Mayor a 1000): ");
            scanf("%f",&sueldo);
        }
        while(sueldo<=1000);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nLa antiguedad ingresada no es valida.\n");
            bandera=1;
            printf("\nIngrese antiguedad (En anios - Mayor o igual a 0): ");
            scanf("%d",&anio);
        }
        while(anio<0);
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nEl sexo indicado no es valido. Ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese sexo (M para masculino, F para femenino): ");
            fflush(stdin);
            scanf("%c",&sexo);
            sexo=toupper(sexo);
        }
        while(sexo!='F' && sexo!='M');
        bandera=0;
        do
        {
            if(bandera==1)
                printf("\nLa categoria ingresada se encuentra fuera del rango.\n");
            bandera=1;
            printf("\nIngrese categoria (Entre 1 y 5): ");
            scanf("%d",&categoria);
        }
        while(categoria<1 || categoria>5);
        bandera=0;
        if(categoria==2 || categoria==3)
            bonificacionCategoria=500;
        else if(categoria==4)
            bonificacionCategoria=sueldo*0.1;
        else if(categoria==5)
            bonificacionCategoria=sueldo*0.3;
        else
            bonificacionCategoria=0;
        if(anio>10)
        {
            cantidadEmpleadosAntigudadMayorA10++;
            bonificacionAntiguedad=sueldo*0.1;
        }
        else
            bonificacionAntiguedad=0;
        sueldoFinal=sueldo+bonificacionCategoria+bonificacionAntiguedad;
        if(sexo=='F')
            cantidadMujeres++;
        else
            cantidadHombres++;
        if(banderaMayor==0 || sueldoFinal>sueldoMayor)
        {
            sueldoMayor=sueldoFinal;
            legajoMayor=legajo;
            banderaMayor=1;
        }
        printf("\nSueldo a abonar del empleado: $%.2f\n",sueldoFinal);
        do
        {
            if(bandera==1)
                printf("\nEl numero de legajo ingresado es invalido.\n");
            bandera=1;
            printf("\nIngrese numero de legajo (entre 1000 y 5000 - 0 para terminar): ");
            scanf("%d",&legajo);
        }
        while((legajo<1000 || legajo>5000) && legajo!=0);
    }
    printf("\nEl mayor sueldo es de $%.2f con legajo numero %d\n",sueldoMayor,legajoMayor);
    printf("\nCantidad de empleados de mas de 10 anios de antiguedad: %d\n",cantidadEmpleadosAntigudadMayorA10);
    printf("\nCantidad de hombres: %d\t\tCantidad de mujeres: %d\n",cantidadHombres,cantidadMujeres);
    return 0;
}
