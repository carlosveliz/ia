//
//  Packing.c
//  BinPacking
//
//  Created by José Luis Canepa on 2/9/13.
//  Copyright (c) 2013 José Luis Canepa. All rights reserved.
//

#include <stdio.h>
#include "Packing.h"
#include "Node.h"

void PackingStart()
{
    PackingStartWithBounds(16, 1000);
}

void PackingStartWithBounds(int w, int h)
{
    Node *root = NodeNewPartial(0, 0);

    /*
    root.w = w;
    root.h = h;
    root.x = 0;
    root.y = 0;
    root.used = false;
    Packer(2,12);
    Packer(7,12);
    Packer(8,6);
    Packer(3,6);
    Packer(3,5);
    Packer(5,5);
    Packer(3,12);
    Packer(3,7);
    Packer(5,7);
    Packer(2,6);
    Packer(3,2);

    Packer(300,200);

    Packer(4,2);
    Packer(3,4);
    Packer(4,4);
    Packer(9,2);
    Packer(11,2);*/
    
    NodeFreeRecursive(root);
}