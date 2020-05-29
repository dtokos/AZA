#include "solution.hpp"

struct _progress {
	int depth;
	int *longest;
};
typedef struct _progress Progress;

Node initNode(int value);
bool isLocalMin(Node *map, Vector size, Vector position);
Node *at(Node *map, Vector size, Vector position);
int dfsIncDec(Node *map, Vector size, Vector position, Node *parent, Progress progress);
int dfsDec(Node *map, Vector size, Vector position, Node *parent);
void resetDec(Node *map, Vector size);
bool isOutOfMap(Vector size, Vector position);
int max(int a, int b);

Node *createMap(int init, Vector size) {
	Node *map = (Node *)malloc(size.x * size.y * sizeof(Node));
	
	map[0] = initNode(init);
	for (int i = 1; i < size.x * size.y; ++i)
		map[i] = initNode(map[i - 1].value);
	
	return map;
}

Node initNode(int value) {
	return (Node){.value=(value * 75) % 65537, .inc=0, .dec=0, .visited=false};
}

int findLongestPath(Node *map, Vector size) {
	int longest = 0;
	Vector pos = (Vector){.x=0, .y=0};
	Progress progress = (Progress){.depth=0, .longest=&longest};
	
	for (pos.y = 0; pos.y < size.y; ++pos.y)
		for (pos.x = 0; pos.x < size.x; ++pos.x)
			if (at(map, size, pos)->inc == 0 && isLocalMin(map, size, pos))
				longest = dfsIncDec(map, size, pos, at(map, size, pos), progress);
	
	return longest;
}

bool isLocalMin(Node *map, Vector size, Vector pos) {
	const int curr = at(map, size, pos)->value;
	return (
			(pos.y - 1 < 0       || curr < at(map, size, (Vector){.x=pos.x, .y=pos.y - 1})->value) && // Top
			(pos.x - 1 < 0       || curr < at(map, size, (Vector){.x=pos.x - 1, .y=pos.y})->value) && // Left
			(pos.x + 1 >= size.x || curr < at(map, size, (Vector){.x=pos.x + 1, .y=pos.y})->value) && // Right
			(pos.y + 1 >= size.y || curr < at(map, size, (Vector){.x=pos.x, .y=pos.y + 1})->value)    // Bottom
			
			//(pos.x - 1 < 0       || pos.y - 1 < 0       || curr < at(map, size, Vector{pos.x - 1, pos.y - 1})->value) && // Top Left
			//(pos.x + 1 >= size.x || pos.y - 1 < 0       || curr < at(map, size, Vector{pos.x + 1, pos.y - 1})->value) && // Top Right
			//(pos.x - 1 < 0       || pos.y + 1 >= size.y || curr < at(map, size, Vector{pos.x - 1, pos.y + 1})->value) && // Bottom Left
			//(pos.x + 1 >= size.x || pos.y + 1 >= size.y || curr < at(map, size, Vector{pos.x + 1, pos.y + 1})->value) // Bottom Right
	);
}

Node *at(Node *map, Vector size, Vector position) {
	return map + position.y * size.x + position.x;
}

int dfsIncDec(Node *map, Vector size, Vector pos, Node *parent, Progress progress) {
	if (isOutOfMap(size, pos)) return 0;
	
	Node *curent = at(map, size, pos);
	
	if (curent->visited || curent->value < parent->value) return 0;
	
	int longest = 0;
	curent->visited = true;
	++progress.depth;
	
	longest = max(longest, dfsIncDec(map, size, (Vector){.x=pos.x, .y=pos.y - 1}, curent, progress)); // Top
	longest = max(longest, dfsIncDec(map, size, (Vector){.x=pos.x - 1, .y=pos.y}, curent, progress)); // Left
	longest = max(longest, dfsIncDec(map, size, (Vector){.x=pos.x + 1, .y=pos.y}, curent, progress)); // Right
	longest = max(longest, dfsIncDec(map, size, (Vector){.x=pos.x, .y=pos.y + 1}, curent, progress)); // Bottom
	
	//longest = max(longest, dfsIncDec(map, size, Vector{pos.x - 1, pos.y - 1}, curent)); // Top Left
	//longest = max(longest, dfsIncDec(map, size, Vector{pos.x + 1, pos.y - 1}, curent)); // Top Right
	//longest = max(longest, dfsIncDec(map, size, Vector{pos.x - 1, pos.y + 1}, curent)); // Bottom Left
	//longest = max(longest, dfsIncDec(map, size, Vector{pos.x + 1, pos.y + 1}, curent)); // Bottom Right
	
	curent->visited = false;
	dfsDec(map, size, pos, curent);
	*progress.longest = max(*progress.longest, progress.depth + curent->dec - 1);
	
	resetDec(map, size);
	curent->inc = longest + 1;
	
	return *progress.longest;
}

int dfsDec(Node *map, Vector size, Vector pos, Node *parent) {
	if (isOutOfMap(size, pos)) return 0;
	
	Node *curent = at(map, size, pos);
	
	if (curent->value > parent->value) return 0;
	if (curent->dec != 0 || curent->visited) return curent->dec;
	
	int longest = 0;
	curent->visited = true;
	
	longest = max(longest, dfsDec(map, size, (Vector){.x=pos.x, .y=pos.y - 1}, curent)); // Top
	longest = max(longest, dfsDec(map, size, (Vector){.x=pos.x - 1, .y=pos.y}, curent)); // Left
	longest = max(longest, dfsDec(map, size, (Vector){.x=pos.x + 1, .y=pos.y}, curent)); // Right
	longest = max(longest, dfsDec(map, size, (Vector){.x=pos.x, .y=pos.y + 1}, curent)); // Bottom
	
	//longest = max(longest, dfsDec(map, size, Vector{pos.x - 1, pos.y - 1}, curent)); // Top Left
	//longest = max(longest, dfsDec(map, size, Vector{pos.x + 1, pos.y - 1}, curent)); // Top Right
	//longest = max(longest, dfsDec(map, size, Vector{pos.x - 1, pos.y + 1}, curent)); // Bottom Left
	//longest = max(longest, dfsDec(map, size, Vector{pos.x + 1, pos.y + 1}, curent)); // Bottom Right
	
	curent->dec = longest + 1;
	curent->visited = false;
	
	return curent->dec;
}

void resetDec(Node *map, Vector size) {
	for (int y = 0; y < size.y; ++y)
		for (int x = 0; x < size.x; ++x)
			at(map, size, (Vector){.x=x, .y=y})->dec = 0;
}

bool isOutOfMap(Vector size, Vector pos) {
	return (
		pos.x < 0 || pos.x >= size.x ||
		pos.y < 0 || pos.y >= size.y
	);
}

int max(int a, int b) {
	return a > b ? a : b;
}
