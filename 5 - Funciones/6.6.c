#include <stdlib.h>
#include <stdio.h>

int cifras (int num );

int main()
{
	int cantCifras, auxnumeros3=0, i=10001;
	for(i=10001; i<= 90009; i++)
	{
		cantCifras = cifras(i);

		if(cantCifras == 3)
		{
			auxnumeros3++;
		}
	}
	printf("\nCantidad de numeros con mas cifras 3 que 4: %d", auxnumeros3);


	return 0;
}
int cifras (int num )
{
	int unidad_10mil, unidad_mil, unidad, centena, decena;

	unidad_10mil = num/10000;
	unidad_mil = (num%10000)/1000;
	centena = (num%1000)/100;
	decena = (num%100)/10;
	unidad = (num%10)/1;



	if((unidad_10mil == 3) && (unidad_mil == 3) && (centena == 3) || (decena == 3) && (unidad == 4) )
	{
		//confirmo que hay un 3 en el numero.
		return 3;
	}
	if((unidad_10mil == 3) && (unidad_mil == 3) || (centena == 3) && (decena == 4) && (unidad == 3) )
	{
		//confirmo que hay un 4 en el numero.
		return 3;
	}
	if((unidad_10mil == 3) || (unidad_mil == 3) && (centena == 4) && (decena == 3) && (unidad == 3) )
	{
		//confirmo que hay un 4 en el numero.
		return 3;
	}
	if((unidad_10mil == 3) || (unidad_mil == 4) && (centena == 3) && (decena == 3) && (unidad == 3) )
	{
		//confirmo que hay un 4 en el numero.
		return 3;
	}
	if((unidad_10mil == 4) && (unidad_mil == 3) && (centena == 3) && (decena == 3) || (unidad == 3) )
	{
		//confirmo que hay un 4 en el numero.
		return 3;
	}

	if((unidad_10mil != 4) && (unidad_mil != 3) && (centena != 3) && (decena != 3) || (unidad != 3) )
	{
		//confirmo que hay un 4 en el numero.
		return 0;
	}


}
