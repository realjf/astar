#include "node.h"

Node::Node(int x, int y) {
    this->x = x;
    this->y = y;
    this->f = 0;
    this->g = 0;
    this->h = 0;
    this->parent = nullptr;
}

int Node::getDistance(Node *otherNode) const {
    int dx = std::abs(x - otherNode->x);
    int dy = std::abs(y - otherNode->y);
    return dx + dy;
}

void Node::setWalkable(bool walkable) {
    this->walkable = walkable;
}
