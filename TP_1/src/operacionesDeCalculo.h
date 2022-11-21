/*
 * operacionesDeCalculos.h
 *
 *  Created on: 25 sept 2022
 *      Author: Franc
 */

#ifndef OPERACIONESDECALCULO_H_
#define OPERACIONESDECALCULO_H_

int costoMantenimientoSA(float* total,float hos, float com, float tra);
int costoMantenimientoCA(float* total, int aumento, float hos, float com, float tra);
int promedioJugadores(float* pValor, int div, int divisor);

float Sumar(float primerNumero, float segundoNumero);
float Multiplicar(float primerNumero, float segundoNumero);
float Restar(float primerNumero, float segundoNumero);

#endif /* OPERACIONESDECALCULO_H_ */
