/*
 * biblio.c
 *
 *  Created on: 25 sept 2022
 *      Author: Franc
 */
#include "bibliotecaFunciones.h"

#include <stdio.h>
#include <stdlib.h>

void printMenu(float gHospedaje,float gComida,float gTransporte,int cArqueros,int cDefensores,int cMedioCamp,int cDelanteros)
{

	printf("\t***MENU PRINCIPAL***\n");

	printf("1. Ingreso de los costos de Mantenimiento\n");
	printf("  Costo de Hospedaje: $ %.2f\n", gHospedaje);
	printf("  Costo de Comida: $ %.2f\n", gComida);
	printf("  Costo de Transporte: $ %.2f \n", gTransporte);

	printf("2. Carga de jugadores\n");
	printf("  Arqueros: %d \n", cArqueros);
	printf("  Defensores: %d\n",cDefensores);
	printf("  Mediocampistas: %d\n",cMedioCamp);
	printf("  Delanteros: %d\n",cDelanteros);

	printf("3. Realizar todos los c�lculos\n");
	printf("4. Informar todos los resultados\n");
	printf("5. Salir");
}
//----------------------------------------------------

/**
 * @fn int getIntRange(int*, char*, char*, int, int)
 * @brief

 * @param pValor - variable puntero donde se asigna el valor pedido,
 * @param mensaje - cadena de caracteres dispuesta para un mensaje.
 * @param msjError - cadena de caracteres dispuesta para un mensaje de error.
 * @param min - tipo entero que denota el m�nimo del rango establecido.
 * @param max - tipo entero que denota el m�ximo del rango establecido.
 * @return retorna 0 en caso de que sea diferente de NULL y sea un n�mero entero dentro del rango establecido, si no retorna -1
 */
int getIntRange(int *pValor, char *mensaje, char *msjError, int min, int max) {
	int ret = -1;
	int aux;

	if (pValor != NULL && mensaje != NULL && msjError != NULL && min<=max)
	{
		printf("%s", mensaje);
		scanf("%d", &aux);
		while (aux < min || aux > max)
		{
			printf("%s", msjError);
			scanf("%d", &aux);
		}
		*pValor = aux;
		ret = 0;
	}

	return ret;
}
//------------------------------
/**
 * @fn int getFloatRange(float*, char*, char*, float, float)
 * @brief

 * @param pValor - variable puntero donde se asigna el valor pedido,
 * @param mensaje - cadena de caracteres dispuesta para un mensaje.
 * @param msjError - cadena de caracteres dispuesta para un mensaje de error.
 * @param min - tipo flotante que denota el m�nimo del rango establecido.
 * @param max - tipo flotante que denota el m�ximo del rango establecido.
 * @return retorna 0 en caso de que sea diferente de NULL y sea un n�mero entero dentro del rango establecido.
 * 		   caso contrario retorna -1.
 */
int getFloatRange(float *pValor, char *mensaje, char *msjError, float min, float max) {
	int ret = -1;
	float aux;

	if (pValor != NULL && mensaje != NULL && msjError != NULL && min<=max)
	{
		printf("%s", mensaje);
		scanf("%f", &aux);
		while (aux < min || aux > max)
		{
			printf("%s", msjError);
			scanf("%f", &aux);
		}
		*pValor = aux;
		ret = 0;
	}

	return ret;
}
//-----------------------------
/// @fn int seleccionLiga(int, int*, int*, int*, int*, int*, int*)
/// @brief Funcion que acumula en 1 la cantidad de confederaciones seleccionadas.
///
/// @param opcionLiga - tipo entero, selector del switch.
/// @param afc - tipo entero, cantidad correspondiente a una confederacion
/// @param caf - tipo entero, cantidad correspondiente a una confederacion
/// @param uefa - tipo entero, cantidad correspondiente a una confederacion
/// @param concaf - tipo entero, cantidad correspondiente a una confederacion
/// @param conmebol - tipo entero, cantidad correspondiente a una confederacion
/// @param ofc - tipo entero, cantidad correspondiente a una confederacion
///
/// @return retorna 0 si pudo realizar la suma o -1 si algo fall�
int seleccionLiga(int opcionLiga,int* afc,int* caf,int* uefa,int* concaf,int* conmebol,int* ofc)
{
	int ret=-1;
	if(afc!=NULL && caf!=NULL && uefa!=NULL && concaf!=NULL && conmebol!=NULL && ofc!=NULL)
	{

		switch(opcionLiga)
		{
		case 1:
			*afc=*afc+1;
			break;

		case 2:
			*caf=*caf+1;
			break;
		case 3:
			*uefa=*uefa+1;
			break;

		case 4:
			*concaf=*concaf+1;
			break;

		case 5:
			*conmebol=*conmebol+1;
			break;

		case 6:
			*ofc=*ofc+1;
			break;

		}
		ret=0;
	}

	return ret;

}
//-------------------------------------
/// @fn int tipoPlantel(int, int, int, int, int, int)
/// @brief Eval�a si una de las confederaciones es mayor a todas las demas.
///
/// @param afc - tipo entero, cantidad correspondiente a una confederacion
/// @param caf - tipo entero, cantidad correspondiente a una confederacion
/// @param uefa- tipo entero, cantidad correspondiente a una confederacion
/// @param concaf- tipo entero, cantidad correspondiente a una confederacion
/// @param conmebol- tipo entero, cantidad correspondiente a una confederacion
/// @param ofc- tipo entero, cantidad correspondiente a una confederacion
///
/// @return retorna 1 si la confederacion UEFA es mayor a todas. Caso contrario retorna 0
int tipoPlantel(int afc, int caf, int uefa, int concaf, int conmebol, int ofc)
{
	int ret;
	if(uefa>afc && uefa>caf && uefa>concaf && uefa>conmebol && uefa>ofc)
	{
		ret=1;
	}
	else
	{
		ret=0; // IGUAL O MENOR
	}
	return ret;
}

//------------------------------------
/// @fn void limpiarPantalla()
/// @brief Efect�a varios saltos de l�nea para "vaciar" lo que haya impreso en consola
///

void limpiarPantalla()
{
	int cantidad=40;
	for(int i=0; i<cantidad;i++)
		printf("\n");
}
