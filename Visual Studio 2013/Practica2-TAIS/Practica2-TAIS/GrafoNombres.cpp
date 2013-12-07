//
//  GrafoNombres.cpp
//  Practica2-TAIS
//
//  Created by Daniel Serrano Torres on 03/12/13.
//  Copyright (c) 2013 zombies-software. All rights reserved.
//

#include <limits>
#include "GrafoNombres.h"
#include "SplitString/SplitString.h"
#include "Tabla.h"
#include "Lista.h"

using namespace std;

GrafoNombres::GrafoNombres(string filename, string delimiter) {

	int numeroV = 0;

	bool errorLectura = readNumeroVertices(filename, delimiter, numeroV);

	if (errorLectura) {
		cout << "WARNIGN --> Error al leer el fichero o no se ha encontrado " << endl;
	}
	else {

		nombres = new string[numeroV];

		// Asigno los id - nombre en el vector nombres.
		Tabla<string, uint>::Iterador itTablaNombres = tn.principio();
		while (itTablaNombres != tn.final()) {

			string nombre = itTablaNombres.clave();
			uint numVertice = itTablaNombres.valor();

			nombres[numVertice] = nombre;

			itTablaNombres.avanza();
		}

		_G = new Grafo(numeroV);

		// Se crean las aristas del grafo
		readAristas(filename, delimiter);
	}
}

GrafoNombres::~GrafoNombres() {
	
    delete _G;
	delete[] nombres;
}

bool GrafoNombres::contiene(string s) const {

	return tn.esta(s);
}

int GrafoNombres::indice(string s) const {

	return tn.consulta(s);
}

const string& GrafoNombres::nombre(int v) const {
    
    return nombres[v];
}

const Grafo* GrafoNombres::G() const {
    
    return _G;
}

bool GrafoNombres::readNumeroVertices(const string& file, const string& delimiter, int& numVerticesOut) {

	bool error = false;

	ifstream inputFile;
	inputFile.open(file);

	if (inputFile.is_open())  {

		string cadenaLeida;

		while (getline(inputFile, cadenaLeida)) {

			if (cadenaLeida != "" && !inputFile.eof()) {
				int sizeLine;

				string* partesCadenaLeida = split(cadenaLeida, delimiter, sizeLine);

				string pelicula = partesCadenaLeida[0];

				if (!tn.esta(pelicula)) {
					tn.inserta(pelicula, numVerticesOut);

					// aumento el número de vertices
					numVerticesOut++;
				}

				for (int i = 1; i < sizeLine; i++) {
					string actor = partesCadenaLeida[i];

					if (!tn.esta(actor)) {
						tn.inserta(actor, numVerticesOut);

						// aumento el número de vertices
						numVerticesOut++;
					}
				}
			}
		}

		inputFile.close();
	}
	else {
		error = true;
	}

	return error;
}

bool GrafoNombres::readAristas(const string& file, const string& delimiter) {

	bool error = false;

	ifstream inputFile;
	inputFile.open(file);

	if (inputFile.is_open())  {

		string cadenaLeida;

		while (getline(inputFile, cadenaLeida)) {

			if (cadenaLeida != "" && !inputFile.eof()) {
				int sizeLine;

				string* partesCadenaLeida = split(cadenaLeida, delimiter, sizeLine);

				string pelicula = partesCadenaLeida[0];

				int indicePelicula = -1;

				if ( tn.esta(pelicula) ) {
					indicePelicula = tn.consulta(pelicula);
				}

				if ( indicePelicula != -1 ) {

					for (int i = 1; i < sizeLine; i++) {

						string actor = partesCadenaLeida[i];

						if (tn.esta(actor)) {

							_G->ponArista(indicePelicula, tn.consulta(actor));
						}
					}
				}
			}
		}

		inputFile.close();
	}
	else {
		error = true;
	}

	return error;
}

