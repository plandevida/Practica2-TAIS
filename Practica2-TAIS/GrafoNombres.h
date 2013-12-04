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
//#include <string>

#include "Tabla.h"
#include "Grafo.h"

using namespace std;

class GrafoNombres {
    
private:
    Tabla<string, uint> tn;  // string -> index
    string* nombres;         // index  -> string
    Grafo* _G;               // grafo con vértices numerados
    
public:
    GrafoNombres(string filename, string delimiter) {
        
        read(filename);
    }
    
    ~GrafoNombres(){
        delete _G;
        delete nombres;
    }
    
    bool contiene(string s) const{      // existe un vértice de nombre s?
        
        return tn.esta(s);
    }
    
    int indice(string s) const {        // devuelve el número asociado al vértices
        
        return tn.consulta(s);
    }
    
    const string& nombre(int v) const {  // devuelve el nombre asociado al número v
        
        return nombres[v];
    }
    
    const Grafo& G() const {             // devuelve el grafo de números
        return NULL;
    }
    
private:
    string read(const string& file) {
        
        string cadenaLeida = "";
        
        ifstream inputFile;
        inputFile.open( file );
        
        if ( inputFile.is_open() )  {
        
        while ( getline(inputFile, cadenaLeida) ) { std::cout << cadenaLeida << std::endl; }
        
            inputFile.close();
        }
        return cadenaLeida;
    }
};

#endif /* defined(GrafoNombres_H_) */
