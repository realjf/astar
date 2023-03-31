#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include <iostream>
#include "node.h"

class Map {

public:
    Map();
    Map(int width, int height);

    Node *getNode(int x, int y);

    bool isWalkable(int x, int y) const;

    void setStartNode(Node *node);

    void setEndNode(Node *node);

    void printMap();

    void fillNeighbors();

    void printPath(std::vector<Node *> path);

    void setDiagonalWalkable(bool diagWalkable);

public:
    std::vector<std::vector<Node *>> m_MapData; // 地图数据节点
    Node *startNode;                            // 起点
    Node *endNode;
    int m_Width;             // 宽度
    int m_Height;            // 高度
    bool m_DiagonalWalkable; // 斜方向行走
};

#endif /* _MAP_H_ */
