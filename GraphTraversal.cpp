/*
 * GraphTraversal.cpp
 *
 *  Created on: Jan 31, 2019
 *      Author: sandip.pal
 */

#include "GraphTraversal.h"
#include "GraphStructure.hpp"
namespace std {

GraphTraversal::GraphTraversal(int vertices) {
	

	mpList = new GraphAdjacencyList(vertices);

}

GraphTraversal::~GraphTraversal() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
