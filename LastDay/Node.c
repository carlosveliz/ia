//
//  binpacking.c
//  BinPacking
//
//  Created by José Luis Canepa on 2/9/13.
//  Copyright (c) 2013 José Luis Canepa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

Node *NodeNew(int w, int h, int x, int y)
{
    Node *node = (Node*)malloc(sizeof(Node));
    
    node->w = w;
    node->h = h;
    node->x = x;
    node->y = y;
    
    // Inicializar hijos
    node->parent    = NULL;
    node->left      = NULL;
    node->right     = NULL;
    
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
    memcpy(node, &box, sizeof(Box));
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

void NodePrint(Node *node)
{
    char *name = "Node";
    
    if (node->status == NodeStatusRoot)
    {
        name = "Root";
    }
    
    if (node->status & NodeStatusComplete)
    {
        printf("%s (w:%d h:%d) (x:%d y:%d)", name, node->w, node->h, node->x, node->y);
    }
    else
    {
        printf("%s (w:%d h:%d) not placed", name, node->w, node->h);
    }
}

void NodeFree(Node *node)
{
    // Indica al padre que debe indefinir su nodo
    Node *parent = node->parent;
    
    if (parent)
    {
        if (parent->left == node)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        
        node->parent = NULL;
    }
    
    // Liberar
    free(node);
}

void NodeFreeRecursive(Node *node)
{
    if (node->left)
    {
        NodeFreeRecursive(node->left);
    }
    
    if (node->right)
    {
        NodeFreeRecursive(node->right);
    }
    
    NodeFree(node);
}
