//
//  GrafoNombres.cpp
//  Practica2-TAIS
//
//  Created by Daniel Serrano Torres on 03/12/13.
//  Copyright (c) 2013 zombies-software. All rights reserved.
//

#include "GrafoNombres.h"
#include "SplitString.h"
#include "Tabla.h"
#include "Lista.h"

using namespace std;

GrafoNombres::GrafoNombres(string filename, string delimiter) {
    
    crearGrafo(filename, delimiter);
}

GrafoNombres::~GrafoNombres() {
    
        delete _G;
        delete nombres;
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

void GrafoNombres::crearGrafo(const string& filename, const string& delimiter) {
    
    Tabla<string, Lista<string>> tablaAristas;
    int vertices = 0;
    
    read(filename, delimiter, vertices, tablaAristas);
    
    nombres = new string[vertices];
    
    Tabla<string, uint>::Iterador itTablaNombres = tn.principio();
    while ( itTablaNombres != tn.final() ) {
        
        string nombre = itTablaNombres.clave();
        uint numVertice = itTablaNombres.valor();
        
        nombres[numVertice] = nombre;
    }
    
    _G = new Grafo(vertices, 0);
    
    Tabla<string, Lista<string>>::Iterador itTablaAristas = tablaAristas.principio();
    while ( itTablaAristas != tablaAristas.final() ) {
        
        string nombrePelicula = itTablaAristas.clave();
        
        if ( tn.esta(nombrePelicula) ) {
            
            int numeroVerticePelicula = tn.consulta(nombrePelicula);
            
            Lista<string> actoresPelicula = itTablaAristas.valor();
            
            Lista<string>::Iterador itListaActores = actoresPelicula.principio();
            while ( itListaActores != actoresPelicula.final() ) {
                
                string nombreActor = itListaActores.elem();
                
                if( tn.esta(nombreActor) ) {
                
                    int numeroVerticeActor = tn.consulta(nombreActor);
                
                    _G->ponArista(numeroVerticePelicula, numeroVerticeActor);
                }
                
                itListaActores.avanza();
            }
        }
        
        itTablaAristas.avanza();
    }
}

void GrafoNombres::read(const string& file, const string& delimiter, int& numVerticesOut, Tabla<string, Lista<string>> aristasOut) {
    
    Tabla<string, Lista<string>> pelisActores;
    
    ifstream inputFile;
    inputFile.open( file );
    
    if ( inputFile.is_open() )  {
        
        string cadenaLeida;
        
        while ( getline(inputFile, cadenaLeida) ) {
            
            if ( cadenaLeida != "" && !inputFile.eof()) {
                int sizeLine;
                
                string* partesCadenaLeida = partes(cadenaLeida, sizeLine);
                
                string pelicula = partesCadenaLeida[0];
                
                if( !tn.esta(pelicula) ) {
                    tn.inserta(pelicula, numVerticesOut);
                    
                    // aumento el número de vertices
                    numVerticesOut++;
                }
                
                Lista<string> actores;
                for ( int i = 1; i < sizeLine; i++) {
                    string actor = partesCadenaLeida[i];
                    
                    if( !tn.esta(actor) ) {
                        tn.inserta(actor, numVerticesOut);
                        
                        actores.ponDr(actor);
                        
                        // aumento el número de vertices
                        numVerticesOut++;
                    }
                }
                
                aristasOut.inserta(pelicula, actores);
            }
        }
        
        inputFile.close();
    }
}

string* GrafoNombres::partes(const string& cadena, int& outsize) {
    
    string* partes = split(cadena, "/", outsize);
    
    return partes;
}
