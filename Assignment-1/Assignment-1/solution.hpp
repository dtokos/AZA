#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct _vector {
	int x;
	int y;
};
typedef struct _vector Vector;

struct _node {
	int value;
	int inc;
	int dec;
	bool visited;
};
typedef struct _node Node;

Node *createMap(int init, Vector size);
int findLongestPath(Node *map, Vector size);

#endif
