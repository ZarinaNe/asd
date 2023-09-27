
#include "graph.hpp"

graph::graph(std::vector<Edge> graph, int amountVertex) {
    _g = graph;
    for(int i = 0; i < _g.size(); i++)
    {
        _root.push_back(i);
    }
    _amountVertex = amountVertex;
}

void graph::Bellman_Ford(int startV) {
    // Шаг 0
    std::vector<int> distanse;
    for (int i = 0; i < _amountVertex; i++) {
        if(i!=startV) {
            distanse.push_back(INT8_MAX);
        } else {
            distanse.push_back(0);
        }
    }
    // Шаг 1 .. n-1
    for (const Edge &e : _g) {
        if(distanse[e._node_2] > distanse[e._node_1]+e._weight) {
            distanse[e._node_2] = distanse[e._node_1]+e._weight; // Релаксируем ребро e
        }
    }
    // Шаг n : проверка критерия сущестования цикла отрицательной длины
    for (const Edge &e : _g) {
        if(distanse[e._node_2] > distanse[e._node_1]+e._weight) {
            std::cout << "Граф содержит цикл отрицательной длины"<< std::endl;
            return;
        }
    }
    // Печать расстояний
    std::cout << "Кратчайшие расстояния:" << std::endl;
    for (int i = 0; i < distanse.size(); i++) {
        if(i == startV) { continue; }
        std::cout << startV << "<-->" << i << " = ";
        if (distanse[i] > 0) {
            std::cout << "+" << distanse[i] << std::endl;
        } else {
            std::cout << distanse[i] << std::endl;
        }
    }
}
