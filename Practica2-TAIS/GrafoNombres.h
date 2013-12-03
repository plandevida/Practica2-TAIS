//
//  GrafoNombres.h
//  Practica2-TAIS
//
//  Created by Daniel Serrano Torres on 03/12/13.
//  Copyright (c) 2013 zombies-software. All rights reserved.
//

#ifndef __Practica2_TAIS__GrafoNombres__
#define __Practica2_TAIS__GrafoNombres__

#include <iostream>

#include "Grafo.h"

class GrafoNombres {
    
public:
    GrafoNombres(string filename, string delimiter);
    
    ~GrafoNombres();
    
    bool contiene(string s) const;      // existe un vértice de nombre s?
    int indice(string s) const;         // devuelve el número asociado al vértices
    const string& nombre(int v) const;  // devuelve el nombre asociado al número v
    const Grafo& G() const;             // devuelve el grafo de números
    
};

#endif /* defined(__Practica2_TAIS__GrafoNombres__) */
