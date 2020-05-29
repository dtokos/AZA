#include <stdio.h>
#include "solution.hpp"

int main(int argc, const char * argv[]) {
	int nMaps, init;
	Vector size;
	
	scanf("%i", &nMaps);
	
	for (int i = 0; i < nMaps; ++i) {
		scanf("%i %i %i", &init, &size.y, &size.x);
		Node *map = createMap(init, size);
		printf("%i\n", findLongestPath(map, size));
		free(map);
	}
	
	return 0;
}
