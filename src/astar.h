#ifndef _ASTAR_H_
#define _ASTAR_H_

#include <vector>
#include "node.h"
#include "map.h"

class AStar {
public:
    static std::vector<Node *> findPath(Map *map);

private:
    static int heuristic(Node *node1, Node *node2);

    static bool containsNode(std::vector<Node *> &vector, Node *node);

    static Node *getLowestF(std::vector<Node *> &vector);

    static std::vector<Node *> getNeighbors(Node *node, Map *map);

    static std::vector<Node *> backtrack(Node *node);
};

#endif /* _ASTAR_H_ */
