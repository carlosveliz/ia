//
//  Packing.h
//  BinPacking
//
//  Created by José Luis Canepa on 2/9/13.
//  Copyright (c) 2013 José Luis Canepa. All rights reserved.
//

#include "PackingFile.h"

#ifndef PACKING_H
#define PACKING_H

// Algoritmo de Packing
int PackingStart();
int PackingStartWithBounds(int w, int h);
int PackingStartWithFile(PackingFile *packingFile);

#endif // PACKING_H
