/* 7.2.10 - Ingresar por teclado valores enteros y generar una matriz de 5x3 (5 filas y 3 por columnas). Informar:
a. La suma de los elementos de las columnas.
b. Las sumas de los elementos de las filas.
c. La suma total de los elementos.
d. El valor promedio de toda la matriz.
e. El valor promedio por columna.
f. El máximo valor de la matriz y en qué posición se encuentra (el máximo es único).
g. El mínimo valor de cada columna y en qué posición se encuentra (el mínimo es único).
Utilizar funciones para la carga y para resolver cada uno de los puntos.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Resolucion: para ingresar los valores enteros voy a cagar una matriz de 5x3 utilizando la funcion CargaMat, esta matriz sera una matriz de enteros.
Recordar que los numeros enteros son E={...-3,-2,-1,0,1,2,3,...}
Luego de ingresar los datos (no obligatorio) muestro los datos ingresados en forma de matriz utilizando la funcion MostrarMatFila. Luego de esto, comienzo con los items:
a - Para sumar los elementos de las columnas, voy a guardar dichos elementos en un vector de 3 elementos, obviamente ya que la matriz posee 3 columnas.
La funcion que se va a usar es SumarColumnaMatEnV
Recordar que siempre que tenga un vector acumulador o contador debo inicializarlo. En este caso utilizo la funcion PonerEnCero.
b- Lo que el punto a, pero ahora se suman los elementos de las filas, estos los voy a guardar en un vector de 5 elementos. Tambien este vector tiene que estar inicializado.
Para este item usamos la funcion SumaFilaMatEnV
c- Aca lo unico que hay que hacer es agarrar un vector de los anteriores y realizar la suma de todos los elementos del vector. Utilizamos la funcion SumaVec
d - Para sacar el promedio de toda la matriz hay que recordar que el promedio es la suma total de sus elementos divido la cantidad de estos.
Como sacamos la suma total de la matriz en el item c, vamos a usar ese resultado y dividirla por la cantidad de elementos que tiene la matriz.
En este caso, es una matriz de 5x3, por lo que tiene 5*3=15 elementos. Fijarse que en el main se declaro una variable flotante llamada prom.
Aun asi, si realizamos la division nos va a devolver un entero. Esto es porque la suma total de la matriz es un entero y la cantidad de elementos tambien es un entero.
Como queremos el resultado en tipo float lo que hay que hacer es una conversion y poner (float) entre parentesis.
e- Como tenemos en un vector la suma de los elementos de cada columna (resuelto en el punto a) voy a utilizar nuevamente ese vector y, en otro vector de float,
almacenar los promedios. No confundirse que cada columna (3 en total) contiene 5 elementos. Por lo que vamos a tener que dividir la suma de cada columna por 5
*/

#include<stdio.h>
#include<windows.h>

void CargaMat(int[][3],int,int);
void MostrarMatFila(int[][3],int,int);
void PonerEnCero(int[],int);
void MostrarVec(int[],int);
void MostrarVecReal(float[],int);
void SumaFilaMatEnV(int[][3],int[],int,int);
void SumarColumnaMatEnV(int[][3],int[],int,int);
int SumaVec(int[],int);
void GeneraVecPromColumna(int[],float[],int);
void MaximoMat(int[][3],int,int);

int main()
{
    int MNumeros[5][3],VSumaFila[5],VSumColumna[3],VMenoresColumna[3];
    float prom,VPromColumna[3];
    PonerEnCero(VSumaFila,5);
    PonerEnCero(VSumColumna,3);
    CargaMat(MNumeros,5,3);
    MostrarMatFila(MNumeros,5,3);
    SumaFilaMatEnV(MNumeros,VSumaFila,5,3);
    SumarColumnaMatEnV(MNumeros,VSumColumna,5,3);
    printf("\na)Suma de los elementos de las columnas");
    MostrarVec(VSumColumna,3);
    printf("\n\nb)Suma de los elementos de las filas");
    MostrarVec(VSumaFila,5);
    printf("\n\nc)Suma total de los elementos: %d",SumaVec(VSumColumna,3));
    prom=(float)SumaVec(VSumaFila,5)/15;
    printf("\n\nd)Valor promedio de toda la matriz: %.2f",prom);
    GeneraVecPromColumna(VSumColumna,VPromColumna,3);
    printf("\n\ne)Valor promedio por columna");
    MostrarVecReal(VPromColumna,3);
    MaximoMat(MNumeros,5,3);
    MinValorPorColumna(MNumeros,VMenoresColumna,5,3);
    printf("\n\n");
    system("pause");
}

//Funciones para mostrar los vectores/matrices en pantalla:

void MostrarVec(int v[],int ce)
{
    int i;
    printf("\n");
    for(i=0;i<=ce-1;i++)
        printf("\n%d",v[i]);
}

void MostrarVecReal(float v[],int ce)
{
    int i;
    printf("\n");
    for(i=0;i<=ce-1;i++)
        printf("\n%.2f",v[i]);
}

void MostrarMatFila(int m[][3],int f,int c)
{
    int i,j;
    printf("\nMatriz ingresada:");
    printf("\n");
    for(i=0;i<=f-1;i++)
    {
        printf("\n");
        for(j=0;j<=c-1;j++)
            printf("%d\t",m[i][j]);
    }
    printf("\n");
}

//Funcion para inicializar un vector

void PonerEnCero(int v[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        v[i]=0;
}

//Funcion para ingresar datos en una matriz

void CargaMat (int m[][3],int f,int c)
{
    int i,j,dato;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
        {
            printf("\nIngrese un numero entero (dato ingresado en la posicion (%d,%d): ",i,j);
            scanf("%d",&dato);
            m[i][j]=dato;
        }
}

/*Item a)
La funcion SumarColumnaMatEnV lo que haces es ir sumando los elementos por columnas y el resultado lo va almacenando en un vector.
Utilizo una variable int llamada s, esta variable axiliar lo que va a hacer es almacenar suma total que los elementos por CADA columna --> s+=m[i][j].
Recordar que siempre una variable, sea acumuladora o contadora, la tengo que inicializar --> s=0
Luego de que recorra una columna, el resultado que haya quedado en s lo tengo que almacenar en el vector --> v[j]=s;
Para recorrer la siguiente columna, es necesario que la variable s este en 0 nuevamente, es por eso que s=0 esta dentro del for.
Datos extras:
*En general, las variables que se usan para el ciclo for son i y j: i corresponde para las filas (int f) y j para las columnas (int c)
*Fijarse que en la funcion el primer for es para columnas, y el segundo for es para filas; esto es asi ya que lo estoy recorriendo por columnas.
*/

void SumarColumnaMatEnV(int m[][3],int v[],int f,int c)
{
    int i,j,s;
    for(j=0;j<=c-1;j++)
    {
        s=0;
        for(i=0;i<=f-1;i++)
            s+=m[i][j];
        v[j]=s;
    }
}

/*Item b)
Idem item a), la unica diferencia es que ahora, como vamos a sumar por filas, el vector acumulador sera el 5 elementos.
El primer for recorre filas y el segundo columnas, caso contrario al del item a).
Fijarse tambien que no es necesario una variable auxiliar, por lo que vamos guardando directamente en el vector. -->  v[i]+=m[i][j]
*/

void SumaFilaMatEnV (int m[][3],int v[],int f,int c)
{
    int i,j;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            v[i]+=m[i][j];
}

/*Item c)
Simplemente es una funcion que suma todos los elementos de un vector, declaramos una variable acumuladora (previamente inicializada --> s=0)
En la que va almacenando la suma de los elementos mientras se va recorriendo el vector -->  s+=v[i].
Luego retornamos la suma, o en otras palabras, esta funcion devuelve un entero --> return s
*/

int SumaVec(int v[],int ce)
{
    int i,s=0;
    for(i=0;i<=ce-1;i++)
        s+=v[i];
    return s;
}

/*Item e)
Dos vectores: uno de enteros que contiene la suma de los elementos por columna de la matriz y un vector de float que tendra el promedio de cada columna.
Esta de mas decirlo, ambos vectores tendran la misma dimension/tamaño (en este caso 3).
En el for, el vector de entero es dividido entre la cantidad de elementos que contiene cada columma (5 elementos) y es almacenado en el vector de float.
*/

void GeneraVecPromColumna (int a[],float b[],int ce)
{
    int i;
    for(i=0;i<=ce-1;i++)
        b[i]=(float)a[i]/5;
}

void MaximoMat(int m[][3],int f,int c)
{
    int i,j,mayor=0,x,y;
    for(i=0;i<=f-1;i++)
        for(j=0;j<=c-1;j++)
            if(mayor==0||m[i][j]>mayor)
                {
                    mayor=m[i][j];
                    x=i;
                    y=j;
                }
    printf("\n");
    printf("\nf)El valor maximo es %d de la matriz se encuentra en la posicion (%d,%d)",mayor,x,y);
}

void MinValorPorColumna(int m[][3],int v[],int f,int c)
{
    int i,j,menor,x,y;
    printf("\n\ng)Minimo valor de cada columna");
    printf("\n");
    for(j=0;j<=c-1;j++)
    {
        menor=0;
        for(i=0;i<=f-1;i++)
            if(menor==0||m[i][j]<menor)
            {
                menor=m[i][j];
                x=i;
                y=j;
            }
        v[j]=menor;
        printf("\nEl menor valor de la columna %d es %d encontrado en la posicion (%d,%d)",j+1,v[j],x,y);
    }
}
