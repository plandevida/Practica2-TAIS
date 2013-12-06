//
//  main.cpp
//  Practica2-TAIS
//
//  Created by Daniel Serrano Torres on 03/12/13.
//  Copyright (c) 2013 zombies-software. All rights reserved.
//

#include <iostream>
//#include <string>

#include "GrafoNombres.h"

using namespace std;

const bool MANUAL_DEBUG = false;

void gradoSeparacion(string& origen) {
    
    GrafoNombres pelis("movies.txt", "/");
    
    /*
    cout << "Escriba el nombre del actor: ";
    
    getline(cin, origen);
    
    if ( MANUAL_DEBUG ) cout << "DEBUG --> " << origen;
    
    cout << endl;
    
    while ( origen != "" && origen != "q" ) {
        
        cout << "Escriba el nombre del actor: ";
        
        getline(cin, origen);
    
        if ( MANUAL_DEBUG ) {
            
            cout << "DEBUG --> " << origen;
            
            cout << " origen != \"\" : " << (origen != "") << " o " << " origen != \"q\" " << (origen != "q") << endl;
        }
        
        cout << endl;
    }
    
    if ( MANUAL_DEBUG ) cout << "fuera del bucle" << endl;
     */
    
}

int main(int argc, const char * argv[])
{
    
    string nombreOrigen = "";

    gradoSeparacion(nombreOrigen);
    
    return 0;
}
	