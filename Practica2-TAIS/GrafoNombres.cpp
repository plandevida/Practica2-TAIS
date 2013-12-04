//
//  GrafoNombres.cpp
//  Practica2-TAIS
//
//  Created by Daniel Serrano Torres on 03/12/13.
//  Copyright (c) 2013 zombies-software. All rights reserved.
//

#include "GrafoNombres.h"

using namespace std;

    GrafoNombres::GrafoNombres(string filename, string delimiter) {
        
        read(filename);
        
//        int numeroVertices = 0;
//        
//        for ( int i = 1; i < numeroVertices; i++) {
//            string cadena = "";
//            
//            tn.inserta(cadena, i);
//        }
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
    
//    const Grafo& G() const {
//        
//        return Grafo(0,0);
//    }
    
    string GrafoNombres::read(const string& file) {
        
        string cadenaLeida = "";
        
        ifstream inputFile;
        inputFile.open( file );
        
        if ( inputFile.is_open() )  {
            
        while ( getline(inputFile, cadenaLeida) ) { std::cout << cadenaLeida << std::endl; }
            
            inputFile.close();
        }
        
        return cadenaLeida;
    }