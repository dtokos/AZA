#include "solution.hpp"

int initSpot(int value);
int *mapAt(int col, int row, int *map, Vector size);
int findIncDecPath(int *map, Vector size, Vector position, int *scores, int prev);
int findDecPath(int *map, Vector size, Vector position, int *scores, int prev);
bool isOutOfMap(Vector position, Vector size);
int max(int a, int b);

void printScores(int *scores, Vector size);

int *createMap(int init, Vector size) {
	int *map = (int *)malloc(size.x * size.y * sizeof(int));
	
	map[0] = initSpot(init);
	for (int i = 1; i < size.x * size.y; ++i)
		map[i] = initSpot(map[i - 1]);
	
	return map;
}

int initSpot(int value) {
	return (value * 75) % 65537;
}

int findLongestPath(int *map, Vector size) {
	return 0;
}

