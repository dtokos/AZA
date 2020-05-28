#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _vector {
	int x;
	int y;
};
typedef struct _vector Vector;

int *createMap(int init, Vector size);
int findLongestPath(int *map, Vector size);

#endif
