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
    NodeStatusUndefined = 0b000,
    NodeStatusPartial   = 0b001,
    NodeStatusComplete  = 0b011,
    NodeStatusRoot      = 0b111,
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
void NodeSetBox(Node *node, Box *box);
void NodeSetLeftChild(Node *node, Node *child);
void NodeSetRightChild(Node *node, Node *child);

// Descriptor
void NodePrint(Node *node);

// Destructor
void NodeFree(Node *node);
void NodeFreeRecursive(Node *root);

#endif // NODE_H
