/*5.1.17 Ingresar N artículos (códigos) y sus correspondientes precios. Indicar el código del artículo más caro y el
precio del más barato. NOTA: todos los artículos tienen precios distintos.
--------------------------------------------------------------------------------------------------------------------
Resolucion: como pide tanto maximo como minimo, el primer ingreso del articulo y su precio dentro del ciclo for, dicho
articulo se almacenara en las variables tanto maximo como minimo (if==1) luego para el segundo ingreso la condicion se
ira por el else y ahi es donde se compara el siguiente articulo con el anterior guardada en otras variables. Si no es
maximo, puede que sea un minimo. Del ejercicio anterior 5.1.16, se realizo del modo b)*/

#include<stdio.h>

int main()
{
    int codigo,codigoArticuloMasCaro,cantidadArticulos,i;
    float precio,maximoPrecio,minimoPrecio;
    printf("\nIngresar la cantidad de articulos: ");
    scanf("%d",&cantidadArticulos);
    for(i=1; i<=cantidadArticulos; i++)
    {
        printf("\nIngrese el codigo del articulo: ");
        scanf("%d",&codigo);
        printf("\nIngrese precio (todos los precios deben ser distintos): ");
        scanf("%f",&precio);
        if(i==1)
        {
            maximoPrecio=precio;
            minimoPrecio=precio;
            codigoArticuloMasCaro=codigo;
        }
        else if(precio>maximoPrecio)
        {
            maximoPrecio=precio;
            codigoArticuloMasCaro=codigo;
        }
        else if(precio<minimoPrecio)
            minimoPrecio=precio;
    }
    printf("\nCodigo del articulo mas caro: %d\n",codigoArticuloMasCaro);
    printf("\nPrecio mas barato: $%.2f\n",minimoPrecio);
    return 0;
}
