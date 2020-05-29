#import <XCTest/XCTest.h>
#include "solution.hpp"

#define AssertMap(init, size, expected) \
do { \
	Node *map = createMap(init, size); \
	for (int i = 0; i < size.x * size.y; ++i) { \
		XCTAssertEqual(map[i].value, expected[i]); \
		XCTAssertEqual(map[i].inc, 0); \
		XCTAssertEqual(map[i].dec, 0); \
		XCTAssertFalse(map[i].visited); \
	} \
} while (0)

@interface SolutionTests : XCTestCase

@end

@implementation SolutionTests

-(void)testCreateMap1 {
	Vector size = Vector{4, 4};
	int expected[] = {
		3525, 2227, 35951, 9308, 
		42730, 58974, 32071, 45993,
		41551, 36086, 19433, 15661,
		60446, 11397, 2794, 12939
	};
	AssertMap(47, size, expected);
}

-(void)testCreateMap2 {
	Vector size = Vector{4, 4};
	int expected[] = {
		7425, 32579, 18556, 15423, 
		42596, 48924, 64765, 7637,
		48479, 31390, 60455, 12072,
		53419, 8668, 60267, 63509
	};
	AssertMap(99, size, expected);
}

-(void)testCreateMap3 {
	Vector size = Vector{1, 1};
	int expected[] = {975};
	AssertMap(13, size, expected);
}

-(void)testCreateMap4 {
	Vector size = Vector{4, 4};
	int expected[] = {
		58027, 26583, 27615, 39478, 
		11685, 24394, 60051, 47309,
		9177, 32905, 43006, 14137,
		11683, 24244, 48801, 55540
	};
	AssertMap(4269, size, expected);
}

- (void)testAcceptance1 {
	Vector size = {4, 4};
	Node *map = createMap(47, size);
	XCTAssertEqual(10, findLongestPath(map, size));
}

-(void)testAcceptance2 {
	Vector size = {4, 4};
	Node *map = createMap(99, size);
	XCTAssertEqual(9, findLongestPath(map, size));
}

-(void)testAcceptance3 {
	Vector size = {1, 1};
	Node *map = createMap(13, size);
	XCTAssertEqual(1, findLongestPath(map, size));
}

-(void)testAcceptance4 {
	Vector size = {4, 4};
	Node *map = createMap(4269, size);
	XCTAssertEqual(12, findLongestPath(map, size));
}

-(void)testAcceptance5 {
	Vector size = {10, 10};
	Node *map = createMap(65238, size);
	XCTAssertEqual(16, findLongestPath(map, size));
}

-(void)testAcceptance6 {
	Vector size = {10, 10};
	Node *map = createMap(9745, size);
	XCTAssertEqual(13, findLongestPath(map, size));
}

-(void)testAcceptance7 {
	Vector size = {10, 10};
	Node *map = createMap(9968, size);
	XCTAssertEqual(13, findLongestPath(map, size));
}

-(void)testAcceptance8 {
	Vector size = {10, 10};
	Node *map = createMap(22885, size);
	XCTAssertEqual(11, findLongestPath(map, size));
}

-(void)testAcceptance9 {
	Vector size = {10, 10};
	Node *map = createMap(52703, size);
	XCTAssertEqual(13, findLongestPath(map, size));
}

-(void)testAcceptance10 {
	Vector size = {10, 10};
	Node *map = createMap(47499, size);
	XCTAssertEqual(10, findLongestPath(map, size));
}

@end
