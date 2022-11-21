/*
 * operacionesDeCalculo.c
 *
 *  Created on: 25 sept 2022
 *      Author: Franc
 */

#include <stdio.h>
#include <stdlib.h>
#include "operacionesDeCalculo.h"

/// @fn int costoMantenimientoSA(float*, float, float, float)
/// @brief Funcion que suma los costos de mantenimiento y los asigna a un total
///
/// @pre
/// @post
/// @param total - valor que asigna por referencia.
/// @param hos - variable tipo float
/// @param com - variable tipo float
/// @param tra - variable tipo float
/// @return retorna 0 si pudo efectuar el calculo, -1 si algo falló
int costoMantenimientoSA(float* total,float hos, float com, float tra)
{
	int ret=-1;
	if(total!=NULL)
	{
		*total=Sumar(Sumar(com, hos),tra);
		ret=0;
	}
	return ret;
}
/// @fn int costoMantenimientoCA(float*, float, float, float)
/// @brief Funcion que suma los costos de mantenimiento; los asigna a un total
/// 		con un aumento aplicado.
///
/// @pre
/// @post
/// @param total - valor que asigna por referencia.
/// @param hos - variable tipo float
/// @param com - variable tipo float
/// @param tra - variable tipo float
/// @return retorna 0 si pudo efectuar el calculo, -1 si algo falló
int costoMantenimientoCA(float* total, int aumento, float hos, float com, float tra)
{
	int ret=-1;
	float costo;
	float aux;

	costo=Sumar(Sumar(com, hos),tra);
	aux=Multiplicar(costo, aumento);

	*total=Sumar(aux/100, costo);
	return ret;
}
/**
 * @fn float promedioJugadores(float*, int, int)
 * @brief calcula un promedio
 *
 * @param num1 - variable de tipo entero.
 * @param num2 - variable de tipo entero.
 * @return retorna un promedio de tipo Flotante
 */
int promedioJugadores(float* pValor, int div, int divisor)
{
	 int ret = -1;

	 if(pValor != NULL && divisor != 0){
		 *pValor =(float) (div / divisor);
		 ret = 0;
	 }
	 return ret;
}

float Multiplicar(float primerNumero, float segundoNumero)
{
	float resultado;
	resultado = primerNumero*segundoNumero;

	return resultado;
}

float Sumar(float primerNumero, float segundoNumero)
{
	float resultado;
	resultado = primerNumero+segundoNumero;

	return resultado;
}

float Restar(float primerNumero, float segundoNumero)
{
	float resultado;
	resultado = primerNumero-segundoNumero;

	return resultado;
}
