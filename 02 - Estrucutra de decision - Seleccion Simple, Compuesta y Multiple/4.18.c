/*4.18. Confeccionar un programa que permita ingresar la fecha actual (día, mes y año) y la fecha de nacimiento
de una persona (día, mes y año). Con ambos datos debe calcular la edad de dicha persona.
---------------------------------------------------------------------------------------------------------------
Resolucion: tanto la fecha actual como la fecha de nacimiento (ddmmaaaa) son de tipo int. Para calcular la edad
se debera restar la fecha actual con la fecha de nacimiento, teniendo en cuenta algunas cosas.
Ejemplo:
Se ingresa como fecha de nacimiento 22 de Octubre de 1998 --> 22101998 y como fecha actual 16 de Marzo de 2021
--> 16032021. Luego aplicamos las siguientes operaciones matematicas:
22101998 % 10000 --> Realizamos esta operacion para quedarnos unicamente con el año/resto (1998). Idem la fecha
actual (2021).
2021 - 1998 = 23. Esto es un error ya que todavia no cumple anios. A la fecha actual son 22 anios cumplidos. Por
lo que restamos 1 --> 2021 - 1998 - 1 = 22.
Ahora hay que arreglar este error por si ya se cumplio los anios.
22101998 / 10000 --> Realizamos esta operacion para quedarnos con el dia y el mes (2210). Para tener unicamente
el mes (resto) aplicamos % 100. ---> (22101998/10000)%100 = 10 (Octubre).
Idem la fecha actual = 03 (Marzo). Si el mes de la fecha actual es > al mes de nacimiento, la edad se incrementa.
Si es menor, la edad queda como estaba.
Ahora vamos al caso en el que los meses sean iguales; y ahi vamos a tener en cuenta los dias.
22101998 / 1000000 --> Realizamos esta operacion para quedarnos con el dia (22). Idem para la fecha actual (16)
Si el dia de la fecha actual es >= al dia de la fecha de nacimiento, la edad se incrementa. Caso contrario, queda
como estaba.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    int fecha_nacimiento,fecha_actual,edad;
    printf("\nIngrese su fecha de nacimiento en formado dd/mm/aaaa: ");
    scanf("%d",&fecha_nacimiento);
    printf("\nIngrese la fecha actual: ");
    scanf("%d",&fecha_actual);
    edad=fecha_actual%10000-fecha_nacimiento%10000-1;
    if((fecha_actual/10000)%100>(fecha_nacimiento/10000)%100) //Mes
        edad++;
    else
        if((fecha_actual/10000)%100==(fecha_nacimiento/10000)%100) //Meses iguales
            if(fecha_actual/1000000>=fecha_nacimiento/1000000) //Dias
                edad++;
    printf("\nSu edad es de %d anios\n",edad);
    getch();
    return 0;
}
