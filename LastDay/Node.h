//
//  binpacking.h
//  BinPacking
//
//  Created by José Luis Canepa on 2/9/13.
//  Copyright (c) 2013 José Luis Canepa. All rights reserved.
//

#include <stdbool.h>

#ifndef NODE_H
#define NODE_H

// Estado de un nodo
typedef enum
{
    NodeStatusUndefined = 0b00,
    NodeStatusPartial   = 0b01,
    NodeStatusComplete  = 0b01,
    NodeStatusRoot      = 0b10,
}NodeStatus;

// Estructura que representa un sistema de coordenadas
typedef struct
{
    int w, h;
    int x, y;
}Box;

// Estructura que representa un nodo CBJ, polimorfiza con Box
typedef struct Node
{
    int w, h;
    int x, y;
    
    NodeStatus status;
    
    struct Node *parent;
    struct Node *left;
    struct Node *right;
}Node;

// Constructores de Node
Node *NodeNew(int w, int h, int x, int y);
Node *NodeNewPartial(int w, int h);
Node *NodeNewRoot();

// Setters
void NodeSetBox(Node *node, Box box);
void NodeSetLeftChild(Node *node, Node *child);
void NodeSetRightChild(Node *node, Node *child);

// Destructor
void NodeFree();

#endif // NODE_H
