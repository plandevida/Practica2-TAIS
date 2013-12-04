//
//  main.cpp
//  Practica2-TAIS
//
//  Created by Daniel Serrano Torres on 03/12/13.
//  Copyright (c) 2013 zombies-software. All rights reserved.
//

#include <iostream>

#include "SplitString.h"
#include "GrafoNombres.h"

void gradoSeparacion(string& origen) {
    
//    GrafoNombres pelis("movies.txt", "/");
    
    
    std::cout << "Escriba el nombre del actor: ";
    
    std::cin >> origen;
    
    std::cout << endl;
    
    while ( origen != "" ) {
        
        std::cout << "Escriba el nombre del actor: ";
        
        std::cin >> origen;
        
        std::cout << endl;
    }
    
}

int main(int argc, const char * argv[])
{
    
    string nombreOrigen = "";

    gradoSeparacion(nombreOrigen);
    
    return 0;
}

