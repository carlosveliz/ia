//
//  PackingFile.c
//  LastDay
//
//  Created by José Luis Canepa on 2/9/13.
//  Copyright (c) 2013 Carlos Véliz. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "PackingFile.h"

PackingFile *PackingFileNewWithFile(FILE *file)
{
    PackingFile *packingFile = malloc(sizeof(PackingFile));
    
    packingFile->length = INT_MAX;
    
    return packingFile;
}

PackingFile *PackingFileNewWithFilename(char *filename)
{
    FILE *file = fopen(filename, "r");
    
    PackingFile *packingFile = PackingFileNewWithFile(file);
    
    fclose(file);
    
    return packingFile;
}

void PackingFileFree(PackingFile *packingFile)
{
    free(packingFile);
}