#include "graph.hpp"

bool graph::find(int x) {
    for (int i = 0; i < _visited.size(); i++) {
        if(_visited[i] == x) { return true; }
    }
    return false;
}

graph::graph(std::vector<std::vector<int>> g) {
    _g = g;
    int index = rand()%g.size(); //Cлучайным образом генерируем вершину, с которой начнем формировать остовное дерево
    _visited.push_back(index);
}

int graph::FindMinAdj(int vertex) {
    int min = MIN;
    int vertexMin = -1;
    for (int i = 0; i < _g.size(); i++) {
        if(_g[vertex][i] < min && _g[vertex][i] > 0 && !find(i))
        {
            min = _g[vertex][i];
            vertexMin = i;
        }
    }
    return vertexMin; //Если возращаемое значение -1, то вершина не имеет соседей среди непосещенных
}

void graph::Prima() {
    if(_visited.empty()) {
        int index = rand()%_g.size(); //Cлучайным образом генерируем вершину, с которой начнем формировать остовное дерево
        _visited.push_back(index);
    }
    std::vector<Edge> tree; // Хранит ребра остовного дерева
    int totalWeight = 0;
    while(tree.size() != _g.size()-1) //Остовное дерево всегда имеет на 1 ребро меньше, чем кол-во вершин
    {
        int eWeight = MIN; int eNode_2 = -1; int eNode_1 = -1; // Контрольные значения для сравнения
        for (const int &vertex : _visited) {
            int m = FindMinAdj(vertex); // Для каждой из посещенных вершин находим непосещенную с минимальным расстоянием
            if(_g[vertex][m] < eWeight && m!= -1) {
                eNode_2 = m;
                eWeight = _g[vertex][eNode_2];
                eNode_1 = vertex;
            }
        }
        Edge e(eNode_1,eNode_2,eWeight);
        std::cout << e._node_1 << "<-->" << e._node_2 << "; w = " <<e._weight << std::endl;
        _visited.push_back(e._node_2);
        tree.push_back(e);
        totalWeight += eWeight;
    }
    std::cout << "Минимальный вес остовного дерева = " << totalWeight << std::endl;
    _visited.clear();
}
