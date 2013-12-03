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

void gradoSeparacion(const string& origen) {
    
    GrafoNombres pelis("movies.txt", "/");
    
}

int main(int argc, const char * argv[])
{
    
    string nombreOrigen = "MacIntyre Dixon";

    gradoSeparacion(nombreOrigen);
    
    return 0;
}

