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
#include <string.h>

#include "PackingFile.h"

// Separa la linea de largo length, en la parte "left" y "right" como numeros.
void ParseTabularLinePair(char *line, size_t length, int *left, int *right);

PackingFile *PackingFileNewWithFile(FILE *file)
{
    // Inicializar con nada
    PackingFile *packingFile = malloc(sizeof(PackingFile));
    
    packingFile->width  = 0;
    packingFile->length = INT_MAX;
    packingFile->lengthOptimum = INT_MAX;
    packingFile->count  = 0;
    packingFile->boxes  = NULL;
    
    // Leer primera linea
    {
        size_t length;
        char *line = fgetln(file, &length);
        
        packingFile->count = atoi(line);
    }
    // Leer dos numeros
    {
        size_t length;
        char *line = fgetln(file, &length);
        
        int left, right;
        
        ParseTabularLinePair(line, length, &left, &right);
        
        packingFile->width          = left;
        packingFile->lengthOptimum  = right;
    }
    
    // Cargar N cajas
    {
        Box *boxes = malloc(sizeof(Box)*packingFile->count);
        
        for (int box = 0; box < packingFile->count; box++)
        {
            size_t length;
            char *line = fgetln(file, &length);
            int left, right;
            
            ParseTabularLinePair(line, length, &left, &right);
            
            (boxes+box)->w = left;
            (boxes+box)->h = right;
        }
        
        packingFile->boxes = boxes;
    }
    
    return packingFile;
}

PackingFile *PackingFileNewWithFilename(char *filename)
{
    FILE *file = fopen(filename, "r");
    
    if (file == NULL)
    {
        fprintf(stderr, "No se pudo cargar el archivo %s", filename);
        return NULL;
    }
    
    PackingFile *packingFile = PackingFileNewWithFile(file);
    
    fclose(file);
    
    return packingFile;
}

void PackingFilePrint(PackingFile *packingFile, bool printBoxes)
{
    printf("Packing Problem.\n  Limited to: %d wide\n  Optimum: %d\n", packingFile->width, packingFile->lengthOptimum);
    
    if (printBoxes)
    {
        printf("\nLoaded %d Nodes:\n", packingFile->count);
        
        for (int i=0; i < packingFile->count; i++)
        {
            Box box = packingFile->boxes[i];
            
            printf("\tBox %d %d\n", box.w, box.h);
        }
    }
}

void PackingFileFree(PackingFile *packingFile)
{
    if (packingFile->count)
    {
        free(packingFile->boxes);
    }
    
    free(packingFile);
}



void ParseTabularLinePair(char *line, size_t length, int *left, int *right)
{
    static char tmp[10];
    
    // Encontrar donde esta el \t (punto tab)
    int tab = 0;
    
    for (int i=0; i < length; i++)
    {
        if (line[i] == '\t')
        {
            tab = i;
            break;
        }
    }
    
    // Copiar [0, tab] bytes
    memcpy(tmp, line, sizeof(char)*tab);
    *left = atoi(tmp);
    
    // Copiar [tab+1, n] bytes
    memcpy(tmp, line+tab+1, sizeof(char)*(length-tab));
    
    *right = atoi(tmp);
}