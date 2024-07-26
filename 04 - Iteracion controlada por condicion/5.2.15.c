/*5.2.15 El gobierno de la Ciudad de Buenos Aires realiza una encuesta a los estudiantes de los colegios
secundarios. Los primeros datos a ingresar son la fecha (día, mes y año) y la cantidad de colegios de la ciudad
en que se realizó la encuesta.

De cada colegio se conoce: número de escuela, la cantidad de alumnos inscriptos y la especialidad (‘T’:
técnico, ‘N’: no técnico).

De cada alumno del colegio que respondió la encuesta se conoce: DNI, fecha de nacimiento (día, mes y
año), sexo (‘M’ o ‘F’) y opinión con respecto a los conocimientos adquiridos (‘B’: buenos, ‘M’: malos). Se
identifica el fin de ingreso de datos de los alumnos que respondieron la encuesta por cada colegio con
ingreso 0 en el DNI del estudiante.
Validar todos los datos que se ingresan por teclado.

Informar:
    a. Por cada colegio, el porcentaje de alumnos que contestaron la encuesta sobre la cantidad de
    alumnos inscriptos del colegio.
    b. Cantidad de estudiantes de colegios no técnicos que respondieron la encuesta.
    c. Porcentaje de mujeres de escuelas técnicas sobre la cantidad de estudiantes que respondieron la encuesta.
    d. Porcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos,
    sobre el total de encuestados.
    e. Mayor edad de los estudiantes encuestados.
    f. Número del colegio con mayor opinión buena sobre los conocimientos adquiridos.*/

#include <stdio.h>
#include <ctype.h>

int main()
{

    // Variables para la fecha de ingreso
    int anio,mes,dia,bandera=0;
    // Cantidad de colegios que se realizo la encuesta
    int cantidadColegios,i;
    // Informacion de cada colegio
    int numeroEscuela,alumnosInscriptos;
    char especialidad;
    //Informacion de los alumnos que respondieron (encuestados) la encuesta
    int diaNacimiento,mesNacimiento,anioNacimiento,dni,alumnosEncuestados=0;
    char sexo,opinion;
    // Item b)
    int alumnosColegiosNoTecnicos=0;
    // Item c)
    int mujeresColegiosTecnicos=0,sumaAlumnosEncuestados=0;
    // Item d)
    int alumnosConocimientosMalos=0;
    // Item e)
    int edad,edadMayor;
    // Item f)
    int sumaAlumnosConocimientosBuenos=0,alumnosConocimientosBuenos=0,mayorCantidadAlumnosConocimientosBuenos,mayorNumeroEscuela;

    /******************************************** Fecha ********************************************/
    printf("\n------- Ingrese el dia de hoy -------\n");
    // Anio
    do
    {
        if(bandera==1)
            printf("\nEl anio ingresado es invalido.\n");
        bandera=1;
        printf("\nIngrese anio: ");
        scanf("%d",&anio);
    }
    while(anio<0);
    bandera=0;

    //Mes - Dia
    do
    {
        if(bandera==1)
            printf("\nEl mes ingresado es invalido.\n");
        bandera=1;
        printf("\nIngrese mes: ");
        scanf("%d",&mes);
    }
    while(mes<1 || mes>12);
    bandera=0;
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
        do
        {
            if(bandera==1)
                printf("\nEl dia ingresado es incorrecto. Ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese dia: ");
            scanf("%d",&dia);
        }
        while(!(dia>=1 && dia<=31));
    else if(mes!=2)
        do
        {
            if(bandera==1)
                printf("\nEl dia ingresado es incorrecto. Ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese dia: ");
            scanf("%d",&dia);
        }
        while(!(dia>=1 && dia<=30));
    else if (anio%4==0 && anio%100!=0 || anio%400==0)
        do
        {
            if(bandera==1)
                printf("\nEl dia ingresado es incorrecto. Ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese dia: ");
            scanf("%d",&dia);
        }
        while(!(dia>=1 && dia<=29));
    else
        do
        {
            if(bandera==1)
                printf("\nEl dia ingresado es incorrecto. Ingrese nuevamente.\n");
            bandera=1;
            printf("\nIngrese dia: ");
            scanf("%d",&dia);
        }
        while(!(dia>=1 && dia<=28));
    bandera=0;
    /***********************************************************************************************/

    /************************************* Cantidad de colegios *************************************/
    printf("\n------- Colegios encuestados -------\n");
    do
    {
        if(bandera==1)
            printf("\nLa cantidad ingresada es invalida. Ingrese nuevamente.\n");
        bandera=1;
        printf("\nCantidad de colegios encuestados: ");
        scanf("%d",&cantidadColegios);
    }
    while(cantidadColegios<=0);
    /***********************************************************************************************/

    for(i=1; i<=cantidadColegios; i++)
    {
        bandera=0;
        /****************************************** Colegio ******************************************/

        printf("\n------- Informacion del colegio -------\n");
        // Numero de escuela
        do
        {
            if(bandera==1)
                printf("\nEl numero de colegio es invalido. Ingrese nuevamente.\n");
            bandera=1;
            printf("\nNumero de colegio: ");
            scanf("%d",&numeroEscuela);
        }
        while(numeroEscuela<0);
        bandera=0;

        // Alumnos inscriptos
        do
        {
            if(bandera==1)
                printf("\nLa cantidad ingresada es invalida. Ingrese nuevamente.\n");
            bandera=1;
            printf("\nCantidad de alumnos inscriptos: ");
            scanf("%d",&alumnosInscriptos);
        }
        while(alumnosInscriptos<0);
        bandera=0;

        // Especialidad
        do
        {
            if(bandera==1)
                printf("\nLa especialidad ingresada no es valida. Ingrese nuevamente.\n");
            bandera=1;
            printf("\nEspecialidad ('T' si es Tecnica  o 'N' no tecnico): ");
            fflush(stdin);
            scanf("%c",&especialidad);
            especialidad=toupper(especialidad);
        }
        while(especialidad!='T' && especialidad!='N');
        /***********************************************************************************************/

        /****************************** Alumno que respondio la encuesta ******************************/
        bandera=0;
        printf("\n----- Alumnos que respondieron la encuesta -----\n");
        do
        {
            if(bandera==1)
                printf("\nEl dni ingresado no se encuentra dentro del rango. Ingrese nuevamente.\n");
            bandera=1;
            printf("\nDNI del alumno (0 para terminar): ");
            scanf("%d",&dni);
        }
        while((dni<10000000 || dni>99999999) && dni!=0);

        while(dni!=0 && alumnosEncuestados<alumnosInscriptos)
        {
            bandera=0;
            alumnosEncuestados++;
            // Sexo
            do
            {
                if(bandera==1)
                    printf("\nCaracter invalido.\n");
                bandera=1;
                printf("\nIngrese sexo del alumno (F para femenino, M para masculino): ");
                fflush(stdin);
                scanf("%c",&sexo);
                sexo=toupper(sexo);
            }
            while(sexo!='F' && sexo!='M');

            // Fecha de nacimiento
            bandera=0;
            printf("\nIngrese fecha de nacimiento\n");
            do
            {
                if(bandera==1)
                    printf("\nEl anio ingresado es invalido.\n");
                bandera=1;
                printf("\nIngrese anio: ");
                scanf("%d",&anioNacimiento);
            }
            while(anioNacimiento<0);
            bandera=0;
            do
            {
                if(bandera==1)
                    printf("\nEl mes ingresado es invalido.\n");
                bandera=1;
                printf("\nIngrese mes: ");
                scanf("%d",&mesNacimiento);
            }
            while(mesNacimiento<1 || mesNacimiento>12);
            bandera=0;
            if(mesNacimiento==1 || mesNacimiento==3 || mesNacimiento==5 || mesNacimiento==7 || mesNacimiento==8 || mesNacimiento==10 || mesNacimiento==12)
                do
                {
                    if(bandera==1)
                        printf("\nEl dia ingresado es incorrecto. Ingrese nuevamente.\n");
                    bandera=1;
                    printf("\nIngrese dia: ");
                    scanf("%d",&diaNacimiento);
                }
                while(diaNacimiento<1 || diaNacimiento>31);
            else if(mesNacimiento!=2)
                do
                {
                    if(bandera==1)
                        printf("\nEl dia ingresado es incorrecto. Ingrese nuevamente.\n");
                    bandera=1;
                    printf("\nIngrese dia: ");
                    scanf("%d",&diaNacimiento);
                }
                while(diaNacimiento<1 || diaNacimiento>30);
            else if (anioNacimiento%4==0 && anioNacimiento%100!=0 || anioNacimiento%400==0)
                do
                {
                    if(bandera==1)
                        printf("\nEl dia ingresado es incorrecto. Ingrese nuevamente.\n");
                    bandera=1;
                    printf("\nIngrese dia: ");
                    scanf("%d",&diaNacimiento);
                }
                while(diaNacimiento<1 || diaNacimiento>29);
            else
                do
                {
                    if(bandera==1)
                        printf("\nEl dia ingresado es incorrecto. Ingrese nuevamente.\n");
                    bandera=1;
                    printf("\nIngrese dia: ");
                    scanf("%d",&diaNacimiento);
                }
                while(diaNacimiento<1 || diaNacimiento>28);
            bandera=0;

            // Conocimientos adquiridos
            do
            {
                printf("\nOpinion acerca de los conocimientos adquiridos ('B' buenos, 'M' malos): ");
                fflush(stdin);
                scanf("%c",&opinion);
                opinion=toupper(opinion);
            }
            while(opinion!='B' && opinion!='M');
            bandera=0;
            edad=anio-anioNacimiento;
            if(mes-mesNacimiento<0)
                edad--;
            else if(dia-diaNacimiento<0)
                edad--;
            if(alumnosEncuestados==1 || edad>edadMayor)
                edadMayor=edad;
            if(especialidad=='N' && alumnosEncuestados>=1)
                alumnosColegiosNoTecnicos++;
            if(opinion=='M')
                alumnosConocimientosMalos++;
            else
                alumnosConocimientosBuenos++;
            if(sexo='F' && especialidad=='T')
                mujeresColegiosTecnicos++;
            printf("\n----- Alumnos que respondieron la encuesta -----\n");
            // DNI
            do
            {
                if(bandera==1)
                    printf("\nEl dni ingresado no se encuentra dentro del rango. Ingrese nuevamente.\n");
                bandera=1;
                printf("\nDNI del alumno (0 para terminar): ");
                scanf("%d",&dni);
            }
            while((dni<10000000 || dni>99999999) && dni!=0);
        }
        printf("\nPorcentaje de alumnos que contestaron la encuesta sobre la cantidad de alumnos inscriptos del colegio: %.2f\n",(float)alumnosEncuestados/alumnosInscriptos);
        sumaAlumnosEncuestados+=alumnosEncuestados; // Necesario para el item c)
        alumnosEncuestados=0;   //Se viene el ingreso de otro colegio
        sumaAlumnosConocimientosBuenos+=alumnosConocimientosBuenos;
        if(i==1 || sumaAlumnosConocimientosBuenos>mayorCantidadAlumnosConocimientosBuenos)
        {
            mayorCantidadAlumnosConocimientosBuenos=sumaAlumnosConocimientosBuenos;
            mayorNumeroEscuela=numeroEscuela;
        }
        alumnosConocimientosBuenos=0;
    }
    printf("\n------------------------------------------------------------------------------------------------------\n");
    printf("\nCantidad de estudiantes de colegio no tecnicos que respondieron la encuesta: %d\n",alumnosColegiosNoTecnicos);
    printf("\nPorcentaje de mujeres de escuelas tecnicas sobre la cantidad de estudiantes que respondieron la encuesta: %2.f\n",((float)mujeresColegiosTecnicos/sumaAlumnosEncuestados)*100);
    printf("\nPorcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos, sobre el total de encuestados: %.2f\n",((float)alumnosConocimientosMalos/sumaAlumnosEncuestados)*100);
    printf("\nMayor edad de los estudiantes encuestados: %d\n",edadMayor);
    printf("\nNumero del colegio con mayor opinion buena sobre los conocimientos adquiridos: %d\n",mayorNumeroEscuela);
    return 0;
}
