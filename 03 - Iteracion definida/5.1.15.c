/*5.1.15 Se realizó un concurso de tiro al blanco. Existen 5 participantes y cada uno de ellos efectúa 3 disparos,
registrándose las coordenadas X-Y de cada disparo. Determinar:
a. Cuantos disparos se efectuaron en cada cuadrante POR CADA participante
b. Cuantos disparos se efectuaron en total en el centro.
NOTA: no considere disparos sobre los ejes.
--------------------------------------------------------------------------------------------------------------------
Resolucion: se deberan hacer 2 ciclos for, uno para los 5 participantes y dentro de este, otro que tome los 3
disparos de cada uno. En este, se ingresa por teclado en que coordenadas fue el disparo y dependiendo del cuadrante
que se encuentre, incrementara el contador. Como no se consideran disparos sobre los ejes, si se ingresa alguno ya
sea en el eje x o en el eje y se tiene que decrementar la variable que itera los disparos. Luego por pantalla se
muestra la cantidad de disparos por cada participante.
*/

#include<stdio.h>

int main()
{
    int j,i,primerCuadrante=0,segundoCuadrante=0,tercerCuadrante=0,cuartoCuadrante=0,centro=0;
    float x,y;
    for(i=1; i<=5; i++)
    {
        for(j=1; j<=3; j++)
        {
            printf("\nIngrese las coordenadas del disparo en X: ");
            scanf("%f",&x);
            printf("\nIngrese las coordenadas del disparo en Y: ");
            scanf("%f",&y);
            if(x>0 && y>0)
                primerCuadrante++;
            if(x<0 && y>0)
                segundoCuadrante++;
            if(x<0 && y<0)
                tercerCuadrante++;
            if(x>0 && y<0)
                cuartoCuadrante++;
            if(x==0 && y==0)
                centro++;
            if((x==0 && y!=0) || (x!=0 && y==0))
            {
                printf("\nSe ingreso un disparo sobre algun eje, disparo invalido...\n");
                j--;
            }

        }
        printf("\n-------------------------------------------------------------\n");
        printf("\nPara el participante numero %d realizo los siguientes disparos:\n",i);
        printf("\nDisparos en el primer cuadrante: %d\n",primerCuadrante);
        printf("\nDisparos en el segundo cuadrante: %d\n",segundoCuadrante);
        printf("\nDisparos en el tercer cuadrante: %d\n",tercerCuadrante);
        printf("\nDisparos en el cuarto cuadrante: %d\n",cuartoCuadrante);
        printf("\nDisparos en el centro: %d\n",centro);
        printf("\n-------------------------------------------------------------\n");
    }
    return 0;
}
