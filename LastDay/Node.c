//
//  binpacking.c
//  BinPacking
//
//  Created by José Luis Canepa on 2/9/13.
//  Copyright (c) 2013 José Luis Canepa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

Node *NodeNew(int w, int h, int x, int y)
{
    Node *node = (Node*)malloc(sizeof(Node));
    
    node->w = w;
    node->h = h;
    node->x = x;
    node->y = y;
    
    node->status = NodeStatusComplete;
    
    return node;
}

Node *NodeNewPartial(int w, int h)
{
    Node *node = NodeNew(w, h, 0, 0);
    
    node->status = NodeStatusPartial;
    
    return node;
}

Node *NodeNewRoot()
{
    Node *node = NodeNew(0, 0, 0, 0);
    
    node->status = NodeStatusRoot;
    
    return node;
}

void NodeSetBox(Node *node, Box box)
{
    node->w = box.w;
    node->h = box.h;
    node->x = box.x;
    node->y = box.y;
}

void NodeSetLeftChild(Node *node, Node *child)
{
    node->left = child;
    child->parent = node;
}

void NodeSetRightChild(Node *node, Node *child)
{
    node->right = child;
    child->parent = node;
}

void NodeFree(Node *node)
{
    // Indica al padre que debe indefinir su nodo
    Node *parent = node->parent;
    
    if (parent->left == node)
    {
        parent->left = NULL;
    }
    else
    {
        parent->right = NULL;
    }
    
    node->parent = NULL;
    
    // Liberar
    free(node);
}
