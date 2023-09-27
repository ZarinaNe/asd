#include "graph.hpp"

bool graph::compare(Edge a, Edge b) {
    return a._weight < b._weight;
}

int graph::findRoot(int x) {
    if (_root[x] == x)
        return x;
    else {
        int root_x = findRoot(_root[x]);
        return root_x;
    }
}

graph::graph(std::vector<Edge> graph, int amountVertex) {
    _g = graph;
    for(int i = 0; i < _g.size(); i++)
    {
        _root.push_back(i);
    }
    _amountVertex = amountVertex;
}

void graph::print() {
    for (int i = 0; i < _g.size(); i++) {
        std::cout << _g[i]._node_1 << " " << _g[i]._node_2 << " " << _g[i]._weight << std::endl;
    }
}

void graph::sortEdges() {
    std::sort(_g.begin(),_g.end(), compare);
}

void graph::Kruskal() {
    sortEdges(); // Отсортируем ребра по весу по неубыванию
    int weight = 0; int amountEdge = 0;
    for (int i = 0; i < _g.size(); i++)
    {
        int rootNode_1 = findRoot(_g[i]._node_1);
        int rootNode_2 = findRoot(_g[i]._node_2);
        if(rootNode_1 != rootNode_2)
        {
            _root[rootNode_1] = rootNode_2;
            weight += _g[i]._weight;
            std::cout << _g[i]._node_1 << "<-->" << _g[i]._node_2 << std::endl;
            amountEdge++;

        }
        if(amountEdge == _amountVertex-1) break; //  остовное дерево всегда имеет на 1 ребро меньше, чем кол-во вершин

    }
    std::cout << "Минимальный вес оставного дерева = " << weight << std::endl;
}
