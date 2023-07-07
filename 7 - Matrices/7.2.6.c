#include <conio.h>
#include <stdio.h>

void sumarFilasReservadas(int f, int c, char matriz[f][c], int suma[]);
void sumarColumnasReservadas(int f, int c, char matriz[f][c], int suma[]);
void ordenar(int numero[], int vec[], int tamano);

int main()
{
    char butaca[12][9];
    int fila, columna, suma[12]={0}, ocupadas=0, cant, error, i;
    int butacanum[9]={8,6,4,2,1,3,5,7,9};


    for (fila=0;fila<12;fila++)
        for (columna=0;columna<9;columna++)
            butaca[fila][columna]='D';

    do
    {
        system("cls");
        printf("      8  6  4  2  1  3  5  7  9\n\n");
        for (fila=0;fila<12;fila++)
        {
            printf("%3d ", fila+1);
            for (columna=0;columna<9;columna++)
                printf("%3c", butaca[fila][columna]);
            printf("\n");
        }

        printf("\nNueva reserva:\n");
            do
            {
                printf("Fila (negativo para finalizar): ");
                scanf("%d", &fila);

                if (fila==0 || fila>12)
                    printf("FILA NO VALIDA.\n");
            } while (fila==0 || fila>12);

            fila--;

            if (fila>=0)
            {
                do
                {
                    printf("Columna: ");
                    scanf("%d", &columna);

                    if (columna<1 ||columna>9)
                        printf("COLUMNA NO VALIDA.\n");
                } while (columna<1 ||columna>9);

                if (columna%2==0)
                    columna=4-columna/2;
                else
                    columna=(columna+7)/2;

                error=0;
                i=1;
                if (butaca[fila][columna]=='R')
                {
                    printf("BUTACA RESERVADA.\n");
                    error=1;
                    getch();
                }

                if (error==0)
                {
                    do
                    {
                        printf("Cantidad de reserva: ");
                        scanf("%d", &cant);

                        if (cant<0 || cant+columna>9)
                            printf("CANTIDAD NO VALIDA.\n");
                    } while (cant<0 || cant+columna>9);

                    while (i<cant && error==0)
                    {
                        if (butaca[fila][columna+i]=='R')
                            error=1;
                        i++;
                    }

                    if (error==0)
                    {
                        ocupadas+=cant;
                        for (i=0;i<cant;i++)
                            butaca[fila][columna+i]='R';
                    }
                    else
                    {
                        printf("BUTACAS RESERVADAS.\n");
                        getch();
                    }
                }
            }
    } while (fila>=0);

    sumarFilasReservadas(12, 9, butaca, suma);

    system("cls");
    printf("Total de butacas disponibles: %3d\nTotal de butacas reservadas: %3d\n", 108-ocupadas, ocupadas);

    int filamayor=0;

    printf("Filas vacias: ");

    for (fila=0;fila<12;fila++)
    {
        if (suma[fila]==0)
            printf("%3d", fila+1);
        if (suma[fila]>suma[filamayor])
            filamayor=fila;
    }

    printf("\nFilas con mayor cantidad de espectadores: ");

    for (fila=filamayor;fila<12;fila++)
        if (suma[fila]==suma[filamayor])
            printf("%3d", fila+1);

    for (columna=0;columna<9;columna++)
        suma[columna]=0;

    sumarColumnasReservadas(12, 9, butaca, suma);
    ordenar(butacanum, suma, 9);

    printf("\n\nButaca Cantidad\n");
    for (columna=0;columna<9;columna++)
        printf("%4d %7d\n", butacanum[columna], suma[columna]);

    getch();
    return 0;
}

void sumarFilasReservadas(int f, int c, char matriz[f][c], int suma[])
{
    for (int i=0;i<f;i++)
        for (int j=0;j<c;j++)
            if (matriz[i][j]=='R')
                suma[i]++;
}

void sumarColumnasReservadas(int f, int c, char matriz[f][c], int suma[])
{
    for (int i=0;i<c;i++)
        for (int j=0;j<f;j++)
            if (matriz[j][i]=='R')
                suma[i]++;
}

void ordenar(int numero[], int vec[], int tamano)
{
    int j, aux, fin=1, cota=tamano-1;
    while (fin)
    {
        fin=0;
        for (j=0;j
        <cota;j++)
            if (vec[j]>vec[j+1])
            {
                aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
                aux=numero[j];
                numero[j]=numero[j+1];
                numero[j+1]=aux;
                fin=j;
            }
        cota=fin;
    }
}
