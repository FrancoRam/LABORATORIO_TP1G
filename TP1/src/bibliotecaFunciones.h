/*
 * biblio.h
 *
 *  Created on: 25 sept 2022
 *      Author: Franc
 */

#ifndef BIBLIOTECAFUNCIONES_H_
#define BIBLIOTECAFUNCIONES_H_

int seleccionLiga(int opcionLiga,int* afc,int* caf,int* uefa,int* concaf,int* conmebol,int* ofc);
void printMenu(float gHospedaje,float gComida,float gTransporte,int cArqueros,int cDefensores,int cMedioCamp,int cDelanteros);
int tipoPlantel(int afc, int caf, int uefa, int concaf, int conmebol, int ofc);
int getIntRange(int *pValor, char *mensaje, char *msjError, int min, int max);
int getFloatRange(float *pValor, char *mensaje, char *msjError, float min, float max);
void limpiarPantalla();
#endif /* BIBLIOTECAFUNCIONES_H_ */
