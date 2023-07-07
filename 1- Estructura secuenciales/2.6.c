/*2.6. El precio para un vuelo es de $8800 en clase turista y se aplica un incremento del 30% en primera clase.
Se ingresan la cantidad de pasajes vendidos de clase turista y de primera clase.
Obtener la recaudación total del vuelo.
---------------------------------------------------------------------------------------------------------------
Resolucion: como el precio para el vuelo es de un valor fijo, utilizamos #define para declarar una constante
con ese valor. Idem para el 30% que se pide para primera clase
Luego se ingresan por teclado la cantidad de pasajes vendidos, tanto para la clase turista como para los de
primera clase. Defino dos variables int para el ingreso.
Ahora para obtener la recaudacion se debera multiplicar la cantidad de vuelos por el precio (clase turista).
Para primera clase tengo que hacer lo mismo, con la excepcion de agregar el 30% a los $8800 y luego multiplicar
la cantidad de viajes.
*/

#include <stdio.h>
#define vuelo 8800
#define treinta_porciento 8800*0.3

int main()
{
    int turista,primera_clase,total_turista,total_primera_clase,recaudacion;
    printf("\nIngresar la cantidad de pasajes de clase turista:");
    scanf("%d",&turista);
    printf("\nIngresar la cantidad de pasajes de primera clase:");
    scanf("%d",&primera_clase);
    total_turista=vuelo*turista;
    total_primera_clase=(treinta_porciento+vuelo)*primera_clase;
    recaudacion=total_turista+total_primera_clase;
    printf("\nLa recaudacion del vuelo es de:%d\n",recaudacion);
}
