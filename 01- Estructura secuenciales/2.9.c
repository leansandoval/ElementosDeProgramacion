/*2.9. Confeccionar un programa que ingrese un valor expresado en Kibibyte (KiB)1 y lo informe expresado en:
TiB, GiB, MiB, con leyendas aclaratorias. (1MiB = 1024 KiB; 1GiB = 1024 MiB; 1TiB = 1024 GiB)
--------------------------------------------------------------------------------------------------------------
Resolucion: un simple pasaje de unidades y reglas de 3.
El kibibyte está estrechamente relacionado con el kilobyte (símbolo kB).
Kibibyte y kilobyte no son sinónimos pero suelen usarse incorrectamente como si lo fueran, aunque en
realidad tienen valores diferentes:
1 kibibyte = 1024 B = 210 bytes.
1 kilobyte = 1000 B = 103 bytes.
*/

#include <stdio.h>
int main()
{
    float kib,mib,gib,tib;
    printf("\nIngrese un valor en Kibibyte: ");
    scanf("%f",&kib);
    mib=kib/1024;
    gib=mib/1024;
    tib=gib/1024;
    printf("\nMedibyte: %.2f",mib);
    printf("\n\nGibibyte: %.4f",gib);
    printf("\n\nTebibyte: %.6f\n",tib);
    return 0;
}
