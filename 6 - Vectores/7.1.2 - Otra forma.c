#include <conio.h>
#include <stdio.h>

void cargarVec(float vec[], int tamano);
void combinarVec(float vec1[], float vec2[], float vec3[], int tamano1, int tamano2);

int main()
{
    float vec1[5];
    float vec2[5];
    float vec3[10]={0};
    cargarVec(vec1, 5);
    cargarVec(vec2, 5);
    printf("\n");
    combinarVec(vec1, vec2, vec3, 5, 5);
    for (int i=0;i<10;i++)
        printf("%.2f ", vec3[i]);
    getch();
    return 0;
}

void cargarVec(float vec[], int tamano)
{
    for (int i=0;i<tamano;i++)
    {
        printf("%d: ", i);
        scanf("%f", &vec[i]);
    }
}

void combinarVec(float vec1[], float vec2[], float vec3[], int tamano1, int tamano2)
{
    for (int i=0;i<tamano1+tamano2;i++)
    {
        if (i<tamano1)
            vec3[i]=vec1[i];
        else
            vec3[i]=vec2[i-tamano1];
    }
}
