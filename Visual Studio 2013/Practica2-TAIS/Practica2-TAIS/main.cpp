//
//  main.cpp
//  Practica2-TAIS
//
//  Created by Daniel Serrano Torres on 03/12/13.
//  Copyright (c) 2013 zombies-software. All rights reserved.
//

#include <iostream>

#include "GrafoNombres.h"

using namespace std;

const bool MANUAL_DEBUG = false;

void obtieneDatos(const string& actorOrigen, const string& actorDestino, const GrafoNombres& grafo) {

	int indiceActorOrigen = -1;

	if ( grafo.contiene(actorOrigen) ) {
		indiceActorOrigen = grafo.indice(actorOrigen);
	}

	if (indiceActorOrigen != -1) {
		const Grafo* g = grafo.G();

		//DepthFirstPaths dfpO(*g, indiceActorOrigen);

		BreadthFirstPaths bfp(*g, indiceActorOrigen);

		int indiceActorDestino = -1;

		if ( grafo.contiene(actorDestino) ) {
			indiceActorDestino = grafo.indice(actorDestino);
		}

		if (indiceActorDestino != -1) {

			if ( bfp.hasPathTo(indiceActorDestino) ) {

				//BreadthFirstPaths bfp(*g, indiceActorOrigen);

				int grado = bfp.distance(indiceActorDestino) / 2;

				cout << actorDestino << " tiene un grado de " << grado << " con " << actorOrigen << endl;

				Lista<uint> lista = bfp.pathTo(indiceActorDestino);

				Lista<uint>::Iterador it = lista.principio();

				bool peli = false;
				while (it != lista.final()) {

					const string nombre = grafo.nombre(it.elem());

					cout << nombre;

					if ( nombre != actorDestino) {
						if (peli) {
							cout << "\n with";
							peli = false;
						}
						else {
							cout << "\n was in";
							peli = true;
						}

						cout << endl;
					}
					else {
						cout << endl;
					}

					it.avanza();
				}
			}
			else {
				cout << actorDestino << " no está conectado con " << actorOrigen << endl;
			}
		}
		else {
			cout << actorDestino << " No existe" << endl;
		}
	}
	else {
		cout << actorOrigen << " No existe" << endl;
	}
}

void gradoSeparacion(string& origen) {
    
    GrafoNombres pelis("movies.txt", "/");
	
	string actorDestino = "";
	do {

		cout << "Escriba el nombre del actor destino: ";

		getline(cin, actorDestino);

		if (actorDestino != "") {
			obtieneDatos(origen, actorDestino, pelis);

			if (MANUAL_DEBUG) {

				cout << "DEBUG --> " << actorDestino << endl;

				cout << " origen != \"\" : " << (actorDestino != "") << " o " << " origen != \"q\" " << (actorDestino != "q") << endl;
			}
		}
	} while (actorDestino != "" && actorDestino != "q");
    
    if ( MANUAL_DEBUG ) cout << "fuera del bucle" << endl;
	
}

void numerosActor(const string& origen) {

	GrafoNombres grafo("movies.txt", "/");

	int indiceActorOrigen = -1;

	if (grafo.contiene(origen)) {
		indiceActorOrigen = grafo.indice(origen);
	}

	const Grafo* g = grafo.G();

	BreadthFirstPaths bfp(*g, indiceActorOrigen);

	// actoresNumero almacena el número de actores por número de Bacon (indice del vector)
	int* actoresNumero = new int[11];
	for (int a = 0; a < 11; a++) actoresNumero[a] = 0;

	for (int i = 0; i < g->V(); i++) {

		// Se discriminan los actores que no están conectados con el origen
		if (bfp.hasPathTo(i)) {

			int distancia = bfp.distance(i);

			if ( distancia%2 == 0 ) {

				int numeroBacon = distancia / 2;

				if (numeroBacon < 10) {

					actoresNumero[numeroBacon] += 1;
				}
				else {
					actoresNumero[10] += 1;
				}
			}
		}
	}

	cout << "Origen: " << origen << endl;
	cout << endl << "Número\t" << "# de actores" << endl;

	for (int j = 0; j < 11; j++) {

		if (j < 10) {
			cout << j << "\t" << actoresNumero[j] << endl;
		}
		else {
			cout << ">9" << "\t" << actoresNumero[j] << endl;
		}
	}
}

int main(int argc, const char * argv[])
{
	
	cout << "Escriba el nombre del actor origen: ";

	string origen = "";
	
	getline(cin, origen);

	if (origen != "") {
		gradoSeparacion(origen);
	}
	
	cout << endl << "Escriba el nombre del actor origen: ";

	origen = "";

	getline(cin, origen);

	if (origen != "") {
		numerosActor(origen);
	}

	cout << "Pulse una tecla para terminar..." << endl;
	getline(cin, origen);

    return 0;
}
