#include "map.h"

Map::Map() {
}

Map::Map(int width, int height) {
    // 初始化地图上的节点
    for (int x = 0; x < width; x++) {
        std::vector<Node *> xnode = std::vector<Node *>();
        m_MapData.push_back(xnode);
        for (int y = 0; y < height; y++) {
            Node *node = new Node(x, y);
            m_MapData[x].push_back(node);
        }
    }
    m_Width = width;
    m_Height = height;

    fillNeighbors();
}

Node *Map::getNode(int x, int y) {
    return m_MapData[x][y];
}

bool Map::isWalkable(int x, int y) const {
    // 判断该点是否能行走
    return x >= 0 && x < m_Width && y >= 0 && y < m_Height && m_MapData[x][y]->walkable;
}

void Map::setStartNode(Node *node) {
    startNode = node;
}

void Map::setEndNode(Node *node) {
    endNode = node;
}

void Map::printMap() {
    std::cout << "  ";
    for (int x = 0; x < m_Width; x++) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (int x = 0; x < m_Width; x++) {
        std::cout << x << " ";
        for (int y = 0; y < m_Height; y++) {
            std::cout << m_MapData[x][y]->walkable << " ";
        }
        std::cout << std::endl;
    }
}

void Map::fillNeighbors() {
    // 填充相邻节点
    for (int x = 0; x < m_Width; x++) {
        for (int y = 0; y < m_Height; y++) {
            Node *node = m_MapData[x][y];
            node->neighbors = std::vector<Node *>();
            if (x - 1 >= 0) {
                Node *left = m_MapData[x - 1][y];
                node->neighbors.push_back(left);
            }
            if (y + 1 < m_Height) {
                Node *right = m_MapData[x][y + 1];
                node->neighbors.push_back(right);
            }
            if (y - 1 >= 0) {
                Node *top = m_MapData[x][y - 1];
                node->neighbors.push_back(top);
            }
            if (x + 1 < m_Width) {
                Node *bottom = m_MapData[x + 1][y];
                node->neighbors.push_back(bottom);
            }
            if (m_DiagonalWalkable) {
                if (x - 1 >= 0 && y - 1 >= 0) {
                    Node *leftTop = m_MapData[x - 1][y - 1];
                    node->neighbors.push_back(leftTop);
                }

                if (x + 1 < m_Width && y + 1 < m_Height) {
                    Node *rightBottom = m_MapData[x + 1][y + 1];
                    node->neighbors.push_back(rightBottom);
                }

                if (x - 1 >= 0 && y + 1 < m_Height) {
                    Node *leftBottom = m_MapData[x - 1][y + 1];
                    node->neighbors.push_back(leftBottom);
                }

                if (x + 1 < m_Width && y - 1 >= 0) {
                    Node *rightTop = m_MapData[x + 1][y - 1];
                    node->neighbors.push_back(rightTop);
                }
            }
        }
    }
}

void Map::printPath(std::vector<Node *> path) {
    std::cout << std::endl;
    std::cout << "  ";
    for (int x = 0; x < m_Width; x++) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (int x = 0; x < m_Width; x++) {
        std::cout << x << " ";
        for (int y = 0; y < m_Height; y++) {
            if (startNode->x == x && startNode->y == y) {
                std::cout << "S ";
            } else if (endNode->x == x && endNode->y == y) {
                std::cout << "E ";
            } else {
                bool isPath = false;
                for (Node *node : path) {
                    if (node->x == x && node->y == y) {
                        isPath = true;
                    }
                }
                if (isPath) {
                    std::cout << "* ";
                } else {
                    std::cout << m_MapData[x][y]->walkable << " ";
                }
            }
        }
        std::cout << std::endl;
    }
}

void Map::setDiagonalWalkable(bool diagWalkable) {
    m_DiagonalWalkable = diagWalkable;
    fillNeighbors();
}
