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
        
//        string a[] = {"1","2", "3", "4", "5", "6", "7", "8", "9", "10"};
//        string b[] = {"11","12", "13", "14", "15", "16", "17", "18", "19", "20"};
//        
//        string* pa = a;
//        string* pb = b;
//        
//        for (int j = 0; j< 20 ; j++) {
//            if ( j< 10)
//                cout << a[j] << " ";
//            else
//                cout << b[j-10] << " ";
//        }
//        
//        string* c = copiarArray(pa, 10, pb, 10);
//        
//        for ( int h = 0; h < 20; h++) {
//            cout << c[h] << " ";
//        }
        
        Tabla<string, Lista<string>> tablaPelisActores = read(filename, delimiter);
    }
    
    GrafoNombres::~GrafoNombres() {
        
        if ( _G != NULL )
            delete _G;
        if ( nombres != NULL )
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

    Tabla<string, Lista<string>>& GrafoNombres::read(const string& file, const string& delimiter) {
        
        Tabla<string, Lista<string>> pelisActores;
        
        ifstream inputFile;
        inputFile.open( file );
        
        if ( inputFile.is_open() )  {
            
            string cadenaLeida;
            
            while ( getline(inputFile, cadenaLeida) ) {
                
                int sizeLine;
                
                string* partesCadenaLeida = partes(cadenaLeida, sizeLine);
                
                cout << "++Peli añadir:" << partesCadenaLeida[0] << endl;
                
                Lista<string> actores;
                for ( int i = 1; i < sizeLine; i++) {
                    actores.ponDr(partesCadenaLeida[i]);
                }
                
                cout << "--Lista de actores de peli creada:" << partesCadenaLeida[0] << endl;
                
                pelisActores.inserta(partesCadenaLeida[0], actores);
                
                cout << "**Pelia añadida:" << partesCadenaLeida[0] << endl;
            }
            
            inputFile.close();
        }
        
        return pelisActores;
    }

    string* GrafoNombres::partes(const string& cadena, int& outsize) {
        
        string* partes = split(cadena, "/", outsize);
        
        return partes;
    }

    string* GrafoNombres::copiarArray(const string* destino, const int tamDestino, const string* origen, const int tamOrigen) {
        
        int tamTotal = tamDestino + tamOrigen;
        
        string* nuevoArray = new string[tamTotal];
        
        int i = 0;
        while( i < tamDestino ) {
            
            nuevoArray[i] = destino[i];
            
            i++;
        }
        
        int z = 0;
        for ( int j = i; j < (tamTotal) ; j++ ) {
            
            nuevoArray[j] = origen[z];
            
            z++;
        }
        
        return nuevoArray;
    }
