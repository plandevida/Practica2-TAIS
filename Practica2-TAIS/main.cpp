//
//  main.cpp
//  Practica2-TAIS
//
//  Created by Daniel Serrano Torres on 03/12/13.
//  Copyright (c) 2013 zombies-software. All rights reserved.
//

#include <iostream>
#include <string>

//#include "SplitString.h"
//#include "GrafoNombres.h"

using namespace std;

void gradoSeparacion(string& origen) {
    
//    GrafoNombres pelis("movies.txt", "/");
    
    
    cout << "Escriba el nombre del actor: ";
    
    cin >> origen;
    
    cout << "DEBUG --> " << origen;
    
    cout << endl;
    
    while ( origen != "" ) {
        
        cout << "Escriba el nombre del actor: ";
        
        cin >> origen;
    
        cout << "DEBUG --> " << origen;
        
        cout << endl;
    }
    
    cout << "fuera del bucle";
    
}

int main(int argc, const char * argv[])
{
    
    string nombreOrigen = "";

    gradoSeparacion(nombreOrigen);
    
    return 0;
}

