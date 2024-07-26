/*6.3. Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número que lo identifica y el
resultado de los disparos efectuados. El ingreso finaliza con un número de participante negativo.
Cada participante efectúa 5 disparos, registrándose las coordenadas X-Y de cada disparo.

    • No considere disparos sobre los ejes, pero sí en el centro (si es sobre los ejes las coordenadas
    deberán volver a ingresarse).
    • Para determinar el cuadrante utilizar la función CUADRANTE que reciba las dos coordenadas y
    retorne el cuadrante al cual pertenece (1 a 4) y 0 para indicar un tiro en el centro.

Para calcular el puntaje utilizar la función PUNTAJE que reciba 5 parámetros que representan la cantidad
disparos en cada eje y en el centro. La función debe retornar el puntaje obtenido según la siguiente escala:

    * Cuadrantes 1 y 2: 50 puntos
    * Cuadrantes 3 y 4: 40 puntos
    * Centro: 100 puntos

Determinar:

    a. El puntaje obtenido por cada participante, detallando cuantos disparos realizó en cada cuadrante.
    b. Mostrar el número del participante ganador y el puntaje obtenido.
    c. Calcular y mostrar la cantidad total de disparos en el centro (de todos los participantes)
------------------------------------------------------------------------------------------------------------------
Resolucion: se declara una variable int para el numero de participante y otra para los puntos que acumulo. Como
condicion de fin, en el ciclo while ponemos lo pedido, finaliza cuando se ingrese un numero negativo. Como dice
que cada participante efectua 5 disparos, realizo un ciclo for que vaya hasta esa cantidad. Se registra las
coordenadas X-Y por cada disparo asi que en cada ciclo for se pedira el ingreso de los valores de tipo int x e y.
Como no se debe considerar disparos sobre los ejes (0,Y) o (X,0). Esta condicion sera en un do while cuando se
pida el ingreso de datos.
Utilizo la funcion Cuadrante para saber a que cuadrante fue el disparo, retornandome un int que corresponde al
numero de cuadrante.
Y para el puntaje, con la funcion Puntaje que me retorne los puntos totales de cada participante. Para ello,
utilizo acumuladores para todos los cuadrantes y el centro que se reciben como paramentros y luego los muestro
(item a). Hay que aclarar que para el proximo ingreso todas estas variables deberan estar en 0 nuevamente.
Declaro variables tanto para los puntos del ganador como para su numero (item b), en el primer ingreso, al ser un solo
participante, sera ese mismo el participante ganador. Por lo que sus datos se van a guardar en esas variables. Luego,
en los proximos ingresos, se compara son el participante anterior si lo supera en puntos obtenidos.
Antes de volver a ingresar un numero participante, se deberan conservar la cantidad de disparos en el centro (item c)
para esto declaro una variable que acumule y sume el contador de disparos en el centro y lo guarde en esta variable.
*/

#include<stdio.h>
#include<windows.h>

int Cuadrante (int,int);
int Puntaje(int,int,int,int,int);


int main()
{
    int participante,i,numeroCuadrante,x,y,puntos,puntosPorParticipante=0;
    int cantidadPrimerCuadrante=0,cantidadSegundoCuadrante=0,cantidadTercerCuadrante=0,cantidadCuartoCuadrante=0,cantidadCentro=0;
    int bandera=0,puntosGanador=0,participanteGanador,totalCantidadCentro=0;
    printf("\nIngrese numero de participante (negativo para terminar): ");
    scanf("%d",&participante);
    while(participante>=0)          //Condicion de fin pedida en el enunciado
    {
        for(i=1; i<=5; i++)         //5 disparos por cada participante
        {
            do
            {
                printf("\nDisparo numero %d\n",i);
                printf("\nCoordenadas X: ");
                scanf("%d",&x);
                printf("\nCoordenadas Y: ");
                scanf("%d",&y);
            }
            while(x==0 && y!=0 || x!=0 && y==0);    //Omision de disparos sobre los ejes de coordenadas
            numeroCuadrante=Cuadrante(x,y);         //Retorna el numero de cuadrante
            switch(numeroCuadrante)
            {
            case 0:
                cantidadCentro++;
                break;                              //Cuantos disparos realizo en cada cuadrante
            case 1:
                cantidadPrimerCuadrante++;          //Item a
                break;
            case 2:
                cantidadSegundoCuadrante++;
                break;
            case 3:
                cantidadTercerCuadrante++;
                break;
            case 4:
                cantidadCuartoCuadrante++;
                break;
            }
        }

        puntosPorParticipante=Puntaje(cantidadPrimerCuadrante,cantidadSegundoCuadrante,cantidadTercerCuadrante,cantidadCuartoCuadrante,cantidadCentro);

        if(puntosGanador<puntosPorParticipante)     //Inicialmente el primer participante ingresado es el ganador
        {
            puntosGanador=puntosPorParticipante;    //Luego se compara con el siguiente y se sobreescriben los datos
            participanteGanador=participante;       //Item b
        }

        printf("\na. Puntaje obtenido del participante: %d\n",puntosPorParticipante);
        printf("\nCantidad de disparos en el primer cuadrante: %d\n",cantidadPrimerCuadrante);
        printf("\nCantidad de disparos en el segundo cuadrante: %d\n",cantidadSegundoCuadrante);
        printf("\nCantidad de disparos en el tercer cuadrante: %d\n",cantidadTercerCuadrante);
        printf("\nCantidad de disparos en el cuarto cuadrante: %d\n",cantidadCuartoCuadrante);
        printf("\nCantidad de disparos en el centro: %d\n",cantidadCentro);
        totalCantidadCentro+=cantidadCentro;        //Item c

        //Inicializo nuevamente todas las variables para el proximo participante

        puntosPorParticipante=0;
        cantidadCentro=0;
        cantidadPrimerCuadrante=0;
        cantidadSegundoCuadrante=0;
        cantidadTercerCuadrante=0;
        cantidadCuartoCuadrante=0;
        printf("\nIngrese numero de participante (negativo para terminar): ");
        scanf("%d",&participante);
        bandera=1;  //Bandera por si nunca hubo participantes (ingreso como primer valor un numero negativo)
    }
    if(bandera==1)
    {
        printf("\nb. El participante ganador con numero %d realizo un total de %d puntos\n",participanteGanador,puntosGanador);
        printf("\nc. La cantidad total de disparos totales en el centro es de: %d\n",totalCantidadCentro);
    }
    else
        printf("\nNo hay participantes...\n");
    return 0;
}

/*Para esta funcion unicamente con una secuencia de if's vemos los valores de las coordenadas para identificar el
cuadrante*/

int Cuadrante(int x,int y)
{
    if(x==0&&y==0)
        return 0;
    else if(x<0&&y<0)
        return 3;
    else if(x>0&&y>0)
        return 1;
    else if(x>0&&y<0)
        return 4;
    else
        return 2;
}

/*Esta funcion tambien se podia haber modificado para que reciba unicamente el numero de cuadrante, en vez de recibir
las coordenadas*/

int Puntaje(int cantidadPrimerCuadrante, int cantidadSegundoCuadrante, int cantidadTercerCuadrante, int cantidadCuartoCuadrante, int cantidadCentro)
{
    int totalPuntos;
    return totalPuntos=50*(cantidadPrimerCuadrante+cantidadSegundoCuadrante)+40*(cantidadTercerCuadrante+cantidadCuartoCuadrante)+100*cantidadCentro;
}
