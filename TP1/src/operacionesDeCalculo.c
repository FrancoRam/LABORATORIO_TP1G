/*
 * operacionesDeCalculo.c
 *
 *  Created on: 25 sept 2022
 *      Author: Franc
 */

#include <stdio.h>
#include <stdlib.h>
#include "operacionesDeCalculo.h"


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

int promedioJugadores(float* pValor, int div, int divisor)
{
	 int ret = -1;

	 if(pValor != NULL && divisor != 0){
		 *pValor =(float) div / divisor;
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
