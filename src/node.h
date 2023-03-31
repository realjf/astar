#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include <math.h>

class Node {
public:
    int x; // 节点的 x 坐标
    int y; // 节点的 y 坐标

    std::vector<Node *> neighbors; // 与该节点相邻的节点列表

    int f;        // f = g + h，表示从起点到该节点的总代价
    int g;        // g 表示从起点到该节点的实际代价
    int h;        // h 表示从该节点到终点的估计代价
    Node *parent; // 记录该节点的父节点

    bool walkable = true; // 是否可行走

    Node(int x, int y);

    int getDistance(Node *otherNode) const;

    void setWalkable(bool walkable);
};

#endif /* _NODE_H_ */
