#include <stdio.h>
#include <string.h>
#include <Ncurses.h>
#include <time.h>

#include "Packing.h"

/*
struct Node {
	int w;
	int h;
	int x;
	int y;
    bool root;
	bool used;
	bool isNull;
	struct Node *left;
	struct Node *right;
};

struct Box {
	int w;
	int h;
	int x;
	int y;
    struct Node *fit;
};

struct Node *nodeNew(int w, int h){
    struct Node *node = malloc(sizeof(struct Node));
    node->w = w;
    node->h = h;
    return node;
}

struct Box blocks[3];
struct Node root;


struct Node splitNode(struct Node node, int w, int h){
	node.used = true;
    struct Node new1, new2;

    node.left = &new1;
    node.left->x = node.x;
	node.left->y = node.y + h;
	node.left->w = node.w;
	node.left->h = node.h - h;
    
    node.right = &new2;
	node.right->x = node.x + w;
	node.right->y = node.y;
	node.right->w = node.w - w;
	node.right->h = node.h;
    
	return node;
    
}
int caca =0;
struct Node findNode(struct Node root,  int w, int h) {
	if (root.used){
        struct Node temp, new, new2;
        root.right = &new;
        temp = findNode(*root.right, w, h);
        if (temp.isNull){
            root.left = &new2;
            temp = findNode(*root.left, w, h);
        }
		return temp;
	}else if ((w <= root.w) && (h <= root.h)) {
        caca++;
        printf("\n %d else if", caca);
		return root;
	}
	else {
		printf("\n conflicto con el bloque de w:%d h:%d \n", w, h);
		root.isNull = 1;
		return root;
	}
}

void fit(struct Box block){
	block.x = block.y = 0;
	struct Node node, tmp;
    node = findNode(root, block.w, block.h);
    if (node.isNull == 0){
        *block.fit = splitNode(node, block.w, block.h);
        printf("\n x = %d \n y = %d\n w = %d\n h = %d\n", tmp.x, tmp.y, tmp.w, tmp.h);
    }
    
}

// recibe las dimensiones del bloque a insertar
void Packer(int w, int h){

    struct Box rect;
    rect.w = w;
    rect.h = h;
	fit(rect);
}*/


int main(int argc, char const *argv[])
{
    PackingFile *packingFile = PackingFileNewWithFilename("Sample/c1-p1.txt");
    //PackingStartWithBounds(16, 1000);
    
    if (packingFile == NULL)
    {
        return 1;
    }
    
    PackingFilePrint(packingFile, true);
    PackingFileFree(packingFile);
    
	return 0;
}



