#include <iostream>
#include "../src/map.h"
#include "../src/astar.h"

int main() {
    // 创建地图对象
    Map map(10, 10);

    // 设置起点和终点
    Node *startNode = map.getNode(1, 1);
    Node *endNode = map.getNode(8, 8);
    map.setStartNode(startNode);
    map.setEndNode(endNode);
    map.setDiagonalWalkable(true);

    // 添加障碍物
    map.getNode(2, 2)->setWalkable(false);
    map.getNode(2, 3)->setWalkable(false);
    map.getNode(3, 3)->setWalkable(false);
    map.getNode(4, 3)->setWalkable(false);
    map.getNode(5, 3)->setWalkable(false);
    map.getNode(6, 3)->setWalkable(false);
    map.getNode(7, 3)->setWalkable(false);
    map.getNode(7, 4)->setWalkable(false);
    map.getNode(7, 5)->setWalkable(false);
    map.getNode(7, 6)->setWalkable(false);

    // 运行 A* 算法
    std::vector<Node *> path = AStar::findPath(&map);

    map.printMap();

    std::cout << std::endl;
    // 输出结果vc
    if (path.size() > 0) {
        for (Node *node : path) {
            std::cout << "(" << node->x << "," << node->y << ") ";
        }
        map.printPath(path);
        std::cout << std::endl;
    } else {
        std::cout << "未找到路径！" << std::endl;
    }

    return 0;
}
