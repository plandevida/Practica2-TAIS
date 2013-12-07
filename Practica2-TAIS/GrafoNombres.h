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
    Grafo* _G;               // grafo con veÌ?rtices numerados
    
public:
    GrafoNombres(string filename, string delimiter);
    
    ~GrafoNombres();
    
    bool contiene(string s) const;      // existe un veÌ?rtice de nombre s?
    
    int indice(string s) const;        // devuelve el nuÌ?mero asociado al veÌ?rtices
    
    const string& nombre(int v) const;  // devuelve el nombre asociado al nuÌ?mero v
    
    const Grafo* G() const;             // devuelve el grafo de nuÌ?meros
    
private:
	bool readNumeroVertices(const string& file, const string& delimiter, int& numVerticesOut);
	bool readAristas(const string& file, const string& delimiter);
};

#endif /* defined(GrafoNombres_H_) */
