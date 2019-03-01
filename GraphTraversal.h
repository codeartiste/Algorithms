/*
 * GraphTraversal.h
 *
 *  Created on: Jan 31, 2019
 *      Author: sandip.pal
 */


#ifndef ALGORITHMS_ALGORITHMS_ALGORITHMS_GRAPHTRAVERSAL_H_
#define ALGORITHMS_ALGORITHMS_ALGORITHMS_GRAPHTRAVERSAL_H_

#include "GraphStructure.hpp"

namespace std {

class GraphTraversal {

private:
    int nodes;
public:
	GraphTraversal(int vertices);
	virtual ~GraphTraversal();
	GraphAdjacencyList *mpList;
};

} /* namespace std */

#endif /* ALGORITHMS_ALGORITHMS_ALGORITHMS_GRAPHTRAVERSAL_H_ */
