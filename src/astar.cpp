#include "astar.h"
#include <algorithm>
#include <cmath>

int AStar::heuristic(Node *node1, Node *node2) {
    // 曼哈顿距离
    return std::abs(node1->x - node2->x) + std::abs(node1->y - node2->y);
}

bool AStar::containsNode(std::vector<Node *> &vector, Node *node) {
    return std::find(vector.begin(), vector.end(), node) != vector.end();
}

Node *AStar::getLowestF(std::vector<Node *> &vector) {
    Node *lowestFNode = vector[0];
    for (Node *node : vector) {
        if (node->f < lowestFNode->f) {
            lowestFNode = node;
        }
    }
    return lowestFNode;
}

std::vector<Node *> AStar::getNeighbors(Node *node, Map *map) {
    std::vector<Node *> neighbors;
    for (Node *neighbor : node->neighbors) {
        if (map->isWalkable(neighbor->x, neighbor->y)) {
            neighbors.push_back(neighbor);
        }
    }
    return neighbors;
}

std::vector<Node *> AStar::backtrack(Node *node) {
    std::vector<Node *> path;
    Node *currentNode = node;
    while (currentNode != nullptr) {
        path.push_back(currentNode);
        currentNode = currentNode->parent;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<Node *> AStar::findPath(Map *map) {
    std::vector<Node *> openSet;   // 未处理的节点集合
    std::vector<Node *> closedSet; // 已处理的节点集合
    openSet.push_back(map->startNode);

    while (!openSet.empty()) {
        // 从 openSet 中选取 f 值最小的节点
        Node *currentNode = getLowestF(openSet);

        // 如果当前节点是终点，则返回路径
        if (currentNode == map->endNode) {
            return backtrack(currentNode);
        }

        // 将当前节点从 openSet 中移除，并加入 closedSet 中
        openSet.erase(std::remove(openSet.begin(), openSet.end(), currentNode), openSet.end());
        closedSet.push_back(currentNode);

        // 处理当前节点的邻居节点
        std::vector<Node *> neighbors = getNeighbors(currentNode, map);
        for (Node *neighbor : neighbors) {
            if (containsNode(closedSet, neighbor)) {
                continue; // 如果邻居节点已经在 closedSet 中，则跳过
            }

            int tentativeG = currentNode->g + currentNode->getDistance(neighbor);
            if (!containsNode(openSet, neighbor) || tentativeG < neighbor->g) {
                neighbor->parent = currentNode;
                neighbor->g = tentativeG;
                neighbor->h = heuristic(neighbor, map->endNode);
                neighbor->f = neighbor->g + neighbor->h;

                if (!containsNode(openSet, neighbor)) {
                    openSet.push_back(neighbor);
                }
            }
        }
    }

    return std::vector<Node *>(); // 如果未能找到路径，则返回空向量
}
