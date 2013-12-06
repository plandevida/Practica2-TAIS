//
//  GrafoNombres.h
//  Practica2-TAIS
//
//  Created by Daniel Serrano Torres on 03/12/13.
//  Copyright (c) 2013 zombies-software. All rights reserved.
//

#ifndef GRAFONOMBRES_H_
#define GRAFONOMBRES_H_

#include <iostream>
#include <string>

#include "Tabla.h"
#include "Grafo.h"

using namespace std;

class GrafoNombres {
    
private:
    Tabla<string, uint> tn;  // string -> index
    string* nombres;         // index  -> string
    Grafo* _G;               // grafo con vértices numerados
    
public:
    GrafoNombres(string filename, string delimiter);
    
    ~GrafoNombres();
    
    bool contiene(string s) const;      // existe un vértice de nombre s?
    
    int indice(string s) const;        // devuelve el número asociado al vértices
    
    const string& nombre(int v) const;  // devuelve el nombre asociado al número v
    
    const Grafo* G() const;             // devuelve el grafo de números
    
private:
    void crearGrafo(const string& file, const string& delimiter);
    void read(const string& file, const string& delimiter, int& numVerticesOut, Tabla<string, Lista<string>> aristasOut);
    string* partes(const string& cadena, int& outsize);
};

#endif /* defined(GrafoNombres_H_) */
