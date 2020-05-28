#import <XCTest/XCTest.h>
#include "solution.hpp"

@interface SolutionTests : XCTestCase

@end

@implementation SolutionTests

-(void)testCreateMap1 {
	int expected[] = {
		3525, 2227, 35951, 9308, 
		42730, 58974, 32071, 45993,
		41551, 36086, 19433, 15661,
		60446, 11397, 2794, 12939
	};
	int *map = createMap(47, Vector{4, 4});
	XCTAssertEqual(memcmp(map, expected, 16), 0);
}

-(void)testCreateMap2 {
	int expected[] = {
		7425, 32579, 18556, 15423, 
		42596, 48924, 64765, 7637,
		48479, 31390, 60455, 12072,
		53419, 8668, 60267, 63509
	};
	int *map = createMap(99, Vector{4, 4});
	XCTAssertEqual(memcmp(map, expected, 16), 0);
}

-(void)testCreateMap3 {
	int expected[] = {975};
	int *map = createMap(13, Vector{1, 1});
	XCTAssertEqual(memcmp(map, expected, 1), 0);
}

-(void)testCreateMap4 {
	int expected[] = {
		58027, 26583, 27615, 39478, 
		11685, 24394, 60051, 47309,
		9177, 32905, 43006, 14137,
		11683, 24244, 48801, 55540
	};
	int *map = createMap(4269, Vector{4, 4});
	XCTAssertEqual(memcmp(map, expected, 16), 0);
}

- (void)testAcceptance1 {
	Vector size = {4, 4};
	int map[] = {
		3525, 2227, 35951, 9308, 
		42730, 58974, 32071, 45993,
		41551, 36086, 19433, 15661,
		60446, 11397, 2794, 12939
	};
	XCTAssertEqual(10, findLongestPath(map, size));
}

@end
