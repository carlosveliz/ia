//
//  PackingFile.h
//  LastDay
//
//  Created by José Luis Canepa on 2/9/13.
//  Copyright (c) 2013 Carlos Véliz. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#include "Node.h"

#ifndef PACKING_FILE_H
#define PACKING_FILE_H

// Estructura que representa un problema de packing
typedef struct
{
    int width;
    int length;  // Length is the undefined
    int lengthOptimum;
    
    int count;
    Box *boxes;
}PackingFile;

// Constructores
PackingFile *PackingFileNewWithFile(FILE *file);
PackingFile *PackingFileNewWithFilename(char *filename);

// Descriptor
void PackingFilePrint(PackingFile *packingFile, bool printBoxes);

// Destructor
void PackingFileFree(PackingFile *packingFile);

#endif // PACKING_FILE_H
