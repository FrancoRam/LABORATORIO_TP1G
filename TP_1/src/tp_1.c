/*
 ============================================================================
 Name        : borrador2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "bibliotecaFunciones.h"
//#include "funcionesBasic1.h"
#include "operacionesDeCalculo.h"

#define MAYORIA_CONF_EUROPEA 35


int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int subOpcion;
	int respuesta;
	//confederaciones
	int AFC=0; 		//ASIA
	int CAF=0;		//AFRICA
	int UEFA=0;		//EUROPA
	int CONCAF=0;	//ZONA DEL NORTE
	int CONMEBOL=0;	//SUDAMERICA
	int OFC=0;		//OCEANIA

	//1
	float gHospedaje=0;
	float gComida=0;
	float gTransporte=0;

	float auxH=0;
	float auxC=0;
	float auxT=0;
	//2
	int cArqueros=0;
	int cDefensores=0;
	int cMedioCamp=0;
	int cDelanteros=0;

	float promedioAfc=0;
	float promedioCaf=0;
	float promedioConcaf=0;
	float promedioUefa=0;
	float promedioConmebol=0;
	float promedioOfc=0;




	int numCamiseta;

	//3
	float costoMantenimSa;
	float costoMantenimCa;
	float costoAumentoTotal;
	int plantel=-1; // Variable de validación de cálculos
	int contadorJugadores=0;

	int banderaPromedio=-1;

	do {
		limpiarPantalla();
		printMenu(gHospedaje, gComida, gTransporte, cArqueros, cDefensores, cMedioCamp, cDelanteros);
		respuesta = getIntRange(&opcion, "\n\nSeleccione la opción deseada: \n",
								"\nERROR - Seleccione la opción deseada (1 al 5)\n", 1, 5);
		if (respuesta == 0)
		{
			switch (opcion) {
			case 1:
				getIntRange(&subOpcion,
						"\nSeleccione tipo de costo a ingresar: \n1.Hospedaje\n2.Comida\n3.Transporte",
						"\nERROR - Seleccione el tipo de costo a ingresar (1 al 3): ",
						1, 3);
				switch (subOpcion) {
				case 1:
					getFloatRange(&auxH, "Agregue un costo de hospedaje",
							"ERROR, Ingrese un coste válido", 1, 99999999);
					gHospedaje = auxH + gHospedaje;
					printf("\n\t *Costo sumado*\n\n");
					break;
				case 2:
					getFloatRange(&auxC, "Agregue un costo de comida",
							"ERROR, Ingrese un coste válido", 1, 99999999);
					gComida = auxC + gComida;
					printf("\n\t *Costo sumado*\n\n");
					break;
				case 3:
					getFloatRange(&auxT, "Agregue un costo de transporte",
							"ERROR, Ingrese un coste válido", 1, 99999999);
					gTransporte = auxT + gTransporte;
					printf("\n\t *Costo sumado*\n\n");
					break;
				}
				break;

			case 2:
				getIntRange(&subOpcion,
						"\nSeleccione la posición del jugador: \n1.Arquero\n2.Defensor\n3.Medio campista\n4.Delantero",
						"\nERROR - Seleccione la posición del jugador (1 al 4): ",
						1, 4);
				switch (subOpcion) {
				case 1:
					cArqueros++;
					break;
				case 2:
					cDefensores++;
					break;
				case 3:
					cMedioCamp++;
					break;
				case 4:
					cDelanteros++;
					break;
				}
				printf("Ingrese el número de camiseta: ");
				scanf("%d", &numCamiseta);

				getIntRange(&subOpcion,
						"\nSeleccione la LIGA: \n1.AFC\n2.CAF\n3.UEFA\n4.CONCAF\n5.CONMEBOL\n6.OFC: \n\n",
						"\nERROR - Seleccione la LIGA del jugador (1 al 6): ",
						1, 6);
				seleccionLiga(subOpcion, &AFC, &CAF, &UEFA, &CONCAF, &CONMEBOL,
						&OFC);
				contadorJugadores++;
				break;

			case 3:
				if((gHospedaje==0 && gComida==0 && gTransporte==0) || (cArqueros==0 && cDefensores==0 && cMedioCamp==0 && cDelanteros==0))
				{
					printf("PRIMERO DEBE INGRESAR LOS GASTOS Y LOS JUGADORES\n");
				}
				else
				{
					plantel=tipoPlantel(AFC, CAF, UEFA, CONCAF,CONMEBOL,OFC);
					costoMantenimientoSA(&costoMantenimSa, gHospedaje, gComida, gTransporte);
					costoMantenimientoCA(&costoMantenimCa, MAYORIA_CONF_EUROPEA, gHospedaje, gComida, gTransporte);
					costoAumentoTotal=Restar(costoMantenimCa, costoMantenimSa);

					if(
						promedioJugadores(&promedioAfc, AFC, contadorJugadores)!=-1
						&&
						promedioJugadores(&promedioCaf, CAF,contadorJugadores)!=-1
						&&
						promedioJugadores(&promedioConcaf, CONCAF,contadorJugadores)!=-1
						&&
						promedioJugadores(&promedioUefa, UEFA,contadorJugadores)!=-1
						&&
						promedioJugadores(&promedioConmebol, CONMEBOL,contadorJugadores)!=-1
						&&
						promedioJugadores(&promedioOfc, OFC,contadorJugadores)!=-1
					)
					{
						banderaPromedio=0;
					}
					else
					{
						banderaPromedio=-1;
						printf("\n\t-error al realizar los promedios\n");
					}

					printf("\n\t*Cálculos realizados*\n");
				}

				break;
			case 4:
				if(plantel!=-1)//Validación de cálculos realizados
				{
					if(plantel == 0)
					{
						printf("COSTO DE MANTENIMIENTO: $ %.2f", costoMantenimSa);
					}
					else
					{
						printf("COSTO MANTENIMIENTO INCIAL ERA DE: $ %.2f\n", costoMantenimSa);
						printf("RECIBIÓ UN AUMENTO TOTAL DE: $ %.2f\n", costoAumentoTotal);
						printf("SU NUEVO VALOR ES: $ %.2f\n", costoMantenimCa);
					}

					if(banderaPromedio!=-1)
					{
						printf("\n\nPROMEDIO DE JUGADORES DE LA AFC ES: %.2f\n", promedioAfc);
						printf("PROMEDIO DE JUGADORES DE LA CAF ES: %.2f\n", promedioCaf);
						printf("PROMEDIO DE JUGADORES DE LA CONCAF ES: %.2f\n", promedioConcaf);
						printf("PROMEDIO DE JUGADORES DE LA CONMEBOL ES: %.2f\n", promedioConmebol);
						printf("PROMEDIO DE JUGADORES DE LA UEFA ES: %.2f\n", promedioUefa);
						printf("PROMEDIO DE JUGADORES DE LA OFC ES: %.2f\n\n", promedioOfc);
					}

				}
				else
				{
					printf("\n**PRIMERO DEBE REALIZAR LOS CÁLCULOS**\n");
				}


				break;

			case 5:
				//SALE DEL MENU
				break;
			}
		}
		system("pause");
	} while (opcion != 5);

	return EXIT_SUCCESS;
}







